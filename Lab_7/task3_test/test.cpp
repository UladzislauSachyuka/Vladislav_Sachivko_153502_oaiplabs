#include <gtest/gtest.h>
#include "../task3/task3.h"
#include "../task3/task3.cpp"

TEST(task3, test1) {
	int num1 = 127;
	int num2 = 0;
	int len = 8;
	int n = 100;
	char* add = new char[n];
	char ar1[] = "11111110";
	char ar2[] = "00000000";
	addition(ar1, ar2, add, len, num1, num2);
	ASSERT_STREQ(add, "11111110");
}

TEST(task3, test2) {
	int num1 = -10;
	int num2 = -5;
	int len = 8;
	int n = 100;
	char* add = new char[n];
	char ar1[] = "01010001";
	char ar2[] = "10100001";
	addition(ar1, ar2, add, len, num1, num2);
	ASSERT_STREQ(add, "10001111");
}

TEST(task3, test3) {
	int num1 = 10;
	int num2 = 5;
	int len = 8;
	int n = 100;
	char* add = new char[n];
	char ar1[] = "01010000";
	char ar2[] = "10100000";
	addition(ar1, ar2, add, len, num1, num2);
	ASSERT_STREQ(add, "11110000");
}