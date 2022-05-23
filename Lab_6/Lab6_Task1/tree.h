#ifndef TREE_H
#define TREE_H

#include <cmath>
#include <QString>

class Tree
{
public:
    class Node
    {
    public:
        int key;
        QString value;
        int height;
        Node* left;
        Node* right;

        Node() {}
        Node(int k, QString val) : key(k), value(val), height(1), left(nullptr), right(nullptr) {}
    };

    Node* root = nullptr;
    int n = 0;

public:
    int get_height(Node* head);

    Node* right_rotation(Node* head);

    Node* left_rotation(Node* head);

    Node* insert(Node* head, int k, QString str);

    Node* remove(Node* head, int k);

    Node* search(Node* head, int k);

};

#endif // TREE_H
