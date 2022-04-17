#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "doublelist.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void clearTable();

    void readBooksFromFile();

    void rewriteBooksInFile();

    void sort(Node* left, Node* right);

    //void Books();

    int booksAmount;

private slots:



    void addBookButton_clicked();

    void sortBooksButton_clicked();

    void changeBookButton_clicked();

    void deleteBookButton_clicked();

    void booksButton_clicked();

    void findBookEdit_textChanged(const QString &arg1);

    void on_openFileButton_clicked();

private:
    Ui::Widget *ui;
    DoubleList* List = nullptr;
    //bool f = false;
};

bool containsDigit(const QString& string);
bool check(QString line);
#endif // WIDGET_H
