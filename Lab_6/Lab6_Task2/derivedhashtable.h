#ifndef DERIVEDHASHTABLE_H
#define DERIVEDHASHTABLE_H

#include "hashtable.h"

class DerivedHashTable : public HashTable
{
public:
    DerivedHashTable();

    ~DerivedHashTable();

private:
    Stack* stack1;
    static const int k = 100;
};

#endif // DERIVEDHASHTABLE_H
