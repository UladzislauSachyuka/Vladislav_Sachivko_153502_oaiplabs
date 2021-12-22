#include "task6.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Программа находит количество интересных чисел до заданного числа\n\n";
	cout << "введите количество наборов входных данных\n";
	int n = getinput();
	int* arr = new int[n];
	cout << "введите числа\n";
	for (int i = 0; i < n; ++i)
	{
		arr[i] = getinput();
	}

	int* arr1 = new int[n];
	for (int i = 0; i < n; ++i)
	{
		arr1[i] = interesting(arr[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		cout << '\n' << arr1[i];
	}

	delete[] arr;
	arr = nullptr;
	delete[] arr1;
	arr1 = nullptr;

	return 0;
}