#include "task8.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "����� f(n) - ���������� �������� �������� ������������ ����� n. �� ��������� "
		<< "������������ n ���������� ��������� �������� ����� f(1) + f(2) + ... + f(n).\n\n";
	cout << "������� ����������� ����� n\n";
	int n;
	while (true)
	{
		n = getinput();
		cout << func(n) << "\n\n";
	}

	return 0;
}