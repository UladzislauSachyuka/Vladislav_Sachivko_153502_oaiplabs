#include "star.h"

//Star::Star()
//{

//}

void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    int a=0;
    QPoint *p=new QPoint [top*2+1];

    for (int i=1;i<top*2+2;i++)
    {
       if (!(i%2))
       {
           p[i].rx()=radius/2*cos(a*M_PI/180);
           p[i].ry()=radius/2*sin(a*M_PI/180);
       }
       else
       {
           p[i].rx()=Radius*cos(a*M_PI/180);
           p[i].ry()=Radius*sin(a*M_PI/180);
       }
       a=a+180/top;
    }

    p[top*2+1].rx()=p[1].rx();
    p[top*2+1].ry()=p[1].ry();
    //moveto(p[1].x,p[1].y);

    for (int i=1;i<top*2+1;i++)
    {
       painter->drawLine(p[i].rx(),p[i].ry(), p[i + 1].rx(),p[i + 1].ry());
    }

    delete []p;
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
