// Лабораторная 6, задача 8. Выполнил Сачивко В.Г.
/*У вас есть строка s и фишка, которую вы можете поставить на любой символ
этой строки.
После того, как вы поставите фишку, вы можете подвинуть ее вправо
несколько (возможно, ноль) раз, то есть сделать следующее действие
несколько раз: если текущая позиция фишки обозначена как i, фишка
перемещается в позицию i+1. Конечно же, это действие невозможно, если
фишка находится в последней позиции строки.
После того, как вы закончите двигать фишку вправо, вы можете подвинуть ее
влево несколько (возможно, ноль) раз, то есть сделать следующее действие
несколько раз: если текущая позиция фишки обозначена как i, фишка
перемещается в позицию i−1. Конечно же, это действие невозможно, если
фишка находится в первой позиции строки.
Когда вы ставите фишку или перемещаете ее, вы выписываете символ, на
котором оказалась фишка. Например, если строка s — abcdef, вы ставите
фишку на 3-й символ, двигаете ее вправо 2 раза, а затем двигаете ее влево 3
раза, вы выпишете строку cdedcb.
Вам даны две строки s и t. Ваше задание — определить, можно ли так
выполнить описанные операции со строкой s, что в результате вы выпишете
строку t.*/

#include "task8.h"

int getinput()
{
	int input;
	do
	{
		cin >> input;
		while (cin.get() != '\n')
		{
			cin.clear();
			cin.ignore(100000, '\n');
			cout << "Некорректный ввод. Попробуйте еще раз.\nВведите значение\n ";
			cin >> input;
		}
		if (input < 1)
		{
			cout << "Некорректный ввод. Попробуйте еще раз.\nВведите значение\n ";
		}
	} while (input < 1);

	return input;
}

bool possible_write_left(string str1, string str2, int index)
{
	for (; str2.length() > 0 && index >= 0 && str1[index] == str2[0]; index--)
	{
		str2 = str2.substr(1);
	}
	if (str2.length() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool possible_write(string str1, string str2, int index)
{
	int str1Len = str1.length();
	int curIndex = index;

	for (int curIndex = index; str1[curIndex] == str2[curIndex - index] && curIndex < str1Len; curIndex++)
	{
		if (possible_write_left(str1, str2.substr(curIndex - index), curIndex))
		{
			return true;
		}
	}
	return false;
}

bool possible_write_out(string str1, string str2)
{
	int str1Len = str1.length();
	for (int i = 0; i < str1Len; ++i)
	{
		if (possible_write(str1, str2, i))
		{
			return true;
		}
	}
	return false;
}

