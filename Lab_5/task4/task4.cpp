// Лабораторная 5, задача 4. Выполнил Сачивко В.Г.
/*Создать двумерный динамический массив вещественных чисел. Определить,
встречаются ли среди них элементы с нулевым значением. Если встречаются такие
элементы, то определить их индексы и общее количество. Переставить элементы этого
массива в обратном порядке и вывести на экран.
Использовать функции.*/

#include "task4.h"

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

double getelem()
{
	double input;
	cin >> input;
	while (cin.get() != '\n')
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "Некорректный ввод. Попробуйте еще раз.\nВведите значение\n ";
		cin >> input;
	}
	return input;
}

void array_output(int n, int k, double** arr)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			cout << setw(4) << arr[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

int null_elements(int n, int k, double** arr) 
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			if (arr[i][j] == 0)
			{
				++count;
				cout << "[" << i << "][" << j << "]\n";
			}
		}
	}
	return count;
}

void array_output1(int n, int k, double** arr) 
{
	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = k - 1; j >= 0; --j)
		{
			cout << setw(4) << arr[i][j];
		}
		cout << "\n";
	}
}

