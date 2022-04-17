#include "doublelist.h"

DoubleList::DoubleList()
{

}

DoubleList::~DoubleList()
{
    while (head)
    {
        tail = head->next;
        delete head;
        head = tail;
    }
}

void DoubleList::push_front(Node *item)
{
   item->prev = nullptr;
   item->next = head;
   head = item;
   if (!tail)
       tail = head;
   count++;
}

void DoubleList::push_back(Node *item)
{
    if (!head)
    {
        head = item;
        item->next = nullptr;
        item->prev = nullptr;
    }
    else
    {
        tail->next = item;
        item->prev = tail;
        item->next = nullptr;
    }
    tail = item;
    count++;
}

void DoubleList::pop_front()
{
    if (!head)
        return;
    Node* tmp = head->next;
    delete head;
    head = tmp;
    if (head)
        head->prev = nullptr;
    --count;
}

void DoubleList::pop_back()
{
    if (!tail)
        return;
    Node* tmp = tail->prev;
    delete tail;
    tail = tmp;
    tail->next = nullptr;
    --count;
}

void DoubleList::erase(int pos)
{
    if (!head)
        return;
    if (pos == 1)
        this->pop_front();
    else if (pos == getCount())
        this->pop_back();
    else
    {
        iterator it = begin();
        for (int i = 0; i < pos - 1; ++i, ++it);
        Node* tmp = it.node;
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;
        delete tmp;
        count--;
    }
}

iterator DoubleList::begin()
{
    return iterator(head);
}

iterator DoubleList::end()
{
    return iterator(tail);
}

int DoubleList::getCount()
{
    return count;
}
