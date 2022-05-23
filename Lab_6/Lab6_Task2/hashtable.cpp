#include "hashtable.h"

HashTable::HashTable() : count(0)
{
    //stack = new QStack<QPair<int, int>>[k];
    stack = new Stack[k]();
}

void HashTable::insert(int key, int val)
{
    int index = this->calculate_hash(key);
    //stack->push(QPair<int, int>(key, val));
    stack[index].push(key, val);
    ++count;
}

int HashTable::calculate_hash(int key)
{
    return key % k;
}

void HashTable::remove(int k)
{
    int index = this->calculate_hash(k);
    stack[index].remove(k);
}

QString HashTable::keys_(int k)
{
    int index = this->calculate_hash(k);
    return stack[index].keys();
}

QString HashTable::values_(int k)
{
    int index = this->calculate_hash(k);
    return stack[index].values();
}

int HashTable::value(int k)
{
    int index = this->calculate_hash(k);
    return stack[index].search_(k);
}

int HashTable::find(int k)
{

}
