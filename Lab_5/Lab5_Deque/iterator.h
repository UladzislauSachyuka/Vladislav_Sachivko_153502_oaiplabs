#ifndef ITERATOR_H
#define ITERATOR_H

#include "mydeque.h"

template <typename T>
class iterator
{
public:
    iterator(T **pt, T *p, bool f = false) : ptr_arr(pt), ptr(p)
    {
        if (f)
        {
            i = 0;
            j = MyDeque<T>::head_element_pos;
        }
        else
        {
            i = MyDeque<T>::blocks_count - 1;
            j = MyDeque<T>::tail_element_pos;
        }
    }

    T& operator*()
    {
        return *ptr;
    }

    iterator& operator++()
    {
        if (j == MyDeque<T>::k - 1)
        {
            ++i;
            j = 0;
            ptr = &ptr_arr[i][j];
        }
        else
        {
            ++j;
            ++ptr;
        }
        return *this;
    }

    iterator& operator--()
    {
        if (j == 0)
        {
            --i;
            j = MyDeque<T>::k - 1;
            ptr = &ptr_arr[i][j];
        }
        else
        {
            --j;
            --ptr;
        }
        return *this;
    }

    bool operator==(const iterator& it) const { return ptr == it.ptr; }
    bool operator!=(const iterator& it) const { return ptr != it.ptr; }

    iterator& operator+(const int n)
    {
        int l = n / MyDeque<T>::k;
        int s = n - l * MyDeque<T>::k;
        i += l;
        j += s;
        ptr = &ptr_arr[i][j];
        return *this;
    }

private:
    T** ptr_arr;
    T* ptr;
    int i;
    int j;
};

#endif // ITERATOR_H
