#ifndef TRUCK_H
#define TRUCK_H

#include "Headers.h"

#include "rectangle.h"

class Truck : public Rectangle
{
public:
    Truck();
    void paint(QPainter * e, QPainter * m) override;
    void changeValues() override;

private:
    int angle;
    int end_angle;
};

#endif // TRUCK_H
