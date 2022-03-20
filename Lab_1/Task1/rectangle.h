#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Headers.h"

class Rectangle
{
public:
    Rectangle();
    virtual void paint(QPainter * e, QPainter * m = nullptr);
    virtual void changeValues();
private:
    int x;
    int y;
    int height;
    int length;
};

#endif // RECTANGLE_H
