﻿// Лабораторная 5, задача 1. Выполнил Сачивко В.Г.
/*Сформировать двумерный динамический массив-матрицу А размерностью
n * n (n = 10), причем значения aij определить согласно выражению
при i = 1, 2,...n, j = 1, 2,..., n.
Сформировать транспонированную матрицу B = A(T)
Определить сумму элементов четных строк и нечетных столбцов для массива-
матрицы А и сумму четных столбцов и нечетных строк для массива-матрицы В. На экран
вывести массивы-матрицы А и В построчно и значения сумм. Использовать функции.*/

#include "task1.h"

void initial_arr(int n, int** arr) 
{
	for (int i = 0; i < n; ++i)
	{
		arr[i] = new int[n] {0};
		for (int j = 0; j < n; ++j)
		{
			if (i + 1 <= 5)
			{
				arr[i][j] = 2 * (i + 1) * (j + 1) * (j + 1) - 2 * (j + 1);
			}
			else if (i + 1 > 5)
			{
				arr[i][j] = 3 * (i + 1) * (j + 1) - 3;
			}
		}
	}
}

void output(int n, int** arr, int** arr1) 
{
	static int i = 0;
	for (int j = 0; j < n; ++j)
	{
		cout << setw(4) << arr[i][j];
	}
	cout << "\t";
	for (int j = 0; j < n; ++j)
	{
		cout << setw(4) << arr1[i][j];
	}
	cout << "\n";
	++i;
}

int sum(int k1, int k2, int n, int** arr) 
{
	int sum = 0;
	for (int i = k1; i < n; i += 2)
	{
		for (int j = k2; j < n; j += 2)
		{
			sum += arr[i][j];
		}
	}

	return sum;
}

