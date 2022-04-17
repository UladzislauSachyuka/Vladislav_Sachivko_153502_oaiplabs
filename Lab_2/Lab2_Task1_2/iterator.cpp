#include "iterator.h"

iterator::iterator(Node *tmp) : node(tmp) {}

Node &iterator::operator*() {return *node;}

iterator &iterator::operator++()
{
    assert(node);
    node = node->next;
    return *this;
}

bool iterator::operator==(const iterator &it) const { return it.node == this->node; }

bool iterator::operator!=(const iterator &it) const { return it.node != this->node; }

iterator &iterator::operator+(const int n)
{
    for (int i = 0; i < n; ++i)
    {
        assert(node);
        node = node->next;
    }
    return *this;
}

Node *iterator::getNode()
{
    return node;
}
