#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    checking = new spisok();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete checking;
}


void MainWindow::on_add_button_clicked()
{
    ui->display->clear();

    QString filename = QFileDialog::getOpenFileName(this,
            tr("Open txt"), "//", tr("txt files (*.txt)"));
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    QTextStream in(&file);
    QString input = in.readAll();
    ui->display->setText(input);
}


void MainWindow::on_check_button_clicked()
{
    checking->delSpisok();
    QString input = ui->display->toPlainText();
    QMessageBox messageBox;
    int k = checking->check(input);
    QString pos = getLineNum(k, input);
    if (k != -1) {
        messageBox.warning(0,"failure","failure in position: " + pos);
        messageBox.setFixedSize(500,200);
    }
    else {
        messageBox.information(0,"success","success");
        messageBox.setFixedSize(500,200);
    }

}

QString MainWindow::getLineNum(int i, QString lin)
{
    int number_line = 1;
    int number_index = 0;
    QChar a = '\n';
    for (int k = 0; k <= i; ++k){
        if(lin[k] == a){
            ++number_line;
            number_index = 0;
        }
        else ++number_index;
    }
    QString res;
    res += "line " + QString::number(number_line) + " element " + QString::number(number_index);
    return res;
}

