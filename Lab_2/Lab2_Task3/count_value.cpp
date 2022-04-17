#include "count_value.h"

count_val::Node::Node(double val) : value(val), next(nullptr), prev(nullptr) {}

count_val::count_val() : first(nullptr), last(nullptr) {}

int count_val::getLength()
{
    return length;
}

void count_val::push_back(double val){
    Node* tmp = new Node(val);
    if (first == nullptr && last == nullptr) { //если список пустой
            first = tmp;
            last = tmp;
    }
    else {
            tmp->prev = last;
            last->next = tmp;
            last = tmp;
    }
    ++length;
}

void count_val::delSpisok()
{
    Node *temp = first;
    for(int i = 0; i < length; ++i){
        Node *next = temp->next;
        delete temp;
        temp = next;
    }
    first = nullptr;
    last = nullptr;
    length = 0;
}

void count_val::pop()
{
    if (first == nullptr) return;
    Node* tmp = last;
        --length;
        if (tmp == first){
            last = nullptr;
            first = nullptr;
            delete tmp;
            return;
        }
        else {
            last = tmp->prev;
            last->next = nullptr;
            tmp->prev = nullptr;
            delete tmp;
            return;
        }
}

double count_val::getValue(int n)
{
    Node *tmp = first;
    int i = 0;
    while (i != n) {
        tmp = tmp->next;
        ++i;
    }
    return tmp->value;
}

