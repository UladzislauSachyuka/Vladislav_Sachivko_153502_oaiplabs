#include <gtest/gtest.h>
#include "../task6/task6.h"
#include "../task6/task6.cpp"

TEST(task6, test1) {
	int n = 1;
	ASSERT_EQ(interesting(n), 0);
}

TEST(task6, test2) {
	int n = 9;
	ASSERT_EQ(interesting(n), 1);
}

TEST(task6, test3) {
	int n = 10;
	ASSERT_EQ(interesting(n), 1);
}

TEST(task6, test4) {
	int n = 34;
	ASSERT_EQ(interesting(n), 3);
}

TEST(task6, test5) {
	int n = 880055535;
	ASSERT_EQ(interesting(n), 88005553);
}