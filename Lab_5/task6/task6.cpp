// Лабораторная 5, задача 6. Выполнил Сачивко В.Г.

#include "task6.h"

/*int getinput(char sym, int b = 1)
{
	int n;
	int max = 2147483647;
	do
	{
		cin >> n;
		while (cin.get() != sym)
		{
			cin.clear();
			cin.ignore(100000, sym);
			cout << "Некорректный ввод.\nВведите число.\n ";
			cin >> n;
		}
		if (n < 0)
		{
			return -1;
		}
		
		if ((b < 0 && n >= 0) || (b > 0 && n < 0) || n > max || n < -max || b > max || b < -max)
		{
			cout << "Некорректный ввод.\nВведите числа.\n";
			continue;
			
		}
		if (sym == '\n' && n < b)
		{
			cout << "Некорректный ввод. \nВведите числа.\n";
			continue;
		}
	} while ((b < 0 && n >= 0) || (b > 0 && n < 0) || b > max || b < -max || n > max || n < -max || (sym == '\n' && n < b));
	return n;
}*/

int func(int p) 
{
	int F;
	if (p % 10 > 0)
	{
		F = p % 10;
	}
	else if (p == 0)
	{
		F = 0;
	}
	else
	{
		F = func(p / 10);
	}

	return F;
}

int sum(int p, int q) 
{
	int sum = 0;

	for (int i = p; i <= q; ++i) 
	{
		sum += func(i);
	}

	return sum;
}

