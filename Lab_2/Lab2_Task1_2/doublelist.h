#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include "node.h"
#include "iterator.h"

#include "unit.h"

class doublelist
{
public:
    doublelist();
    ~doublelist();

    void push_back(QDate d, int code, QString city, QTime time, int num, QString tariff, QString number);

    int getLength();

    void extend();

    void erase(QString number);

private:
    int first;
    int last;
    int length;
    int capacity;
    Unit* list;
};













class iterator;

class DoubleList
{
public:
    DoubleList();
    ~DoubleList();

    void push_back(Node* item);

    void pop_front();
    void pop_back();

    void erase(int pos);

    iterator begin();
    iterator end();

    int getCount();

private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;
    friend class iterator;
};

#endif // DOUBLELIST_H
