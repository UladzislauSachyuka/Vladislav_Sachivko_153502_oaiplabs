#include <gtest/gtest.h>
#include "../task5/task5.h"
#include "../task5/task5.cpp"

TEST(task5, test1) {
	int a = 25;
	char* res;
	ASSERT_STREQ(func(a), "XXV");
}

TEST(task5, test2) {
	int a = 100;
	char* res;
	ASSERT_STREQ(func(a), "C");
}

TEST(task5, test3) {
	int a = 1000;
	char* res;
	ASSERT_STREQ(func(a), "M");
}