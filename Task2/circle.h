#ifndef CIRCLE_H
#define CIRCLE_H

#include "universal.h"

class Circle : public Universal
{
private:
    double radius = 80;
public:
    Circle();
    double square() override;
    double perimetr() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)override;
};

#endif // CIRCLE_H
