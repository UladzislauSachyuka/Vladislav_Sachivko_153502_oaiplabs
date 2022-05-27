#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    map = new Myunordered_map<int, int>(50);

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("Ключ")
                                                             << ("Значение"));

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int i = 0; i < map->max_size(); ++i)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem());
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_add_clicked()
{
    QString key_ = ui->key_add->text();
    QString val_ = ui->val->text();
    if (key_.isEmpty() || val_.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Заполните поля");
        return;
    }
    else if (contains_not_digits(key_) || contains_not_digits(val_))
    {
        QMessageBox::warning(this, "Ошибка", "Некорректное значение");
        ui->key_add->clear();
        ui->val->clear();
        return;
    }
    map->insert(key_.toInt(), val_.toInt());
    int ind = map->get_hash(key_.toInt());

    ui->tableWidget->item(ind, 0)->setText(map->keys(key_.toInt()));
    ui->tableWidget->item(ind, 1)->setText(map->values(key_.toInt()));

    ui->key_add->clear();
    ui->val->clear();
}


void MainWindow::on_delete_key_clicked()
{
    QString key_ = ui->key_delete->text();
    if (key_.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Заполните поля");
        return;
    }
    else if (contains_not_digits(key_))
    {
        QMessageBox::warning(this, "Ошибка", "Некорректное значение");
        ui->key_delete->clear();
        return;
    }
    map->erase(key_.toInt());
    int ind = map->get_hash(key_.toInt());

    ui->tableWidget->item(ind, 0)->setText(map->keys(key_.toInt()));
    ui->tableWidget->item(ind, 1)->setText(map->values(key_.toInt()));

    ui->key_delete->clear();
}


void MainWindow::on_find_clicked()
{
    QString key_ = ui->key_find->text();
    if (!map->contains(key_.toInt()))
    {
        QMessageBox::warning(this, "Ошибка", "Такого ключа нет");
        ui->key_find->clear();
        return;
    }
    ui->text_find->setText(QString::number(map->find(key_.toInt())));
}


void MainWindow::on_contains_clicked()
{
    QString key_ = ui->line_contains->text();
    if (map->contains(key_.toInt()))
        ui->contains_text->setText("true");
    else
        ui->contains_text->setText("false");
}

bool contains_not_digits(const QString &str)
{
    for(int i = 0; i < str.size(); i++){
        if(!str[i].isDigit()) return true;
    }
    return false;
}
