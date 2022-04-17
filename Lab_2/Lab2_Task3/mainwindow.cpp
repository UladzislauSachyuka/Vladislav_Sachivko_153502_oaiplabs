#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_valueButton_clicked()
{
    int i = 0;
    QMessageBox messageBox;
    k = ui->table->rowCount();
    while (i != k){
        polish.delSpisok();
        QString input;
        QTableWidgetItem *item = ui->table->item(i, 0);
        if (item != nullptr) input = item->text();
        if (!check(input)){
            //qDebug() << 1;
            messageBox.warning(0,"failure","failure in position: " + QString::number(i + 1));
            messageBox.setFixedSize(500,200);
        }
        else {
            //qDebug() << 2;
            getPolish(input);
            ui->table->setItem(i, 1, new QTableWidgetItem(polish.get_all()));
            double a, b, c, d, e;
            item = ui->table->item(i, 2);
            if (item != nullptr) input = item->text();
            a = input.toDouble();
            item = ui->table->item(i, 3);
            if (item != nullptr) input = item->text();
            b = input.toDouble();
            item = ui->table->item(i, 4);
            if (item != nullptr) input = item->text();
            c = input.toDouble();
            item = ui->table->item(i, 5);
            if (item != nullptr) input = item->text();
            d = input.toDouble();
            item = ui->table->item(i, 6);
            if (item != nullptr) input = item->text();
            e = input.toDouble();
            ui->table->setItem(i, 7, new QTableWidgetItem(QString::number(count_polish(a, b, c, d, e))));
        }


        ++i;
    }
}

bool MainWindow::check(QString input){
    int count = 0;
    if (input.size() > 255) return false;
    for (int i = 0; i < input.size(); ++i) {
        if (i + 1 != input.size() && input[i].isLetter() && input[i + 1].isLetter()){
            return false;
        }
        if (i + 1 != input.size() && input[i].isPunct() && input[i + 1].isPunct() && (input[i + 1] == ')' && input[i + 1] != ')')){
            return false;
        }
        if (input[i] == '(') ++count;
        if (input[i] == ')') --count;
        if (input[i].isLetter() && !(input[i] >= 'a' && input[i] <= 'e')) return false;
        if (count < 0) return false;
    }
    if (count != 0) return false;
    return true;
}

void MainWindow::getPolish(QString& input)
{
    int i = 0;
    while (i < input.size()){
        if (input[i].isLetter()) polish.push_back(input[i], false);
        else if ((input[i].isPunct() || input[i] == '+') && input[i] != ')'){
            if (punct.getLength() == 0 || punct.getValue(punct.getLength() - 1) == '(' || input[i] == '(' || do_firstly(input[i]) > do_firstly(punct.getValue(punct.getLength() - 1))) {}
            else if (do_firstly(input[i]) <= do_firstly(punct.getValue(punct.getLength() - 1))) {
                while (punct.getLength() != 0 && do_firstly(input[i]) <= do_firstly(punct.getValue(punct.getLength() - 1)) &&
                       punct.getValue(punct.getLength() - 1) != '('){
                    polish.push_back(punct.getValue(punct.getLength() - 1), true);
                    punct.pop();
                }
            }
            punct.push_back(input[i], true);

        }
        else if (input[i] == ')'){
            while (punct.getValue(punct.getLength() - 1) != '('){
                polish.push_back(punct.getValue(punct.getLength() - 1), true);
                punct.pop();
            }
            punct.pop();
        }
        ++i;
    }
    while (punct.getLength() != 0){
        polish.push_back(punct.getValue(punct.getLength() - 1), true);
        punct.pop();
    }
}

int MainWindow::do_firstly(QChar val)
{
   if (val == '+' || val == '-') return 1;
   else return 2;
}

double MainWindow::count_polish(double a, double b, double c, double d, double e)
{
    QString input = polish.get_all();
    count_val total;
    for (int i = 0; i < input.size(); ++i){
        if (input[i].isLetter()) total.push_back(get_val(input[i], a, b, c, d, e));
        else {
            double a_n, b_n;
            a_n = total.getValue(total.getLength() - 1);
            total.pop();
            b_n = total.getValue(total.getLength() - 1);
            total.pop();
            double res = get_res(input[i], b_n, a_n);
            total.push_back(res);
        }
    }
    return total.getValue(0);
}

double MainWindow::get_val(QChar input, double a, double b, double c, double d, double e)
{
    if (input == 'a') return a;
    else if (input == 'b') return b;
    else if (input == 'c') return c;
    else if (input == 'd') return d;
    else return e;
}

double MainWindow::get_res(QChar input, double a, double b)
{
    if (input == '+') return a + b;
    else if (input == '-') return a - b;
    else if (input == '*') return a * b;
    else return a / b;
}

void MainWindow::on_add_expr_clicked()
{
    if (k == 255) {
        QMessageBox messageBox;
        messageBox.warning(0,"failure","you've reached the limit");
        messageBox.setFixedSize(500,200);
        return;
    }

    ui->table->setRowCount(k + 1);

    ui->table->setItem(k, 0,new QTableWidgetItem(ui->expr_get->text()));
    double a = ui->a_get->value();
    double b = ui->b_get->value();
    double c = ui->c_get->value();
    double d = ui->d_get->value();
    double e = ui->e_get->value();
    ui->table->setItem(k, 2,new QTableWidgetItem(QString::number(a)));
    ui->table->setItem(k, 3,new QTableWidgetItem(QString::number(b)));
    ui->table->setItem(k, 4,new QTableWidgetItem(QString::number(c)));
    ui->table->setItem(k, 5,new QTableWidgetItem(QString::number(d)));
    ui->table->setItem(k, 6,new QTableWidgetItem(QString::number(e)));
}

QString MainWindow::expr()
{
    return ui->expr_get->text();
}


