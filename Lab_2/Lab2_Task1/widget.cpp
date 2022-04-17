#include "widget.h"
#include "ui_widget.h"
#include <QStringList>
#include <QMessageBox>
#include <QKeyEvent>
#include <QTime>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->booksButton, SIGNAL(clicked()), this, SLOT(booksButton_clicked()));
    connect(ui->addBookButton, SIGNAL(clicked()), this, SLOT(addBookButton_clicked()));
    connect(ui->sortBooksButton, SIGNAL(clicked()), this, SLOT(sortBooksButton_clicked()));
    connect(ui->findBookEdit, SIGNAL(textChanged(const QString&)), this, SLOT(findBookEdit_textChanged(const QString&)));
    connect(ui->changeBookButton, SIGNAL(clicked()), this, SLOT(changeBookButton_clicked()));
    connect(ui->deleteBookButton, SIGNAL(clicked()), this, SLOT(deleteBookButton_clicked()));
    connect(ui->sortBooksButton, SIGNAL(clicked()), this, SLOT(sortBooksButton_clicked()));


    ui->bookCodeEdit->setMaxLength(12);
    ui->authorSurnameEdit->setMaxLength(20);
    ui->titleEdit->setMaxLength(25);
    ui->yearEdit->setMaxLength(8);
    ui->publisherEdit->setMaxLength(12);

    this->readBooksFromFile();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::readBooksFromFile()
{
    QFile file("C:\\Qt\\Labs\\Lab2_Task1\\bookList.txt");

    if(file.open(QIODevice::ReadWrite)){
        QTextStream stream(&file);


        QString line;
        int count = 0;
        while(!stream.atEnd()){
            line = stream.readLine();
            if(line != "") count++;
        }

        booksAmount = count;

        stream.seek(0);
        int _code;
        QString _authorSurname;
        QString _title;
        int _year;
        QString _publisher;
        int _pages;

        List = new DoubleList();

        QStringList list;

        for(int i = 0; i < booksAmount; i++){
            list = stream.readLine().split('|');
            _code = list[0].toInt();
            _authorSurname = list[1];
            _title = list[2];
            _year = list[3].toInt();
            _publisher = list[4];
            _pages = list[5].toInt();

            ui->bookComboBox->addItem(_title);

            List->push_back(new Node(_code, _authorSurname, _title, _year, _publisher, _pages));
        }
        file.close();

    }
}

void Widget::clearTable()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);
}

/*void Widget::Books()
{
    this->clearTable();
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("Код книги")
                                                             << ("Фамилия автора")
                                                             << ("Название")
                                                             <<  ("Год выпуска")
                                                             <<  ("Издательство")
                                                             <<  ("Кол-во страниц"));
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    iterator it = List->begin();

    for(int i = 0; i < booksAmount; i++, ++it){
        ui->tableWidget->insertRow(i);
        //ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(bookList[i].getBookCode()))); //add dates to table
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(it.operator*().number)));
        //ui->tableWidget->setItem(i, 1, new QTableWidgetItem(bookList[i].getAuthorSurname()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(it.operator*().authorSurname));
        //ui->tableWidget->setItem(i, 2, new QTableWidgetItem(bookList[i].getTitle()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(it.operator*().title));
        //ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(bookList[i].getYear())));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(it.operator*().year)));
        //ui->tableWidget->setItem(i, 4, new QTableWidgetItem(bookList[i].getLanguage()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(it.operator*().publisher));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(it.operator*().pages)));
    }

}*/

void Widget::addBookButton_clicked()
{
    QString code = ui->bookCodeEdit->text();
    QString surname = ui->authorSurnameEdit->text();
    QString title = ui->titleEdit->text();
    QString year = ui->yearEdit->text();
    QString publisher = ui->publisherEdit->text();
    QString pages = ui->pagesEdit->text();

    bool isExist = false;
    iterator it = List->begin();

    for(int i = 0; i < booksAmount; i++){
        if(it.operator*().title == title) isExist = true;
        ++it;
    }
    if(isExist){
        QMessageBox::warning(this, "Ошибка", "Книга с таким названием уже существует.");
    }
    else if(code.toInt() != 0 && year.toInt() != 0 && !surname.contains(' ') && !containsDigit(surname) && !containsDigit(title)
            && !containsDigit(publisher) && !publisher.contains(' ') && year.size() < 5){

        List->push_back(new Node(code.toInt(), surname, title, year.toInt(), publisher, pages.toInt()));

        booksAmount += 1;

        QFile file("C:\\Qt\\Labs\\Lab2_Task1\\bookList.txt");
        if(file.open(QIODevice::ReadWrite | QIODevice::Append)){
            QTextStream stream(&file);

            stream << code + "|";
            stream << surname + "|";
            stream << title + "|";
            stream << year + "|";
            stream << publisher + "|";
            stream << pages + "\n";

            file.close();
            ui->bookCodeEdit->clear();
            ui->authorSurnameEdit->clear();
            ui->titleEdit->clear();
            ui->yearEdit->clear();
            ui->publisherEdit->clear();
            ui->pagesEdit->clear();
        }

        this->booksButton_clicked();

        ui->bookComboBox->addItem(title);
    } else {
        QMessageBox::warning(this, "Ошибка", "Некорректный ввод!");
    }
}

void Widget::rewriteBooksInFile()
{
    QFile file("C:\\Qt\\Labs\\Lab2_Task1\\bookList.txt");
    if(file.open(QIODevice::WriteOnly)){
        QTextStream stream(&file);
        iterator it = List->begin();
        if (it == nullptr)
            stream << "";
        else {
            for(int i = 0; i < List->getCount(); i++, ++it){
                stream << it.operator*().number << "|" << it.operator*().authorSurname
                   << "|" << it.operator*().title << "|"
                   << it.operator*().year << "|" << it.operator*().publisher << "|" << it.operator*().pages << "\n";
            }
        file.close();
        }
    }
    else {
        qDebug() << "File not open\n";
    }

}

void Widget::sort(Node *left, Node *right)
{
    Node* start;
    Node* current;
    Node temp;
    int copyinteger;

    if (left==right) return;

    start = left;
    current = start->next;

    while(1)
        {
            if (start->year < current->year)
            {
                copyinteger = current->year;
                temp.year = current->year;
                temp.authorSurname = current->authorSurname;
                //temp.next = current->next;
                temp.number = current->number;
                temp.pages = current->pages;
                //temp.prev = current->prev;
                temp.publisher = current->publisher;
                temp.title = current->title;
                current->year = start->year;
                current->authorSurname = start->authorSurname;
                //current->next = start->next;
                current->number = start->number;
                current->pages = start->pages;
                //current->prev = start->prev;
                current->publisher = start->publisher;
                current->title = start->title;
                start->year = copyinteger;
                start->authorSurname = temp.authorSurname;
                //start->next = temp.next;
                start->number = temp.number;
                start->pages = temp.pages;
                //start->prev = temp.prev;
                start->publisher = temp.publisher;
                start->title = temp.title;
            }
            if (current == right) break;
            current = current->next;
        }
        copyinteger = left->year;
        temp.authorSurname = left->authorSurname;
        //temp.next = left->next;
        temp.number = left->number;
        temp.pages = left->pages;
        //temp.prev = left->prev;
        temp.publisher = left->publisher;
        temp.title = left->title;
        //temp.year = left->year;


        left->year = current->year;
        left->authorSurname = current->authorSurname;
        //left->next = current->next;
        left->number = current->number;
        left->pages = current->pages;
        left->publisher = current->publisher;
        left->title = current->title;

        current->year = copyinteger;
        current->authorSurname = temp.authorSurname;
        current->number = temp.number;
        current->pages = temp.pages;
        current->publisher = temp.publisher;
        current->title = temp.title;


        Node* oldcurrent = current;
        current = current->prev;
        if (current != NULL)
        {
           if ((left->prev != current) && (current->next != left))
           this->sort(left,current);
        }
        current = oldcurrent;
        current = current->next;
        if (current != NULL)
        {
           if ((current->prev != right) && (right->next != current))
           this->sort(current,right);
        }

        this->booksButton_clicked();
        this->rewriteBooksInFile();
}

void Widget::sortBooksButton_clicked()
{
    Node* left = List->begin().getNode();
    Node* right = List->end().getNode();
    this->sort(left, right);
}


void Widget::changeBookButton_clicked()
{
    QString _title = ui->bookComboBox->currentText();

    QString code = ui->bookCodeEdit->text();
    QString surname = ui->authorSurnameEdit->text();
    QString title = ui->titleEdit->text();
    QString year = ui->yearEdit->text();
    QString publisher = ui->publisherEdit->text();
    QString pages = ui->pagesEdit->text();

    if(code.toInt() != 0 && year.toInt() != 0 && !containsDigit(surname) && !containsDigit(title)
            && !containsDigit(publisher) && year.size() < 5){
        iterator it = List->begin();
        for(int i = 0; i < booksAmount; i++, ++it){
            if(it.operator*().title == _title){
                it.operator*().number = code.toInt();
                it.operator*().authorSurname = surname;
                it.operator*().title = title;
                it.operator*().year = year.toInt();
                it.operator*().publisher = publisher;
                it.operator*().pages = pages.toInt();
                break;
            }
        }
        ui->bookComboBox->insertItem(ui->bookComboBox->currentIndex(), title);
        ui->bookComboBox->removeItem(ui->bookComboBox->currentIndex());

        ui->bookCodeEdit->clear();
        ui->authorSurnameEdit->clear();
        ui->titleEdit->clear();
        ui->yearEdit->clear();
        ui->publisherEdit->clear();
        ui->pagesEdit->clear();

        this->rewriteBooksInFile();
        this->booksButton_clicked();
    }
    else {
        QMessageBox::warning(this, "Ошибка", "Некорректный ввод!");
    }

}


void Widget::deleteBookButton_clicked()
{
    if(booksAmount > 0){
        iterator it = List->begin();

        for (int i = 0; i < booksAmount; i++, ++it) {
            if (it.operator*().title == ui->bookComboBox->currentText()) {
                List->erase(i + 1);
            }
        }

        booksAmount -= 1;

        ui->bookComboBox->removeItem(ui->bookComboBox->currentIndex());
        this->rewriteBooksInFile();
        this->booksButton_clicked();
    } else {
        QMessageBox::warning(this, "Ошибка", "Cписок пуст!");
    }
}

bool containsDigit(const QString& string)
{
    for(int i = 0; i < string.size(); i++){
        if(string[i].isDigit()) return true;
    }
    return false;
}

void Widget::booksButton_clicked()
{
    this->clearTable();
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("Код книги")
                                                             << ("Фамилия автора")
                                                             << ("Название")
                                                             <<  ("Год выпуска")
                                                             <<  ("Издательство")
                                                             <<  ("Кол-во страниц"));
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    iterator it = List->begin();

    for(int i = 0; i < booksAmount; i++, ++it){
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(it.operator*().number)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(it.operator*().authorSurname));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(it.operator*().title));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(it.operator*().year)));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(it.operator*().publisher));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(it.operator*().pages)));
        connect(ui->findBookEdit, SIGNAL(textChanged(const QString&)), this, SLOT(findBookEdit_textChanged(const QString&)));
    }
}


void Widget::findBookEdit_textChanged(const QString &arg1)
{
    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
        for(int j = 0; j < ui->tableWidget->columnCount(); j++){
            ui->tableWidget->item(i, j)->setBackground(QBrush(Qt::white));
        }
    }
    if(arg1 != ""){
        iterator it = List->begin();
        for(int i = 0; i < booksAmount; i++, ++it){
            if(it.operator*().title.contains(arg1, Qt::CaseInsensitive)){
                for(int j = 0; j < 6; j++) ui->tableWidget->item(i, j)->setBackground(QBrush(Qt::yellow));
            }
        }
    }
}

bool check(QString line)
{
    int res = 0;
    for (auto c : line){
        if (c == '|') ++res;
    }
    if (res != 5) return false;
    return true;
}

void Widget::on_openFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open txt"),
                                                    "C:\\Qt\\Labs\\Lab2_Task1\\", tr("txt files (*.txt)"));
    QFile file(fileName);
    if(file.open(QIODevice::ReadWrite)){
        QTextStream stream(&file);


        QString line;
        int count = 0;
        while(!stream.atEnd()){
            line = stream.readLine();
            if (!check(line)) {
                QMessageBox::warning(this, "Ошибка", "Некорректные данные");
                file.close();
                return;
            }
            else if(line != "") count++;
        }

        booksAmount = count;

        stream.seek(0);
        int _code;
        QString _authorSurname;
        QString _title;
        int _year;
        QString _publisher;
        int _pages;

        QString __code;
        QString __authorSurname;
        QString __title;
        QString __year;
        QString __publisher;
        QString __pages;

        QStringList list;
        QFile file("C:\\Qt\\Labs\\Lab2_Task1\\bookList.txt");
        file.open(QIODevice::ReadWrite | QIODevice::Append);
        QTextStream str(&file);
        for(int i = 0; i < booksAmount; i++){
            list = stream.readLine().split('|');
            _code = list[0].toInt();
            __code = list[0];
            str << __code + "|";
            _authorSurname = list[1];
            __authorSurname = list[1];
            str << __authorSurname + "|";
            _title = list[2];
            __title = list[2];
            str << __title + "|";
            _year = list[3].toInt();
            __year = list[3];
            str << __year + "|";
            _publisher = list[4];
            __publisher = list[4];
            str << __publisher + "|";
            _pages = list[5].toInt();
            __pages = list[5];
            str << __pages + "\n";

            ui->bookComboBox->addItem(_title);

            List->push_back(new Node(_code, _authorSurname, _title, _year, _publisher, _pages));
        }
        file.close();

        /*QFile file("C:\\Qt\\Labs\\Lab2_Task1\\bookList.txt");
        if(file.open(QIODevice::ReadWrite | QIODevice::Append)){
            QTextStream stream(&file);
            for (int i = 0; i < booksAmount; ++i) {
            stream << __code + "|";
            stream << __authorSurname + "|";
            stream << __title + "|";
            stream << __year + "|";
            stream << __publisher + "|";
            stream << __pages + "\n";

            file.close();
            ui->bookCodeEdit->clear();
            ui->authorSurnameEdit->clear();
            ui->titleEdit->clear();
            ui->yearEdit->clear();
            ui->publisherEdit->clear();
            ui->pagesEdit->clear();
            }
        }*/

    }
}

