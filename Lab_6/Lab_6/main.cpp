#include "task1.h"


int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Дана строка символов, состоящая из цифр, разделенных пробелами.Вывести на "
		<< "экран числа этой строки в порядке возрастания их значений.\n\n";

	cout << "Введите строку\n";
	char str[80];
	cin.getline(str, 80);

	cout << "\nИсходная строка: " << str;

	for (int i = 0; i < length(str) - 1; i += 2)
	{
		int smallestindex = i;
		for (int currentindex = i + 2; currentindex < length(str); currentindex += 2)
		{
			if (symbol(str[currentindex]) < symbol(str[smallestindex]))
			{
				char temp = str[currentindex];
				str[currentindex] = str[smallestindex];
				str[smallestindex] = temp;
			}
		}
	}

	cout << "\n\nЧисла этой строки в порядке возрастания: " << str << "\n";

	return 0;
}