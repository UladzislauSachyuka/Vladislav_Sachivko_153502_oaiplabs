#ifndef UNIT_H
#define UNIT_H

#include <QString>
#include <QDate>

class Unit
{
public:
    Unit() {}

    Unit(QDate d, int code, QString city, QTime time, int num, QString tariff, QString number) :
        date(d), code(code), city(city), time(time), number_in_the_city(num), tariff(tariff), number(number) {}
public:
    QDate date;
    int code;
    QString city;
    QTime time;
    int number_in_the_city;
    QString tariff;
    QString number;
    int nextIndex;
    int prevIndex;
    int index;
};

#endif // UNIT_H
