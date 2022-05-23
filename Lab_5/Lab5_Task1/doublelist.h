#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <QPointer>
#include "myqueue.h"

struct node
{
    int value;
    QSharedPointer<node> next;
    QSharedPointer<node> prev;
};

class DoubleList : private MyQueue<int>
{
public:
    DoubleList();

    void push_back(const int& val);
    void push_front(const int& val);

    void pop_back();
    void pop_front();

    int getCount() const;

    QSharedPointer<node> begin();

private:
    QSharedPointer<node> head;
    QSharedPointer<node> tail;
    int count;
};

#endif // DOUBLELIST_H
