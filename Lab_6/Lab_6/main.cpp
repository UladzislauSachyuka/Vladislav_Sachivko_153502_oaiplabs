#include "task1.h"


int main()
{
	setlocale(LC_ALL, "rus");
	cout << "���� ������ ��������, ��������� �� ����, ����������� ���������.������� �� "
		<< "����� ����� ���� ������ � ������� ����������� �� ��������.\n\n";

	cout << "������� ������\n";
	char str[80];
	cin.getline(str, 80);

	cout << "\n�������� ������: " << str;

	for (int i = 0; i < length(str) - 1; i += 2)
	{
		int smallestindex = i;
		for (int currentindex = i + 2; currentindex < length(str); currentindex += 2)
		{
			if (symbol(str[currentindex]) < symbol(str[smallestindex]))
			{
				char temp = str[currentindex];
				str[currentindex] = str[smallestindex];
				str[smallestindex] = temp;
			}
		}
	}

	cout << "\n\n����� ���� ������ � ������� �����������: " << str << "\n";

	return 0;
}