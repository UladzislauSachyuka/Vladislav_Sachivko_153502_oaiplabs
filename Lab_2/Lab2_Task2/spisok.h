#ifndef SPISOK_H
#define SPISOK_H
#include <QString>
#include <QChar>

class spisok
{
private:
    struct Node {
            QChar code;
            int index;
            Node* next;
            Node* prev;
            Node (QChar ind, int indexx);
            Node () {}
    };
    Node* first;
    Node* last;
    int length = 0;

public:

    spisok();

    int getLength();

    void push_back(QChar code, int indexx);

    void delSpisok();

    bool pop(QChar code);

    int check(QString input);

};

#endif // SPISOK_H
