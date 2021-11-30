// Лабораторная 6. Задача 3. Выполнил Сачивко В.Г.
/*9.Ввести массив строк. В функции для каждой строки
проверить, является она симметричной или нет. (Симметричной считается
строка, которая одинаково читается слева направо и справа налево).
Вывести на экран саму строку и результат её обработки. Стандартных
функций работы со строками не использовать.*/

#include "task3.h"

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
			cout << "Incorrect input. Try again.\nEnter the value\n ";
			cin >> input;
		}
		if (input < 1)
		{
			cout << "Incorrect input. Try again.\nEnter the value\n ";
		}
	} while (input < 1);

	return input;
}

int length(char* str) 
{
	int len = 0;
	while (str[len] != '\0') 
	{
		++len;
	}
	return len;
}

void symmetric_string(char* str, int& j) 
{
	int l = 0;
	j = 0;
	if (length(str) % 2 == 0)
	{
		j = length(str) / 2 - 1;
		l = length(str) / 2;
	}
	else
	{
		j = length(str) / 2 - 1;
		l = length(str) / 2 + 1;
	}
	bool flag = true;
	for (j, l; j >= 0, l <= length(str) - 1; --j, ++l)
	{
		if (str[j] != str[l])
		{
			cout << str << " is not symmetrical\n";
			flag = false;
			break;
		}
	}

	if (flag)
	{
		cout << str << " is symmetrical\n";
	}
}

