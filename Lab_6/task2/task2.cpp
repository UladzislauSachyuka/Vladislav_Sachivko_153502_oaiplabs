// Лабораторная 6. Задача 2. Выполнил Сачивко В.Г.
/*Найти, каких букв в тексте больше – гласных или согласных.*/

#include "task2.h"

int length(char* arr) 
{
	int length = 0;
	while (arr[length] != '\0')
	{
		++length;
	}
	return length;
}