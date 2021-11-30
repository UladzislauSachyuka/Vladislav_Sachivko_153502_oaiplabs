// Лабораторная 6, задача 9. Выполнил Сачивко В.Г.
/*В заданной строке, состоящей из букв, цифр и прочих символов, найдите
сумму всех чисел.*/

#include "task9.h"

double value(string str) 
{
	int i = 0, j = 0, count = 0;
	double value = 0;
	while (true)
	{
		if (str.empty())
		{
			break;
		}
		while (true)
		{
			if ((isdigit(str[j])) || (str[j] == '-' && isdigit(str[j + 1]) && j + 1 < str.length()) ||
				(str[j] == '.' && j - 1 >= 0 && isdigit(str[j - 1]) && j + 1 < str.length() && isdigit(str[j + 1])) 
				|| (str[j] == 'e' && j - 1 >= 0 && isdigit(str[j - 1]) && (j + 1 < str.length() && (isdigit(str[j + 1]) || str[j + 1] == '-'))))
			{
				if (j + 1 < str.length() && str[j + 1] == '-' && str[j] != 'e')
				{
					++count;
					j = 0;
					break;
				}
				++count;
				++j;
			}
			else
			{
				j = 0;
				break;
			}
		}

		if (isdigit(str[j]) || (str[j] == '-' && isdigit(str[j + 1]) && j + 1 < str.length()) ||
			(str[j] == '.' && j - 1 >= 0 && isdigit(str[j - 1])))
		{
			value += stof(str);
		}
		if (count > 0)
		{
			str.erase(i, count);
			count = 0;
		}
		else
		{
			str.erase(i, 1);
		}
		j = 0;
	}
	return value;
}

//if (j - 1 >= 0 && j + 1 < str.length() && str[j] == 'e' && isdigit(str[j - 1]) && ((str[j + 1] == '-'
//	&& isdigit(str[j + 2])) || isdigit(str[j + 1])))
//{
//	--j;
//	while (isdigit(str[j]) && j >= 0)
//	{
//		++count;
//		--j;
//	}
//	while (isdigit(str[j]))
//}