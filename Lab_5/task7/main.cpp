#include "task7.h"

int main()
{
	setlocale(LC_ALL, "rus");

	cout << "Рекурсивная функция задана следующим образом:\n"
		<< "f(0, 0) = 1\n"
		<< "f(n, r) = сумма значений функции f(n-1, r-i), где i от 0 до n*(k-1),после которой затем находится сумма mod m\n"
		<< "где m = 10^t."
		<< "С клавиатуры вводятся числа k, n, t. Их возможные значения:\n 0 < k < 10^19, 0 < n < 10^19 0 < t < 10\n\n";

	unsigned long long k, n, t, m;
	int occasion = 0;

	while (true)
	{
		cout << "Введите k\n";
		k = getinput(true, pow(10, 19));

		cout << "Введите n\n";
		n = getinput(true, pow(10, 19));

		cout << "Введите t\n";
		t = getinput(true, 10);

		if (k == 0 && n == 0 && t == 0)
		{
			return 0; // место где мы должны завершить программу
		}

		m = pow(10, t);

		++occasion;

		cout << "Case #" << occasion << ": " << result(k % m, n, m) << "\n";
	}

	return 0;
}