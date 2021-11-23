// Лабораторная 5, задача 7. Выполнил Сачивко В.Г.
// Рекурсивная функция, которая высчитывает x

#include "task7.h"

unsigned long long result(unsigned long long k, unsigned long long n, unsigned long long m)
{
	if (!n) 
	{
		return 1;
	}
	if (n % 2) 
	{
		return (k * result((k * k) % m, n / 2, m)) % m;
	}
	else
	{
		return result((k * k) % m, n / 2, m); 
	}
}

unsigned long long getinput(bool check, int max_)
{
	unsigned long long input;

	do
	{
		cin >> input;

		while (cin.get() != '\n')
		{
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "Некорректный ввод. Попробуйте еще раз\n";
			cin >> input;
		}

		if (input < 0 && input >= max_ && check)
			cout << "Некорректный ввод. Попробуйте еще раз\n";

	} while (input < 0 && input >= max_ && check);

	return input;
}

