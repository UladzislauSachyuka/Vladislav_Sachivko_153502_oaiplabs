#include "task10.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "������� ����� ����������� �����\n";
	int poisoned = getinput();
	char* pois = ternarySistem(poisoned);

	cout << func(pois) << " ����� ���������\n";

	delete[] pois;
	pois = nullptr;

	return 0;
}