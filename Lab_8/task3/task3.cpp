#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>

using namespace std;

string P_in = "inTask3.txt";
string P_out = "outTask3.txt";
ofstream fout;
ifstream fin;

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

class Employee 
{
public:

    Employee() {
        char name[] = " ";
        char last_name[] = " ";
        char patronymic[] = " ";
        char pers_number[] = " ";
        char hours_worked[] = " ";
        char hourly_rate[] = " ";
    }

    void print_employee() 
    {
        cout << "Name: " << name << '\n';
        cout << "Last name:" << last_name << '\n';
        cout << "Patronymic: " << patronymic << '\n';
        cout << "Personal number: " << pers_number << '\n';
        cout << "Working hours: " << hours_worked << '\n';
        cout << "Hourly rate: " << hourly_rate << '\n';
    }

    void set_inf() 
    {
        int num;
        double hours;
        double h_rate;
        cout << "Type the name of worker\n";
        cin >> name;
        cout << "Type the last name of worker\n";
        cin >> last_name;
        cout << "Type the patronymic of worker\n";
        cin >> patronymic;
        cout << "Type the personal number of worker\n";
        num = getinput();
        _itoa(num, pers_number, 10);
        cout << "Type the hours person worked\n";
        hours = getinput();
        _itoa(hours, hours_worked, 10);
        cout << "Type the hourly rate\n";
        h_rate = getinput();
        _itoa(h_rate, hourly_rate, 10);
    }

    double get_salary() 
    {
        double overtime = 0;
        if (atoi(hours_worked) > 144) 
        {
            overtime = atoi(hours_worked) - 144;
            _itoa(144, hours_worked, 10);
        }
        double salary = (atoi(hours_worked) * atoi(hourly_rate) + overtime * 2 * atoi(hourly_rate)) * 0.88;
        return salary;
    }

    void print_salary() 
    {
        cout << "Worker " << name << " " << last_name << " " << patronymic << " get salary\n";
        cout << get_salary();
        cout << "\n\n";
    }

private:
    char name[15];
    char last_name[15];
    char patronymic[15];
    char pers_number[15];
    char hours_worked[15];
    char hourly_rate[15];
};

void input(int* n) 
{
    cout << "Enter the number of workers\n";
    int k;
    k = getinput();

    Employee* em = (Employee*)calloc(k, sizeof(Employee));

    fout.open(P_out, ofstream::app & ofstream::trunc);

    if (!fout.is_open()) 
        cout << "Cannot open the file!\n";
    else 
    {
        for (int i = 0; i < k; ++i) 
        {
            em[i].set_inf();
            fout.write((char*)&em[i], sizeof(Employee));
        }
    }
    fout.close();
    *n = k;
}

void view(int size) 
{
    fin.open(P_out);
    auto e = (Employee*)calloc(size, sizeof(Employee));
    if (!fin.is_open()) 
        cout << "Cannot open the file!\n";
    else 
    {
        for (int i = 0; i < size; i++) 
        {
            fin.read((char*)&e[i], sizeof(Employee));
            cout << i + 1 << ":\n";
            e[i].print_employee();
            cout << "\n\n";
        }
    }
    fin.close();
}

void add(int* n) 
{
    fout.open(P_out, fstream::app);
    if (!fout.is_open()) 
        cout << "Cannot open the file!\n";
    else 
    {
        int size = (*n);
        cout << "Enter the number of records you want to add\n";
        int rec;
        rec = getinput();
        auto* e = (Employee*)calloc(rec, sizeof(Employee));
        for (int i = 0; i < rec; ++i) 
        {
            e[i].set_inf();
            fout.write((char*)&e[i], sizeof(Employee));
        }
        *n = size + rec;
    }
    fout.close();
}

void deleting(int* n) 
{
    cout << "Type the number of record you want to delete:\n";
    int rec;
    rec = getinput();
    while (rec > (*n))
    {       
        cout << "Incorrect input\n";
        rec = getinput();
    }

    fin.open(P_out);

    for (int i = 0; i < rec; i++) 
    {
        fin.seekg(sizeof(Employee));
    }

    int size = 0;

    for (int i = rec; i <= *(n); i++) 
        size++;

    Employee* employees = new Employee[size];

    for (int i = 0; i < size; i++) 
    {
        fin.read((char*)&employees[i], sizeof(Employee));
    }
    fin.close();
    for (int i = 0; i < size - 1; i++) 
    {
        employees[i] = employees[i + 1];
    }
    filesystem::resize_file(P_out, (rec - 1) * sizeof(Employee));

    fout.open(P_out, ios_base::app);
    for (int i = 0; i < size - 1; i++) 
    {
        fout.write((char*)&employees[i], sizeof(Employee));
    }
    fin.close();
    (*n)--;
}

void edit(int n) 
{
    Employee* e = (Employee*)calloc(n, sizeof(Employee));
    fin.open(P_out);
    if (!fin.is_open()) 
        cout << "Cannot open the file!\n";
    else 
    {
        for (int i = 0; i < n; ++i) 
        {
            fin.read((char*)&e[i], sizeof(Employee));
        }
    }
    fin.close();

    cout << "Enter the number of worker you want to edit\n";
    int rec;
    rec = getinput();

    while (rec < 0 || rec > n) 
    {
        cout << "Incorrect value\n";
        cin.clear();
        cin.ignore(32767, '/n');
        rec = getinput();
    }

    for (int i = 0; i < n; ++i) 
    {
        if (i == rec - 1) 
            e[i].set_inf();
    }

    fout.open(P_out, fstream::trunc);
    if (!fout.is_open()) 
        std::cout << "Cannot open the file!\n";
    else 
    {
        for (int i = 0; i < n; i++) 
        {
            fout.write((char*)&e[i], sizeof(Employee));
        }
    }
    fout.close();
}

void task(int n) 
{
    Employee* e = (Employee*)calloc(n, sizeof(Employee));
    fin.open(P_out);
    if (!fin.is_open()) 
        cout << "Cannot open the file!\n";
    else 
    {
        for (int i = 0; i < n; ++i) 
        {
            fin.read((char*)&e[i], sizeof(Employee));
        }
    }
    fin.close();

    for (int i = 0; i < n; ++i) 
    {
        e[i].print_salary();
    }

    fout.open(P_in, std::fstream::app & std::fstream::trunc);
    if (!fout.is_open()) 
        std::cout << "Cannot open the file!\n";
    else 
    {
        for (int i = 0; i < n; ++i) 
        {
            fout << e[i].get_salary() << "\n";
        }
    }
    fout.close();
}

void show_menu() 
{
    cout << "1. Create new file\n";
    cout << "2. Read the file\n";
    cout << "3. Add new employee record\n";
    cout << "4. Delete record\n";
    cout << "5. Edit record\n";
    cout << "6. Show employees salary\n";
    cout << "7. Program exit\n";
}

int main() 
{
    int menu;
    int n = 0;
    bool is_exit = false;

    while (!is_exit) 
    {
        show_menu();
        menu = getinput();
        switch (menu) 
        {
        case 1:
            input(&n);
            break;
        case 2:
            if (n == 0) 
                cout << "You should add information before view it\n";
            else 
                view(n);
            break;
        case 3:
            add(&n);
            break;
        case 4:
            if (n == 0)
                cout << "You should add information before deleting it\n";
            else
                deleting(&n);
            break;
        case 5:
            if (n == 0) 
                cout << "You should add information before changing it\n";
            else 
                edit(n);
            break;
        case 6:
            if (n == 0) 
                cout << "You should add information before completing the task\n";
            else 
                task(n);
            break;
        default:
            is_exit = true;
        }
    }
    return 0;
}