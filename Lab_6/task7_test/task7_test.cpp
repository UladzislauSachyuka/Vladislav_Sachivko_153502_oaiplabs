#include <gtest/gtest.h>
#include "../task7/task7.h"
#include "../task7/task7.cpp"

TEST(task7, test1) {
	char arr[] = "aaaaaaaaaaaa";
	EXPECT_TRUE(identical_letters(arr), TRUE);
}

TEST(task7, test2) {
	char arr[] = "jsfkjdhfkjsdfh";
	EXPECT_FALSE(identical_letters(arr), FALSE);
}

TEST(task7, test3) {
	char arr[] = "CCCCCCCCCCCCCCCCCCCC";
	EXPECT_TRUE(identical_letters(arr), TRUE);
}

TEST(task7, test4) {
	char arr[] = "abcdefedcba";
	EXPECT_TRUE(palindrome(arr), TRUE);
}

TEST(task7, test5) {
	char arr[] = "hellolle";
	EXPECT_FALSE(palindrome(arr), FALSE);
}

TEST(task7, test6) {
	char arr[] = "AMERICANBOYOBNACIREMA";
	EXPECT_TRUE(palindrome(arr), TRUE);
}

