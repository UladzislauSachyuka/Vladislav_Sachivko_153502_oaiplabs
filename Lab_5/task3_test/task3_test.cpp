#include "../../task3_static_lib/task3_static_lib.h"
#include <gtest/gtest.h>
#include "..\task3\Debug\task3_static_lib.h"

TEST(production, task3)
{
	int n;
	int* arr = 0;
	n = 3;
	arr = new int [n] {2, 4, 8};
	
	ASSERT_EQ(prod(n, arr), 64);

	delete[] arr;
}

TEST(production1, task3)
{
	int n;
	int* arr = 0;
	n = 10;
	arr = new int [n] {2, 4, 8, 3, 2, 1, 6, 4, 9, 6};

	ASSERT_EQ(prod(n, arr), 497664);

	delete[] arr;
}

TEST(production2, task3)
{
	int n;
	int* arr = 0;
	n = 15;
	arr = new int [n] {2, 4, 8, 3, 2, 1, 6, 4, 9, 6, 2, 3, 4, 5, 6};

	ASSERT_EQ(prod(n, arr), 358318080);

	delete[] arr;
}
