#include <iostream>
using namespace std;

int main()
{
	int  i, n, k, z = 0;
	setlocale(LC_ALL, "rus");

	cout << "Введите длину массива.\n";
	do
	{
		cin >> n;
		while (cin.get() != '\n')
		{
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "Некорректный ввод.\nВведите длину массива.\n ";
			cin >> n;
		}
		if (n <= 1 || n > 25)
		{
			cout << "Некорректный ввод.\nВведите длину массива.\n ";
		}
	} while (n <= 1 || n > 25);

	int* a = new int[n];
	for (i = 0; i < n; ++i)
	{
		a[i] = rand() % 10;
	}
	cout << "Исходный массив :\n";
	for (i = 0; i < n; ++i)
	{
		cout << a[i] << "\t";
	}
	cout << "\n";

	for (i = 0; i < n; i++)
	{
		for (k = i + 1; k < n; k++)
		{
			if (a[i] == a[k])
			{
				a[k] = 10;
				z++;
			}
		}
	}

	cout << "Массив после изменений :\n";
	for (i = 0; i < n; i++)
	{
		if (a[i] < 10)
		{
			cout << a[i] << "\t";
		}
	}
	cout << "\n";

	delete[] a;

	return 0;
}