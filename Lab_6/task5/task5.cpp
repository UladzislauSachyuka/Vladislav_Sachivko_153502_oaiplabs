// Лабораторная 6. Задача 5. Выполнил Сачивко В.Г.
/*Во многих прикладных задачах, таких как поиск в сети или расшифровка
генома, требуется совершать некоторые действия со строками. Например,
часто требуется по некоторым данным о строке восстановить ее саму.
Вам даны две строки S1 и S2. Известно, что одна из них была суффиксом
искомой строки S, а другая — ее префиксом. Также известна длина искомой
строки L, а также то, что строка S состояла только из строчных букв
латинского алфавита.
Необходимо определить число строк, удовлетворяющих этим
ограничениям. Так как это число может быть достаточно большим, то
необходимо вывести его по модулю m.*/

#include "task5.h"

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

int strings(string str1, string str2, int l, int m) 
{
	unsigned long long k;
	if (str1.length() + str2.length() < l)
	{
		if (str1 == str2)
		{
			k = pow(26, l - str1.length() - str2.length());
		}
		else
		{
			k = pow(26, l - str1.length() - str2.length()) * 2;
		}
		return k % m;
	}
	else if (str1.length() + str2.length() == l)
	{
		if (str1 == str2)
		{
			return 1 % m;
		}
		else
		{
			return 2 % m;
		}
	}
	else if (str1.length() + str2.length() - l <= str1.length() || str1.length() + str2.length() - l <= str2.length())
	{
		string arr1, arr2, arr3, arr4;
		int count;
		count = str1.length() + str2.length() - l;
		for (int i = str1.length() - count; i < str1.length(); ++i)
		{
			arr1 += str1[i];
		}
		for (int i = 0; i < count; ++i)
		{
			arr2 += str2[i];
		}
		for (int i = str2.length() - count; i < str2.length(); ++i)
		{
			arr3 += str2[i];
		}
		for (int i = 0; i < count; ++i)
		{
			arr4 += str1[i];
		}
		if (str1 == str2)
		{
			return 1 % m;
		}
		else if (arr1 == arr2 && arr3 == arr4)
		{
			if (arr4 == arr1 || arr2 == arr3)
			{
				return 1 % m;
			}
			else
			{
				return 2 % m;
			}
		}
		else if (arr1 == arr2 || arr3 == arr4)
		{
			return 1 % m;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
	return 0;
}

