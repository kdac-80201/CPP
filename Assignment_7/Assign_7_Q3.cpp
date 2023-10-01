#include <iostream>
using namespace std;

class employee
{
private:
    int id;
    float sal;
    string designation;

public:
    employee()
    {
        this->id = 0;
        this->sal = 0;
        this->designation = "";
    }

    employee(int id, float sal, string designation)
    {
        this->id = id;
        this->sal = sal;
        this->designation = designation;
    }

    int get_id()
    {
        return this->id;
    }
    void set_id(int id)
    {
        this->id = id;
    }
    void set_sal(float sal)
    {
        this->sal;
    }
    float get_sal()
    {
        return this->sal;
    }
    string get_designation()
    {
        return this->designation;
    }

    virtual void set_designation(string desg) = 0;
    virtual void display() = 0;
    virtual void accept() = 0;
    friend void display_count(employee **ptr, int index);
    friend void Designation(employee **arr, int index);

    friend class manager;
    friend class salesman;
    friend class sales_manager;
};

class manager : virtual public employee
{
private:
    float bonus;

public:
    manager()
    {
        this->bonus = 00;
    }
    manager(float bonus)
    {
        this->bonus = bonus;
    }
    manager(float bonus, int id, float sal, string designation) : employee(id, sal, designation)
    {
        this->bonus = bonus;
    }
    int get_bonus()
    {
        return this->bonus;
    }
    void set_bonus(float bonus)
    {
        this->bonus = bonus;
    }
    void display()
    {
        cout<<"Id: "<<id<<endl;
        cout<<"Salary: "<<sal<<endl;
        cout<<"Designation: "<<designation<<endl;
        cout << "Bonus: " << bonus << endl;
    }
    void accept()
    {
        cout << "Enter Id ";
        cin >> id;
        cout << "Enter Salary ";
        cin >> sal;
        // cout << "Enter Designation ";
        // cin >> designation;
        cout << "Enter bonus ";
        cin >> bonus;
    }
    void set_designation(string desg)
    {
        this->designation = desg;
    }

protected:
    void display_manager()
    {
        cout << "Id " << id << endl;
        cout << "Salary " << sal << endl;
        cout << "Designation " << designation << endl;
        cout << "Bonus " << this->bonus << endl;
    }
    void accept_manager()
    {
        // cout << "Enter Id ";
        // cin >> id;
        // cout << "Enter Salary ";
        // cin >> sal;
        cout << "Enter bonus";
        cin >> this->bonus;
    }
};

class salesman : virtual public employee
{
private:
    float comm;

public:
    salesman()
    {
        this->comm = 00;
    }
    salesman(float comm)
    {
        this->comm = comm;
    }
    salesman(float comm, int id, float sal, string designation) : employee(id, sal, designation)
    {
        this->comm = comm;
    }
    float get_comm()
    {
        return this->comm;
    }
    void set_comm(float comm)
    {
        this->comm = comm;
    }
    void display()
    {
        cout<<"Id: "<<id<<endl;
        cout<<"Salary: "<<sal<<endl;
        cout<<"Designation: "<<designation<<endl;
        cout << "Commission: " << this->comm << endl;
    }
    void accept()
    {
        cout << "Enter Id ";
        cin >> id;
        cout << "Enter Salary ";
        cin >> sal;
        // cout << "Enter Designation ";
        // cin >> designation;
        cout << "Enter commision: ";
        cin >> comm;
    }
    void set_designation(string desg)
    {
        this->designation = desg;
    }

protected:
    void display_salesman()
    {
        cout << "Id " << id << endl;
        cout << "Salary " << sal << endl;
        cout << "Designation " << designation << endl;
        cout << "Commision " << comm << endl;
    }
    void accept_salesman()
    {
        // cout << "Enter Id ";
        // cin >> id;
        // cout << "Enter Salary ";
        // cin >> sal;
        // cout << "Enter Designation ";
        // cin >> designation;
        cout << "Enter commission: ";
        cin >> this->comm;
    }
};

class sales_manager : public manager, public salesman
{

public:
    sales_manager() {}
    sales_manager(int id, float sal, float bonus, float comm) : employee(id, sal, designation), manager(bonus), salesman(comm)
    {
        // this->set_id(id);
        // this->set_sal(sal);
        // this->set_bonus(bonus);
        // this->set_comm(bonus);
    }
    void display()
    {
        manager::display();
         cout<< "Commision: "<<salesman::get_comm()<<endl;
    }

    void accept()
    {
        manager::accept();
        salesman::accept_salesman();

        // salesman::accept_salesman();
        // manager::accept_manager();
    }
    void set_designation(string desg)
    {
        this->designation = desg;
    }
};

int menu()
{
    int choice;
    cout << "********************" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Accept Employee" << endl;
    cout << "2. Display Employee Count" << endl;
    cout << "3. Display All Employee" << endl;
    cout << "Enter choice " << endl;
    cin >> choice;
    if (choice == 1)
    {
        cout << "*******************" << endl;
        cout << "Enter choice" << endl;
        cout << "10. Accept Manager " << endl;
        cout << "20. Accept Salesman " << endl;
        cout << "30. Accept Sales Manager " << endl;
        cout << "*******************" << endl;
        cin >> choice;
    }
    return choice;
}

int main()
{
    // sales_manager sm(19, 9898.2, 20.69, 56.66);
    // sm.display();
    // sm.accept();
    // sm.display();

    int choice;
    employee *arr[10];
    int index = 0;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 10:
            if (index < 10)
            {
                arr[index] = new manager();
                arr[index]->set_designation("Manager");
                arr[index]->accept();
            }
            else
                cout << "Accept limit exceeds" << endl;
            index++;
            break;
        case 20:
            if (index < 10)
            {
                arr[index] = new salesman();
                arr[index]->set_designation("Salesman");
                arr[index]->accept();
            }
            else
                cout << "Accept limit exceeds" << endl;
            index++;
            break;
        case 30:
            if (index < 10)
            {
                arr[index] = new sales_manager();
                arr[index]->set_designation("Sales Manager");
                arr[index]->accept();
            }
            else
                cout << "Accept limit exceeds" << endl;
            index++;
            break;

        case 2:
            display_count(arr, index);
            break;
        case 3:
            Designation(arr, index);
            break;
        default:
            cout << "Wrong choice";
            break;
        }
    }
    for (int i = 0; i < index; i++)
        delete arr[i];

    return 0;
}

void display_count(employee **ptr, int index)
{
    int mgr = 0;
    int salesmn = 0;
    int salesmgr = 0;
    for (int i = 0; i < index; i++)
    {

        if (typeid(*ptr[i]) == typeid(manager))
        {
            mgr++;
        }
        else if (typeid(*ptr[i]) == typeid(salesman))
        {
            salesmn++;
        }
        else
            salesmgr++;
    }

    cout << "********Count of Employee********" << endl;
    cout << "Manager count " << mgr << endl;
    cout << "Salesman count " << salesmn << endl;
    cout << "Sales Manager " << salesmgr << endl;
}

void Designation(employee **arr, int index)
{
    int mgr = 0;
    int salesmn = 0;
    int salesmgr = 0;
    for (int i = 0; i < index; i++)
    {

        if (typeid(*arr[i]) == typeid(manager))
        {
            mgr++;
        }
        else if (typeid(*arr[i]) == typeid(salesman))
        {
            salesmn++;
        }
        else if(typeid(*arr[i]) == typeid(sales_manager))
            salesmgr++;
    }


    cout<<"Manager "<<mgr<<" Salesman "<<salesmn<<" sales manager "<<salesmgr<<endl;

    if (mgr != 0)
    {
        cout << "********Manager******** " << endl;
        for (int i = 0; i < index; i++)
        {
            if (typeid(*arr[i]) == typeid(manager))
            {
                arr[i]->display();
            }
        }
    }
    if (salesmn != 0)
    {
        cout << "********Salesman********" << endl;

        for (int i = 0; i < index; i++)
        {
            if (typeid(*arr[i]) == typeid(salesman))
            {
                arr[i]->display();
            }
        }
    }
    if (salesmgr != 0)
    {
        cout << "********Sales Manager********" << endl;

        for (int i = 0; i < index; i++)
        {
            if (typeid(*arr[i]) == typeid(sales_manager))
            {
                arr[i]->display();
            }
        }
    }
}
