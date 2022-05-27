#ifndef MYUNORDERED_MAP_H
#define MYUNORDERED_MAP_H

#include <iostream>
#include <QString>
#include <forward_list>
#include <QPair>
#include <vector>

using namespace std;

template <class KeyType, class ValueType, class Hash = std::hash<KeyType>>
class Myunordered_map
{
public:
    Myunordered_map(int sz) : size(sz), arr(sz) {}

    void insert(KeyType key, ValueType value)
    {
        int hash = hasher(key) % size;
        arr[hash].push_front(QPair<KeyType, ValueType>(key, value));
        ++current_size;
        if (current_size >= size * load_factor)
        {

        }
    }

    void erase(KeyType key)
    {
        if (!current_size)
            return;
        int hash = hasher(key) % size;
        auto iter = arr[hash].before_begin();
        auto prev = iter;
        while (iter != arr[hash].end())
        {
            if ((*iter).first == key)
            {
                arr[hash].erase_after(prev);
                --current_size;
                break;
            }
            prev = iter;
            ++iter;
        }
    }

    ValueType find(int key)
    {
        int hash = hasher(key) % size;
        auto iter = arr[hash].begin();
        while (iter != arr[hash].end())
        {
            if (iter->first == key)
                return iter->second;
            ++iter;
        }
        return ValueType();
    }

    int max_size()
    {
        return size;
    }

    int Size()
    {
        return current_size;
    }

    bool empty()
    {
        return current_size == 0;
    }

    void clear()
    {
        arr.clear();
        arr.resize(size);
        current_size = 0;
    }

    bool contains(const KeyType& key)
    {
        int hash = hasher(key) % size;
        auto iter = arr[hash].begin();
        while (iter != arr[hash].end())
        {
            if (iter->first == key)
                return true;
            ++iter;
        }
        return false;
    }

    ValueType& operator[](const KeyType& key)
    {
            int hash = hasher(key) % size;
            auto iter = arr[hash].begin();
            while(iter != arr[hash].end())
            {
                if(iter->first == key)
                    return iter->second;
                ++iter;
            }
            ValueType value;
            insert(key,value);
            return this->operator[](key);
    }

    int get_hash(int key)
    {
        return hasher(key) % size;
    }

    QString keys(int key)
    {
        int hash = hasher(key) % size;
        auto iter = arr[hash].begin();
        QString str = "";
        while (iter != arr[hash].end())
        {
            str += QString::number(iter->first);
            ++iter;
        }
        return str;
    }

    QString values(int key)
    {
        int hash = hasher(key) % size;
        auto iter = arr[hash].begin();
        QString str = "";
        while (iter != arr[hash].end())
        {
            str += QString::number(iter->second);
            ++iter;
        }
        return str;
    }

private:
    void rehash(int new_size)
    {
        vector<std::forward_list<QPair<KeyType,ValueType>>> temparr(new_size);
        std::swap(arr,temparr);
        current_size = 0;
        for(int i = 0;i < size; ++i)
        {
            auto iter = temparr[i].begin();
            while (iter != temparr[i].end())
            {
                insert(iter->first,iter->second);
                ++iter;
            }
        }
        size = new_size;
    }

private:
    Hash hasher;
    int size;
    int current_size = 0;
    std::vector<std::forward_list<QPair<KeyType, ValueType>>> arr;

    const double load_factor = 0.75;
};

#endif // MYUNORDERED_MAP_H

