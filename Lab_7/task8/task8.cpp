// Лабораторная 7, задача 8. Выполнил Сачивко В.Г.
/*Брюс недавно получил работу в NEERC (Numeric Expression Engineering &
Research Center), где изучают и строят много различных любопытных
чисел. Его первым заданием стало исследование двудесятичных чисел.
Натуральное число называется двудесятичным, если его десятичное
представление является суффиксом его двоичного представления; и
двоичное и десятичное представление рассматривается без ведущих
нулей. Например, 1010 = 10102, так что 10 двудесятичное число. Числа
101010 = 11111100102 и 4210 = 1010102 не являются двудесятичными.
Сначала Брюс хочет создать список двудесятичных чисел. Помогите
ему найти n-ое наименьшее двудесятичное число.*/

#include "task8.h"

long long getinput()
{
    long long input;
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
        if (input < 1 || input > 10000)
        {
            cout << "Некорректный ввод. Попробуйте еще раз. Введите значение\n";
        }
    } while (input < 1 || input > 10000);

    return input;
}

long long binary(long long num)
{
    unsigned long long temp = 0;
    unsigned long long d = 0;
    while (num)
    {
        temp += (num % 2) * (long long)pow(10, d);
        d++;
        num /= 2;
    }
    return temp;
}

long long size(long long n)
{
    unsigned long long s = 0;
    while (n) {
        s++;
        n /= 10;
    }
    return s;
}

bool two_dec(long long n2, unsigned long long n22)
{
    return (n22 % (long long)pow(10, size(n2)) == n2);
}


