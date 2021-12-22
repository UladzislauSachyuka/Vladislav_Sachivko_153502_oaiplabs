#include "task1.1.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "ѕрограмма переводит числа из дев€теричной в одиннадцатеричную систему счислени€\n\n";
	cout << "введите число в дев€теричной системе счислени€\n";
	int n = 100;
	char* num9 = new char[n];
	cin >> num9;
	char* num11 = new char[n];
	int value = 0, i = 0;
	int len = length(num9);
	if (num9[0] == '-')
	{
		++i;
	}
	value = val(num9, value, i, len);

	i = 0;
	while (value / 11 >= 11)
	{
		if (value % 11 == 10)
		{
			num11[i] = 'A';
			value /= 11;
			++i;
			num11[i] = into_symbol(value % 11);
			++i;
			value /= 11;
		}
		num11[i] = into_symbol(value % 11);
		value /= 11;
		++i;
	}
	if (value % 11 == 10)
	{
		num11[i] = 'A';
		value /= 11;
		++i;
		num11[i] = into_symbol(value % 11);
	}
	else
	{
		num11[i] = into_symbol(value % 11);
		num11[i + 1] = into_symbol(value / 11);
		++i;
	}
	if (num9[0] == '-')
	{
		num11[i + 1] = '-';
		num11[i + 2] = '\0';
	}
	else
	{
		num11[i + 1] = '\0';
	}

	int size = length(num11);
	for (i = 0; i < size / 2; ++i)
	{
		int temp = num11[i];
		num11[i] = num11[size - 1 - i];
		num11[size - 1 - i] = temp;
	}

	i = 0;
	while (num11[i] == '0')
	{
		for (int j = 0; j < size; ++j)
		{
			num11[j] = num11[j + 1];
		}
		++i;
	}

	cout << "\nчисло в одиннадцатеричной системе счислени€: " << num11 << '\n';

	delete[] num9;
	num9 = nullptr;
	delete[] num11;
	num11 = nullptr;

	return 0;
}