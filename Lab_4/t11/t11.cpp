#include <iostream>
#include <iomanip>

using namespace std;

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

int max(int a, int b) 
{
	if (a > b) 
	{
		return a;
	}
	else if ((a == b) || (a < b))
	{
		return b;
	}
}

int main() 
{
	setlocale(LC_ALL, "rus");
	cout << "введите размер n трехмерного массива\n";
	int n = getinput();
	srand(time(0));

	int*** arr = new int** [n];
	for (int i = 0; i < n; ++i) 
	{
		arr[i] = new int* [n];
		for (int j = 0; j < n; ++j) 
		{
			arr[i][j] = new int[n];
			for (int k = 0; k < n; ++k) 
			{
				arr[i][j][k] = rand() % 100;
			}
		}
	}

	int sum1 = 0;
	for (int i = 0, j = 0, k = 0; i < n; ++i, ++j, ++k) 
	{
		sum1 += arr[i][j][k];
	}

	int sum2 = 0;
	for (int i = n - 1, j = 0, k = 0; i >= 0; --i, ++j, ++k) 
	{
		sum2 += arr[i][j][k];
	}

	int sum3 = 0;
	for (int i = 0, j = 0, k = n - 1; i < n; ++i, ++j, --k) 
	{
		sum3 += arr[i][j][k];
	}

	int sum4 = 0;
	for (int i = 0, j = n - 1, k = 0; i < n; ++i, --j, ++k) 
	{
		sum4 += arr[i][j][k];
	}

	//int arr1[4] = { sum1, sum2, sum3, sum4 };
	int max_value = max(sum1, sum2);
	max_value = max(max_value, sum3);
	max_value = max(max_value, sum4);
	

	if (sum1 == max_value) 
	{
		cout << "сумма первой диагонали наибольшая, она равна " << max_value << "\n";
	}
	else if (sum2 == max_value)
	{
		cout << "сумма второй диагонали наибольшая, она равна " << max_value << "\n";
	}
	else if (sum3 == max_value)
	{
		cout << "сумма третьей диагонали наибольшая, она равна " << max_value << "\n";
	}
	else if (sum4 == max_value)
	{
		cout << "сумма четвертой диагонали наибольшая, она равна " << max_value << "\n";
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j) 
		{
			delete[] arr[i][j];
			arr[i][j] = nullptr;
		}
		delete[] arr[i];
		arr[i] = nullptr;
	}

	delete[] arr;
	arr = nullptr;

	return 0;
}