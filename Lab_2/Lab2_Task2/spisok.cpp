#include "spisok.h"

spisok::Node::Node(QChar ind, int indexx) : code(ind), index(indexx), next(nullptr), prev(nullptr) {}

spisok::spisok() : first(nullptr), last(nullptr) {}

void spisok::push_back(QChar code, int indexx){
    Node* tmp = new Node(code, indexx);
    if (first == nullptr && last == nullptr) {
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

bool spisok::pop(QChar code)
{
    if (first == nullptr) return false;
    if (code == ')' && last->code != '(') return false;
    else if (code == ']' && last->code != '[') return false;
    else if (code == '}' && last->code != '{') return false;
    Node* tmp = last;
        --length;
        if (tmp == first){
            last = nullptr;
            first = nullptr;
            delete tmp;
            return true;
        }
        else {
            last = tmp->prev;
            last->next = nullptr;
            tmp->prev = nullptr;
            delete tmp;
            return true;
        }
}

int spisok::check(QString input)
{
    int count = 0;
    for (int i = 0; i < input.size(); ++i){
        if (input[i] == '[' || input[i] == '(' || input[i] == '{') {
            push_back(input[i], i);
            ++count;
        }
        else if(input[i] == ']' || input[i] == ')' || input[i] == '}') {

            if (!pop(input[i])) return i;
            --count;
        }
    }
    if (count != 0) return first->index;
    else return -1;
}
