#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <QStack>
#include <QPair>
#include "stack.h"

class HashTable
{
public:
    HashTable();

    void insert(int k, int v);

    int calculate_hash(int k);

    void remove(int k);

    QString keys_(int k);

    QString values_(int k);

    int value(int k);

    int find(int k);

private:
    static const int k = 100;
    int count;
    //QStack<QPair<int, int>>* stack;
    Stack* stack;
};

#endif // HASHTABLE_H
