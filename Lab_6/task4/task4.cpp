// Лабораторная 6, задача 4. Выполнил Сачивко В.Г.

#include "task4.h"

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

int length(char* arr) 
{
	int i = 0;
	while (arr[i] != '\0') 
	{
		++i;
	}
	return i;
}

bool func(char ch) 
{
	char consonants[] = "BbCcDdFfGgHhJjKkLlMmNnPpQqRrSsTtVvWwXxZz";
	for (int i = 0; i < length(consonants); ++i) 
	{
		if (ch == consonants[i]) 
		{
			return true;
		}
	}
	return false;
}

