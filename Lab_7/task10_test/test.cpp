#include <gtest/gtest.h>
#include "../task10/task10.h"
#include "../task10/task10.cpp"

TEST(task10, test1) {
	char arr[] = "10212";
	ASSERT_EQ(decimalSistem(arr), 104);
}

TEST(task10, test2) {
	char arr[] = "10211";
	ASSERT_EQ(decimalSistem(arr), 103);
}

TEST(task10, test3) {
	char arr[] = "11211";
	ASSERT_EQ(decimalSistem(arr), 130);
}