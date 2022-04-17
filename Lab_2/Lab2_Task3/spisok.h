#ifndef SPISOK_H
#define SPISOK_H


#include <QString>

class spisok
{
private:
    struct Node {
            QChar value;
            bool symbol; //true - переменная, false - знак
            Node* next;
            Node* prev;
            Node (QChar val, bool symb);
            Node () {}
    };
    Node* first;
    Node* last;
    int length = 0;

public:

    spisok();

    int getLength();

    void push_back(QChar val, bool symb);

    void delSpisok();

    void pop();

    int operate(QString input);

    QChar getValue(int n);

    QString get_all();
};


#endif // SPISOK_H
