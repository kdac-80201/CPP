#include "./menu.h"
#include <iostream>
using namespace std;
Emenu menu(){
    int choice;
    cout<< "******************" <<endl;
    cout<< "0. EXIT " <<endl;
    cout<< "1. Insert " <<endl;
    cout<< "2. Display " <<endl;
    cout<< "3. InsertBySetters" <<endl;
    cout<< "4. DisplayByGetters" <<endl;
    cin>> choice;
    return Emenu(choice);
}
