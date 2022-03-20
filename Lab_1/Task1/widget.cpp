#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    rectangle_f = false;
    truck_f = false;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    painter_1 = new QPainter(this);
    painter_2 = new QPainter(this);
    if(rectangle_f){
        rect.paint(painter_1, painter_2);
    }
    else if(truck_f){
        truck.paint(painter_1, painter_2);
    }
    painter_1->end();
    painter_2->end();
}

void Widget::timer_event()
{

    if(rectangle_f){
        rect.changeValues();
    }
    else if(truck_f){

        truck.changeValues();
    }
    repaint();
}


void Widget::on_RectMoveBtn_clicked()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_event()));
    this->rectangle_f = true;
    this->truck_f = false;
    timer->start(15);
}


void Widget::on_TruckMoveBtn_clicked()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_event()));
    this->rectangle_f = false;
    this->truck_f = true;
    timer->start(50);
}

