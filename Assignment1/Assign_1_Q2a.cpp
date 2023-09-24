#include<iostream>
using namespace std;

struct Date {
    private:

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
        if ((year%4) == 0){
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
    printf("Enter 1 to insert\nEnter 2 to disply date\n3 to Exit\n");

    scanf("%d",&a);
    
    switch (a)
    {
    case 1 :
    d1.acceptDateFromConsole();
        break;
    case 2 :
    d1.printDateOnConsole();
    if (d1.isLeapYear())
    cout<< "It's leap year\n";
    else
    cout<< "Not a leap year\n";
    

        break;
    case 3 :
        b = 0;
        break;
    default :
       d1.initDate();
       printf("Enter valid value!\n");
       break;
    }
    } while (b);

}
