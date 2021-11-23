#include "..\task7\task7.h"
#include <gtest\gtest.h>
#include "..\task7\task7.cpp"

TEST(recursive, task7) {
	ASSERT_EQ(result(1234 % 10000, 1234, 10000), 736);
}

TEST(recursive1, task7) {
	ASSERT_EQ(result(2323 % 100000000, 99999999999, 100000000), 39087387);
}

TEST(recursive2, task7) {
	ASSERT_EQ(result(4 % 1000000000, 99999, 1000000000), 494777344);
}

TEST(recursive3, task7) {
	ASSERT_EQ(result(888 % 100000000, 888, 100000000), 91255296);
}