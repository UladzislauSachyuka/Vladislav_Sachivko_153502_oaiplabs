#include "derivedtree.h"

DerivedTree::DerivedTree()
{

}

int DerivedTree::nodes_with_one_branch(Node *head)
{
    if (head == nullptr)
            return 0;
    if (head->left == nullptr && head->right != nullptr)
        return 1 + nodes_with_one_branch(head->right);
    if (head->left != nullptr && head->right == nullptr)
        return 1 + nodes_with_one_branch(head->left);
    return nodes_with_one_branch(head->left) + nodes_with_one_branch(head->right);
}
