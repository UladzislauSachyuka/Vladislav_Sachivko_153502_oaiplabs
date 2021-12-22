#include "task1.1.h"

int length(char* arr) 
{
	int length = 0;
	while (arr[length] != 0) 
	{
		++length;
	}
	return length;
}

int into_number(char st) 
{
	return st - '0';
}

char into_symbol(int s) 
{
	return 48 + s;
}

int val(char* arr, int value, int i, int len) 
{
	for (i; i < len; ++i)
	{
		value += into_number(arr[i]) * pow(9, len - 1 - i);
	}
	return value;
}

