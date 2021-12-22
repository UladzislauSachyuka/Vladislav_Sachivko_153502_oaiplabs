#include "task7.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Программа проверяет, делится ли введенное пользователем число на заданное простое\n\n";
	cout << "введите число\n";
	long long num = getinput();
	if (divisibility(num, 7))
	{
		cout << "число делится на 7\n";
	}
	else
	{
		cout << "число не делится на 7\n";
	}
	if (divisibility(num, 73))
	{
		cout << "число делится на 73\n";
	}
	else
	{
		cout << "число не делится на 73\n";
	}
	if (divisibility(num, 109))
	{
		cout << "число делится на 109\n";
	}
	else
	{
		cout << "число не делится на 109\n";
	}

	return 0;
}