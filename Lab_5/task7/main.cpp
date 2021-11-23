#include "task7.h"

int main()
{
	setlocale(LC_ALL, "rus");

	cout << "����������� ������� ������ ��������� �������:\n"
		<< "f(0, 0) = 1\n"
		<< "f(n, r) = ����� �������� ������� f(n-1, r-i), ��� i �� 0 �� n*(k-1),����� ������� ����� ��������� ����� mod m\n"
		<< "��� m = 10^t."
		<< "� ���������� �������� ����� k, n, t. �� ��������� ��������:\n 0 < k < 10^19, 0 < n < 10^19 0 < t < 10\n\n";

	unsigned long long k, n, t, m;
	int occasion = 0;

	while (true)
	{
		cout << "������� k\n";
		k = getinput(true, pow(10, 19));

		cout << "������� n\n";
		n = getinput(true, pow(10, 19));

		cout << "������� t\n";
		t = getinput(true, 10);

		if (k == 0 && n == 0 && t == 0)
		{
			return 0; // ����� ��� �� ������ ��������� ���������
		}

		m = pow(10, t);

		++occasion;

		cout << "Case #" << occasion << ": " << result(k % m, n, m) << "\n";
	}

	return 0;
}