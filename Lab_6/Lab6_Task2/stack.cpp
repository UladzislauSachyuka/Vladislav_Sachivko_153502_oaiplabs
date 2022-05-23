#include "stack.h"

Stack::Stack() : head(nullptr), size(0) {}

void Stack::push(int k, int v)
{
    if (!head)
        head = new Node(k, v);
    else
    {
        Node* node = new Node(k, v);
        node->next = head;
        head = node;
    }
    ++size;
}

void Stack::remove(int k)
{
    if (!head || !search(k))
        return;
    this->push(1, 1);
    Node* tmp = head;
    while (tmp->next && tmp->next->key != k)
        tmp = tmp->next;
    Node* node = tmp->next;
    tmp->next = node->next;
    delete node;
    head = head->next;
    --size;
}

bool Stack::search(int k)
{
    if (!head)
        return false;
    Node* tmp = head;
    while (tmp->key != k) {
        tmp = tmp->next;
        if (!tmp)
            return false;
    }
    return true;
}

int Stack::search_(int k)
{
    if (!head)
        return 0;
    Node* tmp = head;
    while (tmp->key != k) {
        tmp = tmp->next;
        if (!tmp)
            return 0;
    }
    return tmp->val;
}

QString Stack::keys()
{
    if (!head)
        return "";
    QString str;
    Node* tmp = head;
    while (tmp)
    {
        str += QString::number(tmp->key) + " ";
        tmp = tmp->next;
    }
    return str;
}

QString Stack::values()
{
    if (!head)
        return "";
    QString str;
    Node* tmp = head;
    while (tmp)
    {
        str += QString::number(tmp->val) + " ";
        tmp = tmp->next;
    }
    return str;
}
