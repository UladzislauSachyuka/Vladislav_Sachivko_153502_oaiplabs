#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "MyBitSet.h"

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
    void on_convert_clicked();

    void on_all_clicked();

    void on_any_clicked();

    void on_count_2_clicked();

    void on_flip_clicked();

    void on_none_clicked();

    void on_size_clicked();

    void on_set_clicked();

    void on_reset_clicked();

private:
    Ui::MainWindow *ui;
    BitSet<8> bit;
};
#endif // MAINWINDOW_H
