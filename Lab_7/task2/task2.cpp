// Лабораторная 7, задача 2. Выполинил Сачивко В.Г.
/*Перевести числа из естественной формы в прямой код. Предусмотреть ввод положительных и
отрицательных чисел.*/

#include "task2.h"

double getinput()
{
	double input;
	cin >> input;
	while (cin.get() != '\n')
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "Некорректный ввод. Попробуйте еще раз.\nВведите значение\n";
		cin >> input;
	}
	return input;
}

int into_number(char st)
{
	return st - '0';
}

char into_symbol(int s)
{
	return 48 + s;
}

