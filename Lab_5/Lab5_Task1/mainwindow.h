#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "myqueue.h"
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_push_clicked();

    void on_pop_clicked();

    void on_empty_clicked();

    void on_size_clicked();

    void on_Task_clicked();

private:
    Ui::MainWindow *ui;
    MyQueue<int>* queue;
    QString str;
};
#endif // MAINWINDOW_H
