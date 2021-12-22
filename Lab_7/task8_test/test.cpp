#include <gtest/gtest.h>
#include "../task8/task8.h"
#include "../task8/task8.cpp"

TEST(task8, test1) {
    long long n = 1;
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
    ASSERT_EQ(d, 1);
}

TEST(task8, test2) {
    long long n = 2;
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
    ASSERT_EQ(d, 10);
}

TEST(task8, test3) {
    long long n = 10;
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
    ASSERT_EQ(d, 1100);
}