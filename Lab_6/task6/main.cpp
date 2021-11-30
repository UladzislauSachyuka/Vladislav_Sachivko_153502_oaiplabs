#include "task6.h"

int main()
{
	cout << "the program outputs the number of different "
		"anagrams that can be obtained from the entered word\n\n";
	cout << "enter the word:\n";

	char* str = new char[80];
	cin.getline(str, 80);

	int elements = 0;
	for (int i = 0; i < 256; ++i)
	{
		int s = 0;
		for (int j = 0; j < length(str); ++j)
		{
			if (char(i) == str[j])
			{
				++s;
			}
		}

		if (s > 1)
		{
			++elements;
		}
	}

	int* arr = new int[elements];

	int k = 0;
	for (int i = 0; i < 256; ++i)
	{
		int s = 0;
		for (int j = 0; j < length(str); ++j)
		{
			if (char(i) == str[j])
			{
				++s;
			}
		}

		if (s > 1)
		{
			arr[k] = s;
			++k;
		}
	}

	int prod = 1;
	for (int i = 0; i < elements; ++i)
	{
		prod *= factorial(arr[i]);
	}

	int count = factorial(length(str)) / prod;

	cout << "The number of different anagrams is equal to " << count << '\n';

	delete[] str;
	str = nullptr;
	delete[] arr;
	arr = nullptr;


	return 0;
}