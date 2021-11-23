// Лабораторная 4, задача 10. Выполнил Сачивко В.Г. 

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int i, k = 0;
	cout << "Построение магического квадрата нечётного порядка методом террас.\n";

	cout << "Введите порядок магического квадрата.\n";
	int l;
	do
	{
		cin >> l;
		while (cin.get() != '\n')
		{
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "Некорректный ввод.\nВведите порядок магического квадрата.\n ";
			cin >> l;
		}
		if (l < 3 || l > 15 || l % 2 == 0)
		{
			cout << "Некорректный ввод.\nВведите порядок магического квадрата.\n ";
		}
	} while (l < 3 || l > 15 || l % 2 == 0);

	int n = 2 * l - 1, t = 1, m = 0;
	int** a;
	a = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		a[i] = (int*)calloc(n, sizeof(int));
	}

	for (i = n / 2; true;)
	{
		for (k; i >= m;)
		{
			a[i][k] = t;
			t++;
			i--;
			k++;
		}
		if (k == n)
		{
			break;
		}
		m++;
		i = n / 2 + m;
		k = m;
	}

	int g = (n - l) / 2;
	for (i = 0; i < n; i++)
	{
		for (k = 0; k < n; k++)
		{
			if (a[i][k] != 0)
			{
				if (k < g)
				{
					a[i][k + l] = a[i][k];
				}
				else if (i < g)
				{
					a[i + l][k] = a[i][k];
				}
				else if (i >= n - g)
				{
					a[i - l][k] = a[i][k];
				}
				else if (k >= n - g)
				{
					a[i][k - l] = a[i][k];
				}
			}
		}
	}
	cout << "Магический квадрат :\n";
	for (int i = g; i < n - g; i++)
	{
		for (int k = g; k < n - g; k++)
		{
			cout << a[i][k] << "\t";
		}
		cout << "\n\n";
	}

	for (int i = 0; i < n; i++)
	{
		free(a[i]);
	}
	free(a);

	return 0;
}