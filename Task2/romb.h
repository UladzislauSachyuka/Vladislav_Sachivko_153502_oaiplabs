#ifndef ROMB_H
#define ROMB_H

#include "universal.h"

class Romb : public Universal
{
private:
    double size = 94.34;
    int angel = 64;
public:
    Romb();
    double square() override;
    double perimetr() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)override;
};

#endif // ROMB_H
