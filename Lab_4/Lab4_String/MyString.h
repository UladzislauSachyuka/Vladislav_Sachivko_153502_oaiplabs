#ifndef MYSTRING_H
#define MYSTRING_H

#include <assert.h>
#include <iostream>
#include <cstring>
#include <QString>

typedef unsigned int size_t;

using namespace std;

size_t Strlen(const char*);

void* Memcpy(void* s1, const void* s2, size_t n)
{
    char* cs1 = (char*)s1;
    const char* cs2 = (char*)s2;
    for (size_t i = 0; i < n; i++)
    {
        *cs1++ = *cs2++;
    }
    return s1;
}

void* Memmove(void* s1, const void* s2, size_t n)
{
    char* cs1 = (char*)s1;
    char* temp = new char[n + 1];
    char* cs2 = (char*)s2;
    Memcpy(temp, cs2, n);
    Memcpy(cs1, temp, n);
    return s1;
}

char* Strcpy(char* s1, const char* s2)
{
    assert(s1 != nullptr && s2 != nullptr);
    while (*s2 != '\0')
        *s1++ = *s2++;
    *s1 = '\0';
    return s1;
}

char* Strncpy(char* s1, const char* s2, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        *s1++ = *s2++;
    *s1 = '\0';
    return s1;
}

char* Strcat(char* s1, const char* s2)
{
    while (*s1)
        s1++;
    while (*s2)
        *s1++ = *s2++;
    *s1 = '\0';
    return s1;
}

char* Strncat(char* s1, const char* s2, size_t n)
{
    while (*s1)
        s1++;
    for (size_t i = 0; i < n; ++i)
        *s1++ = *s2++;
    *s1 = '\0';
    return s1;
}

int Memcmp(const void* s1, const void* s2, size_t n)
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

int Strcmp(const char* s1, const char* s2)
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

int Strcoll(const char* s1, const char* s2)
{
    return Strcmp(s1, s2);
}

int Strncmp(const char* s1, const char* s2, size_t n)
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

size_t Strxfrm(char* s1, const char* s2, size_t n)
{
    size_t n2 = Strlen(s2);
    if (n2 > n)
    {
        Strcpy(s1, s2);
    }
    return n2;
}

char* Strtok(char* s1, const char* s2)
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

void* Memset(void* s, int c, size_t n)
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

size_t Strlen(const char* s)
{
    int len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}

class MyString
{
public:
    char* str;
    int len = 0;
    int capacity = 15;
public:
    MyString() : str(new char[capacity]), len(0)
    {
        str[0] = '\0';
    }

    MyString(const char* s) : len(Strlen(s))
    {
        while (len >= capacity)
            capacity = capacity * 2 + 1;
        str = new char[capacity];
        Strcpy(str, s);
    }

    MyString(const MyString& st) : len(Strlen(st.str))
    {
        while (len >= capacity)
            capacity = capacity * 2 + 1;
        str = new char[capacity];
        Strcpy(str, st.str);
    }

    MyString(MyString&& other) noexcept : str(other.str), len(other.len), capacity(other.capacity)
    {
        str = other.str;
        other.str = nullptr;
        other.len = 0;
        other.capacity = 0;
    }

    ~MyString()
    {
        delete[] str;
    }

    MyString& operator=(const QString& st)
    {
        len = st.length();
        if (capacity < st.capacity())
        {
            delete[] str;
            capacity = st.capacity();
            str = new char[capacity];
        }
        const char* buff=st.toStdString().data();
        Strcpy(str, buff);
        return *this;

    }

    MyString& operator=(const MyString& st)
    {
        if (this == &st)
            return *this;
        len = st.len;
        if (capacity < st.capacity)
        {
            delete[] str;
            capacity = st.capacity;
            str = new char[capacity];
        }
        Strcpy(str, st.str);
        return *this;
    }

    MyString& operator=(const char* s)
    {
        delete[] str;
        len = Strlen(s);
        while (len >= capacity)
            capacity = capacity * 2 + 1;
        str = new char[capacity];
        Strcpy(str, s);
        return *this;
    }

    MyString& operator=(MyString&& st) noexcept
    {
        str = st.str;
        len = st.len;
        capacity = st.capacity;
        st.str = nullptr;
        st.len = 0;
        st.capacity = 0;
        return *this;
    }

    class iterator
    {
    private:
        char* st;
    public:
        iterator(char* s) : st(s) {}

        iterator& operator++()
        {
            ++st;
            return *this;
        }

        char& operator*() { return *st; }

        bool operator!=(const iterator& it) { return this->st != it.st; }
        bool operator==(const iterator& it) { return this->st == it.st; }


    };

    iterator begin() { return str; }
    iterator end() { return str + len; }
    iterator rbegin() { return str + len - 1; }
    iterator rend() {}


    size_t size() const noexcept
    {
        return len;
    }

    size_t length() const noexcept
    {
        return len;
    }

    size_t Capacity() const noexcept
    {
        return capacity;
    }

    void clear() noexcept
    {
        delete[] str;
        len = 0;
        capacity = 15;
        str = new char[capacity];
        str[0] = '\0';
    }

    bool empty() const noexcept
    {
        return len == 0;
    }

    void resize(size_t n)
    {
        if (n >= capacity)
        {
            while (n >= capacity)
                capacity = capacity * 2 + 1;
            len = n;
            str = (char*)realloc(str, n);

        }
        else if (n != 0)
        {
            len = n;
            str = (char*)realloc(str, n + 1);
            str[n] = '\0';

        }
        else
        {
            len = 0;
            str = (char*)realloc(str, n);
        }
    }

    void reserve(size_t n)
    {
        while (n >= capacity)
            capacity = capacity * 2 + 1;
        str = (char*)realloc(str, n);
    }

    char& operator[](size_t pos)
    {
        return str[pos];
    }

    const char& operator[](size_t pos) const
    {
        return str[pos];
    }

    char& at(size_t pos)
    {
        if (pos >= length())
            //throw std::out_of_range("Invalid index");
        return str[pos];
    }

    const char& at(size_t pos) const
    {
        if (pos >= length())
            //throw std::out_of_range("Invalid index");
        return str[pos];
    }

    MyString& operator+=(const MyString& st)
    {
        if (capacity < length() + st.length() + 1)
        {
            char* tmp = new char[length() + 1];
            Strcpy(tmp, str);
            while (capacity < length() + st.length() + 1)
                capacity = capacity * 2 + 1;
            delete[] str;
            str = new char[capacity];
            Strcpy(str, tmp);
        }
        Strcat(str, st.str);
        len = Strlen(str);
        return *this;
    }

    MyString& operator+=(const char* s)
    {
        if (capacity < length() + Strlen(s) + 1)
        {
            char* tmp = new char[length() + 1];
            while (capacity < length() + Strlen(s) + 1)
                capacity = capacity * 2 + 1;
            Strcpy(tmp, str);
            delete[] str;
            str = new char[capacity];
            Strcpy(str, tmp);
        }
        Strcat(str, s);
        len = Strlen(str);
        return *this;
    }

    MyString& operator+=(char c)
    {
        if (capacity < length() + 2)
        {
            char* tmp = new char[length() + 1];
            capacity = capacity * 2 + 1;
            Strcpy(tmp, str);
            delete[] str;
            str = new char[capacity];
            Strcpy(str, tmp);
        }
        const char* ch = new char[2]{c, '\0'};
        Strcat(str, ch);
        delete[] ch;
        len = Strlen(str);
        return *this;
    }

    MyString& append(const MyString& st)
    {
        return operator+=(st);
    }

    MyString& append(const char* s)
    {
        return operator+=(s);
    }

    void push_back(char c)
    {
        operator+=(c);
    }

    MyString& insert(size_t pos, const MyString& st)
    {
        if (capacity < length() + st.length())
            capacity = capacity * 2 + 1;
        char* tmp1 = new char[capacity];
        Strncpy(tmp1, str, pos);
        Strcat(tmp1, st.str);
        char* tmp2 = new char[len + 1 - pos];
        for (int i = pos, j = 0; i <= len + 1 - pos; i++, j++)
        {
            tmp2[j] = str[i];
        }
        tmp2[len - pos] = '\0';
        Strcat(tmp1, tmp2);
        delete[] tmp2;
        delete[] str;
        str = tmp1;
        tmp1 = nullptr;
        len = Strlen(str);
        return *this;
    }

    MyString& erase(size_t pos, size_t len)
    {
        char* tmp1 = new char[capacity];
        Strncpy(tmp1, str, pos);
        char* tmp2 = new char[length() + 1 - pos - len];
        for (int i = pos + len, j = 0; i < length(); i++, j++)
            tmp2[j] = str[i];
        tmp2[length() - pos - len] = '\0';
        Strcat(tmp1, tmp2);
        delete[] tmp2;
        delete[] str;
        str = tmp1;
        tmp1 = nullptr;
        this->len = Strlen(str);
        return *this;
    }

    void pop_back()
    {
        str[len - 1] = '\0';
        --len;
    }

    MyString substr(size_t pos, size_t len) const
    {
        char* tmp = new char[len + 1];
        for (int i = pos, j = 0; i < pos + len; i++, j++)
            tmp[j] = str[i];
        tmp[len] = '\0';
        MyString s = tmp;
        s.len = Strlen(tmp);
        return s;
    }

    friend ostream& operator<<(ostream& os, const MyString& st)
    {
        os << st.str;
        return os;
    }

    friend bool operator==(const MyString& st1, const MyString& st2) noexcept
    {
        return (Strcmp(st1.str, st2.str) == 0);
    }

    friend bool operator==(const MyString& st1, const char* st2)
    {
        return (Strcmp(st1.str, st2) == 0);
    }

    friend bool operator!=(const MyString& st1, const MyString& st2) noexcept
    {
        return (Strcmp(st1.str, st2.str) != 0);
    }

    friend bool operator!=(const MyString& st1, const char* st2)
    {
        return (Strcmp(st1.str, st2) != 0);
    }

    friend bool operator<(const MyString& st1, const MyString& st2) noexcept
    {
        return (Strcmp(st1.str, st2.str) < 0);
    }

    friend bool operator<(const MyString& st1, const char* st2)
    {
        return (Strcmp(st1.str, st2) < 0);
    }

    friend bool operator<=(const MyString& st1, const MyString& st2) noexcept
    {
        return (Strcmp(st1.str, st2.str) <= 0);
    }

    friend bool operator<=(const MyString& st1, const char* st2)
    {
        return (Strcmp(st1.str, st2) <= 0);
    }

    friend bool operator>(const MyString& st1, const MyString& st2) noexcept
    {
        return (Strcmp(st1.str, st2.str) > 0);
    }

    friend bool operator>(const MyString& st1, const char* st2)
    {
        return (Strcmp(st1.str, st2) > 0);
    }

    friend bool operator>=(const MyString& st1, const MyString& st2) noexcept
    {
        return (Strcmp(st1.str, st2.str) >= 0);
    }

    friend bool operator>=(const MyString& st1, const char* st2)
    {
        return (Strcmp(st1.str, st2) >= 0);
    }

    friend MyString operator+(const MyString& st1, const MyString& st2)
    {
        MyString temp = "dfsdfsd";
        delete[] temp.str;
        temp.len = st1.len + st2.len;
        while (temp.capacity < temp.len + 1)
            temp.capacity = temp.capacity * 2 + 1;
        temp.str = new char[temp.capacity];
        Strcpy(temp.str, st1.str);
        Strcpy(temp.str + st1.len, st2.str);

        return temp;
    }
};

#endif // MYSTRING_H



