#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

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
    void on_strlen_clicked();

    void on_strcpy_clicked();

    void on_strcmp_clicked();

    void on_strtok_clicked();

    void on_memcmp_clicked();

    void on_clear_clicked();

    void on_strcat_clicked();

private:
    Ui::MainWindow *ui;
    //MyString str1;
    //MyString str2;

};

/*void* memcpy(void* s1, const void* s2, size_t n)
{
    char* cs1 = (char*)s1;
    const char* cs2 = (char*)s2;
    for (size_t i = 0; i < n; i++)
    {
        *cs1++ = *cs2++;
    }
    return s1;
}

void* memmove(void* s1, const void* s2, size_t n)
{
    char* cs1 = (char*)s1;
    char* temp = new char[n + 1];
    char* cs2 = (char*)s2;
    Memcpy(temp, cs2, n);
    Memcpy(cs1, temp, n);
    return s1;
}

char* strcpy(char* s1, const char* s2)
{
    assert(s1 != nullptr && s2 != nullptr);
    while (*s2 != '\0')
        *s1++ = *s2++;
    *s1 = '\0';
    return s1;
}

char* strncpy(char* s1, const char* s2, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        *s1++ = *s2++;
    *s1 = '\0';
    return s1;
}

char* strcat(char* s1, const char* s2)
{
    while (*s1)
        s1++;
    while (*s2)
        *s1++ = *s2++;
    *s1 = '\0';
    return s1;
}

char* strncat(char* s1, const char* s2, size_t n)
{
    while (*s1)
        s1++;
    for (size_t i = 0; i < n; ++i)
        *s1++ = *s2++;
    *s1 = '\0';
    return s1;
}

int memcmp(const void* s1, const void* s2, size_t n)
{
    const char* cs1 = (char*)s1;
    const char* cs2 = (char*)s2;
    assert(n <= Strlen(cs1) && n <= Strlen(cs2));
    for (size_t i = 0; i < n; i++)
    {
        if (cs1[i] > cs2[i])
            return 1;
        else if (cs1[i] < cs2[i])
            return -1;
    }
    return 0;
}

int strcmp(const char* s1, const char* s2)
{
    size_t len1 = Strlen(s1);
    size_t len2 = Strlen(s2);
    for (size_t i = 0; i < (len1 < len2 ? len1 : len2); i++)
        if (s1[i] > s2[i])
            return 1;
        else if (s1[i] < s2[i])
            return -1;
    if (len1 == len2)
        return 0;
    else if (len1 > len2)
        return 1;
    else
        return -1;
}

int strcoll(const char* s1, const char* s2)
{
    return Strcmp(s1, s2);
}

int strncmp(const char* s1, const char* s2, size_t n)
{
    assert(n <= Strlen(s1) && n <= Strlen(s2));
    for (size_t i = 0; i < n; i++)
    {
        if (s1[i] > s2[i])
            return 1;
        else if (s1[i] < s2[i])
            return -1;
    }
    return 0;
}

size_t strxfrm(char* s1, const char* s2, size_t n)
{
    size_t n2 = Strlen(s2);
    if (n2 > n)
    {
        Strcpy(s1, s2);
    }
    return n2;
}

char* strtok(char* s1, const char* s2)
{
    static char* last = 0;
    if (s1) last = s1;
    if ((last == 0) || (*last == 0)) return 0;
    char* c = last;
    while (strchr(s2, *c)) ++c;
    if (*c == 0) return 0;
    char* start = c;
    while (*c && (strchr(s2, *c) == 0)) ++c;
    if (*c == 0)
    {
        last = c;
        return start;
    }
    *c = 0;
    last = c + 1;
    return start;
}

void* memset(void* s, int c, size_t n)
{
    if (s != nullptr)
    {
        char* tmp_mem = (char*)s;
        for (size_t i = 0; i < n; ++i)
        {
            *tmp_mem++ = c;
        }
    }
    return s;
}

size_t strlen(const char* s)
{
    int len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}*/

#endif // MAINWINDOW_H
