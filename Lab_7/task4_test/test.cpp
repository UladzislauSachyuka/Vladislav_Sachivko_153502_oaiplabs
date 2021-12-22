#include <gtest/gtest.h>
#include "../task4/task4.h"
#include "../task4/task4.cpp"

TEST(task4, test1) {
	char ar1[] = "4A25";
	char ar2[] = "4A25";
	int len1 = 4, len2 = 4, n = 100;
	char* add = new char[n];
	subtraction(ar1, ar2, add, len1, len2);
	ASSERT_STREQ(add, "0000");
}

TEST(task4, test2) {
	char ar1[] = "1234";
	char ar2[] = "1234";
	int len1 = 4, len2 = 4, n = 100;
	char* add = new char[n];
	subtraction(ar1, ar2, add, len1, len2);
	ASSERT_STREQ(add, "0000");
}

TEST(task4, test3) {
	char ar1[] = "1A91";
	char ar2[] = "1A91";
	int len1 = 4, len2 = 4, n = 100;
	char* add = new char[n];
	subtraction(ar1, ar2, add, len1, len2);
	ASSERT_STREQ(add, "0000");
}