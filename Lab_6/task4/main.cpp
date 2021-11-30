#include "task4.h"

int main()
{
	cout << "The program reworks the text in accordance with the reform\n\n";
	cout << "enter the number of strings\n";
	int m = getinput();
	cout << "enter the text\n";
	int size = 100;
	char** str = new char* [m];
	for (int i = 0; i < m; ++i)
	{
		str[i] = new char[size];
		cin.getline(str[i], 100, '\n');
	}

	for (int j = 0; j < m; ++j)
	{
		for (int i = 0; i < size; ++i)
		{
			if (str[j][i] == 'q')
			{
				if (str[j][i + 1] == 'u')
				{
					str[j][i] = 'k';
					str[j][i + 1] = 'v';
				}
				else
				{
					str[j][i] = 'k';
				}
			}
			else if (str[j][i] == 'Q')
			{
				if (str[j][i + 1] == 'u')
				{
					str[j][i] = 'K';
					str[j][i + 1] = 'v';
				}
				else
				{
					str[j][i] = 'K';
				}
			}
			else if (str[j][i] == 'W')
			{
				str[j][i] = 'V';
			}
			else if (str[j][i] == 'w')
			{
				str[j][i] = 'v';
			}
			else if (str[j][i] == 'x')
			{
				for (int l = size - 1; l > i; --l)
				{
					str[j][l] = str[j][l - 1];
				}
				str[j][i] = 'k';
				str[j][i + 1] = 's';
			}
			else if (str[j][i] == 'X')
			{
				for (int l = size - 1; l > i; --l)
				{
					str[j][l] = str[j][l - 1];
				}
				str[j][i] = 'K';
				str[j][i + 1] = 's';
			}
			else if (str[j][i] == 'p' && str[j][i + 1] == 'h')
			{
				for (int l = i + 1; l < size - 1; ++l)
				{
					str[j][l - 1] = str[j][l];
				}
				str[j][i] = 'f';
			}
			else if (str[j][i] == 'P' && str[j][i + 1] == 'h')
			{
				for (int l = i + 1; l < size - 1; ++l)
				{
					str[j][l - 1] = str[j][l];
				}
				str[j][i] = 'F';
			}
			else if (str[j][i] == 'y' && str[j][i + 1] == 'o' && str[j][i + 2] == 'u')
			{
				for (int l = i + 2; l < size - 1; ++l)
				{
					str[j][l - 2] = str[j][l];
				}
				str[j][i] = 'u';
			}
			else if (str[j][i] == 'Y' && str[j][i + 1] == 'o' && str[j][i + 2] == 'u')
			{
				for (int l = i + 2; l < size - 1; ++l)
				{
					str[j][l - 2] = str[j][l];
				}
				str[j][i] = 'U';
			}
			else if (str[j][i] == 'o' && str[j][i + 1] == 'o')
			{
				for (int l = i + 1; l < size - 1; ++l)
				{
					str[j][l - 1] = str[j][l];
				}
				str[j][i] = 'u';
			}
			else if (str[j][i] == 'O' && str[j][i + 1] == 'o')
			{
				for (int l = i + 1; l < size - 1; ++l)
				{
					str[j][l - 1] = str[j][l];
				}
				str[j][i] = 'U';
			}
			else if (str[j][i] == 'e' && str[j][i + 1] == 'e')
			{
				for (int l = i + 1; l < size - 1; ++l)
				{
					str[j][l - 1] = str[j][l];
				}
				str[j][i] = 'i';
			}
			else if (str[j][i] == 'E' && str[j][i + 1] == 'e')
			{
				for (int l = i + 1; l < size - 1; ++l)
				{
					str[j][l - 1] = str[j][l];
				}
				str[j][i] = 'I';
			}
			else if (str[j][i] == 't' && str[j][i + 1] == 'h')
			{
				for (int l = i + 1; l < size - 1; ++l)
				{
					str[j][l - 1] = str[j][l];
				}
				str[j][i] = 'z';
			}
			else if (str[j][i] == 'T' && str[j][i + 1] == 'h')
			{
				for (int l = i + 1; l < size - 1; ++l)
				{
					str[j][l - 1] = str[j][l];
				}
				str[j][i] = 'Z';
			}
			else if (str[j][i] == 'c')
			{
				if (str[j][i + 1] == 'e' || str[j][i + 1] == 'i' || str[j][i + 1] == 'y')
				{
					str[j][i] = 's';
				}
				else
				{
					str[j][i] = 'k';
				}
			}
			else if (str[j][i] == 'C')
			{
				if (str[j][i + 1] == 'e' || str[j][i + 1] == 'i' || str[j][i + 1] == 'y')
				{
					str[j][i] = 'S';
				}
				else
				{
					str[j][i] = 'K';
				}
			}

			if (func(str[j][i]))
			{
				while (tolower(str[j][i]) == tolower(str[j][i + 1]))
				{
					for (int n = i + 1; n < size - 1; ++n)
					{
						str[j][n - 1] = str[j][n];
					}
				}
			}
		}
	}

	for (int i = 0; i < m; ++i)
	{
		cout << str[i] << '\n';
	}

	for (int i = 0; i < m; ++i)
	{
		delete str[i];
		str[i] = nullptr;
	}
	delete[] str;
	str = nullptr;

	return 0;
}