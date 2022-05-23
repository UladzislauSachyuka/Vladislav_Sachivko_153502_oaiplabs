    #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "hashtable.h"
#include "derivedhashtable.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void rewrite_table();

private slots:
    void on_add_clicked();

    void on_delete_key_clicked();

    void on_find_clicked();

    void on_task_clicked();

private:
    Ui::MainWindow *ui;
    HashTable* hashtable;
    DerivedHashTable* table;
    static const int k = 100;
};

bool contains_not_digits(const QString& str);

#endif // MAINWINDOW_H
