#ifndef CYLINDER_H
#define CYLINDER_H
#include<iostream>
using namespace std;

class cylinder{
    
    double height;
    double radius;
public: 
cylinder();
cylinder(double radius,double height);
void accept();
void getVolume();

int getRadius();
int getHeight();

void setRadius();
void setHeight();



};
#endif