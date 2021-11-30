// Лабораторная 6, задача 7. Выполнил Сачивко В.Г.
/*В заданной строке S найти максимальную по длине подстроку, которая
не является палиндромом.*/

#include "task7.h"

int length(char* arr) 
{
	int i = 0;
	while (arr[i] != '\0') 
	{
		++i;
	}
	return i;
}

bool identical_letters(char* arr) 
{
	for (int i = 0; i < length(arr); ++i) 
	{
		if (arr[i] != arr[0]) 
		{
			return false;
		}
	}
	return true;
}

bool palindrome(char* arr) 
{
	for (int i = 0; i < length(arr); ++i)
	{
		if (arr[i] != arr[length(arr) - 1 - i])
		{
			return false;
		}
	}
	return true;
}

