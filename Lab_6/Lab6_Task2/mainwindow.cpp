#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hashtable = new HashTable();
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("Ключ")
                                                             << ("Значение"));

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int i = 0; i < k; ++i)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem());
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem());
    }

    table = new DerivedHashTable();
    ui->tableWidget_2->setColumnCount(2);
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList() << ("Ключ")
                                                             << ("Значение"));

    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int i = 0; i < k; ++i)
    {
        ui->tableWidget_2->insertRow(i);
        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem());
        ui->tableWidget_2->setItem(i, 1, new QTableWidgetItem());
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::rewrite_table()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("Ключ")
                                                             << ("Значение"));

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for (int i = 0; i < k; ++i)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->item(0, 0)->setText(hashtable->keys_(i));
        ui->tableWidget->item(0, 1)->setText(hashtable->values_(i));
    }
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
    hashtable->insert(key_.toInt(), val_.toInt());
    int ind = hashtable->calculate_hash(key_.toInt());
    //QString str1 = ui->tableWidget->item(ind, 0)->text();
    //QString str2 = ui->tableWidget->item(ind, 1)->text();

    //ui->tableWidget->item(ind, 0)->setText(str1 + key_ + " ");
    //ui->tableWidget->item(ind, 1)->setText(str2 + val_ + " ");
    ui->tableWidget->item(ind, 0)->setText(hashtable->keys_(key_.toInt()));
    ui->tableWidget->item(ind, 1)->setText(hashtable->values_(key_.toInt()));

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
    hashtable->remove(key_.toInt());
    int ind = hashtable->calculate_hash(key_.toInt());
    //QString str1 = ui->tableWidget->item(ind, 0)->text();
    //QString str2 = ui->tableWidget->item(ind, 1)->text();

    ui->tableWidget->item(ind, 0)->setText(hashtable->keys_(key_.toInt()));
    int m = hashtable->value(key_.toInt());
    if (m == 0)
        ui->tableWidget->item(ind, 1)->setText("");
    else
        ui->tableWidget->item(ind, 1)->setText(QString::number(hashtable->value(key_.toInt())));

    ui->key_delete->clear();
}


void MainWindow::on_find_clicked()
{
    QString key_ = ui->key_find->text();
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
    QString val_ = QString::number(table->value(key_.toInt()));
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("Ключ")
                                                             << ("Значение"));

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(key_));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(val_));
}

bool contains_not_digits(const QString &str)
{
    for(int i = 0; i < str.size(); i++){
        if(!str[i].isDigit()) return true;
    }
    return false;
}


void MainWindow::on_task_clicked()
{
    int max = -100, index = 0;
    for (int i = 0; i < k; ++i)
    {
        int key_ = rand() % 100;
        if (key_ > max)
        {
            max = key_;
            index = table->calculate_hash(key_);
        }
        int val_ = rand() % 50;
        table->insert(key_, val_);
        int ind = table->calculate_hash(key_);
        ui->tableWidget_2->item(ind, 0)->setText(table->keys_(key_));
        ui->tableWidget_2->item(ind, 1)->setText(table->values_(key_));
    }
    ui->line_task->setText(QString::number(index + 1));
}

