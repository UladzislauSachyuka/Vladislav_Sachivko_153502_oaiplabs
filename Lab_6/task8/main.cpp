#include "task8.h"

int main()
{
	cout << "enter the number of input data sets\n";
	int n = getinput();
	while (n--)
	{
		cout << "enter the strings\n";
		string str1, str2;
		cin >> str1 >> str2;
		if (possible_write_out(str1, str2))
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}

	return 0;
}