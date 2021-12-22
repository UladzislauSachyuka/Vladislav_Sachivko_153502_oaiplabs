#include <gtest/gtest.h>
#include "../task1.1/task1.1.h"
#include "../task1.1/task1.1.cpp"

TEST(task1, test1) {
	char arr[] = "12345";
	int len = length(arr);
	int expected = 8303;
	EXPECT_EQ(val(arr, 0, 0, len), expected);
}

TEST(task1, test2) {
	char arr[] = "12345678";
	int len = length(arr);
	int expected = 6053444;
	EXPECT_EQ(val(arr, 0, 0, len), expected);
}

TEST(task1, test3) {
	char arr[] = "1234567812";
	int len = length(arr);
	int expected = 490328975;
	EXPECT_EQ(val(arr, 0, 0, len), expected);
}