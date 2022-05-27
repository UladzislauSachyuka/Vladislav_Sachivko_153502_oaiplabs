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
}


void MainWindow::on_convert_clicked()
{
    QString val = ui->number->text();
    for (int i = 0; i < val.size(); ++i)
    {
        if (!val[i].isDigit())
        {
            QMessageBox::warning(this, "Ошибка", "Введите число");
            ui->number->clear();
            return;
        }
    }

    unsigned char num = ui->number->text().toInt();
    bit.arr[0] = num;


    ui->textBrowser->setText(QString::fromStdString(bit.to_string()));
}


void MainWindow::on_all_clicked()
{
    if (bit.all())
        ui->textBrowser->setText("true");
    else
        ui->textBrowser->setText("false");
}


void MainWindow::on_any_clicked()
{
    if (bit.any())
        ui->textBrowser->setText("true");
    else
        ui->textBrowser->setText("false");
}


void MainWindow::on_count_2_clicked()
{
    ui->textBrowser->setText(QString::number(bit.count()));
}


void MainWindow::on_flip_clicked()
{
    bit.flip();
    ui->textBrowser->setText(QString::fromStdString(bit.to_string()));
}


void MainWindow::on_none_clicked()
{
    if (bit.none())
        ui->textBrowser->setText("true");
    else
        ui->textBrowser->setText("false");
}


void MainWindow::on_size_clicked()
{
    ui->textBrowser->setText(QString::number(bit.size()));
}


void MainWindow::on_set_clicked()
{
    bit.set();
    ui->textBrowser->setText(QString::fromStdString(bit.to_string()));
}


void MainWindow::on_reset_clicked()
{
    bit.reset();
    ui->textBrowser->setText(QString::fromStdString(bit.to_string()));
}

