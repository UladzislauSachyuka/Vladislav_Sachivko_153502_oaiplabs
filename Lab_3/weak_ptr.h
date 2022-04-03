#ifndef WEAK_PTR_H
#define WEAK_PTR_H
#include <iostream>

#include "shared_ptr.h"

template <class T>
class Weak_ptr {
private:
    ControlBlock<T>* cptr = nullptr;

    template <class U>
    friend class Shared_ptr;

public:
    Weak_ptr() {}

    Weak_ptr(const Shared_ptr<T>& ptr) : cptr(ptr.cptr) {
        if (cptr)
            ++cptr->weak_count;
    }

    ~Weak_ptr() {
        --cptr->weak_count;
        if (cptr->shared_count == 0 && cptr->weak_count == 0) {
            delete cptr;
        }
    }

    bool expired() const {
        return cptr->shared_count == 0;
    }

    Weak_ptr<T>& operator=(Weak_ptr<T>& another) {
        if (cptr) {
            --cptr->weak_count;
        }
        cptr = another.cptr;
        if (cptr) {
            ++cptr->weak_count;
        }
        return *this;
    }

    Weak_ptr<T>& operator=(Shared_ptr<T>& another) {
        if (cptr) {
            --cptr->weak_count;
        }
        cptr = another.cptr;
        if (cptr) {
            ++cptr->weak_count;
        }
        return *this;
    }

    Weak_ptr<T>& operator=(Shared_ptr<T>&& another) {
        if (cptr) {
            --cptr->weak_count;
        }
        cptr = another.cptr;
        another.cptr = nullptr;
        return *this;
    }

    void reset() {
        if (cptr) {
            --cptr->weak_count;
        }
        cptr = nullptr;
    }

    void swap(Weak_ptr<T>& another) {
        std::swap(cptr, another.cptr);
    }

    int use_count() {
        if (cptr)
            return cptr->shared_count;
    }

    Shared_ptr<T> lock() {
        return (expired() ? Shared_ptr<T>() : Shared_ptr<T>(*this));
    }

};

template <class T>
class Weak_ptr<T[]> {
private:
    ControlBlock<T>* cptr = nullptr;

public:
    Weak_ptr() {}

    Weak_ptr(const Shared_ptr<T>& ptr) : cptr(ptr.cptr) {
        if (cptr)
            ++cptr->weak_count;
    }

    ~Weak_ptr() {
        --cptr->weak_count;
        if (cptr->shared_count == 0 && cptr->weak_count == 0) {
            delete cptr;
        }
    }

    bool expired() const {
        return cptr->shared_count == 0;
    }

    Weak_ptr<T>& operator=(Weak_ptr<T>& another) {
        if (cptr) {
            --cptr->weak_count;
        }
        cptr = another.cptr;
        if (cptr) {
            ++cptr->weak_count;
        }
        return *this;
    }

    Weak_ptr<T>& operator=(Shared_ptr<T>& another) {
        if (cptr) {
            --cptr->weak_count;
        }
        cptr = another.cptr;
        if (cptr) {
            ++cptr->weak_count;
        }
        return *this;
    }

    Weak_ptr<T>& operator=(Shared_ptr<T>&& another) {
        if (cptr) {
            --cptr->weak_count;
        }
        cptr = another.cptr;
        another.cptr = nullptr;
        return *this;
    }

    void reset() {
        if (cptr) {
            --cptr->weak_count;
        }
        cptr = nullptr;
    }

    void swap(Weak_ptr<T>& another) {
        Qswap(cptr, another.cptr);
    }

    int use_count() {
        if (cptr)
            return cptr->shared_count;
    }

    Shared_ptr<T> lock() {
        return (expired() ? Shared_ptr<T>() : Shared_ptr<T>(*this));
    }

};

#endif // WEAK_PTR_H
