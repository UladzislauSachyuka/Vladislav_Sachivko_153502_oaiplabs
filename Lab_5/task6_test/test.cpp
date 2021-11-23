#include "..\task6\task6.h"
#include <gtest\gtest.h>
#include "..\task6\task6.cpp"

TEST(find_sum, task6) {
	ASSERT_EQ(sum(1, 10), 46);
}

TEST(find_sum1, task6) {
	ASSERT_EQ(sum(10, 20), 48);
}

TEST(find_sum2, task6) {
	ASSERT_EQ(sum(30, 40), 52);
}