#ifndef COUNT_VALUE_H
#define COUNT_VALUE_H


#include <QString>

class count_val
{
private:
    struct Node {
            double value;
            Node* next;
            Node* prev;
            Node (double val);
            Node () {}
    };
    Node* first;
    Node* last;
    int length = 0;

public:

    count_val();

    int getLength();

    void push_back(double val);

    void delSpisok();

    void pop();

    int operate(QString input);

    double getValue(int n);
};


#endif // COUNT_VALUE_H
