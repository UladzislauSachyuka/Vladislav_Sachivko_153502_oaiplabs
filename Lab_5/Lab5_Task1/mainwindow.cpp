#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    queue = new MyQueue<int>;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete queue;
}


void MainWindow::on_push_clicked()
{
    int val = ui->get_val->text().toInt();
    queue->push(val);
    str += QString::number(val) + " ";
    ui->display->setText(str);
}


void MainWindow::on_pop_clicked()
{
    if (queue->empty()) {
        QMessageBox::warning(this, "Ошибка", "Очередь пустая");
        return;
    }
    int val = queue->front();
    if (val == 0) {
        str = str.right(str.size() - 2);
        queue->pop();
        ui->display->setText(str);
        return;
    }
    int i = 0;
    while (val != 0)
    {
        ++i;
        val /= 10;
    }
    queue->pop();
    str = str.right(str.size() - i - 1);
    ui->display->setText(str);
}


void MainWindow::on_empty_clicked()
{
    ui->display->clear();
    if (queue->empty())
        ui->display->setText("true");
    else
        ui->display->setText("false");
}


void MainWindow::on_size_clicked()
{
    ui->display->clear();
    ui->display->setText(QString::number(queue->size()));
}


void MainWindow::on_Task_clicked()
{
    Dialog get;
    if (get.exec() == QDialog::Accepted) {

    }
}

