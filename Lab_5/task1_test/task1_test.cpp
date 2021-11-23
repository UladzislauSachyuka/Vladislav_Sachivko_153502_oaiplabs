#include <gtest/gtest.h>
#include "../task1/task1.h"
#include "../task1/task1.cpp"

TEST(testsum, task1) {
	int n;
	int** arr = 0;
	n = 3;

	arr = new int* [n]
	{
		new int[n] {5, 7, 2},
			new int[n] {1, 2, 3},
			new int [n] {4, 5, 6}
	};

	ASSERT_EQ(sum(1, 0, n, arr), 4);

	for (int i = 0; i < n; ++i) 
	{
		delete[] arr[i];
	}
	delete[] arr;
}

TEST(testsum1, task1) {
	int n;
	int** arr = 0;
	n = 3;

	arr = new int* [n]
	{
		new int[n] {5, 1, 4},
			new int[n] {7, 2, 5},
			new int [n] {2, 3, 6}
	};

	ASSERT_EQ(sum(0, 1, n, arr), 4);

	for (int i = 0; i < n; ++i)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

TEST(testsum3, task1) {
	int n, m;
	int** arr = 0;
	n = 4;
	m = 3;

	arr = new int* [n]
	{
		new int[m] {5, 7, 2},
			new int[m] {1, 2, 3},
			new int [m] {4, 5, 6}, 
			new int [m] {3, 0, 7}
	};

	ASSERT_EQ(sum(1, 0, n, arr), 14);

	for (int i = 0; i < n; ++i)
	{
		delete[] arr[i];
	}
	delete[] arr;
}