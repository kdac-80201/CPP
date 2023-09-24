#include<iostream>
using namespace std;

class Box{
    private:

    float length;
    float width;
    float height;

    public:

    Box(){
        length = 1;
        width = 1;
        height = 1;
    }
void accept(){
    cout<< "Enter lenght ";
    cin>> length;
    cout<< "Enter Width ";
    cin>> width;
    cout<< "Enter Height ";
    cin>> height;

}
void display(){
    cout<<" Volume of the box: " <<length*width*height;
}
    
};

int main(){

Box bo;

enum e{Exit,Input,Display};
bool b = 1;
do
{
cout<< "\n*************************\n";
cout<< "Enter 0 to Exit\nEnter 1 for input\nEnter 2 for Display\n" <<endl;
cout<< "Enter choice "<< endl;
int count;
cin>> count;
switch (count)
{
case Exit:
   b = 0;
   cout<< "Thank you for using my s/w ]>_<[ "<<endl;
    break;

case Input:
    bo.accept();
break;


case Display:
    bo.display();

break;


default:
cout<< "Please enter valid value! ";
    break;
}


} while (b);


}