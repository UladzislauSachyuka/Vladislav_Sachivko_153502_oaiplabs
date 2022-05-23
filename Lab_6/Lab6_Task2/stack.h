#ifndef STACK_H
#define STACK_H

#include <QString>

class Stack
{
public:
    struct Node
    {
        int key;
        int val;
        Node* next;

        Node(int k, int v) : key(k), val(v), next(nullptr) {}
    };

    Stack();

    void push(int k, int v);

    void remove(int k);

    bool search(int k);

    int search_(int k);

    QString keys();

    QString values();

private:
    Node* head;
    int size;
};

#endif // STACK_H
