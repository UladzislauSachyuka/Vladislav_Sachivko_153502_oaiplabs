// Лабораторная 7, задача 6. Выполнил Сачивко В.Г.

#include "task6.h"

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
			cout << "Некорректный ввод. Попробуйте еще раз. Введите значение\n";
			cin >> input;
		}
		if (input < 1 || input > 1000000000)
		{
			cout << "Некорректный ввод. Попробуйте еще раз. Введите значение\n";
		}
	} while (input < 1 || input > 1000000000);

	return input;
}

int interesting(int k) 
{
	return (k + 1) / 10;
}

