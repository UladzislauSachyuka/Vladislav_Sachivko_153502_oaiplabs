// Лабораторная 7, задача 10. Выполнил Сачивко В.Г.
/*Патриций решил устроить праздник и для этого приготовил 240
бочек вина. Однако к нему пробрался недоброжелатель, который подсыпал
яд в одну из бочек. Недоброжелателя тут же поймали, дальнейшая его судьба
неизвестна. Про яд известно, что человек, который его выпил, умирает в
течение 24 часов. До праздника осталось два дня, то есть 48 часов. У
патриция есть пять рабов, которыми он готов пожертвовать, чтобы узнать, в
какой именно бочке яд. Каким образом можно это узнать?*/

#include "task10.h"

int decimalSistem(char* poisRes)
{
	int res = 0, tmp = 1;
	for (int i = 4; i >= 0; i--)
	{
		res += (poisRes[i] - '0') * tmp;
		tmp *= 3;
	}
	return res;
}

int func(char* pois)
{
	bool first[] = { 1, 1, 1, 1, 1 };
	cout << "после первого дня: ";
	for (int i = 0; i < 5; i++)
	{
		if (pois[i] == '0')
		{
			first[i] = false;
			cout << '\n' << i + 1 << " раб умер";
		}
	}

	bool alive = true;
	for (int i = 0; i < 5; i++)
		if (first[i] == false)
			alive = false;
	if (alive)
		cout << "никто не умер\n";

	bool Second[] = { 1, 1, 1, 1, 1 };
	cout << "\n\nпосле второго дня\n";
	for (int i = 0; i < 5; i++)
	{
		if (pois[i] == '1')
		{
			Second[i] = false;
			cout << i + 1 << " раб умер\n";
		}
	}
	alive = true;
	for (int i = 0; i < 5; i++)
		if (Second[i] == false)
			alive = false;
	if (alive)
		cout << "\nникто не умер\n";
	char* result = new char[6];
	for (int i = 0; i < 5; i++)
		result[i] = '2';
	result[5] = '\0';
	for (int i = 0; i < 5; i++)
	{
		if (first[i] == false)
			result[i] = '0';
		else if (Second[i] == false)
			result[i] = '1';
	}
	int res = decimalSistem(result);
	delete[] result;
	return res;
}

char* ternarySistem(int poisoned)
{
	char* tmp = new char[6];
	tmp[5] = '\0';
	for (int i = 4; i >= 0; i--)
	{
		tmp[i] = '0' + (poisoned % 3);
		poisoned /= 3;
	}
	return tmp;
}

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
			cout << "Некорректный ввод. Попробуйте еще раз. Введите значение\n";
			cin >> input;
		}
		if (input < 1 || input > 240)
		{
			cout << "Некорректный ввод. Попробуйте еще раз. Введите значение\n";
		}
	} while (input < 1 || input > 240);

	return input;
}

