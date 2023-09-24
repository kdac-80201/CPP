#include<iostream>
using namespace std;
class tollbooth{
    private:

    unsigned int count_cars;
    double total_cash;


public:

tollbooth(){
    count_cars = 0;
    total_cash = 0;
}
void payingCars(){

    total_cash = total_cash + 0.50;
    count_cars = count_cars + 1;

}
void nopayCar(){

    count_cars = count_cars + 1;

}
void printOnConsole(){
    
double noPayCars = count_cars - int(total_cash/0.50);
cout<< "\n********************************\n";
cout<< "Cars that didn't pay: "<<noPayCars <<endl;
cout<< "Count of cars that pays: " << (total_cash/0.50) <<endl;
cout<< "Total cash: " <<total_cash <<endl;
}
};


int main(){
tollbooth t1;

bool b1 = 1;
enum e1 {PassedByPay= 1,PassedByNotPay,ShowDetails,Exit};

do
{
cout<< "1. Passed with paying\n2. Passed Without paying\n3. Show details\n4. Exit" <<endl;
cout<<"Choose Option ";
int choice;
cin>> choice;

switch (choice)
{
case PassedByPay:
    t1.payingCars();
    break;
case PassedByNotPay:
    t1.nopayCar();
    break;
case ShowDetails:
    t1.printOnConsole();
    break;
case Exit:
    cout<<"Car was stopped by the Cop ;)";

    b1 =0;

default:
cout<< "Enter valid value! ";
    break;
}   
} while (b1);

}