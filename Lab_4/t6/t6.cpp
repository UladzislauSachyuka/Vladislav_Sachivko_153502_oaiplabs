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
		if (input < 1)
		{
			cout << "Некорректный ввод. Попробуйте еще раз.\nВведите значение\n ";
		}
	} while (input < 1);

	return input;
}

void newmatrix(int N, int M, int i, int j, int** arr) 
{
	if (i > 0 && j > 0) 
	{
		if ((arr[i][j] < arr[i - 1][j]) || (arr[i][j] < arr[i][j - 1])) 
		{
			if (arr[i - 1][j] > arr[i][j - 1]) 
			{
				arr[i][j] = arr[i - 1][j];
			}
			else 
			{
				arr[i][j] = arr[i][j - 1];
			}
		}
	}
	else if (i == 0 && j > 0) 
	{
		if (arr[i][j] < arr[i][j - 1]) 
		{
			arr[i][j] = arr[i][j - 1];
		}
	}
	else if (i > 0 && j == 0) 
	{
		if (arr[i][j] < arr[i - 1][j]) 
		{
			arr[i][j] = arr[i - 1][j];
		}
	}
}

void output_matrix(int N, int M, int** arr) 
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << setw(4) << arr[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

int main()
{
	setlocale(LC_ALL, "rus");

	cout << "введите количество строк матрицы\n";
	int N = getinput();
	cout << "введите количество столбцов матрицы\n";
	int M = getinput();

	int** arr = new int* [N];
	for (int i = 0; i < N; ++i)
	{
		arr[i] = new int[M];
		for (int j = 0; j < M; ++j)
		{
			cout << "введите элемент с индексом [" << i << "][" << j << "]\n";
			arr[i][j] = getelement();
		}
	}

	cout << "исходная матрица\n";
	
	output_matrix(N, M, arr);

	cout << "\nновая матрица\n";

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			 newmatrix(N, M, i, j, arr);
		}
	}

	output_matrix(N, M, arr);

	for (int i = 0; i < N; ++i)
	{
		delete[] arr[i];
		arr[i] = nullptr;
	}

	delete[] arr;
	arr = nullptr;



	return 0;
}