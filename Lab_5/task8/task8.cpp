// Лабораторная 5, задача 8. Выполнил Сачивко В.Г.
/*Пусть f(n) - наибольший нечетный делитель натурального числа n. По заданному
натуральному n необходимо вычислить значение суммы f(1) + f(2) + ... + f(n).*/

#include "task8.h"

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
			cout << "Некорректный ввод. Попробуйте еще раз.\nВведите значение\n ";
			cin >> input;
		}
		if (input < 1)
		{
			cout << "Некорректный ввод. Попробуйте еще раз.\nВведите значение\n ";
		}
	} while (input < 1);

	return input;
}

int func(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		int k = i;
		if (k % 2 != 0)
		{
			sum += k;
		}
		else if (k % 2 == 0)
		{
			do
			{
				k = k / 2;
			} while (k % 2 == 0);
			sum += k;
		}
	}
	return sum;
}
