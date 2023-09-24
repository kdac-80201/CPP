#include <iostream>
using namespace std;

class Employee
{
private:
    int empid;
    string name;
    double salary;

public:
    Employee();
    void acceptEmployee();
    void displayEmployee();
    void increment();
};

Employee::Employee()
{
    this->empid = 0;
    this->name = "";
    this->salary = 300;
}

void Employee::acceptEmployee()
{
    cout << "Enter the empid = ";
    cin >> this->empid;
    cout << "Enter the name = ";
    cin >> this->name;
    cout << "Enter the salary = ";
    cin >> this->salary;
}
void Employee::displayEmployee()
{
    cout << "Empid = " << this->empid << endl;
    cout << "Name = " << this->name << endl;
    cout << "Salary = " << this->salary << endl;
}

void Employee::increment()
{
    this->salary = this->salary * 2;
}

enum Emenu
{
    EXIT,
    ADD_EMPLOYEE,
    DISPLAY_EMPLOYEE,
    INCREMENT
};

Emenu menu()
{
    int choice;
    cout << "*******************" << endl;
    cout << "0. EXIT" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. Display Employee" << endl;
    cout << "3. Increment Salary" << endl;
    cout << "Enter your choice = ";
    cin >> choice;
    cout << "*******************" << endl;
    return Emenu(choice);
}

int main()
{
    Employee e;
    Emenu choice;
    while ((choice = menu()) != EXIT)
    {
        switch (choice)
        {
        case ADD_EMPLOYEE:
            e.acceptEmployee();
            break;
        case DISPLAY_EMPLOYEE:
            e.displayEmployee();
            break;
        case INCREMENT:
            e.increment();
            cout << "Congratulations...You received an increment" << endl;
            break;
        default:
            cout << "Wrong choice entered ...:(" << endl;
            break;
        }
    }
    cout << "Thank you for using our app...:)" << endl;
    return 0;
}