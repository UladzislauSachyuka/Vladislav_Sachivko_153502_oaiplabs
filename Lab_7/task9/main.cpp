#include "task9.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "введите натуральное число\n";
	int n = getinput();
	int k = 1001;
	char* arr = new char[k];
	int i = 0;
	while (n != 0)
	{
		arr[i] = char(48 + n % 3);
		n /= 3;
		++i;
	}
	arr[i] = '\0';

	int size = length(arr);
	for (int j = 0; j < size / 2; ++j)
	{
		int temp = arr[j];
		arr[j] = arr[size - 1 - j];
		arr[size - 1 - j] = temp;
	}

	for (int j = size - 1; j > 0; --j)
	{
		if (arr[j] == '0')
		{
			arr[j] = '3';
			while (arr[j - 1] == '0' && j - 1 >= 0)
			{
				arr[j - 1] = '2';
				--j;
			}
			arr[j - 1] = char(48 + int(arr[j - 1] - '0') - 1);
		}
	}

	i = 0;
	while (arr[i] == '0')
	{
		to_the_left(arr, size);
		--size;
	}

	cout << arr << '\n';

	return 0;
}