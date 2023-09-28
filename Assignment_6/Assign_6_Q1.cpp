#include <iostream>
#include <string>
using namespace std;

class date
{
    int day;
    int month;
    int year;

public:
    date()
    {
        this->day = 06;
        this->month = 01;
        this->year = 2002;
    }
    date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void acceptDate()
    {
        cout << "Enter day: ";
        cin >> this->day;
        cout << "Enter month: ";
        cin >> this->month;
        cout << "Enter year: ";
        cin >> this->year;
    }
    void displayDate()
    {
        cout << day << "/" << month << "/" << year <<endl;
    }
    bool is_leap_year(){
        if (this->year%4 == 0 || this->year%100 != 0 && this->year%400 == 0)
        return 1;
        else
        return 0;
        
    }
};



class person
{
    private:
    string name;
    string addr;
    date d1;
public:
    
    person(){
        this->name = "Afnan";
        this->addr = "Beed";
    }
    person(string name,string addr)
    {
        this->name = name;
        this->addr = addr;
    }
    void set_name()
    {
        cout << "Enter name";
        cin >> this->name;
    }
    string get_name()
    {
        return this->name;
    }
    void set_addr()
    {
        cout << "Enter addr ";
        cin >> this->addr;
    }
    string get_addr()
    {
        return this->addr;
    }
    date set_birth_date()
    {
        return d1;
    }
    void get_birth_date()
    {
        this->d1.displayDate();
    }
    
    void accept()
    {
        cout << "Enter Name: ";
        cin >> this->name;
        cout << "Enter Address: ";
        cin >> this->addr;
        cout<<"Enter D.O.B: "<<endl;
        d1.acceptDate();
    }

    void display()
    {
        cout << "Name: " << this->name<<endl;
        cout << "Address: " << this->addr<<endl;
        cout << "D.O.B: ";
        d1.displayDate();
    }
};

class employee
{
private:
    int id;
    float sal;
    string dept;
    date d1;
    person p1;
public:
    
    employee()
    {
        this->id = 100;
        this->sal = 1000;
        this->dept = "Tech";
    }
    employee(int empid,string dept,double salary,int day,int month,int year):d1(day,month,year)
    {
        this->id = empid;
        this->dept = dept;
        this->sal = salary;
    }

    void set_id()
    {
        cout << "Enter Employee Id ";
    }

    int get_id()
    {
        return this->id;
    }
    void set_sal()
    {
        cout << "Enter sal";
        cin >> this->sal;
    }
    int get_sal()
    {
        return this->sal;
    }

    void set_dept()
    {
        cout << "Enter dept ";
        cin >> this->dept;
    }
    string get_dept()
    {
        return this->dept;
    }
    date set_joining_date()
    {
        return d1;
    }
    void get_joining_date()
    {
        d1.displayDate();
    }
    void accept()
    {
        p1.accept();
        cout<<"Enter dept: ";
        cin>> this->dept;
        cout<<"Employee Id: ";
        cin>> this->id;
        cout<<"Salary: ";
        cin>> this->sal;
        cout<<"Enter joining date in: "<<endl;
        this->d1.acceptDate();
    }
    void display(){
        cout<<"******************************"<<endl;
        p1.display();
        cout<<"Employee Id: " <<this->id <<endl;
        cout<<"Salary: "<<this->sal<<endl;
        cout<<"Department: "<<this->dept<<endl;
        cout<<"Joining Date: ";
        this->d1.displayDate();
    }
};

int main()
{
    employee e1;
    e1.accept();
    e1.display();

    // cout<<"1.Entry by Person 2.Entry by employee";
    // int ch;
    // cin>> ch;
    // if (ch == 1)
    // {
    //     person p1;
    //     p1.accept();
    //     p1.display();
    // }
    // else if (ch == 2)
    // {
    //     employee e1;
    //     e1.accept();
    //     e1.display();
    // }
    // else{
    //     cout<<"Invalid Option ";
    //     exit(0);
    // }
    
    
// person p1;
// p1.accept();
// p1.display();

// employee e1;
// date d1;



}