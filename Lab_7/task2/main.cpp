#include "task2.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Программа переводит числа из естественной формы в прямой код\n\n";
	cout << "введите число\n";
	double num = getinput();

	int n = 1001;
	char* arr = new char[n];

	int k = fabs(num);
	int i = 0;
	while (k != 0)
	{
		arr[i] = into_symbol(k % 2);
		k /= 2;
		++i;
	}
	if (num < 0)
	{
		if (int(num) == 0)
		{
			arr[i] = '0';
			++i;
		}
		arr[i] = '1';
	}
	else
	{
		if (int(num) == 0)
		{
			arr[i] = '0';
			++i;
		}
		arr[i] = '0';
	}

	for (int l = 0; l < (i + 1) / 2; ++l)
	{
		char temp = arr[l];
		arr[l] = arr[i - l];
		arr[i - l] = temp;
	}
	if (num - int(num) > 0)
	{
		arr[i + 1] = '.';
		i += 2;
	}
	else
		++i;


	double fractional_part = fabs(num) - int(fabs(num));
	int count = 0;
	while (true)
	{
		if (count > 16)
		{
			break;
		}
		if (fractional_part == 1 || fractional_part == 0)
		{
			arr[i] = '1';
			break;
		}
		arr[i] = into_symbol(int(fractional_part * 2));
		fractional_part = fractional_part * 2 - int(fractional_part * 2);
		++i;
		++count;
	}

	arr[i] = '\0';
	cout << arr << '\n';

	delete[] arr;
	arr = nullptr;

	return 0;
}