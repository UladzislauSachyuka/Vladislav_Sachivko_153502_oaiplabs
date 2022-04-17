#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->ConversationsButton, SIGNAL(clicked()), this, SLOT(ConversationsButton_clicked()));
    connect(ui->addConversationButton, SIGNAL(clicked()), this, SLOT(addConversationButton_clicked()));
    //connect(ui->sortConversationsButton, SIGNAL(clicked()), this, SLOT(sortConversationsButton_clicked()));
    connect(ui->findConversationEdit, SIGNAL(textChanged(const QString&)), this, SLOT(findConversationEdit_textChanged(const QString&)));
    connect(ui->findConversationEdit_2, SIGNAL(textChanged(const QString&)), this, SLOT(findConversationEdit_2_textChanged(const QString&)));
    connect(ui->changeConversationButton, SIGNAL(clicked()), this, SLOT(changeConversationButton_clicked()));
    connect(ui->deleteConversationButton, SIGNAL(clicked()), this, SLOT(deleteConversationButton_clicked()));
    //connect(ui->sortConversationsButton, SIGNAL(clicked()), this, SLOT(sortConversationsButton_clicked()));

    this->readConversationsFromFile();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::clearTable()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);
}

void Widget::readConversationsFromFile()
{
    QFile file("C:\\Qt\\Labs\\Lab2_Task1_2\\conversationList.txt");

    if(file.open(QIODevice::ReadWrite)){
        QTextStream stream(&file);

        QString line;
        int count = 0;
        while(!stream.atEnd()){
            line = stream.readLine();
            if(line != "") count++;
        }

        conversationsAmount = count;

        stream.seek(0);
        QDate _d;
        int _code;
        QString _city;
        QTime _time;
        int _number_in_the_city;
        QString _tariff;
        QString _number;

        List = new DoubleList();

        QStringList list;

        for(int i = 0; i < conversationsAmount; i++){
            list = stream.readLine().split('|');
            _d = QDate::fromString(list[0]);
            _code = list[1].toInt();
            _city = list[2];
            _time = QTime::fromString(list[3]);
            _number_in_the_city = list[4].toInt();
            _tariff = list[5];
            _number = list[6];

            ui->conversationComboBox->addItem(_number);

            List->push_back(new Node(_d, _code, _city, _time, _number_in_the_city, _tariff, _number));
        }
        file.close();

    }
}

void Widget::rewriteConversationsInFile()
{
    QFile file("C:\\Qt\\Labs\\Lab2_Task1_2\\conversationList.txt");
    if(file.open(QIODevice::WriteOnly)){
        QTextStream stream(&file);
        iterator it = List->begin();
        if (it == nullptr)
            stream << "";
        else {
            for(int i = 0; i < List->getCount(); i++, ++it){
                stream << it.operator*().date.toString() << "|" << it.operator*().code
                   << "|" << it.operator*().city << "|"
                   << it.operator*().time.toString() << "|" << it.operator*().number_in_the_city << "|"
                   << it.operator*().tariff << it.operator*().number << "\n";
            }
        file.close();
        }
    }
    else {
        qDebug() << "File not open\n";
    }

}

void Widget::addConversationButton_clicked()
{
    QDate date = ui->dateEdit->date();
    QString code = ui->codeEdit->text();
    QString city = ui->cityEdit->text();
    QTime time = ui->timeEdit->time();
    QString number_in_the_city = ui->numEdit->text();
    QString tariff = ui->tariffEdit->text();
    QString number = ui->phoneNumEdit->text();

    /*bool isExist = false;
    iterator it = List->begin();

    for(int i = 0; i < conversationsAmount; i++){
        if(it.operator*().title == title) isExist = true;
        ++it;
    }
    if(isExist){
        QMessageBox::warning(this, "Ошибка", "Книга с таким названием уже существует.");
    }*/
    if(/*date.isValid() &&*/ code.toInt() != 0 && !city.contains(' ') && !containsDigit(city) /*&& time.isValid()*/ /*&& !number_in_the_city.contains(' ')*/
            && !tariff.contains(' ') && !containsDigit(tariff)){

        List->push_back(new Node(date, code.toInt(), city, time, number_in_the_city.toInt(), tariff, number));

        conversationsAmount += 1;

        QFile file("C:\\Qt\\Labs\\Lab2_Task1_2\\conversationList.txt");
        if(file.open(QIODevice::ReadWrite | QIODevice::Append)){
            QTextStream stream(&file);

            stream << date.toString() + "|";
            stream << code + "|";
            stream << city + "|";
            stream << time.toString() + "|";
            stream << number_in_the_city + "|";
            stream << tariff + "|";
            stream << number + "\n";

            file.close();
            ui->dateEdit->clear();
            ui->codeEdit->clear();
            ui->cityEdit->clear();
            ui->timeEdit->clear();
            ui->numEdit->clear();
            ui->tariffEdit->clear();
            ui->phoneNumEdit->clear();
        }

        this->ConversationsButton_clicked();

        ui->conversationComboBox->addItem(number);
    } else {
        QMessageBox::warning(this, "Ошибка", "Некорректный ввод!");
    }
}


void Widget::changeConversationButton_clicked()
{
    QString _number = ui->conversationComboBox->currentText();

    QDate date = ui->dateEdit->date();
    QString code = ui->codeEdit->text();
    QString city = ui->cityEdit->text();
    QTime time = ui->timeEdit->time();
    QString number_in_the_city = ui->numEdit->text();
    QString tariff = ui->tariffEdit->text();
    QString number = ui->phoneNumEdit->text();

    if(/*date.isValid() &&*/ code.toInt() != 0 && !city.contains(' ') && !containsDigit(city) && time.isValid() && !number_in_the_city.contains(' ')
            && !tariff.contains(' ') && !containsDigit(tariff)){
        iterator it = List->begin();
        for(int i = 0; i < conversationsAmount; i++, ++it){
            if(it.operator*().number == _number){
                it.operator*().date = date;
                it.operator*().code = code.toInt();
                it.operator*().city = city;
                it.operator*().time = time;
                it.operator*().number_in_the_city = number_in_the_city.toInt();
                it.operator*().tariff = tariff;
                it.operator*().number = number;
                break;
            }
        }
        ui->conversationComboBox->insertItem(ui->conversationComboBox->currentIndex(), number);
        ui->conversationComboBox->removeItem(ui->conversationComboBox->currentIndex());

        ui->dateEdit->clear();
        ui->codeEdit->clear();
        ui->cityEdit->clear();
        ui->timeEdit->clear();
        ui->numEdit->clear();
        ui->tariffEdit->clear();
        ui->phoneNumEdit->clear();

        this->rewriteConversationsInFile();
        this->ConversationsButton_clicked();
    }
    else {
        QMessageBox::warning(this, "Ошибка", "Некорректный ввод!");
    }
}


void Widget::deleteConversationButton_clicked()
{
    if(conversationsAmount > 0){
            iterator it = List->begin();

            for (int i = 0; i < conversationsAmount; i++, ++it) {
                if (it.operator*().number == ui->conversationComboBox->currentText()) {
                    List->erase(i + 1);
                }
            }

            conversationsAmount -= 1;

            ui->conversationComboBox->removeItem(ui->conversationComboBox->currentIndex());
            this->rewriteConversationsInFile();
            this->ConversationsButton_clicked();
        } else {
            QMessageBox::warning(this, "Ошибка", "Cписок пуст!");
        }
}

void Widget::ConversationsButton_clicked()
{
    this->clearTable();
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("Дата")
                                                             << ("Код")
                                                             << ("Город")
                                                             <<  ("Время")
                                                             <<  ("Ном. в гор.")
                                                             <<  ("Тариф")
                                                             << ("Номер"));
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    iterator it = List->begin();

    for(int i = 0; i < conversationsAmount; i++, ++it){
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(it.operator*().date.toString()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(it.operator*().code)));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(it.operator*().city));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(it.operator*().time.toString()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(it.operator*().number_in_the_city)));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(it.operator*().tariff));
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(it.operator*().number));
        //connect(ui->findBookEdit, SIGNAL(textChanged(const QString&)), this, SLOT(findBookEdit_textChanged(const QString&)));
    }
}


void Widget::on_openFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open txt"),
                                                    "C:\\Qt\\Labs\\Lab2_Task1_2\\", tr("txt files (*.txt)"));
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

        conversationsAmount = count;

        stream.seek(0);
        QDate _d;
        int _code;
        QString _city;
        QTime _time;
        int _number_in_the_city;
        QString _tariff;
        QString _number;

        //bookList = new Book[booksAmount];

        //List = new DoubleList();

        QStringList list;

        for(int i = 0; i < conversationsAmount; i++){
            list = stream.readLine().split('|');
            _d = QDate::fromString(list[0]);
            _code = list[1].toInt();
            _city = list[2];
            _time = QTime::fromString(list[3]);
            _number_in_the_city = list[4].toInt();
            _tariff = list[5];
            _number = list[6];

            ui->conversationComboBox->addItem(_number);

            List->push_back(new Node(_d, _code, _city, _time, _number_in_the_city, _tariff, _number));
        }
        file.close();

    }
}

bool containsDigit(const QString& string)
{
    for(int i = 0; i < string.size(); i++){
        if(string[i].isDigit()) return true;
    }
    return false;
}

bool check(QString line)
{
    int res = 0;
    for (auto c : line){
        if (c == '|') ++res;
    }
    if (res != 6) return false;
    return true;
}

void Widget::findConversationEdit_textChanged(const QString &arg1)
{
    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
        for(int j = 0; j < ui->tableWidget->columnCount(); j++){
            ui->tableWidget->item(i, j)->setBackground(QBrush(Qt::white));  //clear table
        }
    }
    if(arg1 != ""){
        iterator it = List->begin();
        for(int i = 0; i < conversationsAmount; i++, ++it){
            if(it.operator*().city.contains(arg1, Qt::CaseInsensitive)){
                for(int j = 0; j < 7; j++) ui->tableWidget->item(i, j)->setBackground(QBrush(Qt::yellow));
            }
        }
    }
}


void Widget::findConversationEdit_2_textChanged(const QString &arg1)
{
    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
        for(int j = 0; j < ui->tableWidget->columnCount(); j++){
            ui->tableWidget->item(i, j)->setBackground(QBrush(Qt::white));  //clear table
        }
    }
    if(arg1 != ""){
        iterator it = List->begin();
        for(int i = 0; i < conversationsAmount; i++, ++it){
            if(it.operator*().number.contains(arg1, Qt::CaseInsensitive)){
                for(int j = 0; j < 7; j++) ui->tableWidget->item(i, j)->setBackground(QBrush(Qt::yellow));
            }
        }
    }
}

