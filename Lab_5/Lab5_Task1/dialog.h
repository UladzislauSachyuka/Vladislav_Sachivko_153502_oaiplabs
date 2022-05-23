#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "doublelist.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    DoubleList *list1;
    DoubleList *list2;
    DoubleList *list3;
};

#endif // DIALOG_H
