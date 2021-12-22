#include "task8.h"

int main() {
    setlocale(LC_ALL, "rus");
    unsigned long long n;
    cout << "введите номер списка\n";
    n = getinput();

    unsigned long long i = 1;
    unsigned long long k = 1;
    unsigned long long d = 0;
    while (k <= n)
    {
        unsigned long long n2 = binary(i);
        if (two_dec(n2, binary(n2)))
        {
            k++;
            d = n2;
        }
        ++i;
    }
    cout << d << '\n';

    return 0;
}