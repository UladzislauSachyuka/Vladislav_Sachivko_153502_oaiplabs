#include <gtest/gtest.h>
#include "../Lab_6/task1.h"
#include "../Lab_6/task1.cpp"

TEST(task1, test1) {
	char arr[] = "helloworld";
	ASSERT_EQ(length(arr), 10);
}

TEST(task1, test2) {
	char arr[] = "prettyyounggirlofmymind";
	ASSERT_EQ(length(arr), 23);
}

TEST(task1, test3) {
	char arr[] = "fkjasdhkjsdfhkjdsfhksdfhkdsjfhjdskfh";
	ASSERT_EQ(length(arr), 36);
}

TEST(task1, test4) {
	char s = '1';
	ASSERT_EQ(symbol(s), 1);
}

TEST(task1, test5) {
	char s = '5';
	ASSERT_EQ(symbol(s), 5);
}

TEST(task1, test6) {
	char s = '9';
	ASSERT_EQ(symbol(s), 9);
}