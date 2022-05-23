#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tree = new Tree();
    t = new DerivedTree();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tree;
    delete t;
}

void MainWindow::preorder(Tree::Node *head)
{
    int k = head->key;
    QString val = head->value;
    this->print(k, val);

    if (head->left)
        this->preorder(head->left);
    if (head->right)
        this->preorder(head->right);
}

void MainWindow::postorder(Tree::Node *head)
{
    if (head->left)
        this->postorder(head->left);
    if (head->right)
        this->postorder(head->right);

    int k = head->key;
    QString val = head->value;

    this->print(k, val);
}

void MainWindow::inorder(Tree::Node *head)
{
    if (head->left)
        this->inorder(head->left);

    int k = head->key;
    QString val = head->value;

    this->print(k, val);

    if (head->right)
        this->inorder(head->right);
}

void MainWindow::print(int k, QString val)
{
    static int m = 0;
    ui->tableWidget->insertRow(m);
    ui->tableWidget->setItem(m, 0, new QTableWidgetItem(QString::number(k)));
    ui->tableWidget->setItem(m, 1, new QTableWidgetItem(val));

    ++m;

    if (m >= MainWindow::k)
        m = 0;
}


void MainWindow::on_add_clicked()
{
    QString key_ = ui->key->text();
    QString value_ = ui->val->text();
    if (key_.isEmpty() || value_.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Заполните поля");
        return;
    }
    else if (contains_not_digits(key_))
    {
        QMessageBox::warning(this, "Ошибка", "Некорректный ключ");
        return;
    }

    ui->key->clear();
    ui->val->clear();

    for (int i = 0; i < k; ++i)
    {
        if (ui->tableWidget->item(i, 0)->text() == key_)
        {
            QMessageBox::warning(this, "Ошибка", "Такой ключ уже есть");
            return;
        }
    }

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("Ключ")
                                                             << ("Значение"));

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget->insertRow(k);
    ui->tableWidget->setItem(k, 0, new QTableWidgetItem(key_));
    ui->tableWidget->setItem(k, 1, new QTableWidgetItem(value_));

    ++k;
}


void MainWindow::on_add_to_the_tree_clicked()
{
    if (MainWindow::k == 0)
    {
        QMessageBox::warning(this, "Ошибка", "Добавьте записи в массив");
        return;
    }
    for (int i = 0; i < k; ++i)
    {
        QString key_ = ui->tableWidget->item(i, 0)->text();
        QString value_ = ui->tableWidget->item(i, 1)->text();

        if (tree->search(tree->root, key_.toInt()))
            continue;
        tree->root = tree->insert(tree->root, key_.toInt(), value_);
    }
}


void MainWindow::on_find_clicked()
{
    QString key_ = ui->find_by_key->text();
    if (tree->search(tree->root, key_.toInt()))
    {
        for (int i = 0; i < k; ++i)
        {
            if (ui->tableWidget->item(i, 0)->text() == key_)
                for(int j = 0; j < 2; j++) ui->tableWidget->item(i, j)->setBackground(QBrush(Qt::yellow));
        }
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Такого ключа нет");
    }
}


void MainWindow::on_del_clicked()
{
    QString key_ = ui->delete_by_key->text();
    ui->delete_by_key->clear();
    if (!tree->search(tree->root, key_.toInt()))
    {
        QMessageBox::warning(this, "Ошибка", "Такого ключа нет");
        ui->delete_by_key->clear();
        return;
    }
    tree->root = tree->remove(tree->root, key_.toInt());
    int* arr1 = new int[k - 1];
    QString* arr2 = new QString[k - 1];
    for (int i = 0, j = 0; i < k; ++i)
    {
        if (ui->tableWidget->item(i, 0)->text() != key_)
        {
            arr1[j] = ui->tableWidget->item(i, 0)->text().toInt();
            arr2[j] = ui->tableWidget->item(i, 1)->text();
            ++j;
        }
    }
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("Ключ")
                                                             << ("Значение"));

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int i = 0; i < k - 1; ++i)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(arr1[i])));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(arr2[i]));
    }

    --k;
}


void MainWindow::on_preorder_clicked()
{
    if (MainWindow::k == 0)
        return;
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("Ключ")
                                                             << ("Значение"));

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->preorder(tree->root);
}


void MainWindow::on_postorder_clicked()
{
    if (MainWindow::k == 0)
        return;
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("Ключ")
                                                             << ("Значение"));

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->postorder(tree->root);
}


void MainWindow::on_symmetrical_clicked()
{
    if (MainWindow::k == 0)
        return;
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("Ключ")
                                                             << ("Значение"));

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->inorder(tree->root);
}


void MainWindow::on_add_pair_to_the_tree_clicked()
{
    QString key_ = ui->key_1->text();
    QString val_ = ui->val_1->text();
    if (key_.isEmpty() || val_.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Заполните поля");
        return;
    }
    else if (contains_not_digits(key_))
    {
        QMessageBox::warning(this, "Ошибка", "Некорректный ключ");
        return;
    }
    ui->key_1->clear();
    ui->val_1->clear();
    if (tree->search(tree->root, key_.toInt()))
    {
        QMessageBox::warning(this, "Ошибка", "Такой ключ уже есть");
        return;
    }

    tree->root = tree->insert(tree->root, key_.toInt(), val_);

    ui->tableWidget->insertRow(k);
    ui->tableWidget->setItem(k, 0, new QTableWidgetItem(key_));
    ui->tableWidget->setItem(k, 1, new QTableWidgetItem(val_));

    ++k;
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
    if (MainWindow::k == 0)
    {
        QMessageBox::warning(this, "Ошибка", "Добавьте записи в массив");
        return;
    }
    for (int i = 0; i < k; ++i)
    {
        QString key_ = ui->tableWidget->item(i, 0)->text();
        QString value_ = ui->tableWidget->item(i, 1)->text();
        if (t->search(t->root, key_.toInt()))
            continue;
        t->root = t->insert(t->root, key_.toInt(), value_);
    }

    ui->textBrowser->clear();
    ui->textBrowser->setText(QString::number(t->nodes_with_one_branch(t->root)));
}

