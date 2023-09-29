#include<iostream>
using namespace std;



class employee{
    private:
    int id;
    float sal;
    public:

    employee(){
        this->id = 0;
        this->sal = 2000;
    }

    employee(int id,float sal)
    {
        this->id = id;
        this->sal = sal;
    }

    int get_id(){
        return this->id;
    }
    void set_id(int id){
        this->id = id;
    }
    void set_sal(float sal){
        this->sal;
    }
    float get_sal(){
        return this->sal;
    }

    void display(){
        cout<<"Id "<< id<<endl;
        cout<<"Salary "<< sal<<endl;
    }
    void accept(){
        cout<<"Enter Id ";
        cin>> id;
        cout<<"Enter Salary ";
        cin>>sal;
    }

};

class manager : virtual public employee{
    private:
        float bonus;
    public:
    manager(){
        this ->bonus = 20;
    }
    manager(float bonus){
        this->bonus = bonus;
    }
    manager(float bonus,int id,float sal): employee(id,sal)
    {
        this->bonus = bonus;
    }
    int get_bonus(){
        return this->bonus;
    }
    void set_bonus(float bonus){
        this->bonus = bonus;
    }
    void display(){
        cout<<"Bonus "<< bonus<<endl;
    }
    void accept(){
        cout<<"Enter bonus ";
        cin>> bonus;
    }
    protected:
    void display_manager(){
        cout<<"Bonus "<<this->bonus<<endl;
    }
    void accept_manager(){
        cout<<"Enter bonus";
        cin>> this->bonus;

    }
};

class salesman : virtual public employee{
    private:
    float comm;
    public:
    salesman(){
        this-> comm = 10;
    }
    salesman(float comm){
        this->comm = comm;
    }
    salesman(float comm,int id,float sal):employee(id,sal){
        this->comm = comm;
    }
    float get_comm(){
        return this->comm;
    }
    void set_comm(float comm){
        this->comm = comm;
    }
    void display(){
        cout<<"Commission "<<this->comm <<endl;
    }
    void accept(){
        cout<<"Enter commision ";
        cin>> comm;
    }
    protected:
    void display_salesman(){
        cout<<"Commision "<<comm<<endl;
    }
    void accept_saleman(){
        cout<<"Enter commission "<<endl;
        cin>> this->comm;
    }
};


class sales_manager : public manager,public salesman {
    private: 
    
    public:
    sales_manager(int id,float sal,float bonus,float comm):employee(id,sal),manager(bonus),salesman(comm)
     {
        // this->set_id(id);
        // this->set_sal(sal);
        // this->set_bonus(bonus);
        // this->set_comm(bonus);
        

    }
    void display(){
        employee::display();
        manager::display_manager();
        salesman::display_salesman(); 
    }

    void accept(){
        employee::accept();
        manager::accept_manager();
        salesman::accept_saleman();      
    }
    
    
};

int main(){
    sales_manager sm(19,9898.2,20.69,56.66);
    sm.display();
    sm.accept();
    sm.display();

}