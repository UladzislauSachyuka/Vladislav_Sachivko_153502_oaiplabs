#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "doublelist.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

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

    void readConversationsFromFile();

    void rewriteConversationsInFile();

    //void sort(Node* left, Node* right);

    //void Books();

    int conversationsAmount;

private slots:
    void addConversationButton_clicked();

    void changeConversationButton_clicked();

    void deleteConversationButton_clicked();

    //void sortConversationsButton_clicked();

    void ConversationsButton_clicked();

    void on_openFileButton_clicked();

    void findConversationEdit_textChanged(const QString &arg1);

    void findConversationEdit_2_textChanged(const QString &arg1);

private:
    Ui::Widget *ui;
    DoubleList* List = nullptr;
};

bool containsDigit(const QString& string);
bool check(QString line);
#endif // WIDGET_H
