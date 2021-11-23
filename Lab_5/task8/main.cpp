#include "task8.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Пусть f(n) - наибольший нечетный делитель натурального числа n. По заданному "
		<< "натуральному n необходимо вычислить значение суммы f(1) + f(2) + ... + f(n).\n\n";
	cout << "введите натуральное число n\n";
	int n;
	while (true)
	{
		n = getinput();
		cout << func(n) << "\n\n";
	}

	return 0;
}