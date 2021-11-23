#include "pch.h"
#include "task5_dynamic_lib_.h"
#include <utility>
#include <limits.h>

#include <iostream>
#include <iomanip>

using namespace std;

extern "C" int _declspec(dllexport) getinput() 
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

extern "C" int _declspec(dllexport) getelem() 
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

extern "C" void _declspec(dllexport) array_output(int n, int k, int** arr) 
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

extern "C" double _declspec(dllexport) average(int count, int* arr1) 
{
	int sum = 0;
	for (int i = 0; i < count; ++i)
	{
		sum += arr1[i];
	}
	return sum / count;
}