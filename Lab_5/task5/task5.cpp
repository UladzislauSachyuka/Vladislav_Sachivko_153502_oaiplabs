// Лабораторная 5, задача 5. Выполнил Сачивко В.Г.
/*Дан двумерный динамический массив целых чисел. Значения элементов данного
массива ввести с клавиатуры. Создать динамический массив из элементов,
расположенных в четных столбцах данного массива и имеющих нечетное значение.
Вычислить среднее арифметическое элементов динамического массива.
Вывести результат на экран.
Использовать функции.*/

#include <iostream>
#include <iomanip>

#include "..\Debug\task5_dynamic_lib_.h"
#pragma comment (lib, "..\\Debug\\task5_dynamic_lib_.lib")

using namespace std;

/*int getinput()
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

int getelem()
{
	int input;
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

void array_output(int n, int k, int** arr)
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

double average(int count, int *arr1)
{
	int sum = 0;
	for (int i = 0; i < count; ++i)
	{
		sum += arr1[i];
	}
	return sum / count;
}*/

int main() 
{
	setlocale(LC_ALL, "rus");

	cout << "Дан двумерный динамический массив целых чисел. Значения элементов данного "
		<< "массива ввести с клавиатуры.Создать\nдинамический массив из элементов,"
		<< "расположенных в четных столбцах данного массива и имеющих нечетное значение."
		<< "Вычислить\nсреднее арифметическое элементов динамического массива."
		<< "Вывести результат на экран."
		<< "Использовать функции.\n\n";

	cout << "введите количество строк массива\n";
	int n = getinput();
	cout << "введите количество столбцов матрицы\n";
	int k = getinput();

	int** arr = new int* [n];
	for (int i = 0; i < n; ++i) 
	{
		arr[i] = new int[k];
		for (int j = 0; j < k; ++j) 
		{
			cout << "введите значение элемента с индексом [" << i << "][" << j << "]\n";
			arr[i][j] = getelem();
		}
	}

	cout << "\nисходный массив\n";
	array_output(n, k, arr);

	int count = 0;
	for (int i = 0; i < n; ++i) 
	{
		for (int j = 1; j < k; j += 2) 
		{
			if (arr[i][j] % 2 != 0) 
			{
				++count;
			}
		}
	}

	if (count > 0) 
	{
		int* arr1 = new int[count];
		int l = -1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 1; j < k; j += 2)
			{
				if (arr[i][j] % 2 != 0)
				{
					++l;
					arr1[l] = arr[i][j];
				}
			}
		}

		cout << "новый массив из элементов, расположенных в четных столбцах исходного массива и имеющих нечетное значение\n";
		for (int i = 0; i < count; ++i) 
		{
			cout << setw(4) << arr1[i];
		}

		cout << "\nсреднее арифметическое равно " << average(count, arr1) << "\n";

		delete[] arr1;
		arr1 = nullptr;
	}
	else 
	{
		cout << "в четных столбцах элементов с нечетным значением нет\n";
	}

	for (int i = 0; i < n; ++i)
	{
		delete[] arr[i];
		arr[i] = nullptr;
	}

	delete[] arr;
	arr = nullptr;

	return 0;
}