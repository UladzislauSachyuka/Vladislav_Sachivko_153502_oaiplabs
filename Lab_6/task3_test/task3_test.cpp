#include <gtest/gtest.h>
#include "../task3/task3.h"
#include "../task3/task3.cpp"

TEST(task3, test1) {
	char arr[] = "abcdefedcba";
	int obtained;
	int expected = -1;
	symmetric_string(arr, obtained);
	ASSERT_EQ(obtained, expected);
}

TEST(task3, test2) {
	char arr[] = "aabbccdd";
	int obtained;
	int expected = 3;
	symmetric_string(arr, obtained);
	ASSERT_EQ(obtained, expected);
}

TEST(task3, test3) {
	char arr[] = "ahdgffghma";
	int obtained;
	int expected = 2;
	symmetric_string(arr, obtained);
	ASSERT_EQ(obtained, expected);
}
