#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include <QPointer>
using namespace std;
template <typename T>
class MyQueue
{
public:
    struct Node
    {
        T value = T();
        QSharedPointer<Node> next;
    };

    MyQueue() : sz(0) {}

    void push(const T& val)
    {
        if (!head)
        {
            head = QSharedPointer<Node>(new Node);
            tail = QSharedPointer<Node>(head);
            head->value = val;
            head->next = nullptr;
            ++sz;
            return;
        }
        ++sz;
        QSharedPointer<Node> tmp = QSharedPointer<Node>(new Node);
        tmp->value = val;
        tmp->next = nullptr;
        tail->next = tmp;
        tail = tmp;
    }

    void push(T&& val)
    {
        if (!head)
        {
            head = QSharedPointer<Node>(new Node);
            tail = QSharedPointer<Node>(head);
            head->value = val;
            head->next = nullptr;
        }

        ++sz;
        QSharedPointer<Node> tmp = QSharedPointer<Node>(new Node);
        tmp->value = val;
        tmp->next = nullptr;
        tail->next = tmp;
        tail = tmp;
    }

    void pop()
    {
        if (!head)
            return;
        QSharedPointer<Node> tmp = QSharedPointer<Node>(head);
        head = head->next;
        --sz;
    }

    bool empty() const
    {
        return sz == 0;
    }

    int size() const
    {
        return sz;
    }

    T& front()
    {
        return head->value;
    }

    T& back()
    {
        return tail->value;
    }

private:
    QSharedPointer<Node> head;
    QSharedPointer<Node> tail;
    int sz;
};

#endif // MYQUEUE_H
