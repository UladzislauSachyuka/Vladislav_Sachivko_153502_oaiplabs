#include "mydeque.h"


/*template<typename T>
MyDeque<T>::MyDeque() : sz(0), arr(new T*[1]), blocks_count(1) ,head(nullptr), tail(nullptr)
{
    arr[0] = new T[k];
}

template<typename T>
void MyDeque<T>::push_back(const T &val)
{
    if (!head)
    {
        arr[0][0] = val;
        ++sz;
        head = tail = arr[0];
        empty_elements_after_tail = 14;
        head_element_pos = tail_element_pos = 0;
    }
    else if (empty_elements_after_tail == 0)
    {
        arr = realloc((T**)arr, ++blocks_count);
        arr[blocks_count - 1][0] = val;
        ++sz;
        tail = arr[blocks_count - 1];
        empty_elements_after_tail = 14;
        tail_element_pos = 0;
    }
    else
    {
        arr[blocks_count - 1][tail_element_pos + 1] = val;
        ++sz;
        tail = &arr[blocks_count - 1][tail_element_pos + 1];
        --empty_elements_after_tail;
        ++tail_element_pos;
    }
}*/

/*template<typename T>
void MyDeque<T>::push_front(const T &val)
{

}

template<typename T>
void MyDeque<T>::pop_back()
{

}

template<typename T>
void MyDeque<T>::pop_front()
{

}

template<typename T>
void MyDeque<T>::clear()
{

}

template<typename T>
int MyDeque<T>::size() const
{

}

template<typename T>
bool MyDeque<T>::empty() const
{

}

template<typename T>
void MyDeque<T>::resize()
{

}

template<typename T>
iterator<T> MyDeque<T>::begin()
{
    return ptr(head);
}

template<typename T>
iterator<T> MyDeque<T>::end()
{
    return ptr(tail);
}*/
