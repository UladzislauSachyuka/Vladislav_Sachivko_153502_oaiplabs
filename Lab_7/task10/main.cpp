#include "task10.h"

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "введите номер отравленной бочки\n";
	int poisoned = getinput();
	char* pois = ternarySistem(poisoned);

	cout << func(pois) << " бочка отравлена\n";

	delete[] pois;
	pois = nullptr;

	return 0;
}