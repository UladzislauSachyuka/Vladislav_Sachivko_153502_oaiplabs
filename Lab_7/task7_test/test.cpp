#include <gtest/gtest.h>
#include "../task7/task7.h"
#include "../task7/task7.cpp"

TEST(task7, test1) {
	long long a = 49;
	int k = 7;
	EXPECT_TRUE(divisibility(a, k), TRUE);
}

TEST(task7, test2) {
	long long a = 730;
	int k = 73;
	EXPECT_TRUE(divisibility(a, k), TRUE);
}

TEST(task7, test3) {
	long long a = 10900;
	int k = 109;
	EXPECT_TRUE(divisibility(a, k), TRUE);
}