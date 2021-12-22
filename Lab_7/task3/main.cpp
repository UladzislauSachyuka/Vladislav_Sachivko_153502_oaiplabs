#include "task3.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "введите первое число\n";
	int num1 = getinput();
	cout << "введите второе число\n";
	int num2 = getinput();
	int n = 1001;
	char* arr1 = new char[n];
	char* arr2 = new char[n];
	char* add = new char[n];
	int len1, len2;
	binary(arr1, num1, len1);
	binary(arr2, num2, len2);
	if (num1 < 0)
		dop_code(arr1, len1);
	if (num2 < 0)
		dop_code(arr2, len2);

	addition(arr1, arr2, add, len1, num1, num2);

	delete[] arr1;
	arr1 = nullptr;
	delete[] arr2;
	arr2 = nullptr;
	delete[] add;
	add = nullptr;

	return 0;
}