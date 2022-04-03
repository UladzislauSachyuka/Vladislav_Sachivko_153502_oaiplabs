#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <iostream>

#include "unique_ptr.h"

template <class T>
struct ControlBlock {
    T* ptr = nullptr;
    int shared_count = 0;
    int weak_count = 0;
};

template <class T>
class Weak_ptr;

template <class T>
class Shared_ptr {
private:
    ControlBlock<T>* cptr = nullptr;
    template <class U>
    friend class Weak_ptr;
public:
    Shared_ptr() {}

    explicit Shared_ptr(T* ptr) : cptr(new ControlBlock<T>) {
        cptr->ptr = ptr;
        ++(cptr->shared_count);
    }

    explicit Shared_ptr(const Weak_ptr<T>& ptr) : cptr(ptr.cptr) {
        if (cptr)
            ++cptr->shared_count;
    }

    ~Shared_ptr() {
        --cptr->shared_count;
        if (cptr->shared_count > 0) {
            return;
        }

        if (cptr->weak_count == 0) {
            delete cptr;
            return;
        }
        delete cptr->ptr;
        cptr->ptr = nullptr;
    }

    Shared_ptr(const Shared_ptr<T>& another) {
        cptr = another.cptr;
        ++(cptr->shared_count);
    }

    Shared_ptr<T>& operator=(Shared_ptr<T>& another) {
        if (cptr) {
            --(cptr->shared_count);
        }
        cptr = another.cptr;
        if (cptr) {
            ++(cptr->shared_count);
        }
        return *this;
    }

    Shared_ptr(Shared_ptr<T>&& another) {
        cptr = another.cptr;
        another.cptr = nullptr;
    }

    Shared_ptr<T>& operator=(Shared_ptr<T>&& another) {
        if (cptr) {
            --(cptr->shared_count);
        }
        cptr = another.cptr;
        another.cptr = nullptr;

        return *this;
    }

    bool unique() {
        if (cptr->ptr == nullptr) {
            return false;
        }
        return cptr->shared_count == 1;
    }

    T* operator->() {
        return cptr->ptr;
    }

    T& operator*() {
        return *(cptr->ptr);
    }

    explicit operator bool() const noexcept {
        return cptr->ptr != nullptr;
    }

    int use_count() const noexcept {
        return cptr->ptr ? cptr->shared_count : 0;
    }

    void swap(Shared_ptr<T>& another) {
        std::swap(cptr, another.cptr);
    }

    T* get() {
        return cptr->ptr;
    }

    void reset() {
        if (cptr)
            --cptr->shared_count;
        cptr = nullptr;
    }
};

//template<typename T, typename... Args>
//Shared_ptr<T> make_shared_ptr(Args&&... args)
//{
//    return Shared_ptr<T>(new T(std::forward<Args>(args)...));
//}

template <class T>
class Shared_ptr<T[]> {
private:
    ControlBlock<T>* cptr = nullptr;
    template <class U>
    friend class Weak_ptr;
public:
    Shared_ptr() {}

    explicit Shared_ptr(T* ptr) : cptr(new ControlBlock<T>) {
        cptr->ptr = ptr;
        ++(cptr->shared_count);
    }

    explicit Shared_ptr(const Weak_ptr<T>& ptr) : cptr(ptr.cptr) {
        if (cptr)
            ++cptr->shared_count;
    }

    ~Shared_ptr() {
        --cptr->shared_count;
        if (cptr->shared_count > 0) {
            return;
        }

        if (cptr->weak_count == 0) {
            delete cptr;
            return;
        }
        delete[] cptr->ptr;
        cptr->ptr = nullptr;
    }

    Shared_ptr(const Shared_ptr& another) {
        cptr = another.cptr;
        ++(cptr->shared_count);
    }

    Shared_ptr<T>& operator=(Shared_ptr<T>& another) {
        if (cptr) {
            --(cptr->shared_count);
        }
        cptr = another.cptr;
        if (cptr) {
            ++(cptr->shared_count);
        }
        return *this;
    }

    Shared_ptr(Shared_ptr&& another) {
        cptr = another.cptr;
        another.cptr = nullptr;
    }

    Shared_ptr<T>& operator=(Shared_ptr<T>&& another) {
        if (cptr) {
            --(cptr->shared_count);
        }
        cptr = another.cptr;
        another.cptr = nullptr;

        return *this;
    }

    bool unique() {
        if (cptr->ptr == nullptr) {
            return false;
        }
        return cptr->shared_count == 1;
    }

    T* operator->() {
        return cptr->ptr;
    }

    T& operator*() {
        return *(cptr->ptr);
    }

    /*T& operator[] (const int& i) const {
        return cptr->ptr[i];
    }*/

    explicit operator bool() const noexcept {
        return get() != nullptr;
    }

    int use_count() const noexcept {
        return cptr->ptr ? cptr->shared_count : 0;
    }

    void swap(Shared_ptr<T>& another) {
        Qswap(cptr, another.cptr);
    }

    T* get() {
        return cptr->ptr;
    }

    void reset() {
        if (cptr)
            --cptr->shared_count;
        cptr = nullptr;
    }
};

#endif // SHARED_PTR_H
