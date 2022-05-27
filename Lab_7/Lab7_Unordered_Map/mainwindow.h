#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "Myunordered_map.h"

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
    void on_add_clicked();

    void on_delete_key_clicked();

    void on_find_clicked();

    void on_contains_clicked();

private:
    Ui::MainWindow *ui;
    Myunordered_map<int, int> *map;
};

bool contains_not_digits(const QString &str);

#endif // MAINWINDOW_H
