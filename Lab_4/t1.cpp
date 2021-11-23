// Лабораторная 4, задача 1. Выполнил Сачивко В.Г.
// Вариант 9
#include <iostream>
#include <iomanip>

using namespace std;

int getinput()  
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
	const int k = 10;
	int j = 0, l = 0;
	int arr[k], new_arr_negative[k], new_arr[k];

	
	//srand(time(0));

	for (int i = 0; i < k; ++i) 
	{
		cout << "Введите элемент массива с индексом " << i << endl;
		//arr[i] = (rand() % 10);
		arr[i] = getinput();
		if (arr[i] < 0)
		{
			new_arr_negative[j] = arr[i];
			j++;
		}
		else 
		{
			new_arr[l] = arr[i];
			l++;
		}
	}

	cout << "\n";
	cout << "Исходный массив\n";
	for (int i = 0; i < k; ++i) 
	{
		cout << setw(4) << arr[i];
	}

	cout << "\n";

	cout << "Новый массив с отрицательными элементами\n";
	for (int i = 0; i < j; ++i)
	{
		cout << setw(4) << new_arr_negative[i];
	}
	cout << "\n";

	cout << "Второй новый массив со всеми остальными элементами\n";
	for (int i = 0; i < l; ++i) 
	{
		cout << setw(4) << new_arr[i];
	}

	return 0;
}