#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MyString.h"
#include <QDebug>
MyString str1;
MyString str2;

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


void MainWindow::on_strlen_clicked()
{
    ui->display->clear();
    str1 = ui->string1->text();
    str2 = ui->string2->text();
    int val1 = str1.length();
    int val2 = str2.length();
    ui->display->setText(QString::number(val1) + " " + QString::number(val2));
}


void MainWindow::on_strcpy_clicked()
{
    if (ui->string1->text() == "" || ui->string2->text() == "") {
        QMessageBox::warning(this, "Ошибка", "Введите строки");
    }
    ui->display->clear();
    str1 = ui->string1->text();
    str2 = ui->string2->text();
    str1 = str2;
    ui->display->setText(str1.str);
    str1 = ui->string1->text();
}


void MainWindow::on_strcmp_clicked()
{
    if (ui->string1->text() == "" || ui->string2->text() == "") {
        QMessageBox::warning(this, "Ошибка", "Введите строки");
    }
    ui->display->clear();
    str1 = ui->string1->text();
    str2 = ui->string2->text();
    ui->display->setText(QString::number(Strcmp(str1.str, str2.str)));
}


void MainWindow::on_strtok_clicked()
{
    if (ui->string1->text() == "" || ui->string2->text() == "") {
        QMessageBox::warning(this, "Ошибка", "Введите строки");
    }
    ui->display->clear();
    str1 = ui->string1->text();
    str2 = ui->string2->text();
    QString str;
    char* pch;
    pch = Strtok(str1.str, str2.str);
    while (pch != NULL)
    {
        str += pch;
        str += "\n";
        pch = Strtok(NULL, str2.str);
    }
    ui->display->setText(str);
}


void MainWindow::on_memcmp_clicked()
{
    if (ui->string1->text() == "" || ui->string2->text() == "") {
        QMessageBox::warning(this, "Ошибка", "Введите строки");
    }
    ui->display->clear();
    str1 = ui->string1->text();
    str2 = ui->string2->text();
    ui->display->setText(QString::number(Memcmp(str1.str, str2.str, str1.size())));
}


void MainWindow::on_clear_clicked()
{
    ui->display->clear();
    ui->string1->clear();
    ui->string2->clear();
}


void MainWindow::on_strcat_clicked()
{
    if (ui->string1->text() == "" || ui->string2->text() == "") {
        QMessageBox::warning(this, "Ошибка", "Введите строки");
    }
    ui->display->clear();
    str1 = ui->string1->text();
    str2 = ui->string2->text();
    str1 += str2;
    ui->display->setText(str1.str);
    str1 = ui->string1->text();
}

