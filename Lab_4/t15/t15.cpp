#include <iostream>

using namespace std;

int getinput(int a = 28, int b = 2)
{
	int n;
	do
	{
		cin >> n;
		while (cin.get() != '\n')
		{
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "Некорректный ввод.\nВведите число.\n ";
			cin >> n;
		}
		if (n < b || n > a)
		{
			cout << "Некорректный ввод.\nВведите число.\n ";
		}
	} while (n < b || n > a);
	return n;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int i, n, k, m = 1, l = 1, z;
	
	cout << "Введите размер таблицы.\n";
	n = getinput();
	int** a = new int* [n];
	for (i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}

	i = 0, k = 1;
	a[0][0] = 1;
	bool e = true;
	while (m < n)
	{
		if (i <= m && e)
		{
			l++;
			a[i][k] = l;
			i++;
		}
		else if (k >= 0)
		{
			l++;
			k--;
			a[i - 1][k] = l;
		}
		if (i > m)
		{
			e = false;
			if (k == 0)
			{
				i = 0;
				e = true;
				m++;
				k = m;
			}
		}
		if (k == n)
			break;
	}

	cout << "Таблица : \n";
	for (i = 0; i < n; i++)
	{
		for (k = 0; k < n; k++)
		{
			cout << a[i][k] << "\t";
		}
		cout << "\n\n";
	}

	cout << "Введите число для поиска в таблице.\n";
	z = getinput(a[n - 1][0], 1);
	int ii = 0, kk = 0;
	for (i = 0; i < n; i++)
	{
		for (k = 0; k < n; k++)
		{
			if (z == a[i][k])
			{
				ii = i;
				kk = k;
				goto plum;
			}
		}
	}

plum:
	cout << "Число находится в " << ii << " строке и " << kk << " столбце.\n";

	for (i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;

	return 0;
}