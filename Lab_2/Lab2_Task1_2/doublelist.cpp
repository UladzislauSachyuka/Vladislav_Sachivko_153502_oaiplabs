#include "doublelist.h"

doublelist::doublelist() : first(-1), last(-1), length(0), capacity(0) {
    list = new Unit[1];
}

doublelist::~doublelist()
{

}

void doublelist::push_back(QDate d, int code, QString city, QTime time, int num, QString tariff, QString number)
{
    if(length == capacity) extend();
    Unit *tmp = new Unit(d, code, city, time, num, tariff, number);
    tmp->index = length;
    if (first == -1) {
            first = tmp->index;
            last = tmp->index;
            list[length] = *tmp;
    }
    else {
        list[last].nextIndex = length;
        list[length] = *tmp;
        tmp->prevIndex = last;
        last = tmp->index;
    }
    ++length;
}

int doublelist::getLength()
{
    return length;
}

void doublelist::extend()
{
    capacity *= 2;
    Unit *extension = new Unit[capacity];
    for (int i = 0; i < length; ++i) extension[i] = list[i];
    delete[] list;
    list = extension;
}

void doublelist::erase(QString number)
{
    Unit tmp = list[first];
    while (tmp.nextIndex != -1){
        if (tmp.number == number){
            if (tmp.index == first && first == last){
                last = -1;
                first = -1;
                return;
            }
            else if (tmp.index == last){
                last = tmp.prevIndex;
                list[last].nextIndex = -1;
                return;
            }
            else if (tmp.index == first) {
                first = tmp.nextIndex;
                tmp = list[tmp.nextIndex];
                tmp.prevIndex = -1;
            }
            else {
                list[tmp.prevIndex].nextIndex = tmp.nextIndex;
                list[tmp.nextIndex].prevIndex = tmp.prevIndex;
                tmp = list[tmp.nextIndex];
            }
        }
        else tmp = list[tmp.nextIndex];
    }
    return;
}



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
