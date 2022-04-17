#ifndef ITERATOR_H
#define ITERATOR_H

#include "doublelist.h"

class iterator
{
public:
    iterator(Node* tmp);

    Node& operator*();

    iterator& operator++();

    bool operator==(const iterator& it) const;
    bool operator!=(const iterator& it) const;

    iterator& operator+(const int n);

    Node* getNode();

private:
    Node* node;
    friend class DoubleList;
};

#endif // ITERATOR_H
