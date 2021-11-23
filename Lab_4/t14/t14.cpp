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
			cout << "Некорректный ввод.\nВведите размер поля.\n ";
			cin >> n;
		}
		if (n < 5 || n > 28)
		{
			cout << "Некорректный ввод.\nВведите размер поля.\n ";
		}
	} while (n < 5 || n > 28);
	return n;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int  i, k, cols, rows, bombs;
	
	cout << "Введите высоту поля.\n";
	rows = getinput();
	cout << "Введите ширину поля.\n";
	cols = getinput();
	bombs = rows * cols / 10;

	char** a;
	a = (char**)calloc(rows, sizeof(char*));
	for (int i = 0; i < rows; i++)
	{
		a[i] = (char*)calloc(cols, sizeof(char));
	}
	for (int j = 0; j < bombs;)
	{
		i = rand() % rows;
		k = rand() % cols;
		if (a[i][k] != '*')
		{
			a[i][k] = '*';
			j++;
		}
	}

	int** a1;
	int g;
	a1 = (int**)calloc(rows, sizeof(int*));
	for (int i = 0; i < rows; i++)
	{
		a1[i] = (int*)calloc(cols, sizeof(int));
	}

	int number;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			number = 0;
			for (k = i - 1; k <= i + 1; k++)
			{
				for (g = j - 1; g <= j + 1; g++)
				{
					if (k == i && g == j || (k > rows - 1 || k < 0 || g > cols - 1 || g < 0))
					{
						continue;
					}
					if (a[k][g] == '*')
					{
						number++;
					}
				}
			}
			if (a[i][j] != '*' && a[i][j] != '.')
			{
				a1[i][j] = number;
			}
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < cols; k++)
		{
			if (a[i][k] == '*')
			{
				cout << a[i][k] << "\t";
			}
			else if (a1[i][k] == 0)
			{
				cout << ".\t";
			}
			else
			{
				cout << a1[i][k] << "\t";
			}
		}
		cout << "\n\n";
	}

	for (int i = 0; i < rows; i++)
	{
		free(a1[i]);
	}
	free(a1);
	for (int i = 0; i < rows; i++)
	{
		free(a[i]);
	}
	free(a);

	return 0;
}