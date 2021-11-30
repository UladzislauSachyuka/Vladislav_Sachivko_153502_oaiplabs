#include <gtest/gtest.h>
#include "../task6/task6.h"
#include "../task6/task6.cpp"

TEST(task6, test1) {
	int obtained = 5;
	int expected = 120;
	ASSERT_EQ(factorial(obtained), expected);
}

TEST(task6, test2) {
	int obtained = 7;
	int expected = 5040;
	ASSERT_EQ(factorial(obtained), expected);
}

TEST(task6, test3) {
	int obtained = 9;
	int expected = 362880;
	ASSERT_EQ(factorial(obtained), expected);
}