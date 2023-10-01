#include <iostream>
using namespace std;

class Product
{
    int id;
    string title;
    float price;
    char type;

public:
    Product()
    {
        this->id = 00;
        this->title = "";
        this->price = 00;
        this->type = ' ';
    }

    Product(int id, string title, int price, char type)
    {
        this->id = id;
        this->title = title;
        this->price = price;
        this->type = type;
    }
    // void set_type(char type){
    //     this->type = type;
    // }
    virtual void set_type(char type) = 0;
    virtual void accept() = 0;
    virtual void display() = 0;

    friend class Book;
    friend class Tapes;
    friend void calculateBill(Product **arr, int index);
    friend void Display_Details(Product **arr, int index);
};
class Book : public Product
{
    string author;

public:
    Book()
    {
        this->author = "";
    }
    Book(string author, int id, string title, float price, char type) : Product(id, title, price, type)
    {
        this->author = author;
    }

    void accept()
    {
        // Product::accept();

        cout << "Enter id: ";
        cin >> this->id;
        cout << "Enter Title: ";
        cin >> this->title;
        cout << "Enter Price: ";
        cin >> this->price;
        // cout<<"Enter Type: ";
        // cin>>this->type;
        cout << "Enter author ";
        cin >> this->author;
    }
    void display()
    {
        // Product::display();
        cout << "Id: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Price " << price << endl;
        cout << "Type " << type << endl;
        cout << "Author: " << author << endl;
    }
    void set_type(char type)
    {
        this->type = type;
    }
};

class Tapes : public Product
{
    string artist;

public:
    Tapes()
    {
        this->artist = "";
    }
    Tapes(string artist, int id, string title, float price, char type) : Product(id, title, price, type)
    {

        this->artist = artist;
    }
    void accept()
    {
        // Product::accept();

        cout << "Enter id: ";
        cin >> this->id;
        cout << "Enter Title: ";
        cin >> this->title;
        cout << "Enter Price: ";
        cin >> this->price;
        // cout<<"Enter Type: ";
        // cin>>this->type;
        cout << "Enter Artist: ";
        cin >> this->artist;
    }
    void display()
    {
        // Product::display();
        cout << "Id: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Price " << price << endl;
        cout << "Type " << type << endl;
        cout << "Artist " << artist << endl;
    }
    void set_type(char type)
    {
        this->type = type;
    }
};

int menu()
{
    int choice;
    cout << "0. Exit" << endl;
    cout << "1. Buy Book" << endl;
    cout << "2. Buy Tape" << endl;
    cout << "3. Display Bill" << endl;
    cout << "4. Display Details" << endl;
    cin >> choice;
    return choice;
}

int main()
{

    int choice;
    Product *arr[3];
    int index = 0;
    while ((choice = menu()) != 0)
    {

        switch (choice)
        {
        case 1:
            if (index < 3)
            {
                arr[index] = new Book();
                arr[index]->accept();
                arr[index]->set_type('B');
            }
            else
                cout << " Purchase value Exceeds" << endl;
            index++;
            break;
        case 2:
            if (index < 3)
            {
                arr[index] = new Tapes();
                arr[index]->accept();
                arr[index]->set_type('T');
            }
            else
                cout << " Purchase value Exceeds" << endl;
            index++;
            break;
        case 3:
            calculateBill(arr, index);
            // Product *p = new Tapes();
            break;
        case 4:
            Display_Details(arr, index);
        default:
            break;
        }
    }
    return 0;
}

void calculateBill(Product **arr, int index)
{
    int i = 0;
    int bk = 0;
    int tp = 0;
    int bookQty = 0;
    int TapeQty = 0;
    // int bookPrice = 0;
    // int tapePrice = 0;

    for ( ;i < index; i++)
    {
        if (arr[i]->type == 'B')
        {
            // arr[i]->display();
            bk = bk + arr[i]->price;
            bookQty = bookQty + 1;
        }
        else if(arr[i]->type == 'T')
        {
            // arr[i]->display();
            tp = tp + arr[i]->price;
            TapeQty = TapeQty + 1;
        }
    }
    cout << "********Bill********" << endl;
    if (bk != 0 && tp != 0)
    {
        cout << "Book Qty " << bookQty << " Price: " << bk << endl;
        cout << "Tape Qty " << TapeQty << " Price: " << tp << endl;
        cout << "Bill with Discount " << (bk - (0.1 * bk)) + (tp - (0.05 * tp))<<endl;
        cout<<"Total Bill "<< bk+tp<<endl;
    }
    if (bk!= 0)
    {
        cout<<"Book Qty "<<bookQty<<endl; 
        cout<<"Total Bill "<<bk<<endl;

    }
    else{
        cout<<"Book Qty "<<TapeQty<<endl; 
        cout<<"Total Bill "<<tp<<endl;   
    }
    
}

void Display_Details(Product **arr, int index)
{
    for (int i = 0; i < index; i++)
    {
        arr[i]->display();
    }
}