#ifndef VECTOR_H
#define VECTOR_H


#include "mainwindow.h"

typedef unsigned int size_t;

using namespace std;

template<typename T>
class Vector
{
private:
    T* arr;
    int size;
    int capacity = 15;
public:
    Vector() : arr(new T[capacity]), size(0), capacity(15)  {}

    explicit Vector(size_t n) : size(n)
    {
        while (capacity < n)
            capacity *= 2;
        arr = new T[capacity];
        for (int i = 0; i < n; i++)
            arr[i] = 0;
    }

    explicit Vector(size_t n, const T& val) : size(n)
    {
        while (capacity < n)
            capacity *= 2;
        arr = new T[capacity];
        for (int i = 0; i < n; i++)
            arr[i] = val;
    }

    Vector(const Vector& x) : size(x.size), capacity(x.capacity)
    {
        arr = new T[capacity];
        for (int i = 0; i < size; i++)
            arr[i] = x.arr[i];
    }

    Vector(Vector&& x) : arr(x.arr), size(x.size), capacity(x.capacity)
    {
        x.arr = nullptr;
        x.size = x.capacity = 0;
    }

    ~Vector()
    {
        delete[] arr;
    }

    Vector& operator=(const Vector& x)
    {
        if (this == &x)
            return *this;
        delete[] arr;
        size = x.size;
        capacity = x.capacity;
        arr = new T[capacity];
        for (int i = 0; i < size; i++)
            arr[i] = x.arr[i];

        return *this;
    }

    Vector& operator=(Vector&& x)
    {
        if (this == &x)
            return *this;
        delete[] arr;
        arr = x.arr;
        size = x.size;
        capacity = x.capacity;
        x.arr = nullptr;
        x.size = x.capacity = 0;

        return *this;
    }

    class iterator
    {
    private:
        T* arr;
    public:
        iterator(T* ar) : arr(ar) {}

        iterator& operator++()
        {
            ++arr;
            return *this;
        }

        iterator& operator=(const iterator& it)
        {
            arr = it.arr;
            return *this;
        }

        iterator& operator=(const T* ar)
        {
            arr = ar;
            return *this;
        }

        iterator& operator+(size_t n)
        {
            for (int i = 0; i < n; ++i)
                ++arr;
            return arr;
        }

        T* operator[](size_t pos) { return arr[pos]; }

        T& operator*() { return *arr; }

        T* get() { return arr; }

        bool operator==(const iterator& it) { return arr == it.arr; }
        bool operator!=(const iterator& it) { return arr != it.arr; }
    };

    iterator begin() noexcept { return arr; }
    iterator end() noexcept { return arr + size; }

    size_t Size() const noexcept
    {
        return size;
    }

    size_t Capacity() const noexcept
    {
        return capacity;
    }

    bool empty() const noexcept
    {
        return size == 0;
    }

    void resize(size_t n)
    {
        if (n > size)
        {
            if (n > capacity)
            {
                while (capacity < n)
                    capacity *= 2;
                arr = (T*)realloc(arr, capacity);
            }
            for (int i = size; i < n; ++i)
                arr[i] = 0;

        }
        else if (n < size)
        {
            arr = (T*)realloc(arr, n);
        }
        size = n;
    }

    void resize(size_t n, const T& val)
    {
        if (n > size)
        {
            if (n > capacity)
            {
                while (capacity < n)
                    capacity *= 2;
                arr = (T*)realloc(arr, capacity);
            }
            for (int i = size; i < n; ++i)
                arr[i] = val;
        }
        else if (n < size)
        {
            arr = (T*)realloc(arr, n);
        }
        size = n;
    }

    void reserve(size_t n)
    {
        if (n <= capacity)
            return;
        while (capacity < n)
            capacity *= 2;
        arr = (T*)realloc(arr, n);
    }

    T& operator[](size_t pos)
    {
        return arr[pos];
    }

    T& at(size_t pos)
    {
        if (pos >= size)
            throw std::out_of_range("Invalid index");
        return arr[pos];
    }

    T& front() { return arr[0]; }
    T& back() { return arr[size - 1]; }

    T* data() noexcept { return arr; }

    void assign(size_t n, const T& val)
    {
        if (n >= size)
        {
            if (n > capacity)
            {
                while (capacity < n)
                    capacity *= 2;
                arr = (T*)realloc(arr, n);
            }
            for (int i = 0; i < n; i++)
                arr[i] = val;
        }
        else
        {
            while (capacity / 2 > n)
                capacity /= 2;
            arr = (T*)realloc(arr, capacity);
            for (int i = 0; i < n; i++)
                arr[i] = val;
        }
        size = n;
    }

    void push_back(const T& val)
    {
        if (size + 1 > capacity)
        {
            capacity *= 2;
            arr = (T*)realloc(arr, capacity);
        }
        arr[size] = val;
        ++size;
    }

    void push_back(T&& val)
    {
        if (size + 1 > capacity)
        {
            capacity *= 2;
            arr = (T*)realloc(arr, capacity);
        }
        arr[size] = val;
        ++size;
    }

    void pop_back()
    {
        if (empty())
            return;
        --size;
    }

    iterator insert(iterator pos, const T& val)
    {
        if (size + 1 > capacity)
        {
            capacity *= 2;
            arr = (T*)realloc(arr, capacity);
        }

        int p = 0;
        while (this->arr != pos.get())
        {
            ++arr;
            ++p;
        }

        for (int i = size; i > p; --i)
            this->arr[i] = this->arr[i - 1];
        this->arr[p] = val;
        ++size;

        return arr;
    }

    iterator erase(iterator pos)
    {
        int p = 0;
        while (this->arr != pos.get())
        {
            ++arr;
            ++p;
        }

        T* tmp1 = new T[p + 1];
        for (int i = 0; i < p; ++i)
            tmp1[i] = arr[i];

        T* tmp2 = new T[size - p - 1];
        for (int i = p + 1, j = 0; i < size; ++i, ++j)
            tmp2[j] = arr[i];

        delete[] arr;
        --size;
        arr = new T[capacity];
        for (int i = 0; i < p; ++i)
            arr[i] = tmp1[i];

        for (int i = p, j = 0; i < size; ++i, ++j)
            arr[i] = tmp2[j];

        delete[] tmp1;
        delete[] tmp2;

        return arr + p;
    }

    void swap(Vector& x)
    {
        std::swap(*this, x);
    }

    void clear() noexcept
    {
        delete[] arr;
        size = 0;
        capacity = 15;
        arr = new T[capacity];
    }

    template<typename... Args>
    void emplace_back(const Args&... args)
    {
        if (size == capacity)
            reserve(2 * capacity);
        new (arr + size) T(args...);
        ++size;
    }

};

#endif // VECTOR_H
