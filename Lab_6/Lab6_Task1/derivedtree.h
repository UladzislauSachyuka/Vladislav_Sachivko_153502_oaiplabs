#ifndef DERIVEDTREE_H
#define DERIVEDTREE_H

#include "tree.h"

class DerivedTree : public Tree
{
public:
    DerivedTree();

    int nodes_with_one_branch(Node* head);
};

#endif // DERIVEDTREE_H
