// Лабораторная 7, задача 1. Выполнил Сачивко В.Г.
/*Необходимо разработать программу для перевода чисел из
одной системы счисления в другую. Выполнить два варианта решения
задачи: без использования массивов и с помощью массивов.
Из девятичной в одиннадцатеричную*/

#include <iostream>
#include <cmath>

using namespace std;

long long getinput()
{
	long long input;
	cin >> input;
	while (cin.get() != '\n')
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "Некорректный ввод. Попробуйте еще раз.\nВведите значение\n";
		cin >> input;
	}
	long long n = input;
	while (n != 0) 
	{
		if (n % 10 == 9) 
		{
			cout << "Некорректный ввод. Попробуйте еще раз.\nВведите значение\n";
			input = getinput();
			break;
		}
		n /= 10;
	}
 	return input;
}

int main() 
{
	setlocale(LC_ALL, "rus");
	cout << "Программа переводит числа из девятеричной в одиннадцатеричную систему счисления\n\n";
	cout << "введите число в девятеричной системе счисления\n";
	long long num9 = getinput();

	long long value = 0, k = 0;
	while (num9 != 0) 
	{
		value += abs(num9 % 10) * pow(9, k);
		num9 /= 10;
		++k;
	}

	long long val = value;
	int div = 0;
	while (val != 0) 
	{
		++div;
		val /= 11;
	}

	while (div--) 
	{
		long long temp = value;
		for (int i = 0; i < div; ++i) 
		{
			temp /= 11;
		}
		if (temp % 11 == 10) 
		{
			cout << "A";
		}
		else 
		{
			cout << temp % 11;
		}
	}

	return 0;
}