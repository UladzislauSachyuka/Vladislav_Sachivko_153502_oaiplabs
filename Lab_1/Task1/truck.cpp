#include "truck.h"

Truck::Truck()
{
    angle = 0;
    end_angle = -40;
}

void Truck::paint(QPainter *e,  QPainter * m)
{
    QRectF rec2(260, 155, 70, 95);
    QBrush Brush(Qt::gray);

    e->fillRect(rec2, Brush);

    QRectF rec3(65, 250, 265, 40);
    Brush.setColor(Qt::blue);

    e->fillRect(rec3, Brush);

    QRectF rec4(310, 170, 20, 20);
    Brush.setColor(Qt::white);

    e->fillRect(rec4, Brush);

    e->setBrush(QBrush(Qt::black));
    //Brush.setColor(Qt::black);
    e->drawEllipse(90, 275, 30, 30);
    e->drawEllipse(275, 275, 30, 30);


    QTransform mat;
    mat.translate(60, 250);
    m->setTransform(mat);
    m->rotate(angle);

    QRectF rec1(10, -100, 195, 100);
    Brush = QBrush((Qt::red));
    m->fillRect(rec1, Brush);
}

void Truck::changeValues()
{
    if(angle > end_angle && abs(angle) < abs(end_angle)){
//        qDebug() << "End angle\t" << end_angle;
//        qDebug() << "Angle\t" << angle;
        --angle;

    }
}
