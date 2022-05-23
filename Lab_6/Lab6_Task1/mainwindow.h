#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "tree.h"
#include "derivedtree.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void preorder(Tree::Node* head);

    void postorder(Tree::Node* head);

    void inorder(Tree::Node* head);

    void print(int k, QString val);

private slots:
    void on_add_clicked();

    void on_add_to_the_tree_clicked();

    void on_find_clicked();

    void on_del_clicked();

    void on_preorder_clicked();

    void on_postorder_clicked();

    void on_symmetrical_clicked();

    void on_add_pair_to_the_tree_clicked();

    void on_task_clicked();

private:
    Ui::MainWindow *ui;
    Tree* tree;
    DerivedTree* t;
    int k = 0;
};

bool contains_not_digits(const QString& str);

#endif // MAINWINDOW_H
