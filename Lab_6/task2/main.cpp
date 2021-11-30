#include "task2.h"

int main()
{
	cout << "Find which letters in the text are more - vowels or consonants\n\n";
	cout << "enter the text:\n";

	char* str = new char[80];
	cin.getline(str, 80);
	cout << "\nSource text: " << str << "\n\n";

	char* vowels = new char[] {'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o', 'u', 'y', '\0'};

	int vow = 0;
	int letters = 0;
	for (int i = 0; i < length(str); ++i)
	{
		for (int j = 0; j < 12; ++j)
		{
			if (str[i] == vowels[j])
			{
				++vow;
			}
		}
		if (str[i] != ' ')
		{
			++letters;
		}
	}

	if (vow == letters - vow)
	{
		cout << "the number of vowels and consonants is the same\n";
	}
	else
	{
		vow > (letters - vow) ? cout << "there are more vowels than consonants\n" : cout << "there are more consonants than vowels\n";
	}

	delete[] str;
	str = nullptr;
	delete[] vowels;
	vowels = nullptr;

	return 0;
}