#include<iostream>
#include<iostream>
using namespace std;

class Address{
    private:

    string building;
    string street;
    string city;
    int pin;

public:

Address(){
   cout<<"Parameterless constructor called\n";
}

Address(string b,string s,string c,int p){
    string building = b;
    string street = s;
    string city = c;
    int pin = p;
}

void accept(){
    cout<< "Enter Building name ";
    cin>> this->building;

    cout<< "Enter street name ";
    cin>> this->street;

    cout<< "Enter City ";
    cin>> this ->city;

    cout<< "Enter pincode ";
    cin>> this->pin;
}

void display(){
    cout<< "Bulding name "<<this->building << " Street name " <<street <<endl;
    cout<< " City name" << this->city << " Pincode " << this->pin <<endl;

}
 void get_building(){
    cout<< "Building: " <<this->building <<"\n";
}
void get_street(){
    cout<< "Street name: " <<this->street <<"\n";
}
void get_city(){
    cout<< "City name: " <<this->city <<"\n";
}
void get_pin(){
    cout<< "Pincode: " <<this->pin <<"\n";
}


void set_buiding(){
    cout<< "Enter Building Name:\n";
    cin>> this->building;
}
void set_street(){
    cout<< "Enter Street Name:\n";
    cin>> this->street;
}
void set_city(){
    cout<< "Enter City name:\n";
    cin>> this-> city;
}

void set_pin(){
    cout<< "Enter pincode:\n";
    cin>> this->pin;
}


};

int main(){
    Address ad;             // parameterless Constructor will be called 
    Address("Baig","Balepeer","Beed",431122); // parameterized Constructor will be called 

    ad.accept();            // Use to insert values
    ad.display();           // Use to Print values into terminal
    ad.get_building();      // rest are individual diplay function calls
    ad.get_street();
    ad.get_city();
    ad.get_pin();

    ad.set_buiding();       // rest are individual insert function calls
    ad.set_street();
    ad.set_city();
    ad.set_pin();
}