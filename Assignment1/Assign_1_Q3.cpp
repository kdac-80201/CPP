#include<iostream>
#include<string>
using namespace std;

class Student{

    int roll_no;
    string name;
    float marks;

public:

void initStudent(){
  this->roll_no = 0;
  this->name = "";
  this->marks= 0;
}

void acceptStudentFromConsole(){
    cout<< "Enter Rollno" <<endl; 
    cin>> this->roll_no;
    cout<<"Name" <<endl;
    cin>>this->name;
    cout<< "Name Marks" << endl;
    cin>> this->marks;
}

void printStudentOnConsole(){
cout<<"Rollno: "<< this->roll_no <<" Name: " << name <<" Marks: " <<marks <<endl;
}


};

int main(){
   struct Student s1;
   bool b = 1;
   do
{
    

    int a;
    printf("Enter 1 to insert\nEnter 2 to disply date\n3 to Exit\n");

    scanf("%d",&a);
    
    switch (a)
    {
    case 1 :
    s1.acceptStudentFromConsole();
        break;
    case 2 :
    s1.printStudentOnConsole();
    

        break;
    case 3 :
        b = 0;
        break;
    default :
       s1.initStudent();
       printf("Enter valid value!\n");
       break;
    }
    } while (b);

}
