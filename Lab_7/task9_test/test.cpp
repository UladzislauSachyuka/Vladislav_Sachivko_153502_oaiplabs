#include <gtest/gtest.h>
#include "../task9/task9.h"
#include "../task9/task9.cpp"

TEST(task9, test1) {
	char arr[] = "ajsfbasjfba";
	int len = 11;
	to_the_left(arr, 11);
	ASSERT_STREQ(arr, "jsfbasjfba");
}

TEST(task9, test2) {
	char arr[] = "0000112141241";
	int len = 13;
	to_the_left(arr, 13);
	ASSERT_STREQ(arr, "000112141241");
}

TEST(task9, test3) {
	char arr[] = "12312asf";
	int len = 8;
	to_the_left(arr, 8);
	ASSERT_STREQ(arr, "2312asf");
}