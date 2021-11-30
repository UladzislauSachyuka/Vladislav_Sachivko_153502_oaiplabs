// Лабораторная 6, задача 6. Выполнил Сачивко В.Г.
/*Анаграммой слова называется любая перестановка всех букв слова.
Например, из слова SOLO можно получить 12 анаграмм: SOLO, LOSO,
OSLO, OLSO, OSOL, OLOS, SLOO, LSOO, OOLS, OOSL, LOOS,
SOOL.
Напишите программу, которая выводит количество различных
анаграмм, которые могут получиться из этого слова.*/

#include "task6.h"

int length(char* arr) 
{
	int i = 0;
	while (arr[i] != '\0') 
	{
		++i;
	}
	return i;
}

int factorial(int n) 
{
	if (n == 1) 
	{
		return 1;
	}
	return n * factorial(n - 1);
}

