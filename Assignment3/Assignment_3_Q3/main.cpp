#include "./cylinder.h"
#include "./menu.h"
using namespace std;

int main(){
    cylinder c1;
    cylinder c2(10.20,20.1);

    // c1.accept();
    // c1.getVolume();
    Emenu choice;

    while ((choice = menu()) != Exit)
    {
        switch (choice)
        {
        case Insert:
            c1.accept();
            break;
        case Display:
        c1.getVolume();
        break;
        case InsertBySetter:
        c1.setHeight();
        c1.setRadius();
        break;
        case DisplayBygetter:
        cout<< "Volume = " << c1.getRadius() * c1.getRadius() * c1.getHeight() <<endl;
        break;
        
        default:
        cout<< "Wrong choice enter again! ";
            break;
        }
    }
    }