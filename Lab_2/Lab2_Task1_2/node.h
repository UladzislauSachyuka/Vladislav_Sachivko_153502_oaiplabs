#ifndef NODE_H
#define NODE_H

#include <QString>
#include <QDate>

class Node
{
public:
    Node(QDate d, int code, QString city, QTime time, int num, QString tariff, QString number) :
        date(d), code(code), city(city), time(time), number_in_the_city(num), tariff(tariff), number(number) {}
public:
    QDate date;
    int code;
    QString city;
    QTime time;
    int number_in_the_city;
    QString tariff;
    QString number;
    Node* next = nullptr;
    Node* prev = nullptr;
};

#endif // NODE_H
