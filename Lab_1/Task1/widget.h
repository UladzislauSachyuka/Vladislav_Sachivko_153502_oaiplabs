#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "Headers.h"
#include "rectangle.h"
#include "truck.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent * e) override;
public slots:
    void timer_event();

private slots:
    void on_RectMoveBtn_clicked();

    void on_TruckMoveBtn_clicked();

private:
    Ui::Widget *ui;
    QTimer * timer;
    QPainter * painter_1;
    QPainter * painter_2;
    bool rectangle_f;
    bool truck_f;
    Truck truck;
    Rectangle rect;

};
#endif // WIDGET_H
