#include <iostream>

using namespace std;

int cable(int n, int* a)
{
	int cables, i;
	int* a1 = new int[n];
	a1[0] = a[0];
	for (i = 1; i < n; i++)
	{
		a1[i] = a1[i - 1] + a[i];
	}
	cables = a1[i - 1] - i + 1;
	return cables;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int  i, n, cables;
	
	cout << "Введите количество удлиннителей.\n";
	do
	{
		cin >> n;
		while (cin.get() != '\n')
		{
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "Некорректный ввод.\nВведите количество удлиннителей.\n ";
			cin >> n;
		}
		if (n < 1)
		{
			cout << "Некорректный ввод.\nВведите количество удлиннителей.\n ";
		}
	} while (n < 1);

	int* a = new int[n];
	if (n == 1)
	{
		cables = 1;
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			a[i] = i + 1;
		}
		cables = cable(n, a);
	}
	cout << "Соединив оптимально удлиннители, вы получите " << cables << " розеток(ку/ки). \n";

	delete[] a;

	return 0;
}