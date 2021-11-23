#include <iostream>

using namespace std;

int getinput()
{
	int input;
	do
	{
		cin >> input;
		while (cin.get() != '\n')
		{
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "Некорректный ввод. Попробуйте еще раз.\nВведите значение\n ";
			cin >> input;
		}
		if (input < 1 || input > 2147483647)
		{
			cout << "Некорректный ввод. Попробуйте еще раз.\nВведите значение\n ";
		}
	} while (input < 1 || input > 2147483647);

	return input;
}

int getin(int k)
{
	int input;
	do
	{
		cin >> input;
		while (cin.get() != '\n')
		{
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "Некорректный ввод. Попробуйте еще раз.\nВведите значение\n ";
			cin >> input;
		}
		if (input < 0 || input > 2147483647)
		{
			cout << "Некорректный ввод. Попробуйте еще раз.\nВведите значение\n ";
		}
	} while (input < 0 || input > 2147483647);

	return input;
}

int main() 
{
	setlocale(LC_ALL, "rus");
	cout << "введите натуральное число n\n";
	int n = getinput();
	int g = n;
	int k = 0;
	/*do
	{
		n = n / i;
		i *= 10;
	} while (n % i != n); 
	*/

	while (g) 
	{
		k++;
		g /= 10;
	}

	int* arr = new int[k];
	for (int j = 0; j < k; ++j) 
	{
		arr[k - j - 1] = n % 10;
		n = n / 10;
	}

	cout << "число n имеет " << k << " digits\n\n";

	cout << "введите номер i разряда\n";

	int i = 0;
	i = getin(k);

	cout << "в разряде с номером " << i << " находится цифра " << arr[k - 1 - i];

	delete[] arr;
	arr = nullptr;

	return 0;
}