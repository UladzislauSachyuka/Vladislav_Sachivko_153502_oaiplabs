// Лабораторная 8, задача 2. Выполнил Сачивко В.Г.
/*Для книг, хранящихся в библиотеке, задаются: регистрационный
номер книги, автор, название, год издания, издательство, количество
страниц. Вывести список книг с фамилиями авторов в алфавитном порядке,
изданных после заданного года*/

#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

struct Book
{
	char num[15];
	char author[15];
	char name[15];
	char year[15];
	char izdatelstvo[15];
	char pages[15];
};

int getinput()
{
	int input;
	cin >> input;
	while (cin.get() != '\n')
	{
		cin.clear();
		cin.ignore(100000, '\n');
		cout << "Incorrect input. Try again.\nEnter the value\n";
		cin >> input;
	}
	return input;
}

void seemenu() {
	cout << "1. Viewing records in file\n";
	cout << "2. Data initialization\n";
	cout << "3. File correction\n";
	cout << "4. Adding elements to a file\n";
	cout << "5. Deleting elements in a file\n";
	cout << "6. A list of books with authors' surnames in alphabetical order published after a given year\n";
	cout << "7. Program exit\n";
}

void showData(int n)
{
	Book* Books;
	Books = (Book*)calloc(n, sizeof(Book));
	ifstream  fin;
	fin.open("C:\\Users\\ноут\\source\\repos\\Lab_8\\Task2.txt");
	string buff;

	for (int i = 0; i < n; i++)
	{
		fin.read((char*)&Books[i], sizeof(Book));
		cout << Books[i].num << "        " << Books[i].author << "         " << Books[i].name << "                  " << Books[i].year << 
		"                         " << Books[i].izdatelstvo << "                   " << Books[i].pages << '\n';
	}
	fin.close();
}

void writeData(int& n)
{
	Book* Books;
	int k;
	cout << "enter the number of structures\n";
	n = getinput();
	Books = (Book*)calloc(n, sizeof(Book));

	ofstream file("C:\\Users\\ноут\\source\\repos\\Lab_8\\Task2.txt", ios_base::app);

	for (int i = 0; i < n; ++i)
	{
		cout << "enter the registration number of the book\n";
		k = getinput();
		_itoa(k, Books[i].num, 10);
		cout << "enter the author's name\n";
		cin.getline(Books[i].author, 20);
		cout << "enter the name of the book\n";
		cin.getline(Books[i].name, 20);
		cout << "enter the year of publication of the book\n";
		k = getinput();
		_itoa(k, Books[i].year, 10);
		cout << "enter the name of the publisher\n";
		cin >> Books[i].izdatelstvo;
		cout << "enter the number of pages\n";
		k = getinput();
		_itoa(k, Books[i].pages, 10);

		file.write((char*)&Books[i], sizeof(Book));
	}
	file.close();
}

void change(int& n)
{
	cout << "enter the number of the line you want to change\n";
	int num, k;
	num = getinput();
	if (num > n)
	{
		cout << "there is no such line\n";
		exit(0);
	}

	Book* Books;
	Books = (Book*)calloc(n, sizeof(Book));

	ifstream  fin;
	fin.open("C:\\Users\\ноут\\source\\repos\\Lab_8\\Task2.txt");

	for (int i = 0; i < n; i++)
	{
		fin.read((char*)&Books[i], sizeof(Book));
	}

	fin.close();

	ofstream fout("C:\\Users\\ноут\\source\\repos\\Lab_8\\Task2.txt", ofstream::out | ofstream::trunc);
	fout.close();

	ofstream file("C:\\Users\\ноут\\source\\repos\\Lab_8\\Task2.txt", ios_base::app);

	cout << "enter the registration number of the book\n";
	k = getinput();
	_itoa(k, Books[num - 1].num, 10);
	cout << "enter the author's name\n";
	cin.getline(Books[num - 1].author, 20);
	cout << "enter the name of the book\n";
	cin.getline(Books[num - 1].name, 20);
	cout << "enter the year of publication of the book\n";
	k = getinput();
	_itoa(k, Books[num - 1].year, 10);
	cout << "enter the name of the publisher\n";
	cin >> Books[num - 1].izdatelstvo;
	cout << "enter the number of pages\n";
	k = getinput();
	_itoa(k, Books[num - 1].pages, 10);

	for (int i = 0; i < n; i++)
	{
		file.write((char*)&Books[i], sizeof(Book));
	}
	file.close();
}

void AddData(int& n)
{
	int size, k;
	cout << "how many items do you want to add?\n";
	size = getinput();
	Book* Books;
	Books = (Book*)calloc(n + size, sizeof(Book));

	ifstream  fin;
	fin.open("C:\\Users\\ноут\\source\\repos\\Lab_8\\Task2.txt");

	for (int i = 0; i < n; i++)
	{
		fin.read((char*)&Books[i], sizeof(Book));
	}

	fin.close();

	ofstream fout("C:\\Users\\ноут\\source\\repos\\Lab_8\\Task2.txt", ofstream::out | ofstream::trunc);
	fout.close();

	ofstream file("C:\\Users\\ноут\\source\\repos\\Lab_8\\Task2.txt", ios_base::app);

	for (int i = 0; i < n; ++i)
	{
		file.write((char*)&Books[i], sizeof(Book));
	}

	for (int i = n; i < n + size; ++i)
	{
		cout << "enter the registration number of the book\n";
		k = getinput();
		_itoa(k, Books[i].num, 10);
		cout << "enter the author's name\n";
		cin.getline(Books[i].author, 20);
		cout << "enter the name of the book\n";
		cin.getline(Books[i].name, 20);
		cout << "enter the year of publication of the book\n";
		k = getinput();
		_itoa(k, Books[i].year, 10);
		cout << "enter the name of the publisher\n";
		cin >> Books[i].izdatelstvo;
		cout << "enter the number of pages\n";
		k = getinput();
		_itoa(k, Books[i].pages, 10);

		file.write((char*)&Books[i], sizeof(Book));
	}
	file.close();
	n += size;
}

void Delete(int& n)
{
	cout << "Which line do you want to delete?\n";
	int line;
	line = getinput();
	if (line > n)
	{
		cout << "there is no such line\n";
		exit(0);
	}
	Book* Books;
	Books = (Book*)calloc(n, sizeof(Book));

	ifstream  fin;
	fin.open("C:\\Users\\ноут\\source\\repos\\Lab_8\\Task2.txt");

	for (int i = 0; i < n; i++)
	{
		fin.read((char*)&Books[i], sizeof(Book));
	}

	fin.close();

	ofstream fout("C:\\Users\\ноут\\source\\repos\\Lab_8\\Task2.txt", ofstream::out | ofstream::trunc);
	fout.close();

	ofstream file("C:\\Users\\ноут\\source\\repos\\Lab_8\\Task2.txt", ios_base::app);
	for (int i = 0; i < line - 1; ++i)
	{
		file.write((char*)&Books[i], sizeof(Book));
	}

	for (int i = line; i < n; ++i)
	{

		file.write((char*)&Books[i], sizeof(Book));
	}
	file.close();
	--n;
}

void findData(int& n)
{
	cout << "enter the year\n";
	int year = getinput();

	Book* Books;
	Books = (Book*)calloc(n, sizeof(Book));
	Book* needed_Books;
	needed_Books = (Book*)calloc(n, sizeof(Book));

	ifstream fin;
	fin.open("C:\\Users\\ноут\\source\\repos\\Lab_8\\Task2.txt");

	for (int i = 0; i < n; i++)
	{
		fin.read((char*)&Books[i], sizeof(Book));
	}

	fin.close();

	int j = -1;
	ofstream file("C:\\Users\\ноут\\source\\repos\\Lab_8\\outTask2.txt", ios_base::app & ofstream::trunc);
	if (!file.is_open())
		cout << "error\n";
	for (int i = 0; i < n; ++i)
	{
		if (year < atoi(Books[i].year))
		{
			++j;
			strcpy_s(needed_Books[j].num, Books[i].num);
			strcpy_s(needed_Books[j].author, Books[i].author);
			strcpy_s(needed_Books[j].name, Books[i].name);
			strcpy_s(needed_Books[j].year, Books[i].year);
			strcpy_s(needed_Books[j].izdatelstvo, Books[i].izdatelstvo);
			strcpy_s(needed_Books[j].pages, Books[i].pages);
		}
	}

	if (j >= 0)
	{
		int left = 0, right = j - 1;   bool swapped = true;
		while ((left < right) && swapped)
		{
			swapped = false;
			for (int i = left; i < right; i++)
			{
				if (int(needed_Books[i].author[0]) < int(needed_Books[i + 1].author[0]))
				{
					Book temp = needed_Books[i]; needed_Books[i] = needed_Books[i + 1]; needed_Books[i + 1] = temp;
					swapped = true;
				}
			}
			right--;

			for (int i = right; i > left; i--)
			{
				if (int(needed_Books[i - 1].author[0]) < int(needed_Books[i].author[0]))
				{
					Book temp = needed_Books[i]; needed_Books[i] = needed_Books[i - 1]; needed_Books[i - 1] = temp;
					swapped = true;
				}
			}
			left++;
		}
	}

	if (j >= 0)
	{
		for (int i = 0; i <= j; ++i)
		{
			file << needed_Books[i].author;
			file << "  ";
			file << needed_Books[i].name;
			file << "  ";
			file << needed_Books[i].year;
			file << '\n';
		}
	}
	else
		cout << "there are no published books after this year\n";

	file.close();

}

int main()
{
	Book Books;
	int num, year, pages, n = 0;
	int menu;
	seemenu();
	menu = getinput();

	while (true)
	{
		switch (menu)
		{
		case 1:
			if (n == 0)
				cout << "No data\n";
			else
			{
				cout << "Number\t\tAuthor\t\tTitle\t\tPublication date\t\tPublisher\t\tPages\n";
				showData(n);
			}
			break;
		case 2:
			writeData(n);
			break;
		case 3:
			if (n == 0)
				cout << "enter the data\n";
			else
				change(n);
			break;
		case 4:
			AddData(n);
			break;
		case 5:
			if (n == 0)
				cout << "no data\n";
			else
				Delete(n);
			break;
		case 6:
			if (n == 0)
				cout << "no data\n";
			else
				findData(n);
			break;
		default:
			ofstream file("C:\\Users\\ноут\\source\\repos\\Lab_8\\Task2.txt", ofstream::out | ofstream::trunc);
			file.close();
			exit(0);
			break;
		}
		seemenu();
		menu = getinput();
	}

	return 0;
}