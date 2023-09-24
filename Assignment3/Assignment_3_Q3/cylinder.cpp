#include "./cylinder.h"

cylinder :: cylinder(){
    this -> radius = 1;
    this -> height = 1;
}

cylinder:: cylinder(double radius,double height){
this->radius = radius;
this -> height = height;
}

void cylinder::accept(){
    cout<< "Enter Height: ";
    cin>> this->height;
    cout<< "Enter radius: ";
    cin>> this ->radius; 
}
int cylinder ::getRadius(){
    return this->radius;
}
int cylinder ::getHeight(){
    return this->height;
}
void cylinder ::setRadius(){
    cout<<"Enter Radius ";
    cin>> this->radius;
}
void cylinder ::setHeight(){
    cout<< "Enter height ";
    cin>> this->height;
}


void cylinder ::getVolume(){
    int volume = this-> getRadius() * this-> getRadius() * this -> getHeight();

    cout<< "Volume of cylinder = "<< volume <<endl;
}