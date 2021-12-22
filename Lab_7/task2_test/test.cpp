#include <gtest/gtest.h>
#include "../task2/task2.h"
#include "../task2/task2.cpp"

TEST(task2, test1) {
	char ch = '5';
	int expected = 5;
	EXPECT_EQ(into_number(ch), expected);
}

TEST(task2, test2) {
	char ch = '9';
	int expected = 9;
	EXPECT_EQ(into_number(ch), expected);
}

TEST(task2, test3) {
	char ch = '0';
	int expected = 0;
	EXPECT_EQ(into_number(ch), expected);
}

TEST(task2, test4) {
	int ch = 1;
	ASSERT_EQ(into_symbol(ch), '1');
}

TEST(task2, test5) {
	int ch = 5;
	ASSERT_EQ(into_symbol(ch), '5');
}

TEST(task2, test6) {
	int ch = 9;
	ASSERT_EQ(into_symbol(ch), '9');
}