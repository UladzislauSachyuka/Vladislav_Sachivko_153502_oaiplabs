#include <gtest/gtest.h>
#include "../task9/task9.h"
#include "../task9/task9.cpp"

const double ERR = 0.01;

TEST(task9, test1) {
	string str = "12.3asjfh234sjafh0.33jsaf-10";
	double expected = 236.63;
	ASSERT_NEAR(value(str), expected, ERR);
}

TEST(task9, test2) {
	string str = "10safhaj5jasfgas9asgfa-3";
	int expected = 21;
	ASSERT_EQ(value(str), expected);
}

TEST(task9, test3) {
	string str = "hsfag7.92sfahfg0.3hsagfa39";
	double expected = 47.22;
	ASSERT_NEAR(value(str), expected, ERR);
}