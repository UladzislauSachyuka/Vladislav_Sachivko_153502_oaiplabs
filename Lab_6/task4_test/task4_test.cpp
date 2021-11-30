#include <gtest/gtest.h>
#include "../task4/task4.h"
#include "../task4/task4.cpp"

TEST(task4, test1) {
	char ch = 'b';
	EXPECT_TRUE(func(ch), TRUE);
}

TEST(task4, test2) {
	char ch = 'a';
	EXPECT_FALSE(func(ch), FALSE);
}

TEST(task4, test3) {
	char ch = 'z';
	EXPECT_TRUE(func(ch), TRUE);
}