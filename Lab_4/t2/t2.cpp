// Лабораторная 4, задача 2. Выполнил Сачивко В.Г.
// Вариант 9
#include <iostream>
#include <iomanip>

using namespace std;

/*int getinput()
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
}*/

int main() 
{
	setlocale(LC_ALL, "rus");
	const int N = 3, M = 4;

	int arr[N][M] = 
	{
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};


	/*for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j) 
		{
			cout << "введите элемент массива с индексом [" << i << "][" << j << "]" << endl;
			arr[i][j] = getinput();
		}
	}*/

	cout << "исходный массив\n";

	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			cout << setw(4) << arr[i][j];
		}
		cout << "\n";
	}
	cout << "\n";

	int max_value = -2147483647;
	for (int i = 0, j = 0; j < M - 2; ++j) 
	{
		if (arr[i][j] > max_value) 
		{
			max_value = arr[i][j];
		}
	}
	
	for (int i = 1, j = 0; j < 1; j++) 
	{
		if (arr[i][j] > max_value) 
		{
			max_value = arr[i][j];
		}
	}

	cout << "максимальный элемент, лежащий выше побочной диагонали равен " << max_value << "\n";

	return 0;
}
