#ifndef UNIVERSAL_H
#define UNIVERSAL_H

#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>
#include <cmath>

class Universal : public QGraphicsItem
{
private:
    bool univers;
    double k = 1;
    int a = 0;
public:
    Universal();
    bool getUnivers();
    void setUnivers(bool uni);
    double getK();

    void move_up();
    void size();
    void move_right();
    void move_left();
    void move_down();
    void rotate();

    virtual double square();
    virtual double perimetr();

protected:
    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // UNIVERSAL_H
