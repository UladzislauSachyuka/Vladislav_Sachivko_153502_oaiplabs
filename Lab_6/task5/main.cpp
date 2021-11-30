#include "task5.h"

int main()
{
	cout << "enter the number of input data sets\n";
	int n = getinput();

	while (n--)
	{
		cout << "enter the length of the string\n";
		int l = getinput();
		cout << "enter m\n";
		int m = getinput();
		cout << "enter the lines\n";
		string str1, str2;
		getline(cin, str1);
		getline(cin, str2);

		cout << "the result is " << strings(str1, str2, l, m) << '\n';
	}

	return 0;
}