// Лабораторная 7, задача 3. Выполнил Сачивко В.Г.
/*Осуществить сложение чисел. Разработать функции для
выполнения операции сложения. Предусмотреть ввод положительных и
отрицательных чисел.Найдите сумму двоичных чисел, заданных в естественной форме.
Сложение выполните в дополнительном коде. Ответ выразите в прямом
коде.*/

#include "task3.h"

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
		if (input < -127 || input > 127)
		{
			cout << "Некорректный ввод. Попробуйте еще раз. Введите значение\n";
		}
	} while (input < -128 || input > 127);

	return input;
}

void binary(char* ar, int num, int& len) 
{
	int i = 0;
	int val = num;
	while (val != 0) 
	{
		ar[i] = char(abs(val) % 2 + 48);
		val /= 2;
		++i;
	}
	while (i < 7) 
	{
		ar[i] = '0';
		++i;
	}
	if (num >= 0)
		ar[i] = '0';
	else
		ar[i] = '1';
	len = i + 1;
}

void dop_code(char* ar, int len) 
{
	int i;
	for (i = 0; i < len - 1; ++i) 
	{
		if (ar[i] == '0')
			ar[i] = '1';
		else if (ar[i] == '1')
			ar[i] = '0';
	}
	i = 0;
	if (ar[i] == '0')
		ar[i] = '1';
	else 
	{
		while (ar[i + 1] == '1')
		{	
			ar[i] = '0';
			++i;
		}
		ar[i] = '0';
		ar[i + 1] = '1';
	}
}

void from_dop_to_direct_code(char* ar, int len) 
{
	int i;
	for (i = 0; i < len - 1; ++i) 
	{
		if (ar[i] == '0')
			ar[i] = '1';
		else if (ar[i] == '1')
			ar[i] = '0';
	}
	i = 0;
	if (ar[i] == '0')
		ar[i] = '1';
	else
	{
		while (ar[i + 1] == '1')
		{
			ar[i] = '0';
			++i;
			continue;
		}
		ar[i] = '0';
		ar[i + 1] = '1';
	}
}

void addition(char* ar1, char* ar2, char* add, int len, int num1, int num2) 
{
	int m = 0, i;
	int len_add = len;
	for (i = 0; i < len - 1; ++i) 
	{
		if (int(ar1[i] - '0') + int(ar2[i] - '0') + m > 2)
		{
			add[i] = '1';
			m = 1;
		}
		else if (int(ar1[i] - '0') + int(ar2[i] - '0') + m > 1) 
		{
			add[i] = '0';
			m = 1;
		}
		else 
		{
			add[i] = char(int(ar1[i] - '0') + int(ar2[i] - '0') + m + 48);
			m = 0;
		}
	}

	if ((num1 >= 0 && num2 >= 0) || (num1 >= 0 && num2 <= 0 && num1 - abs(num2) > 0) || (num2 >= 0 && num1 <= 0 && num2 - abs(num1) > 0))
	{
		add[i] = '0';
		add[i + 1] = '\0';
	}
	else
	{
		add[i] = '1';
		add[i + 1] = '\0';
		from_dop_to_direct_code(add, len_add);
	}

	for (int j = len_add - 1; j >= 0; --j) 
		cout << add[j];
	cout << '\n';
}

