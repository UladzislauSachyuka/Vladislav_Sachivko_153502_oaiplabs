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

bool isLocalMinimum(int** arr, int i, int j, int N, int M)
{ 
	for (int k = i - 1; k <= i + 1; k++) 
	{
		for (int g = j - 1; g <= j + 1; g++) 
		{
			if (k == i && g == j || (k > N - 1 || k < 0 || g > M - 1 || g < 0))
			{
				continue;
			}
			if (!(arr[i][j] < arr[k][g]))
			{
				return false;
			}
		}								
	}

	return true;
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
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			cout << setw(4) << arr[i][j];
		}
		cout << "\n";
	}

	int count = 0;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			if (isLocalMinimum(arr, i, j, N, M)) 
			{
				++count;
			}
		}
	}

	cout << "количество локальных минимумов равно " << count << "\n";

	for (int i = 0; i < N; ++i)
	{
		delete[] arr[i];
		arr[i] = nullptr;
	}

	delete[] arr;
	arr = nullptr;

	return 0;
}