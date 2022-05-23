
#include "doublelist.h"

DoubleList::DoubleList()
{

}

void DoubleList::push_back(const int &val)
{
    if (!head)
    {
        head = QSharedPointer<node>(new node);
        tail = QSharedPointer<node>(head);
        head->value = val;
        head->next = nullptr;
        head->prev = nullptr;
        ++count;
        return;
    }

    ++count;
    QSharedPointer<node> tmp = QSharedPointer<node>(new node);
    tmp->value = val;
    tmp->next = nullptr;
    tail->next = tmp;
    tmp->prev = tail;
    tail = tmp;
}

void DoubleList::push_front(const int &val)
{
    QSharedPointer<node> tmp = QSharedPointer<node>(new node);
    tmp->value = val;
    tmp->prev = nullptr;
    tmp->next = head;
    head = tmp;
    if (!tail)
        tail = head;
    ++count;
}

void DoubleList::pop_back()
{
    if (!tail)
        return;
    QSharedPointer<node> tmp = QSharedPointer<node>(tail->prev);
    tail.clear();
    tail = tmp;
    tail->next = nullptr;
    --count;
}

void DoubleList::pop_front()
{
    if (!head)
        return;
    QSharedPointer<node> tmp = QSharedPointer<node>(head->next);
    head.clear();
    head = tmp;
    head->prev = nullptr;
    --count;
}

int DoubleList::getCount() const
{
    return count;
}

QSharedPointer<node> DoubleList::begin()
{
    return head;
}
