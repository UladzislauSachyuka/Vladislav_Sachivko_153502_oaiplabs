#ifndef SQUARE_H
#define SQUARE_H

#include "universal.h"

class Square : public Universal
{
private:
    double size = 60;
public:
    Square();
    double square() override;
    double perimetr() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)override;
};

#endif // SQUARE_H
