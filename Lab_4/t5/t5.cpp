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

double newmatrix(double** arr, int i, int j, int N, int M)
{
	double sum = 0;
	double div = 0;
	for (int k = i - 1; k <= i + 1; k++) 
	{
		for (int g = j - 1; g <= j + 1; g++) 
		{
			if (k == i && g == j || (k > N - 1 || k < 0 || g > M - 1 || g < 0))
			{
				continue;
			}
			sum = sum + arr[k][g];
			++div;
		}								
	}

	return sum / div;
}


int main()
{
	setlocale(LC_ALL, "rus");

	cout << "введите количество строк матрицы\n";
	int N = getinput();
	cout << "введите количество столбцов матрицы\n";
	int M = getinput();

	double** arr = new double* [N];
	for (int i = 0; i < N; ++i)
	{
		arr[i] = new double[M];
		for (int j = 0; j < M; ++j)
		{
			cout << "введите элемент с индексом [" << i << "][" << j << "]\n";
			arr[i][j] = getelement();
		}
	}

	cout << "исходная матрица\n";
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << setw(4) << arr[i][j];
		}
		cout << "\n";
	}

	cout << "\nсглаженная матрица\n";

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << setw(4) << newmatrix(arr, i, j, N, M);
		}
		cout << "\n";
	}

	for (int i = 0; i < N; ++i)
	{
		delete[] arr[i];
		arr[i] = nullptr;
	}

	delete[] arr;
	arr = nullptr;



	return 0;
}