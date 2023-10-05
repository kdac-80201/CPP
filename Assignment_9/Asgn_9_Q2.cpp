#include <iostream>
using namespace std;

enum account_type
{
    EXIT1,
    SAVING,
    CURRENT,
    DMAT
};

class insufficient_funds
{
private:
    int accid;
    double cur_balance;
    double withdraw_amount;

public :

insufficient_funds()
{
    cout<<"Insufficient Funds."<<endl;
}

insufficient_funds(int id, double cur_balance, double withdrawl_amount)
{
    this->accid = id;
    this->cur_balance = cur_balance;
    this->withdraw_amount = withdrawl_amount;
}

void display()
{
    cout<<"ERROR 4002 : Insufficient Balance"<<endl;
    cout<<"ID : "<<this->accid<<endl;
    cout<<"Current Balance : "<<this->cur_balance<<endl;
    cout<<"Withdrawl Ammount : "<<this->withdraw_amount<<endl;
}
};

class account
{
private:
    int id;
    account_type type;
    double balance;

public:
    account()
    {
        this->id = 0;
        this->type = SAVING;
        this->balance = 0;
    }

    account(int id, account_type type)
    {
        this->id = id;
        this->type = type;
        cout<<"Account created successfully."<<endl;
    }

    void accept(int id)
    {
        this->id = id;
        if(this-> id < 0)
        throw 2004;

        string name;
        cout << "Enter Account Type : ";
        cin >> name;
        if (name == "SAVING")
            this->type = SAVING;
        else if (name == "CURRENT")
            this->type = CURRENT;
        else if (name == "DMAT")
            this->type = DMAT;
        else
        throw 1000;
    }

    void display()
    {
        cout << "ID : " << this->id << endl;
        cout << "Type : ";
        switch (this->type)
        {
        case SAVING:
            cout << "SAVING" << endl;
            break;
        case CURRENT:
            cout << "CURRENT" << endl;
            break;
        case DMAT:
            cout << "DMAT" << endl;
            break;
        }
        cout << "Balance : " << this->balance << endl;
    }

    void set_id(int id)
    {
        this->id = id;
    }

    double get_id()
    {
        return this->id;
    }

    void set_type(account_type type)
    {
        this->type = type;
    }

    int get_type()
    {
        return this->type;
    }

    double get_balance()
    {
        return this->balance;
    }

    void deposit(double amount)
    {
        this->balance = this->balance + amount;
        cout<<"Deposited Successfully."<<endl;
        cout<<"Current Balance : "<<this->balance<<endl;
    }

    void withdraw(double amount)
    {
        if(amount > this->balance)
        throw insufficient_funds(this->id, this->balance, amount);
        this->balance = this->balance - amount;
        cout<<"Withdrawed Successfully.."<<endl;
        cout<<"Remaining Balance : "<<this->balance<<endl;
    }
};

enum create_account
{
    ID,
    ACCOUNT_TYPE,
    BALANCE
};

enum menu_1
{
    EXIT,
    CREATE_ACCOUNT,
    WITHDRAW,
    DEPOSIT,
    DISPLAY
};

menu_1 menu()
{
    int choice;
    cout<<"-----------------------"<<endl;
    cout<<"**State Bank of India**"<<endl;
    cout<<"0 : EXIT"<<endl;
    cout<<"1 : Create Account"<<endl;
    cout<<"2 : Withdraw Ammount"<<endl;
    cout<<"3 : Deposit Ammount"<<endl;
    cout<<"4 : Display Details"<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;
    cout<<"-----------------------"<<endl;
    return menu_1(choice);
}
account_type menu_2()
{
    int choice;
    cout<<"-----------------------"<<endl;
    cout<<"0 : EXIT"<<endl;
    cout<<"1 : SAVING"<<endl;
    cout<<"2 : CURRENT"<<endl;
    cout<<"3 : DMAT"<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;
    cout<<"-----------------------"<<endl;
    return account_type(choice);
}


int main()
{
    int choice;
    account *arr[5];
    int index = 0;
    while((choice = menu())!=EXIT)
    {
        switch(choice)
        {
            case CREATE_ACCOUNT : try
                                  {
                                    if(index==5)
                                    throw 6006;
                                    int account_type1 = menu_2();
                                    if(account_type1 == EXIT1) break;
                                    if(account_type1 != EXIT1 && account_type1 != SAVING && account_type1!=CURRENT && account_type1!=DMAT)
                                    throw 2020;
                                    int id;
                                    cout<<"Enter ID : ";
                                    cin>>id;
                                    if(id<=0)
                                    throw 2004;
                                    for(int i=0; i<index; i++)
                                    {
                                        if(arr[i]->get_id() == id)
                                        throw 1000;
                                    }
                                    arr[index] = new account(id, (account_type)account_type1);
                                    index++;
                                  }
                                  catch(int a)
                                  {
                                    if(a == 1000)
                                    cout<<"Error "<<a<<" : ID already exists."<<endl;
                                    else if(a == 2004)
                                    cout<<"Error "<<a<<" : ID must be positive."<<endl;
                                    else if(a == 2020)
                                    cout<<"Error "<<a<<" : Entered Invalid Account Type."<<endl;
                                    else if(a == 6006)
                                    cout<<"Cannot create more accounts."<<endl;
                                  }
                                  break;
            case WITHDRAW       : try
                                  {
                                    int id;
                                    cout<<"Enter ID : ";
                                    cin>>id;
                                    if(id<=0)
                                    throw 3002;
                                    for(int i = 0; i<index; i++)
                                    {
                                        if(arr[i]->get_id() == id)
                                        {
                                            double amount;
                                            cout<<"Enter Withdrawl Amount : ";
                                            cin>>amount;
                                            try
                                            {
                                                arr[i]->withdraw(amount);
                                            }
                                            catch(insufficient_funds i1)
                                            {
                                                i1.display();
                                            }
                                        }
                                        else throw 1000;
                                    }
                                  }
                                  catch(int a)
                                  {
                                    if(a == 3002)
                                    cout<<"Please enter a valid ID.."<<endl;
                                    else if(a==1000)
                                    cout<<"ID not found."<<endl;
                                  }
                                  break;
            case DEPOSIT        : try
                                  {
                                    int id;
                                    cout<<"Enter ID : ";
                                    cin>>id;
                                    if(id<=0)
                                    throw 3002;
                                    for(int i = 0; i<index; i++)
                                    {
                                        if(arr[i]->get_id() == id)
                                        {
                                            double amount;
                                            cout<<"Enter Deposit Amount : ";
                                            cin>>amount;
                                            if(amount==0)
                                            throw 4005;
                                            arr[i]->deposit(amount);
                                        }
                                        else throw 1000;
                                    }
                                  }
                                  catch(int a)
                                  {
                                    if(a == 3002)
                                    cout<<"Please enter a valid ID.."<<endl;
                                    else if(a==1000)
                                    cout<<"ID not found."<<endl;
                                    else if(a==4005)
                                    cout<<"Please enter a valid amount.."<<endl;
                                  }
                                  break;
                        default : cout<<"Entered Wrong Choice.."<<endl;
            case DISPLAY : try
                                  {
                                    int id;
                                    cout<<"Enter ID : ";
                                    cin>>id;
                                    if(id<=0)
                                    throw 3002;
                                    for(int i = 0; i<index; i++)
                                    {
                                        if(arr[i]->get_id() == id)
                                        {
                                            arr[i]->display();
                                        }
                                        else throw 1000;
                                    }
                                  }
                                  catch(int a)
                                  {
                                    if(a == 3002)
                                    cout<<"Please enter a valid ID.."<<endl;
                                    else if(a==1000)
                                    cout<<"ID not found."<<endl;
                                    else if(a==4005)
                                    cout<<"Please enter a valid amount.."<<endl;
                                  }
                                  break;
            
        }
    }

    for(int i = 0; i<index; i++)
    delete arr[i];
    cout<<"Exited Successfully.."<<endl;
}