// Лабораторная 6, задача 1. Выполнил Сачивко В.Г.
/*Дана строка символов, состоящая из цифр, разделенных пробелами. Вывести на
экран числа этой строки в порядке возрастания их значений.*/

#include "task1.h"

int length(char* arr) 
{
	int length = 0;
	while (arr[length] != '\0')
	{
		++length;
	}
	return length;
}

int symbol(char st) 
{
	return st - '0';
}

