#include "spisok.h"

spisok::Node::Node(QChar val, bool symb) : value(val), symbol(symb), next(nullptr), prev(nullptr) {}

spisok::spisok() : first(nullptr), last(nullptr) {}

int spisok::getLength()
{
    return length;
}

void spisok::push_back(QChar val, bool symb){
    Node* tmp = new Node(val, symb);
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

void spisok::delSpisok()
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

void spisok::pop()
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

QChar spisok::getValue(int n)
{
    Node *tmp = first;
    int i = 0;
    while (i != n) {
        tmp = tmp->next;
        ++i;
    }
    return tmp->value;
}

QString spisok::get_all()
{
    QString res;
    Node *tmp = first;
    while (tmp != nullptr){
        res += tmp->value;
        tmp = tmp->next;
    }
    return res;
}

