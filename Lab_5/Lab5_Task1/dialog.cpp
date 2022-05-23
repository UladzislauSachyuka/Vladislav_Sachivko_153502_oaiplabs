#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    list1 = new DoubleList;
    list2 = new DoubleList;
    list3 = new DoubleList;

    QString str1, str2;

    for (int i = 0; i < 50; ++i)
    {
        int val = rand() % 100 - 50;
        list1->push_back(val);
        str1 += QString::number(val) + " ";
    }

    ui->textBrowser->setText(str1);
    str1.clear();

    QSharedPointer<node> tmp = list1->begin();
    for (int i = 0; i < 50; ++i)
    {
        if (tmp->value < 0)
        {
            list2->push_back(tmp->value);
            str1 += QString::number(tmp->value) + " ";
        }
        else
        {
            list3->push_back(tmp->value);
            str2 += QString::number(tmp->value) + " ";
        }
        tmp = tmp->next;
    }

    ui->textBrowser_2->setText(str1);
    ui->textBrowser_3->setText(str2);
}

Dialog::~Dialog()
{
    delete ui;
    delete list1;
    delete list2;
    delete list3;
}

void Dialog::on_pushButton_clicked()
{
    close();
}

