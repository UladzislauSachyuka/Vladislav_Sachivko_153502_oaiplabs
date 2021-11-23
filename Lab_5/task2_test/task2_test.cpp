#include "../task2/task2.h"
#include <gtest/gtest.h>
#include "..\task2\task2.cpp"
const double ERR = 0.0001;
TEST(testfunc, task2) {
	int n;
	int* arr = 0;
	n = 3;

	arr = new int [n] {1, 2, 3};

	ASSERT_NEAR(func(arr, 0, n / 3), 0.399182, ERR);
	ASSERT_NEAR(func(arr, n / 3 + 1, n - 1), 1.131112504660312, ERR);

	delete[] arr;
}

TEST(testfunc1, task2) {
	int n;
	int* arr = 0;
	n = 3;

	arr = new int [n] {1, 2, 3};

	ASSERT_NEAR(func(arr, n / 3 + 1, n - 1), 1.131112504660312, ERR);

	delete[] arr;
}

TEST(testfunc2, task2) {
	int n;
	int* arr = 0;
	n = 3;

	arr = new int [n] {1, 2, 3};

	ASSERT_NEAR(func(arr, 0, n - 1), 0.451520088689973, ERR);

	delete[] arr;
}