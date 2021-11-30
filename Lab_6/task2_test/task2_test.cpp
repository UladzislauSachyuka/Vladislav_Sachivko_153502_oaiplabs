#include <gtest/gtest.h>
#include "../task2/task2.h"
#include "../task2/task2.cpp"

TEST(task2, test1) {
	char arr[] = "thefinalcountdown";
	ASSERT_EQ(length(arr), 17);
}

TEST(task2, test2) {
	char arr[] = "jdksagbfsjkdfhkjsdhfjkqsfhkjqhfkjsdhfkjsdfhsjkhfdk";
	ASSERT_EQ(length(arr), 50);
}

TEST(task2, test3) {
	char arr[] = "jkdghsfsqjkdfhjkqgfhjkqfhqkklhefq;lwkjf;eqwjflewkjflkhqghgqg";
	ASSERT_EQ(length(arr), 60);
}