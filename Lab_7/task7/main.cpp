#include "task7.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "��������� ���������, ������� �� ��������� ������������� ����� �� �������� �������\n\n";
	cout << "������� �����\n";
	long long num = getinput();
	if (divisibility(num, 7))
	{
		cout << "����� ������� �� 7\n";
	}
	else
	{
		cout << "����� �� ������� �� 7\n";
	}
	if (divisibility(num, 73))
	{
		cout << "����� ������� �� 73\n";
	}
	else
	{
		cout << "����� �� ������� �� 73\n";
	}
	if (divisibility(num, 109))
	{
		cout << "����� ������� �� 109\n";
	}
	else
	{
		cout << "����� �� ������� �� 109\n";
	}

	return 0;
}