#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "unique_ptr.h"
#include "shared_ptr.h"
#include "weak_ptr.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Unique_ptr<int> p1(new int(3));
    QString s1="создаём объект p1 (ptr:{3})\n";
    Unique_ptr<int> p2(new int(10));
    s1+="создаём объект p2 (ptr:{10})\n";

    p2.swap(p1);
    s1+="метод p2.Swap(p1):  p1(ptr:{10}), p2(ptr:{3})\n";
    s1+="Проверим метод Swap:\n";

    if(*p1 == 10 && *p2 == 3){
        s1+="Тест прошёл успешно\n";
    }else{
        s1+="Тест провален\n";
    }

    int* b1 = p2.get();
    int a = *p2;
    int b2 = *b1;

    s1+="Проверим метод Get и оператор * : \n";
    if(b2==a){
        s1+="Тест прошёл успешно\n";
    }else{
        s1+="Тест провален\n";
    }


    s1+="Проверим оператор bool:\n";
    if(p2){
        s1+="Тест прошёл успешно\n";
    }else{
        s1+="Тест провален\n";
    }

    p2.release();
    s1+="Проверим метод Release:\n";
    if(p2.get()==nullptr && (*b1)==3){
        s1+="Тест прошёл успешно\n";
    }else{
        s1+="Тест провален\n";
    }

    ui->textBrowser->setText(s1);
    update();

}


void MainWindow::on_pushButton_2_clicked()
{
    QString s2="";
    Shared_ptr<int> p1 = Shared_ptr<int>(new int(4));
    s2+="создаём объект p1 через new ptr:({4},количество: 1)\n";
    Shared_ptr<int> p2(p1);
    s2+="создаём объект p2 через конструктор p2(p1) ptr:({4},количество: 2)\n";
    Shared_ptr<int> p3 = Shared_ptr<int>(new int(11));
    s2+="создаём объект p3 через new ptr:({11},количество: 1)\n";
    Shared_ptr<int> p4 = Shared_ptr<int>();
    s2+="создаём пустой объект p4 (nullptr ,количество: 0)\n";
    p4 = p1;
    s2+="Оператор = (p4=p1):  p4({4} ,количество: 3)\n";

    s2+="Проверим метод Use_count:\n";
    s2+="1): {p3 = 1} ";
    if(p3.use_count()==1){
        s2+="Тест прошёл успешно\n";
    }else{
        s2+="Тест провален\n";
    }
    s2+="2): {p4 = 3}";
    if(p4.use_count()==3){
        s2+="Тест прошёл успешно\n";
    }else{
        s2+="Тест провален\n";
    }

    s2+="Проверим метод Get и оператор * :\n";
    int a1 = *p4;
    int* temp1 = p4.get();
    int a2 = *temp1;
    s2+="1): {a1 = a2}";
    if(a1==a2){
        s2+="Тест прошёл успешно\n";
    }else{
        s2+="Тест провален\n";
    }

    int a3 = *p3;
    int* temp2 = p3.get();
    int a4 = *temp2;
    s2+="1): {a3 = a4}";
    if(a3==a4){
        s2+="Тест прошёл успешно\n";
    }else{
        s2+="Тест провален\n";
    }


    s2+="Проверим метод Swap:\n";
    p1.swap(p3);
    s2+="1): ";
    if(p1.use_count() == 1 && *p1 == 11){
        s2+="Тест прошёл успешно\n";
    }else{
        s2+="Тест провален\n";
    }
    s2+="2): ";
    if(p3.use_count() == 3 && *p3 == 4){
        s2+="Тест прошёл успешно\n";
    }else{
        s2+="Тест провален\n";
    }

    s2+="Проверим метод Unique: \n";
    s2+="1): ";
    if(p1.unique() == false){
        s2+="Тест прошёл успешно\n";
    }else{
        s2+="Тест провален\n";
    }
    s2+="2): ";
    if(p3.unique() == false){
        s2+="Тест прошёл успешно\n";
    }else{
        s2+="Тест провален\n";
    }

    s2+="Проверим оператор bool:\n";
    s2+="1): ";
    if(p3){
        s2+="Тест прошёл успешно\n";
    }else{
        s2+="Тест провален\n";
    }

    ui->textBrowser_2->setText(s2);
    update();
}


void MainWindow::on_pushButton_3_clicked()
{
    QString s3="";
    Shared_ptr<int> h1 = Shared_ptr<int>(new int(15));
    s3+="создаём объект MyShared_ptr h1,(ptr:{15},shared:1, weak:0)\n";
    Weak_ptr<int> p1(h1);
    s3+="создаём объект MyWeak_ptr p1, конструктор p1(h1),(ptr:{15},shared:1, weak:1)\n";
    Weak_ptr<int> p2(p1);
    s3+="создаём объект MyWeak_ptr p2, конструктор p2(p1),(ptr:{15},shared:1, weak:2)\n";
    Weak_ptr<int> p3;
    s3+="создаём объект MyWeak_ptr p3, пустой конструктор,(ptr:nullptr, shared:0, weak:0)\n";
    p3 = h1;
    s3+="оператор = (p3 = h1), (ptr:{15},shared:1, weak:3)\n";
    Shared_ptr<int> h2 = Shared_ptr<int>(new int(13));
    s3+="создаём объект MyShared_ptr h2,(ptr:{13},shared:1, weak:0)\n";


    s3+="Проверим метод Lock:\n";
    s3+="1): {p1} ";
    if(p1.lock().operator bool()){
        s3+="Тест прошёл успешно\n";
    }else{
        s3+="Тест провален\n";
    }

    s3+="2): ";
    if(p2.lock().unique() == false){
        s3+="Тест прошёл успешно\n";
    }else{
        s3+="Тест провален\n";
    }

     Weak_ptr<int> p4(h2);

    s3+="Проверим метод Use_count:\n";
    s3+="1): ";
    if(p1.use_count() == 1){
        s3+="Тест прошёл успешно\n";
    }else{
        s3+="Тест провален\n";
    }
    s3+="2): ";
    if(p4.use_count() == 1){
        s3+="Тест прошёл успешно\n";
    }else{
        s3+="!Тест провален\n";
    }

    s3+="Проверим метод Swap:\n";
    s3+="1): ";
    p1.swap(p4);
    if(p4.use_count() == 1){
        s3+="Тест прошёл успешно\n";
    }else{
        s3+="Тест провален\n";
    }
    s3+="2): ";
    if(p1.use_count() == 1){
        s3+="Тест прошёл успешно\n";
    }else{
        s3+="Тест провален\n";
    }

    ui->textBrowser_3->setText(s3);
    update();

}
