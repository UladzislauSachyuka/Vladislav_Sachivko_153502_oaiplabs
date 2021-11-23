#include <iostream>
#include <iomanip>

using namespace std;

int getelement()
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
		if (input < 2)
		{
			cout << "Некорректный ввод. Попробуйте еще раз.\nВведите значение\n ";
		}
	} while (input < 2);

	return input;
}

int main() 
{
	setlocale(LC_ALL, "rus");
	cout << "введите размер массива\n";
	int n = getinput();
	int* arr = new int[n];

	for (int i = 0; i < n; ++i) 
	{
		cout << "введите элемент с индексом [" << i << "]\n";
		arr[i] = getelement();
	}

	cout << "исходный массив\n";
	for (int i = 0; i < n; ++i) 
	{
		cout << arr[i] << " ";
	}
	cout << "\n";

	int max = -2147483647;
	int k = 0;
	for (int i = 0; i < n; ++i) 
	{
		if (arr[i] > max) 
		{
			max = arr[i];
			k = i;
		}
	}

	int min = 2147483647;
	int m = 0;
	for (int i = 0; i < n; ++i) 
	{
		if (arr[i] < min) 
		{
			min = arr[i];
			m = i;
		}
	}

	int r = 0;
	if (k > m) 
	{
		for (m + 1; m + 1 < k; ++m) 
		{
			arr[m + 1] = 0;
			r++;
		}
	}
	else if (k < m) 
	{
		for (k + 1; k + 1 < m; ++k)
		{
			arr[k + 1] = 0;
			r++;
		}
	}
	
	cout << "второй массив\n";
	for (int k = 0; k < n; ++k)
	{
		cout << arr[k] << " ";
	}
	cout << "\n";

	if (2 * r > n)
	{
		int* arr1 = new int[n - r];
		for (int i = 0, k = 0; i < n; ++i)
		{
			if (arr[i] != 0)
			{
				arr1[k] = arr[i];
				k++;
			}
		}
		cout << "третий массив\n";
		for (int k = 0; k < n - r; ++k)
		{
			cout << arr1[k] << " ";
		}

		delete[] arr1;
		arr1 = nullptr;
	}

	delete[] arr;
	arr = nullptr;

	return 0;
}