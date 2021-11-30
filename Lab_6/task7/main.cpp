#include "task7.h"

int main()
{
	cout << "enter the string\n";
	char str[105];
	cin.getline(str, 105);

	if (identical_letters(str))
	{
		cout << -1 << '\n';
	}
	else if (palindrome(str))
	{
		cout << "the length of the maximum non-palindrome is " << length(str) - 1 << '\n';
	}
	else
	{
		cout << "the length of the maximum non-palindrome is " << length(str) << '\n';
	}

	return 0;
}