#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include "node.h"
#include "iterator.h"

class iterator;

class DoubleList
{
public:
    DoubleList();
    ~DoubleList();

    void push_front(Node* item);
    void push_back(Node* item);

    void pop_front();
    void pop_back();

    void erase(int pos);

    iterator begin();
    iterator end();

    int getCount();


private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;
    friend class iterator;
};

#endif // DOUBLELIST_H
