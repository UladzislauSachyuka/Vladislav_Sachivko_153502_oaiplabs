/*Лабораторная 7, задача 5. Выполнил Сачивко В.Г.*/
/*Перевести число из арабской системы записи чисел в римскую*/

#include "task5.h"

int getinput()
{
    int input;
    do
    {
        cin >> input;
        while (cin.get() != '\n')
        {
            cin.clear();
            cin.ignore(100000, '\n');
            cout << "Некорректный ввод. Попробуйте еще раз. Введите значение\n";
            cin >> input;
        }
        if (input < 1 || input > 3999)
        {
            cout << "Некорректный ввод. Попробуйте еще раз. Введите значение\n";
        }
    } while (input < 1 || input > 3999);

    return input;
}

char* func(int a) 
{
    int cur, j = 0;
    char tmp;
    char* f = new char[10];
    char b[][2] = 
    {
        'I','V',
        'X','L',
        'C','D',
        'M'
    };
    for (int i = 1; a > 0 && i < 5; i++) 
    {
        cur = a % 10;
        if (cur > 0 && cur < 4) 
        {
            for (int r = 0; r < cur; r++) 
            {
                f[j] = b[i - 1][0];
                j++;
            }
        }
        else if (cur == 4) 
        {
            f[j] = b[i - 1][1];
            f[j + 1] = b[i - 1][0];
            j += 2;
        }
        else if (cur > 4 && cur < 9) 
        {
            cur -= 5;
            for (int r = 0; r < cur; r++) 
            {
                f[j] = b[i - 1][0];
                j++;
            }
            f[j] = b[i - 1][1];
            j++;
        }
        else if (cur == 9) 
        {
            f[j] = b[i][0];
            f[j + 1] = b[i - 1][0];
            j += 2;
        }
        a /= 10;
    }
    for (int i = 0; i < j / 2; i++) 
    {
        tmp = f[i];
        f[i] = f[j - 1 - i];
        f[j - 1 - i] = tmp;
    }
    f[j] = 0;
    return f;
}


