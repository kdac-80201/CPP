#include<iostream>
using namespace std;

class Date{
    int day;
    int month;
    int year;

    public:
    Date(){
        this->day = 06;
        this->month = 01;
        this->year = 2002;

    }
    Date(int day,int month,int year){
        this->day = day;
        this->month = month;
        this->year = year;

    }
    int get_day(){
        return this->day;
    }
    void set_day(int day){
        this->day = day;
    }
    int get_month(){
        return this->month;
    }
    void set_month(int month){
        this->month = month;
    }
    int get_year(){
        return this->year;
    }
    void display(){
        cout<<"Date "<<day<<"/"<<month<<"/"<<year<<endl;
    }
    void accept(){
        cout<<"Day ";
        cin>> this->day;
        cout<<"Month ";
        cin>>this->month;
        cout<<"Year ";
        cin>>this->year;
    }
    bool is_leap_year(){
        if (this->year%400 == 0 || this->year%100 != 0 && this->year%4==0 )
            return 1;
        else
        return 0;
        
    }
};


class Person{
        string name;
        string addr;
        Date d1;

        public:
        Person(){
            this->name = "";
            this->addr = "";

        }
        Person(string name,string addr,int day,int month,int year):d1(day,month,year)
        {
            this->name = name;
            this->addr = addr;
        }

        string get_name(){
            return this->name;
        }
        void set_name(string name){
            this->name = name;
        }
        string get_addr(){
            return this->addr;
        }
        void set_addr(string addr){
            this->addr = addr;
        }
        Date get_birth_date(){
            return this->d1;
        }
        void display(){
            cout<<"*****************"<<endl;
            cout<<"Name: "<<name<<endl;
            cout<< "Address: " <<addr <<endl;
            d1.display();           

        }
        void accept(){
            cout<<"Enter Name: ";
            cin>> this->name;
            cout<<"Enter Address: ";
            cin>> this->addr;
            cout<<"Enter Birth ";
            d1.accept();
        }

        
    };


    class Employee :public Person{
        int id;
        float sal;
        string dept;
        Date d1;
        public:
        Employee(){
            this->id = 0;
            this->sal = 0.0;
            this->dept = "Knowhere";
        }
        Employee(int id,float sal,string dept,string name,string addr,int day,int month,int year,int day2,int month2,int year2):Person(name,addr,day,month,year),d1(day2,month2,year2)
        // Employee(int id,float sal,string dept,string name,string addr,int day,int month,int year,int day2,int month2,int year2):Person(name,addr,day,month,year)
        {
            this->id = id;
            this->sal = sal;
            this->dept = dept;
        }
        int get_id(){
            return this->id;
        }
        void set_id(int id){
            this->id = id;
        }
        int get_sal(){
            return this->sal;
        }
        void set_sal(){
            this->sal = sal;
        }
        string get_dept(){
            return this->dept;
        }
        void set_dept(string dept){
            this->dept = dept;
        }
        Date get_joining_date(){
            return d1;
        }
        void set_joining_date(Date d1){
            this->d1 = d1;
        }
        void display(){
            Person::display();
            cout<<"Id: "<<this->id<<endl;
            cout<<"Salary: "<<this->sal<<endl;
            cout<<"Department: "<<this->dept<<endl;
            d1.display();
        }
        void accept(){
            Person::accept();
            cout<<"Enter ID: ";
            cin>>this->id;
            cout<<"Enter Salary: ";
            cin>>this->sal;
            cout<<"Enter Department: ";
            cin>> this->dept;
            cout<<"Enter joining ";
            d1.accept();
        }
    };

    int main(){
        Employee e1(1,25000,"Develpment","afnan","balepeer",10,12,23,10,12,2002);
        e1.display();
        e1.accept();
        e1.display();

    }
