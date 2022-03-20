#ifndef BOOK_H
#define BOOK_H


#include <QString>

class Book
{
public:
    Book(int code = 0, QString authorSurname = "none", QString title = "none", int year = 0, QString language = "none");
    ~Book();

    int getBookCode() const;
    QString getAuthorSurname() const;
    QString getTitle() const;
    int getYear() const;
    QString getLanguage() const;

private:
    int code;
    QString authorSurname;
    QString title;
    int year;
    QString language;
};

#endif // BOOK_H
