#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "book.h"
#include "reader.h"
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

    void readReadersFromFile();

    void rewriteBooksInFile();

    void rewriteReadersInFile();


    int borrowedBooksAmount;
    int booksAmount;
    int readersAmount;

private slots:
    void booksButton_clicked();

    void readersBooksButton_clicked();

    void readersButton_clicked();

    void debtorsButton_clicked();

    void addBookButton_clicked();

    void addReaderButton_clicked();

    void sortReadersButton_clicked();

    void sortBooksButton_clicked();

    void findBookEdit_textChanged(const QString &arg1);

    void findReaderEdit_textChanged(const QString &arg1);

    void changeBookButton_clicked();

    void changeReaderButton_clicked();

    void deleteBookButton_clicked();

    void deleteReaderButton_clicked();


    void on_fileButton_clicked();

private:
    Ui::Widget *ui;
    Book* bookList;
    Reader* readerList;
    bool f = false;
};

bool containsDigit(const QString& string);
#endif // WIDGET_H
