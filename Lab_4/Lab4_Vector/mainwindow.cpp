#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    v.~Vector();
}


void MainWindow::on_push_back_clicked()
{
    if (f) {
        str = "";
        f = false;
    }
    int val = ui->val_get->value();
    v.push_back(val);
    str += QString::number(val) + ' ';
    ui->display->setText(str);
}


void MainWindow::on_pop_back_clicked()
{
    if (v.Size() == 0)
    {
        QMessageBox::warning(this, "Ошибка", "Вектор пуст");
        return;
    }
    int k = v[v.Size() - 1];
    int i = 0;
    while (k != 0)
    {
        ++i;
        k /= 10;
    }
    v.pop_back();
    str = str.left(str.size() - i - 1);
    ui->display->setText(str);
}


void MainWindow::on_emplace_back_clicked()
{
        if (f) {
            str = "";
            f = false;
        }
        int val = ui->val_get->value();
        v.emplace_back(val);
        str += QString::number(val) + ' ';
        ui->display->setText(str);
}


void MainWindow::on_clear_clicked()
{
    v.clear();
    ui->display->clear();
    f = true;
}


void MainWindow::on_assign_clicked()
{
    str = "";
    f = false;
    v.clear();
    ui->display->clear();
    int val = ui->val_get->value();
    v.assign(1, val);
    str += QString::number(val) + ' ';
    ui->display->setText(str);
}


void MainWindow::on_resize_clicked()
{
    int val = ui->val_get->value();
    v.resize(val);
}


void MainWindow::on_size_clicked()
{
    ui->display->clear();
    ui->display->setText(QString::number(v.Size()));
}


void MainWindow::on_capacity_clicked()
{
    ui->display->clear();
    ui->display->setText(QString::number(v.Capacity()));
}


void MainWindow::on_empty_clicked()
{
    ui->display->clear();
    if (v.empty())
        ui->display->setText("true");
    else
        ui->display->setText("false");
}

