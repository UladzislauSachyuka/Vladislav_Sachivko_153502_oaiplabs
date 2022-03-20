#include "rectangle.h"

Rectangle::Rectangle()
{
    x = 100;
    y = 100;
    length = 100;
    height = 100;
}

void Rectangle::paint(QPainter * e,  QPainter * m)
{
    Q_UNUSED(m);
    e->setPen(QPen(Qt::red, 1, Qt::SolidLine));
    e->setBrush(Qt::red);
    e->drawRect(x, y, length, height);
}

void Rectangle::changeValues()
{
    ++this->x;
}
