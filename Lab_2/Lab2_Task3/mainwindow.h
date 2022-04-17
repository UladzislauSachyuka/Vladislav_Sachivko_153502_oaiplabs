#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>
#include "spisok.h"
#include <QMessageBox>
#include <QDebug>
#include "count_value.h"
//#include "dialog.h"
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString expr();

private slots:

    void on_valueButton_clicked();

    bool check(QString input);

    void getPolish(QString& input);

    int do_firstly(QChar val);

    double count_polish(double a, double b, double c, double d, double e);

    double get_val(QChar input, double a, double b, double c, double d, double e);

    double get_res(QChar input, double a, double b);

    void on_add_expr_clicked();

private:
    Ui::MainWindow *ui;
    spisok polish;
    spisok punct;
    int k = 15;
};

#endif // MAINWINDOW_H
