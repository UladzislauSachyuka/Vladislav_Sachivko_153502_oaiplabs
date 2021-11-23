#include "..\task4\task4.h"
#include <gtest\gtest.h>
#include "..\task4\task4.cpp"

TEST(find_null, task4) { 
	int rows, cols;

	double** arr = 0;
	rows = 2;
	cols = 5;

	arr = new double* [rows]
	{
		new double[cols] {1, 0, 3, 5, 0},
			new double[cols] {7, 9, 0, 4, 3}
	};

	ASSERT_EQ(null_elements(2, 5, arr), 3);
}

TEST(find_null1, task4) {
	int rows, cols;

	double** arr = 0;
	rows = 3;
	cols = 3;

	arr = new double* [rows]
	{
		new double[cols] {1, 0, 3},
			new double[cols] {7, 9, 0},
			new double [cols] {1, 2, 3}
	};

	ASSERT_EQ(null_elements(3, 3, arr), 2);
}

TEST(find_null2, task4) {
	int rows, cols;

	double** arr = 0;
	rows = 5;
	cols = 7;

	arr = new double* [rows]
	{
		new double[cols] {1, 0, 3, 0, 4, 5, 1},
			new double[cols] {7, 9, 0, 9, 8, 0, 3},
			new double [cols] {1, 2, 3, 8, 0, 3, 0},
			new double [cols] {3, 4, 9, 0, 1, 4, 0},
			new double[cols] {1, 2, 3, 4, 5, 6, 7}
	};

	ASSERT_EQ(null_elements(5, 7, arr), 8);
}

  