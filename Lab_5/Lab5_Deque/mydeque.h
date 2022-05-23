#ifndef MYDEQUE_H
#define MYDEQUE_H

#include <iostream>
//#include "iterator.h"

template <typename T>
class iterator;

template <typename T>
class MyDeque
{
public:
    MyDeque() : sz(0), blocks_count(1), arr(new T*[1]), head(nullptr), tail(nullptr)
    {
        arr[0] = new T[k];
    }

    ~MyDeque()
    {
        for (int i = 0; i < blocks_count; ++i)
            delete[] arr[i];
        delete[] arr;
    }

    void push_back(const T &val)
    {
        if (!head)
        {
            arr[0][0] = val;
            head = tail = arr[0];
            empty_elements_after_tail = k - 1;
            head_element_pos = tail_element_pos = 0;
        }
        else if (empty_elements_after_tail == 0)
        {
            arr = (T**)realloc(arr, ++blocks_count);
            arr[blocks_count - 1] = new T[k];
            arr[blocks_count - 1][0] = val;
            tail = arr[blocks_count - 1];
            empty_elements_after_tail = k - 1;
            tail_element_pos = 0;
        }
        else
        {
            arr[blocks_count - 1][tail_element_pos + 1] = val;
            //*(++tail) = val;
            tail = &arr[blocks_count - 1][tail_element_pos + 1];
            --empty_elements_after_tail;
            ++tail_element_pos;
        }
        ++sz;
    }

    void push_front(const T& val)
    {
        if (!head)
        {
            arr[0][0] = val;
            head = tail = arr[0];
            empty_elements_before_head = 0;
            empty_elements_after_tail = k - 1;
            head_element_pos = tail_element_pos = 0;
        }
        else if (empty_elements_before_head == 0)
        {
            arr = (T**)realloc(arr, ++blocks_count);
            arr[blocks_count - 1] = new T[k];
            T* tmp = arr[blocks_count - 1];
            for (int i = blocks_count - 1; i > 0; --i)
                arr[i] = arr[i - 1];
            arr[0] = tmp;

            arr[0][k - 1] = val;
            head = &arr[0][k - 1];
            empty_elements_before_head = k - 1;
            head_element_pos = k - 1;
        }
        else
        {
            arr[0][head_element_pos - 1] = val;
            head = &arr[0][head_element_pos - 1];
            --empty_elements_before_head;
            --head_element_pos;
        }
        ++sz;
    }

    void pop_back()
    {
        if (!tail)
            return;
        if (empty_elements_after_tail == k - 1)
        {
            arr = (T**)realloc(arr, --blocks_count);
            if (!arr)
            {
                sz = 0;
                head = tail = nullptr;
                empty_elements_before_head = 0;
                empty_elements_after_tail = 15;
                head_element_pos = 0;
                tail_element_pos = 0;
                return;
            }
            tail = &arr[blocks_count - 1][k - 1];
            empty_elements_after_tail = 0;
            tail_element_pos = k - 1;
        }
        else
        {
            tail = &arr[blocks_count - 1][tail_element_pos - 1];
            ++empty_elements_after_tail;
            --tail_element_pos;
        }
        --sz;
    }

    void pop_front()
    {
        if (!head)
            return;
        if (empty_elements_before_head == k - 1)
        {
            for (int i = 0; i < blocks_count - 1; ++i)
                arr[i] = arr[i + 1];
            arr = (T**)realloc(arr, --blocks_count);
            if (!arr)
            {
                sz = 0;
                head = tail = nullptr;
                empty_elements_before_head = 0;
                empty_elements_after_tail = 15;
                head_element_pos = 0;
                tail_element_pos = 0;
                return;
            }
            head = &arr[0][0];
            empty_elements_before_head = 0;
            head_element_pos = 0;
        }
        else
        {
            head = &arr[0][head_element_pos + 1];
            ++empty_elements_before_head;
            ++head_element_pos;
        }
        --sz;
    }

    void clear()
    {
        for (int i = 0; i < blocks_count; ++i)
            delete[] arr[i];
        delete[] arr;
        sz = 0;
        blocks_count = 1;
        arr = new T*[1];
        arr[0] = new T[k];
        head = tail = nullptr;
        empty_elements_before_head = 0;
        empty_elements_after_tail = 15;
        head_element_pos = 0;
        tail_element_pos = 0;
    }

    int size() const { return sz; }

    bool empty() const { return sz == 0; }

    void resize(int count)
    {
        if (!head)
        {
            int l = count - blocks_count * k;
            int m = 0, s = l % k;
            while (l != 0)
            {
                l /= k;
                ++m;
            }
            arr = (T**)realloc(arr, blocks_count + m);
            for (int i = blocks_count; i < blocks_count + m; ++i)
            {
                arr[i] = new T[k];
                for (int j = 0; j < k; ++j)
                    arr[i][j] = T();
            }
            blocks_count += m;
            head = arr[0];
            tail = &arr[blocks_count][s - 1];
            empty_elements_before_head = 0;
            empty_elements_after_tail = k - s;
            head_element_pos = 0;
            tail_element_pos = s - 1;
            return;
        }
        if (count > sz)
        {
            if (count <= blocks_count * k)
            {
                int l = blocks_count * k - count;
                for (int i = tail_element_pos; i < k - l; ++i)
                    arr[blocks_count - 1][i] = T();
                tail = &arr[blocks_count - 1][k - l - 1];
                empty_elements_after_tail = l;
                tail_element_pos = k - l - 1;
            }
            else
            {
                int l = count - blocks_count * k;
                int m = 0, s = l % k;
                while (l != 0)
                {
                    l /= k;
                    ++m;
                }
                arr = (T**)realloc(arr, blocks_count + m);
                for (int i = blocks_count; i < blocks_count + m; ++i)
                {
                    arr[i] = new T[k];
                    for (int j = 0; j < k; ++j)
                        arr[i][j] = T();
                }
                blocks_count += m;
                tail = &arr[blocks_count][s - 1];
                empty_elements_after_tail = k - s;
                tail_element_pos = s - 1;
            }
            sz = count;
        }
        else if (count < sz)
        {
            if (count >= (blocks_count - 1) * k)
            {
                int l = blocks_count * k - count;
                tail = &arr[blocks_count][k - l - 1];
                empty_elements_after_tail = l;
                tail_element_pos = k - l - 1;
            }
            else
            {
                int l = blocks_count * k - count;
                int m = 0, s = l % k;
                while (l != 0)
                {
                    l /= k;
                    ++m;
                }
                arr = (T**)realloc(arr, blocks_count - m);
                blocks_count -= m;
                tail = &arr[blocks_count][k - s - 1];
                empty_elements_after_tail = k - s;
                tail_element_pos = k - s - 1;
            }
            sz = count;
        }
        else
            return;
    }

    iterator<T> begin()
    {
        return iterator<T>(arr, head, true);
    }
    iterator<T> end()
    {
        return iterator<T>(arr, tail, false);
    }

    T& operator[](int pos)
    {
        return arr[pos / k][pos - pos / k * k];
    }

    T& front()
    {
        return arr[0][head_element_pos];
    }

    T& back()
    {
        return arr[blocks_count - 1][tail_element_pos];
    }

private:
    static const int k = 15;
    int sz;
    int blocks_count;
    T** arr;
    T* head;
    T* tail;
    int empty_elements_before_head = 0;
    int empty_elements_after_tail = 15;
    int head_element_pos = 0;
    int tail_element_pos = 0;
    friend class iterator<T>;
};

#endif // MYDEQUE_H
