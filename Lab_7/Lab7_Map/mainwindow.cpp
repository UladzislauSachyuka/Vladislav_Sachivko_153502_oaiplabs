#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    map = new MyMap<QString, QString>;
}

MainWindow::~MainWindow()
{
    delete map;
    delete ui;
}


void MainWindow::on_insert_clicked()
{
    QString key_ = ui->key_edit->text();
    QString value_ = ui->val_edit->text();

    if (key_.isEmpty() || value_.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Заполните поля");
        return;
    }

    ui->key_edit->clear();
    ui->val_edit->clear();

    for (int i = 0; i < k; ++i)
    {
        if (ui->tableWidget->item(i, 0)->text() == key_)
        {
            QMessageBox::warning(this, "Ошибка", "Такой ключ уже есть");
            return;
        }
    }

    map->insert(key_, value_);
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("Ключ")
                                                             << ("Значение"));

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    MyMap<QString, QString>::l_iterator it(map->l_begin());

    for (int i = 0; i < map->size(); ++i, ++it)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(it->pair.first));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(it->pair.second));
    }

    ++k;
}


void MainWindow::on_erase_clicked()
{
    if (map->empty())
    {
        QMessageBox::warning(this, "Ошибка", "Контейнер пуст");
        return;
    }
    QString key_ = ui->erase_by_key->text();
    if (key_.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Заполните поле");
        return;
    }
    ui->erase_by_key->clear();

    map->erase(key_);
    --map->sz;

    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("Ключ")
                                                             << ("Значение"));

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    MyMap<QString, QString>::l_iterator it(map->l_begin());

    for (int i = 0; i < map->size(); ++i, ++it)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(it->pair.first));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(it->pair.second));
    }

    --k;
}


void MainWindow::on_size_clicked()
{
    int size_ = map->size();
    ui->textBrowser->setText(QString::number(size_));
}

