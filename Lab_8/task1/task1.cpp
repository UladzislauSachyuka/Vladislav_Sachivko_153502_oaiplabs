// Лабораторная 8, задача 1. Выполнил Сачивко В.Г.
/* Различные цеха завода выпускают продукцию нескольких наименований.
Сведения о выпущенной продукции включают наименование, количество, номер
цеха. Для заданного цеха вывести количество выпущенных изделий (Шейкер
сортировка по убыванию).*/

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

struct Workshop 
{
	string name;
	int quantity;
	int workshop_number;
	int price;
	int exportation;
};

int getinput()
{
	int input;
	cin >> input;
	while (cin.get() != '\n')
	{
		cin.clear();
		cin.ignore(100000, '\n');
		printf("Incorrect input. Try again.\nEnter the value\n");
		cin >> input;
	}
	return input;
}

void seemenu() 
{
	printf("1.Entering a dynamic array of structures\n");
	printf("2.Viewing the contents of a dynamic array of structures\n");
	printf("3.Addition of new structures\n");
	printf("4.Finding and displaying a structure with a given element value\n");
	printf("5.Deleting a structure\n");
	printf("6.Changing an array element\n");
	printf("7.Sorting an array of structures by the number of products produced\n");
	printf("8.Menu exit\n");
}

Workshop* AddStruct(Workshop* Obj, const int amount) 
{
	if (amount == 0) 
	{
		Obj = new Workshop[amount + 1];
	}
	else
	{
		Workshop* tempObj = new Workshop[amount + 1];

		for (int i = 0; i < amount; ++i)
		{
			tempObj[i] = Obj[i];
		}
		delete[] Obj;

		Obj = tempObj;
	}
	return Obj;
}

void setData(Workshop* Obj, const int amount) 
{
	printf("enter the product name\n");
	char* buf = new char[100];
	scanf("%s", buf);
	Obj[amount].name = buf;
	delete[] buf;
	printf("enter the quantity of products produced\n");
	Obj[amount].quantity = getinput();
	printf("enter the workshop number\n");
	Obj[amount].workshop_number = getinput();
	printf("what is the price per product?\n");
	Obj[amount].price = getinput();
	printf("where will the products go (1 - for export, 0 - for the domestic market)?\n");
	while (true)
	{
		Obj[amount].exportation = getinput();
		if (Obj[amount].exportation == 0 || Obj[amount].exportation == 1)
			break;
		else
			printf("Incorrect input\n");
	}
}

void showData(const Workshop* Obj, const int amount) 
{
	printf("\n\nname\tquantity\tworkshop number\tprice per product\texport\n\n");
	for (int i = 0; i < amount; ++i) 
	{
		printf(Obj[i].name.c_str());
		printf("\t%d\t\t%d\t\t\t%d\t\t%d\n", Obj[i].quantity, Obj[i].workshop_number, Obj[i].price, Obj[i].exportation);
	}
}

void shaker_sort(Workshop* Obj, const int amount) 
{
	int left = 0, right = amount - 1;   bool swapped = true;
	while ((left < right) && swapped) 
	{
		swapped = false;
		for (int i = left; i < right; i++) 
		{
			if (Obj[i].quantity < Obj[i + 1].quantity) 
			{
				Workshop temp = Obj[i]; Obj[i] = Obj[i + 1]; Obj[i + 1] = temp;
				swapped = true;
			}
		}
		right--;

		for (int i = right; i > left; i--) 
		{
			if (Obj[i - 1].quantity < Obj[i].quantity) 
			{
				Workshop temp = Obj[i]; Obj[i] = Obj[i - 1]; Obj[i - 1] = temp;
				swapped = true;
			}
		}
		left++;
	}
}

Workshop* Delete(Workshop* Obj, int& amount, int num) 
{
	Workshop* tempObj = new Workshop[amount - 1];

	for (int i = 0, j = 0; i < amount; ++i, ++j)
	{
		if (i != num)
			tempObj[j] = Obj[i];
		else
			--j;
	}
	--amount;

	delete[] Obj;

	Obj = tempObj;

	return Obj;
}

void find(Workshop* Obj, const int amount) 
{
	printf("choose a parameter\n1.Name 2.Quantity 3.Workshop number 4.Price 5.Exportation\n");
	int parameter, quant, price, num, exp;
	string name1;
	parameter = getinput();

	switch (parameter) 
	{
	case 1:
		printf("enter the name\n");
		cin >> name1;
		for (int i = 0; i < amount; ++i) 
		{
			if (Obj[i].name == name1)
			{
				printf(Obj[i].name.c_str());
				printf("\t%d\t\t%d\t\t\t%d\t\t%d\n", Obj[i].quantity, Obj[i].workshop_number, Obj[i].price, Obj[i].exportation);
			}
		}
		break;
	case 2:
		printf("enter the quantity\n");
		quant = getinput();
		for (int i = 0; i < amount; ++i)
		{
			if (Obj[i].quantity == quant)
			{
				printf(Obj[i].name.c_str());
				printf("\t%d\t\t%d\t\t\t%d\t\t%d\n", Obj[i].quantity, Obj[i].workshop_number, Obj[i].price, Obj[i].exportation);
			}
		}
		break;
	case 3:
		printf("enter the workshop number\n");
		num = getinput();
		for (int i = 0; i < amount; ++i)
		{
			if (Obj[i].workshop_number == num)
			{
				printf(Obj[i].name.c_str());
				printf("\t%d\t\t%d\t\t\t%d\t\t%d\n", Obj[i].quantity, Obj[i].workshop_number, Obj[i].price, Obj[i].exportation);
			}
		}
		break;
	case 4:
		printf("enter the price\n");
		price = getinput();
		for (int i = 0; i < amount; ++i)
		{
			if (Obj[i].price == price)
			{
				printf(Obj[i].name.c_str());
				printf("\t%d\t\t%d\t\t\t%d\t\t%d\n", Obj[i].quantity, Obj[i].workshop_number, Obj[i].price, Obj[i].exportation);
			}
		}
		break;
	case 5:
		printf("enter exportation(1 - for export, 0 - for the domestic market)\n");
		while (true)
		{
			exp = getinput();
			if (exp == 0 || exp == 1)
				break;
			else
				printf("Incorrect input\n");
		}
		for (int i = 0; i < amount; ++i)
		{
			if (Obj[i].exportation == exp)
			{
				printf(Obj[i].name.c_str());
				printf("\t%d\t\t%d\t\t\t%d\t\t%d\n", Obj[i].quantity, Obj[i].workshop_number, Obj[i].price, Obj[i].exportation);
			}
		}
		break;
	default:
		printf("there is no such parameter\n");
		break;
	}
}

Workshop* input(Workshop* Workshops, int& amount)
{
	int n;
	int YesOrNot = 0;
	printf("Enter 1, if you want a certain number of structures\n");
	printf("Enter 2, if you want input before the structure with the specified attribute appears\n");
	printf("Enter 3, if you want to have a dialog\n");
	while (true) 
	{
		n = getinput();
		if (n == 1 || n == 2 || n == 3)
			break;
		else
			printf("Incorrect input\n");
	}
	
	switch (n)
	{
	case 1:
		printf("enter the number of structures\n");
		amount = getinput();
		Workshops = new Workshop[amount];
		for (int i = 0; i < amount; ++i)
		{
			printf("enter the product name\n");
			char* buf = new char[100];
			scanf("%s", buf);
			Workshops[i].name = buf;
			delete[] buf;
			printf("enter the quantity of products produced\n");
			Workshops[i].quantity = getinput();
			printf("enter the workshop number\n");
			Workshops[i].workshop_number = getinput();
			printf("what is the price per product?\n");
			Workshops[i].price = getinput();
			printf("where will the products go (1 - for export, 0 - for the domestic market)?\n");
			while (true)
			{
				Workshops[i].exportation = getinput();
				if (Workshops[i].exportation == 0 || Workshops[i].exportation == 1)
					break;
				else
					printf("Incorrect input\n");
			}
		}
		break;
	case 2:
		do
		{
			Workshops = AddStruct(Workshops, amount);
			setData(Workshops, amount);
			++amount;
		} while (Workshops[amount - 1].name != "0" && Workshops[amount - 1].quantity != 0 && Workshops[amount - 1].workshop_number != 0
			&& Workshops[amount - 1].price != 0 && Workshops[amount - 1].exportation != 0);
		break;
	case 3:
		do
		{
			Workshops = AddStruct(Workshops, amount);
			setData(Workshops, amount);

			++amount;

			printf("do you want to continue(1 - yes, 0 - no)?\n");
			while (true)
			{
				YesOrNot = getinput();
				if (YesOrNot == 0 || YesOrNot == 1)
					break;
				else
					printf("Incorrect input\n");
			}
		} while (YesOrNot != 0);
		break;
	default: 
		printf("try again\n");
		break;
	}
	return Workshops;
}

int main() 
{
	Workshop* Workshops = 0;
	Workshop* NewWorkshops;
	int workshop_amount = 0;
	int YesOrNot = 0;
	int menu, k = 0, num;
	bool fl = false;
	seemenu();
	menu = getinput();
	while (true)
	{
		switch (menu)
		{
		case 1:
			Workshops = input(Workshops, workshop_amount);
			break;
		case 2:
			if (Workshops != nullptr)
				showData(Workshops, workshop_amount);
			else
				printf("there is no data\n");
			break;
		case 3:
			Workshops = AddStruct(Workshops, workshop_amount);
			++workshop_amount;
			setData(Workshops, workshop_amount - 1);
			break;
		case  4:
			if (Workshops != nullptr) 
				find(Workshops, workshop_amount);
			else 
				printf("there is no data\n");
			break;
		case 5:
			if (Workshops != nullptr)
			{
				printf("what structure do you want to delete?\n");
				while (true)
				{
					num = getinput();
					if (num > 0 && num <= workshop_amount)
						break;
					else
						printf("Incorrect input\n");
				}
				Workshops = Delete(Workshops, workshop_amount, num - 1);
			}
			else 
				printf("there is no data\n");
			break;
		case 6:
			if (Workshops != nullptr)
			{
				printf("what structure do you want to change?\n");
				while (true)
				{
					num = getinput();
					if (num > 0 && num <= workshop_amount)
						break;
					else
						printf("Incorrect input\n");
				}
				setData(Workshops, num - 1);
			}
			else 
				printf("there is no data\n");
			break;
		case 7:
			if (Workshops != nullptr)
			{
				shaker_sort(Workshops, workshop_amount);
				showData(Workshops, workshop_amount);
			}
			else 
				printf("there is no data\n");
			break;
		case 8:
			if (Workshops != nullptr)
			{
				fl = true;
				break;
			}
			else 
				printf("there is no data\n");
		default:
			exit(0);
			break;
		}
		if (fl == true)
			break;
		seemenu();
		menu = getinput();
	}

	printf("enter the number of the workshop for which you want to find out the quantity of products\n");
	while (true)
	{
		num = getinput();
		if (num > 0 && num <= workshop_amount)
			break;
		else
			printf("Incorrect input\n");
	}
	bool flag = false;
	for (int i = 0; i < workshop_amount; ++i) 
	{
		if (Workshops[i].workshop_number == num) 
		{
			printf("the quantity of products is ");
			printf("%d\n", Workshops[i].quantity);
			flag = true;
		}
	}

	if (flag == false)
		printf("there is no such workshop\n");

	delete[] Workshops;

	return 0;
}