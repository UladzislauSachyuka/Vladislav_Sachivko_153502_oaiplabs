#include "tree.h"


int Tree::get_height(Node *head)
{
    if (!head) return 0;
    return head->height;
}

Tree::Node *Tree::right_rotation(Node *head)
{
    Node* newhead = head->left;
    head->left = newhead->right;
    newhead->right = head;
    head->height = 1 + qMax(get_height(head->left), get_height(head->right));
    newhead->height = 1 + qMax(get_height(newhead->left), get_height(newhead->right));
    return newhead;
}

Tree::Node *Tree::left_rotation(Node *head)
{
    Node* newhead = head->right;
    head->right = newhead->left;
    newhead->left = head;
    head->height = 1 + qMax(get_height(head->left), get_height(head->right));
    newhead->height = 1 + qMax(get_height(newhead->left), get_height(newhead->right));
    return newhead;
}

Tree::Node *Tree::insert(Node *head, int k, QString str)
{
    if (!head)
    {
        ++n;
        Node* temp = new Node(k, str);
        return temp;
    }
    if (k < head->key)
        head->left = insert(head->left, k, str);
    else if (k > head->key)
        head->right = insert(head->right, k, str);
    head->height = 1 + qMax(get_height(head->left), get_height(head->right));
    int dif = get_height(head->left) - get_height(head->right);
    if (dif > 1)
    {
        if (k < head->left->key)
            return right_rotation(head);
        else
        {
            head->left = left_rotation(head->left);
            return right_rotation(head);
        }
    }
    else if (dif < -1)
    {
        if (k > head->right->key)
            return left_rotation(head);
        else
        {
            head->right = right_rotation(head->right);
            return left_rotation(head);
        }
    }
    return head;
}

Tree::Node *Tree::remove(Node *head, int k)
{
    if (!head)
        return nullptr;
    if (k < head->key)
        head->left = remove(head->left, k);
    else if (k > head->key)
        head->right = remove(head->right, k);
    else
    {
        Node* r = head->right;
        if (!head->right)
        {
            Node* l = head->left;
            delete head;
            head = l;
        }
        else if (!head->left)
        {
            delete head;
            head = r;
        }
        else
        {
            while (r->left != nullptr)
                r = r->left;
            head->key = r->key;
            head->right = remove(head->right, r->key);
        }
    }
    if (!head)
        return head;
    head->height = 1 + qMax(get_height(head->left), get_height(head->right));
    int dif = get_height(head->left) - get_height(head->right);
    if (dif > 1)
    {
        if (get_height(head->left) >= get_height(head->right))
            return right_rotation(head);
        else
        {
            head->left = left_rotation(head->left);
            return right_rotation(head);
        }
    }
    else if (dif < -1)
    {
        if (get_height(head->right) >= get_height(head->left))
            return left_rotation(head);
        else
        {
            head->right = right_rotation(head->right);
            return left_rotation(head);
        }
    }
    return head;
}

Tree::Node* Tree::search(Node *head, int k)
{
    if (!head)
        return nullptr;
    int key_ = head->key;
    if (key_ == k)
        return head;
    if (key_ > k)
        return search(head->left, k);
    if (key_ < k)
        return search(head->right, k);
}
