// Лабораторная 4. Задача 9. Выполнил Сачивко В.Г.

#include <iostream>

using namespace std;

int getinput()
{
	int n;
	do
	{
		cin >> n;
		while (cin.get() != '\n')
		{
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "Некорректный ввод.\nВведите размер матрицы.\n ";
			cin >> n;
		}
		if (n < 1 || n > 10)
		{
			cout << "Некорректный ввод.\nВведите размер матрицы.\n ";
		}
	} while (n < 1 || n > 10);
	return n;
}

void freematrix(int rows, int** a)
{
	for (int i = 0; i < rows; i++)
	{
		free(a[i]);
	}
	free(a);
}

void output(int rows, int cols, int** a)
{
	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < cols; k++)
			cout << a[i][k] << "\t";
		cout << "\n\n";
	}
}

void fillmatrix(int rows, int cols, int** a)
{
	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < cols; k++)
		{
			a[i][k] = rand() % 10;
		}
	}
}

int** creatematrix(int rows, int cols)
{
	int** a;
	a = (int**)calloc(rows, sizeof(int*));
	for (int i = 0; i < rows; i++)
	{
		a[i] = (int*)calloc(cols, sizeof(int));
	}
	return a;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int  i, k, m, n, h, p;
	
	do
	{
		cout << "Введите количество строк первой матрицы.\n";
		m = getinput();
		cout << "Введите количество столбцов первой матрицы.\n";
		n = getinput();
		cout << "Введите количество строк второй матрицы.\n";
		h = getinput();
		cout << "Введите количество столбцов второй матрицы.\n";
		p = getinput();
		if (n != h)
		{
			cout << "Выполнить умножение матриц невозможно.\n";
		}
	} while (n != h);

	int** a = creatematrix(m, n);
	fillmatrix(m, n, a);
	cout << "Первая матрица :\n";
	output(m, n, a);

	int** b = creatematrix(n, p);
	fillmatrix(n, p, b);
	cout << "Вторая матрица :\n";
	output(n, p, b);

	int** c = creatematrix(m, p);
	int ia = 0, ib = 0, ka = 0, kb = 0, x = 0;
	for (i = 0; i < m; i++)
	{
		for (k = 0; k < p; k++)
		{
			for (int j = 0; j < n; j++)
			{
				c[i][k] = c[i][k] + a[ia][ka + x] * b[ib + x][kb];
				x++;
			}
			x = 0;
			kb++;
		}
		ia++;
		kb = 0;
	}
	cout << "Произведение матриц :\n";
	output(m, p, c);

	freematrix(m, a);
	freematrix(n, b);
	freematrix(m, c);

	return 0;
}