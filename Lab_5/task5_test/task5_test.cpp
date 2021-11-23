#include "..\task5_dynamic_lib_\task5_dynamic_lib_.h"
#include <gtest\gtest.h>
#include "..\task5_\Debug\task5_dynamic_lib_.h"

TEST(find_average, task5) {
	int n;
	int* arr = 0;
	n = 3;

	arr = new int [n] {5, 7, 9};

	ASSERT_EQ(average(n, arr), 7);

	delete[] arr;
}

TEST(find_average1, task5) {
	int n;
	int* arr = 0;
	n = 5;

	arr = new int [n] {5, 7, 9, 3, 1};

	ASSERT_EQ(average(n, arr), 5);

	delete[] arr;
}

TEST(find_average2, task5) {
	int n;
	int* arr = 0;
	n = 10;

	arr = new int [n] {5, 7, 9, 3, 1, 11, 9, 3, 5, 7};

	ASSERT_EQ(average(n, arr), 6);

	delete[] arr;
}