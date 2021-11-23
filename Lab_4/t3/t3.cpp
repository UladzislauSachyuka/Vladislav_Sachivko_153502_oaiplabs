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

int main() 
{
	setlocale(LC_ALL, "rus");

	cout << "введите порядок матрицы N\n";
	int N = getinput();
	int** arr = new int* [N];

	for (int i = 0; i < N; ++i) 
	{
		arr[i] = new int[N];
		for (int j = 0; j < N; ++j) 
		{
			cout << "введите элемент с индексом [" << i << "][" << j << "]\n";
			arr[i][j] = getelement();
		}
	}

	cout << "\nисходная матрица\n";

	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			cout << setw(4) << arr[i][j];
		}
		cout << "\n";
	}

	int* sum = new int[2 * N]{};
	int pos = 0;

	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			sum[pos] = sum[pos] + arr[i][j];
		}
		pos++;
	}

	for (int j = 0; j < N; ++j) 
	{
		for (int i = 0; i < N; ++i) 
		{
			sum[pos] = sum[pos] + arr[i][j];
		}
		pos++;
	}

	//int value = sum[0];
	for (int i = 0; i < N - 1; ++i) 
	{
		if (sum[i + 1] != sum[i])
		{
			cout << "эта матрица не является магическим квадратом\n";
			break;
		}
		else if (sum[i + 1] == sum[i])
		{
			if (i == N - 2) 
			{
				cout << "эта матрица является магическим квадратом\n";
			}
			continue;
		}
	}

	for (int i = 0; i < N; ++i) 
	{
		delete[] arr[i];
		arr[i] = nullptr;	
	}

	delete[] arr;
	arr = nullptr;
	delete[] sum;
	sum = nullptr;

	return 0;
}