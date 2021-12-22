// Лабораторная 7, задача 4. Выполнил Сачивко В.Г.
/*Осуществить сложение и вычитание чисел в в одиннадцатеричной системе
счисления. В другую систему счисления не переводить. В системах
счисления больших десятичной использовать буквы по аналогии с
шестнадцатеричной системой. Разработать функции для выполнения
операции сложения и функции для выполнения операции вычитания.
Предусмотреть ввод положительных и отрицательных чисел.*/

#include "task4.h"

int length(char* arr)
{
	int length = 0;
	while (arr[length] != 0)
	{
		++length;
	}
	return length;
}

bool getinput(char* arr)
{
	for (int i = 0; i < length(arr); ++i)
	{
		if ((int(arr[i]) >= 48 && int(arr[i]) <= 57) || arr[i] == 'A' || arr[0] == '-')
		{

		}
		else
		{
			cout << "Некорректный ввод. Попробуйте еще раз. Введите число\n";
			return true;
		}
	}
	return false;
}

void addition(char* ch1, char* ch2, char* add, int len1, int len2)
{
	if (ch1[len1 - 1] == '-')
	{
		ch1[len1 - 1] = '\0';
		--len1;
	}
	if (ch2[len2 - 1] == '-')
	{	
		ch2[len2 - 1] = '\0';
		--len2;
	}
	int len_add = len1 > len2 ? len1 + 1 : len2 + 1;
	int k, i = 0;
	for (i; i < (len1 > len2 ? len1 : len2); ++i)
	{
		if (i > len2 - 1)
		{
			k = int(ch1[i] - '0');
		}
		else if (i > len1 - 1)
		{
			k = int(ch2[i] - '0');
		}
		else
		{
			k = int(ch1[i] - '0') + int(ch2[i] - '0');
			if (k > 10) 
			{
				k -= 1;
			}
		}
		if (ch1[i] == 'A' && ch2[i] != 'A')
		{
			k = 9 + int(ch2[i] - '0');
		}
		else if (ch2[i] == 'A' && ch1[i] != 'A')
		{
			k = int(ch1[i] - '0') + 9;
		}
		else if (ch1[i] == 'A' && ch2[i] == 'A')
		{
			k = 19;
		}
		if (k == 10)  //////////
		{
			if (ch1[i] == 'A' || ch2[i] == 'A')
			{
				add[i] = char(48 + int(add[i] - '0') + k % 10);
				add[i + 1] = char(48 + 1);
			}
			else
			{
				add[i] = 'A';
			}
		}
		else if (k > 10)
		{
			if (int(add[i] - '0') + k % 10 == 10 || int(add[i] - '0') + k % 10 == 20)
			{
				add[i] = 'A';
			}
			else
			{
				add[i] = char(48 + int(add[i] - '0') + k % 10);
			}
			add[i + 1] = char(48 + 1);
		}
		else
		{
			add[i] = char(48 + int(add[i] - '0') + k);
		}
	}
	if (int(add[i] - '0') > 0 && int(add[i] - '0') < 9) 
		add[i + 1] = '\0';
	else 
		add[i] = '\0';

	if (int(add[len_add - 1] - '0') == 0)
	{
		for (int j = 0; j < len_add - 1; ++j)
		{
			add[j] = add[j + 1];
		}
		--len_add;
	}
	for (int j = len_add - 1; j >= 0; --j)
	{
		cout << add[j];
	}
	cout << '\n';
}

void subtraction(char* ar1, char* ar2, char* subtr, int len1, int len2) 
{
	if (ar1[len1 - 1] == '-')
	{
		ar1[len1 - 1] = '\0';
		--len1;
	}
	if (ar2[len2 - 1] == '-')
	{
		ar2[len2 - 1] = '\0';
		--len2;
	}
	int len_subtr = len1 > len2 ? len1 : len2;
	int k, i = 0;

	for (i; i < (len1 > len2 ? len1 : len2); ++i)
	{
		if (i > len2 - 1)
		{
			k = int(ar1[i] - '0');
		}
		else if (i > len1 - 1)
		{
			k = int(ar2[i] - '0');
		}
		else
		{
			k = int(ar1[i] - '0') - int(ar2[i] - '0');
		}
		if (ar1[i] == 'A' && ar2[i] != 'A')
		{
			k = 10 - int(ar2[i] - '0');
		}
		else if (ar2[i] == 'A' && ar1[i] != 'A')
		{
			k = int(ar1[i] - '0') - 10;
		}
		else if (ar1[i] == 'A' && ar2[i] == 'A')
		{
			k = 0;
		}
		if (k == 10)
		{
			subtr[i] = 'A';
		}
		else if (k < 0)
		{
			if (ar1[i] == '0')
			{
				subtr[i] = char(48 + k + 11);
			}
			else
			{
				if (k + 11 == 10)
				{
					subtr[i] = 'A';
				}
				else
				{
					subtr[i] = char(48 + k + 11);
				}
			}
			int s = i + 1;
			while (ar1[s] == 0)
			{
				ar1[s] = '9';
				++s;
			}
			if (ar1[s] == 'A')
			{
				ar1[s] = '9';
			}
			else
			{
				ar1[s] = char(48 + int(ar1[s] - '0') - 1);
			}
		}
		else
		{
			subtr[i] = char(48 + k);
		}
	}
	subtr[i] = '\0';

	i = len_subtr - 1;
	while (int(subtr[i] - '0') == 0)
	{
		if (len_subtr == 1)
		{
			break;
		}
		for (int j = 0; j < len_subtr - 1; ++j)
		{
			subtr[j] = subtr[j + 1];
		}
		--len_subtr;
	}
	for (int j = len_subtr - 1; j >= 0; --j)
	{
		cout << subtr[j];
	}
	cout << '\n';
}

