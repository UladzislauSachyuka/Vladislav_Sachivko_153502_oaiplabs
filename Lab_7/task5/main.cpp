#include "task5.h"

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "��������� ��������� ����� �� �������� ������� � �������\n";
    cout << "������� �����: ";
    int a = getinput();
    char* res;
    res = func(a);
    cout << res << '\n';

    delete[] res;
    res = nullptr;

    return 0;
}
