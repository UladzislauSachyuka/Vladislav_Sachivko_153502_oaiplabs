#ifndef NODE_H
#define NODE_H

#include <QString>

class Node
{
public:
    Node(int num = 0, QString surname = "", QString title = "", int year = 0, QString publ = "", int pages = 0) :
        number(num), authorSurname(surname), title(title), year(year), publisher(publ), pages(pages) {}
public:
    int number;
    QString authorSurname;
    QString title;
    int year;
    QString publisher;
    int pages;
    Node* next = nullptr;
    Node* prev = nullptr;
};

#endif // NODE_H
