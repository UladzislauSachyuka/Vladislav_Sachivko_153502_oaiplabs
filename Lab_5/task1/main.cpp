#include "task1.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "������������ ��������� ������������ ������-������� � ������������ "
		<< "n * n(n = 10), ������ �������� aij ���������� �������� ��������� : "
		<< "a[i][j] = 2ij ^ 2 - 2j, ���� i <= 5, � 3ij - 3, ���� i > 5 "
		<< "��� i = 1, 2, ...n, j = 1, 2, ..., n.\n"
		<< "������������ ����������������� ������� B = A(T)."
		<< "���������� ����� ��������� ������ ����� � �������� �������� ��� ������� - "
		<< "������� � � ����� ������ �������� � �������� ����� ��� ������� - ������� �.�� ����� "
		<< "������� ������� - ������� � � � \n��������� � �������� ����.������������ �������.\n\n";

	int n = 10;
	int** arr = new int* [n] {0};
	initial_arr(n, arr);

	int** arr1 = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		arr1[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			arr1[i][j] = arr[j][i];
		}
	}

	cout << "\n";

	for (int i = 0; i < n; ++i)
	{
		output(n, arr, arr1);
	}

	/*int sum1 = 0;
	for (int i = 1; i < n; i += 2)
	{
		for (int j = 0; j < n; j += 2)
		{
			sum1 += arr[i][j];
		}
	}

	int sum2 = 0;
	for (int i = 0; i < n; i += 2)
	{
		for (int j = 1; j < n; j += 2)
		{
			sum2 += arr1[i][j];
		}
	}*/

	cout << "\n����� ��������� ������ ����� � �������� �������� ��� �������-������� � = " << sum(1, 0, n, arr);
	cout << "\n����� ��������� �������� ����� � ������ �������� ��� �������-������� B = " << sum(0, 1, n, arr1) << "\n";

	for (int i = 0; i < n; ++i)
	{
		delete[] arr[i];
		delete[] arr1[i];
		arr[i] = nullptr;
		arr1[i] = nullptr;
	}

	delete[] arr;
	arr = nullptr;
	delete[] arr1;
	arr1 = nullptr;

	return 0;
}