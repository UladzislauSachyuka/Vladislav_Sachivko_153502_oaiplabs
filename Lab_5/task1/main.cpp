#include "task1.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Сформировать двумерный динамический массив-матрицу А размерностью "
		<< "n * n(n = 10), причем значения aij определить согласно выражению : "
		<< "a[i][j] = 2ij ^ 2 - 2j, если i <= 5, и 3ij - 3, если i > 5 "
		<< "при i = 1, 2, ...n, j = 1, 2, ..., n.\n"
		<< "Сформировать транспонированную матрицу B = A(T)."
		<< "Определить сумму элементов четных строк и нечетных столбцов для массива - "
		<< "матрицы А и сумму четных столбцов и нечетных строк для массива - матрицы В.На экран "
		<< "вывести массивы - матрицы А и В \nпострочно и значения сумм.Использовать функции.\n\n";

	int n = 10;
	int** arr = new int* [n] {0};
	initial_arr(n, arr);

	int** arr1 = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		arr1[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			arr1[i][j] = arr[j][i];
		}
	}

	cout << "\n";

	for (int i = 0; i < n; ++i)
	{
		output(n, arr, arr1);
	}

	/*int sum1 = 0;
	for (int i = 1; i < n; i += 2)
	{
		for (int j = 0; j < n; j += 2)
		{
			sum1 += arr[i][j];
		}
	}

	int sum2 = 0;
	for (int i = 0; i < n; i += 2)
	{
		for (int j = 1; j < n; j += 2)
		{
			sum2 += arr1[i][j];
		}
	}*/

	cout << "\nсумма элементов четных строк и нечетных столбцов для массива-матрицы А = " << sum(1, 0, n, arr);
	cout << "\nсумма элементов нечетных строк и четных столбцов для массива-матрицы B = " << sum(0, 1, n, arr1) << "\n";

	for (int i = 0; i < n; ++i)
	{
		delete[] arr[i];
		delete[] arr1[i];
		arr[i] = nullptr;
		arr1[i] = nullptr;
	}

	delete[] arr;
	arr = nullptr;
	delete[] arr1;
	arr1 = nullptr;

	return 0;
}