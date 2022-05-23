#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    deque = new MyDeque<int>;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_push_back_clicked()
{
    int val = rand() % 100;
    deque->push_back(val);
    str += QString::number(val) + " ";
    ui->display->setText(str);
}


void MainWindow::on_push_front_clicked()
{
    int val = rand() % 100;
    deque->push_front(val);
    str = QString::number(val) + " " + str;
    ui->display->setText(str);
}


void MainWindow::on_pop_back_clicked()
{
    if (deque->empty())
    {
        QMessageBox::warning(this, "Ошибка", "Дек пуст");
        return;
    }
    int val = deque->back();
    deque->pop_back();
    int i = 0;
    while (val != 0)
    {
        val /= 10;
        ++i;
    }
    str = str.left(str.size() - i - 1);
    ui->display->setText(str);
}


void MainWindow::on_pop_front_clicked()
{
    if (deque->empty())
    {
        QMessageBox::warning(this, "Ошибка", "Дек пуст");
        return;
    }
    int val = deque->front();
    deque->pop_front();
    int i = 0;
    while (val != 0)
    {
        val /= 10;
        ++i;
    }
    str = str.right(str.size() - i - 1);
    ui->display->setText(str);
}


void MainWindow::on_size_clicked()
{
    ui->display->clear();
    ui->display->setText(QString::number(deque->size()));
}


void MainWindow::on_clear_clicked()
{
    if (deque->empty())
        return;
    deque->clear();
    str = "";
    ui->display->clear();
}


void MainWindow::on_empty_clicked()
{
    ui->display->clear();
    if (deque->empty())
        ui->display->setText("true");
    else
        ui->display->setText("false");
}

