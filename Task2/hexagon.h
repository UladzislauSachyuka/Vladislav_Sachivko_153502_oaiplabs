#ifndef HEXAGON_H
#define HEXAGON_H

#include "universal.h"

class Hexagon : public Universal
{
private:
    double radius = 50;
public:
    Hexagon();
    double square() override;
    double perimetr() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)override;
};

#endif // HEXAGON_H
