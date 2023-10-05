#include<iostream>
using namespace std;

int factorial(int number)
{
    int factorial = 1;
    if(number<0)
    throw 1000;
    if(number == 0)
    return 1;
    else
    {
        for(int i = 1; i<=number; i++)
        factorial = factorial*i;
        return factorial;
    }
}

int main()
{
    int number;
    int fact_num;
    cout<<"Enter the number : ";
    cin>>number;
    try
    {
        fact_num = factorial(number);
        cout<<"Factorial is : "<<fact_num<<endl;
    }
    catch(int a)
    {
        cout<<"ERROR "<<a<<" : Entered a negative value."<<endl;
    }

    return 0;
}