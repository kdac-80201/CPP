#include<iostream>
using namespace std;

class Date {

// by default private

    int day;
    int month;
    int year;

    public:

    void initDate(){
        this->day = 06;
        this->month = 01;
        this->year = 2002;

    }
    void printDateOnConsole(){
        cout << this->day <<":" << this->month << ":"<< this->year << endl;
    }
    void acceptDateFromConsole(){
        cout<<"Enter Day Month Year\n";
        cin >> this->day >> this->month >> this->year;
    }

    bool isLeapYear(){
        if (year%400 ==0  || year%100!=0 && year%4==0){
           return 1;
        }
        else
        return 0;

    }

};
int main(){

 struct Date d1;
     bool b = 1;
 
do
{
    

    int a;
    printf("Enter 1 to insert\nEnter 2 to disply date\nEnter 3 to check leap year\nEnter 4 to Exit\n");

    scanf("%d",&a);
    
    switch (a)
    {
    case 1 :
    d1.acceptDateFromConsole();
        break;
    case 2 :
    d1.printDateOnConsole();
        break;
    case 3 :
        if (d1.isLeapYear())
            cout<< "It's leap year\n";
        else
            cout<< "Not a leap year\n";
        break;

    case 4:
        b = 0;
        break;
    default :
       d1.initDate();
       printf("Enter valid value!\n");
       break;
    }
    } while (b);

}
