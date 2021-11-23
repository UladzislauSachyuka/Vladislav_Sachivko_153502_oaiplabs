#include "..\task8\task8.h"
#include <gtest\gtest.h>
#include "..\task8\task8.cpp"

TEST(function, task8) {
	ASSERT_EQ(func(7), 21);
}

TEST(function1, task8) {
	ASSERT_EQ(func(1), 1);
}

TEST(function2, task8) {
	ASSERT_EQ(func(777), 201537);
}