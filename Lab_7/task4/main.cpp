#include "task4.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "ѕрограмма осуществл€ет сложение и вычитание чисел в одиннадцатеричной системе счислени€\n\n";
	cout << "введите первое число\n";
	int n = 1001;
	char* num1 = new char[n];
	while (true)
	{
		cin >> num1;
		if (getinput(num1)) continue;
		else break;
	}
	cout << "введите второе число\n";
	char* num2 = new char[n];
	while (true)
	{
		cin >> num2;
		if (getinput(num2)) continue;
		else break;
	}

	int len1 = length(num1);
	int len2 = length(num2);
	for (int j = 0; j < len1 / 2; ++j)
	{
		char temp = num1[j];
		num1[j] = num1[len1 - 1 - j];
		num1[len1 - 1 - j] = temp;
	}
	for (int j = 0; j < len2 / 2; ++j)
	{
		char temp = num2[j];
		num2[j] = num2[len2 - 1 - j];
		num2[len2 - 1 - j] = temp;
	}

	char* add = new char[n];
	for (int j = 0; j < n - 1; ++j)
	{
		add[j] = '0';
	}
	char* subtr = new char[n];
	for (int j = 0; j < n - 1; ++j)
	{
		subtr[j] = '0';
	}

	char* arr1 = new char[n];
	for (int i = 0; i < len1; ++i)
	{
		arr1[i] = num1[i];
	}
	char* arr2 = num2;
	for (int i = 0; i < len2; ++i)
	{
		arr2[i] = num2[i];
	}

	if (num1[len1 - 1] != '-' && num2[len2 - 1] != '-')
	{
		addition(num1, num2, add, len1, len2);
		if (len1 >= len2)
			subtraction(arr1, arr2, subtr, len1, len2);
		else
		{
			cout << '-';
			subtraction(arr2, arr1, subtr, len2, len1);
		}
	}
	else if (num1[len1 - 1] != '-' && num2[len2 - 1] == '-')
	{
		if (len1 >= len2 - 1)
			subtraction(num1, num2, subtr, len1, len2);
		else
		{
			cout << '-';
			subtraction(num2, num1, subtr, len2, len1);
		}
		addition(arr1, arr2, subtr, len1, len2);
	}
	else if (num1[len1 - 1] == '-' && num2[len2 - 1] != '-')
	{
		if (len1 - 1 >= len2)
		{
			cout << '-';
			subtraction(num1, num2, subtr, len1, len2);
		}
		else
			subtraction(num2, num1, subtr, len2, len1);
		cout << '-';
		addition(arr1, arr2, add, len1, len2);
	}
	else if (num1[len1 - 1] == '-' && num2[len2 - 1] == '-')
	{
		cout << '-';
		addition(arr1, arr2, add, len1, len2);
		if (len1 >= len2)
		{
			cout << '-';
			subtraction(num1, num2, subtr, len1, len2);
		}
		else
			subtraction(num2, num1, subtr, len2, len1);
	}

	delete[] num1;
	num1 = nullptr;
	delete[] num2;
	num2 = nullptr;
	delete[] add;
	add = nullptr;
	delete[] subtr;
	subtr = nullptr;

	return 0;
}