#include <gtest/gtest.h>
#include "../task8/task8.h"
#include "../task8/task8.cpp"

TEST(task8, test1) {
	string str1 = "abcdef";
	string str2 = "cdedcb";
	EXPECT_TRUE(possible_write_out(str1, str2), TRUE);
}

TEST(task8, test2) {
	string str1 = "aaa";
	string str2 = "aaaaa";
	EXPECT_TRUE(possible_write_out(str1, str2), TRUE);
}

TEST(task8, test3) {
	string str1 = "aab";
	string str2 = "baaa";
	EXPECT_FALSE(possible_write_out(str1, str2), FALSE);
}

TEST(task8, test4) {
	string str1 = "ab";
	string str2 = "b";
	EXPECT_TRUE(possible_write_out(str1, str2), TRUE);
}

TEST(task8, test5) {
	string str1 = "abcdef";
	string str2 = "abcdef";
	EXPECT_TRUE(possible_write_out(str1, str2), TRUE);
}

TEST(task8, test6) {
	string str1 = "ba";
	string str2 = "baa";
	EXPECT_FALSE(possible_write_out(str1, str2), FALSE);
}