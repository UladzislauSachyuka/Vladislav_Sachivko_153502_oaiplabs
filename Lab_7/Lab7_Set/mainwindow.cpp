#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    set = new MySet<QString>;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_insert_clicked()
{
    QString key_ = ui->key_edit->text();

    if (key_.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Заполните поля");
        return;
    }

    ui->key_edit->clear();

    for (int i = 0; i < set->size(); ++i)
    {
        if (ui->tableWidget->item(i, 0)->text() == key_)
        {
            QMessageBox::warning(this, "Ошибка", "Такой ключ уже есть");
            return;
        }
    }

    set->insert(key_);
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);

    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("Ключ"));

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    MySet<QString>::l_iterator it(set->l_begin());

    for (int i = 0; i < set->size(); ++i, ++it)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(it->pair.first));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(it->pair.second));
    }
}


void MainWindow::on_erase_clicked()
{
    if (set->empty())
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

    for (int i = 0; i < set->size(); ++i)
    {
        if (ui->tableWidget->item(i, 0)->text() == key_)
        {
            set->erase(key_);
            --set->sz;
            break;
        }
    }


    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);

    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("Ключ"));

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    MySet<QString>::l_iterator it(set->l_begin());

    for (int i = 0; i < set->size(); ++i, ++it)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(it->pair.first));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(it->pair.second));
    }
}


void MainWindow::on_size_clicked()
{
    int size_ = set->size();
    ui->textBrowser->setText(QString::number(size_));
}

