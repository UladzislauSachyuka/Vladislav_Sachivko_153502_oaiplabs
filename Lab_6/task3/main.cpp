#include "task3.h"

int main()
{
	cout << "Enter an array of strings. In the function, check for each row "
		<< "whether it is symmetric or not\n\n";

	cout << "enter the number of strings:\n";
	int n = getinput();

	cout << "\nenter the strings\n";

	char** arr = new char* [n];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = new char[80];
		cin.getline(arr[i], 80);
	}

	cout << "\n";

	int j;
	for (int i = 0; i < n; ++i)
	{
		symmetric_string(arr[i], j);
	}

	for (int i = 0; i < n; ++i)
	{
		delete[] arr[i];
		arr[i] = nullptr;
	}
	delete[] arr;
	arr = nullptr;

	return 0;
}