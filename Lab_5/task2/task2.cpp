// Лабораторная 5, задача 2. Выполнил Сачивко В.Г.
/*Для заданного одномерного массива С из N элементов найти произведение
множителей, вычисляемых по формуле sinCi - cosCi. Рекурсивную функцию
применять каждый раз отдельно для первой трети массива и для остальной части (2/3)
массива. Рекурсивные вызовы заканчивать, когда останется только один или два
элемента.*/


#include "task2.h"


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
		if (input < 3)
		{
			cout << "Некорректный ввод. Попробуйте еще раз.\nВведите значение\n ";
		}
	} while (input < 3);

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

double func(int* arr, int i, int n)  
{
	double elem = sin(arr[i]) - cos(arr[i]);
	if (i == n) 
	{
		return elem;
	}
	else
	{
		++i;
		return elem * func(arr, i, n);
	}
}

/*int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Для заданного одномерного массива С из N элементов найти произведение "
		<< "множителей, вычисляемых по формуле sinCi - cosCi.\nРекурсивную функцию "
		<< "применять каждый раз отдельно для первой трети массива и для остальной части(2 / 3) "
		<< "массива.\nРекурсивные вызовы заканчивать, когда останется только один или два "
		<< "элемента.\n\n";


	cout << "введите количество элементов массива\n";
	int n = getinput();
	
	int* arr = new int[n];
	for (int i = 0; i < n; ++i) 
	{
		cout << "введите элемент с индексом " << i << "\n";
		arr[i] = getelem();
	}

	double prod = func(arr, 0, n / 3);
	prod = prod * func(arr, n / 3 + 1, n - 1);
	cout << "произведение множителей = " << prod << "\n";

	delete[] arr;
	arr = nullptr;

	return 0;
}*/