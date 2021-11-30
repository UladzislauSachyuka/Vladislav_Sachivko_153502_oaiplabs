#include "task4.h"

int main()
{
	setlocale(LC_ALL, "rus");

	cout << "������� ��������� ������������ ������ ������������ �����.����������,"
		<< "����������� �� ����� ��� �������� � �������\n���������.���� ����������� ����� "
		<< "��������, �� ���������� �� ������� � ����� ����������.����������� �������� ����� "
		<< "\n������� � �������� ������� � ������� �� �����. "
		<< "������������ �������.\n\n";

	cout << "������� ���������� ����� �������\n";
	int n = getinput();
	cout << "������� ���������� �������� �������\n";
	int k = getinput();

	double** arr = new double* [n];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = new double[k];
		for (int j = 0; j < k; ++j)
		{
			cout << "������� �������� �������� � �������� [" << i << "][" << j << "]\n";
			arr[i][j] = getelem();
		}
	}

	cout << "\n�������� ������\n";
	array_output(n, k, arr);

	int count = null_elements(n, k, arr);

	if (count == 0)
	{
		cout << "��������� � ������� ��������� ���\n";
	}
	else
	{
		cout << "\n����� ���������� ��������� � ������� ��������� ����� " << count << "\n\n";
	}

	cout << "������ � ��������������� � �������� ������� ����������\n";
	array_output1(n, k, arr);

	for (int i = 0; i < n; ++i)
	{
		delete[] arr[i];
		arr[i] = nullptr;
	}

	delete[] arr;
	arr = nullptr;

	return 0;
}