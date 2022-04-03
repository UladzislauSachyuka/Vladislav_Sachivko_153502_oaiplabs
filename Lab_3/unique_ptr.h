#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H
#include <iostream>

//using namespace std;

template <typename T>
class Unique_ptr
{
private:
    T* ptr;

public:
    Unique_ptr() noexcept : ptr(nullptr) {}

    explicit Unique_ptr(T* ptr) : ptr(ptr) {}

    ~Unique_ptr() {
        delete ptr;
    }

    Unique_ptr(const Unique_ptr&) = delete;
    Unique_ptr& operator=(const Unique_ptr&) = delete;

    Unique_ptr(Unique_ptr&& another) noexcept : ptr(another.ptr) {
        another.ptr = nullptr;
    }

    Unique_ptr& operator=(Unique_ptr&& another) {
        delete ptr;
        ptr = another.ptr;
        another.ptr = nullptr;
        return *this;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    operator bool() {
        return ptr;
    }

    bool isNull() const noexcept {
        return ptr == nullptr;
    }

    T* get() const {
        return ptr;
    }

    T* release() {
        T* tmp = ptr;
        ptr = nullptr;
        return tmp;
    }

    void reset(T* p) {
        delete ptr;
        ptr = p;
    }

    void swap(Unique_ptr& another) {
        std::swap(ptr, another.ptr);
    }
};

template <typename T>
class Unique_ptr<T[]>
{
private:
    T* ptr;

public:
    Unique_ptr() : ptr(nullptr) {}

    explicit Unique_ptr(T* ptr) : ptr(ptr) {}

    ~Unique_ptr() {
        delete[] ptr;
    }

    Unique_ptr(const Unique_ptr&) = delete;
    Unique_ptr& operator=(const Unique_ptr&) = delete;

    Unique_ptr(Unique_ptr&& another) : ptr(another.ptr) {
        another.ptr = nullptr;
    }

    Unique_ptr& operator=(Unique_ptr&& another) {
        delete[] ptr;
        ptr = another.ptr;
        another.ptr = nullptr;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    T& operator[] (const int& i) const {
        return ptr[i];
    }

    operator bool() {
        return ptr;
    }

    bool isNull() const noexcept {
        return ptr == nullptr;
    }

    T* get() const {
        return ptr;
    }

    T* release() {
        T* tmp = ptr;
        ptr = nullptr;
        return tmp;
    }

    void reset(T* p) {
        delete[] ptr;
        ptr = p;
    }

    void swap(Unique_ptr& another) {
        Qswap(ptr, another.ptr);
    }
};

//template <class T, class... Args>
//typename std::enable_if
//<
//    !std::is_array<T>::value,
//    Unique_ptr<T>
//>::type
//make_unique(Args&& ...args) {
//    return Unique_ptr<T>(new T(std::forward<Args>(args)...));
//}

//Для массивов
//template <class T>
//typename std::enable_if
//<
//    std::is_array<T>::value,
//    Unique_ptr<T>
//>::type
//make_unique(std::size_t n) {
//    typedef typename std::remove_extent<T>::type RT;
//    return Unique_ptr<T>(new RT[n]);
//}

#endif // UNIQUE_PTR_H
