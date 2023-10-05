#include <iostream>
#define SIZE 5
using namespace std;

class BOX
{
private:
    float length;
    float width;
    float height;

public:
    BOX()
    {
        this->length = 0;
        this->width = 0;
        this->height = 0;
    }

    BOX(float a)
    {
        this->length = a;
        this->width = a;
        this->height = a;
    }

    BOX(float length, float width, float height)
    {
        this->length = length;
        this->width = width;
        this->height = height;
    }

    float getLength()
    {
        return this->length;
    }

    float getWidth()
    {
        return this->width;
    }

    float getHeight()
    {
        return this->height;
    }

    void acceptData()
    {
        cout << "Enter the lenght : ";
        cin >> this->length;
        cout << "Enter the width : ";
        cin >> this->width;
        cout << "Enter the height : ";
        cin >> this->height;
    }

    void displayData()
    {
        cout << "Length : " << this->length << endl;
        cout << "Breadth : " << this->width << endl;
        cout << "Height : " << this->height << endl;
    }

    void operator=(BOX &b)
    {
        this->length = b.length;
        this->width = b.width;
        this->height = b.height;
    }
    friend void operator>>(istream &in, BOX &b);
};

void operator<<(ostream &out, BOX &a)
{
    out << "Length : " << a.getLength() << endl;
    out << "Breadth : " << a.getWidth() << endl;
    out << "Height : " << a.getHeight();
}

void operator>>(istream &in, BOX &b)
{
    cout << "Enter the lenght : ";
    in >> b.length;
    cout << "Enter the width : ";
    in >> b.width;
    cout << "Enter the height : ";
    in >> b.height;
}

template <class T>
class Stack
{
private:
    int top;
    int size;
    T *arr;

public:
    Stack(int size)
    {
        this->top = 0;
        if (size > 0)
        {
            this->arr = new T[size];
            this->size = size;
        }
        else
        {
            this->arr = new T[SIZE];
            this->size = 5;
        }
    }
    void push()
    {
        if (this->top == this->size)
            cout << "Stack is full." << endl;
        else
        {
            T a;
            cout << "Enter data : ";
            cin >> a;
            this->arr[top] = a;
            this->top++;
        }
    }
    void pop()
    {
        if (this->top == 0)
            cout << "Stack is empty." << endl;
        else
        {
            T a = 0;
            this->arr[top - 1] = a;
            top--;
            cout << "Popped one element." << endl;
        }
    }
    void peek()
    {
        if (this->top == 0)
            cout << "Stack is empty." << endl;
        else
            cout << "Peak is : ";
        cout << this->arr[top - 1];
        cout << endl;
    }
    void isEmpty()
    {
        if (top == 0)
            cout << "Stack is empty." << endl;
        else
            cout << "Stack is not empty." << endl;
    }
    void isFull()
    {
        if (this->top == this->size)
            cout << "Stack is full." << endl;
        else
            cout << "Stack is not full." << endl;
    }
    void print()
    {
        if (top == 0)
            cout << "Stack is empty." << endl;
        else
        {
            cout << "Values are : " << endl;
            cout << "------------" << endl;
            for (int i = this->top - 1; i >= 0; i--)
            {
                cout << arr[i];
                cout << endl;
                cout << "------------" << endl;
            }
        }
        cout << endl;
    }

    ~Stack()
    {
        delete[] arr;
    }
};

enum menu1
{
    EXIT,
    PUSH,
    POP,
    PEEK,
    EMPTY,
    FULL,
    STACK
};

menu1 menu()
{
    int choice;
    cout << "--------------------" << endl;
    cout << "**STACK**" << endl;
    cout << "0 : To Exit" << endl;
    cout << "1 : To Push" << endl;
    cout << "2 : To Pop" << endl;
    cout << "3 : Peek" << endl;
    cout << "4 : Check Empty" << endl;
    cout << "5 : Check Full" << endl;
    cout << "6 : See Stack" << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    cout << "--------------------" << endl;
    cout << endl;
    return menu1(choice);
}

enum type_menu
{
    INT = 1,
    DOUBLE,
    box
};

type_menu menu_type()
{
    int type;
    cout << "Choose type of stack : " << endl;
    cout << "0 : EXIT" << endl;
    cout << "1 : INT" << endl;
    cout << "2 : DOUBLE" << endl;
    cout << "3 : BOX" << endl;
    cin >> type;
    return type_menu(type);
}
int main()
{
    int type;
    int size;
    int choice;
    while ((type = menu_type()) != EXIT)
    {
        switch (type)
        {
        case INT:
        {
            cout << "Enter the size of stack : ";
            cin >> size;
            Stack<int> s1(size);
            while ((choice = menu()) != EXIT)
            {
                switch (choice)
                {
                case PUSH:
                    s1.push();
                    break;
                case POP:
                    s1.pop();
                    break;
                case PEEK:
                    s1.peek();
                    break;
                case EMPTY:
                    s1.isEmpty();
                    break;
                case FULL:
                    s1.isFull();
                    break;
                case STACK:
                    s1.print();
                    break;
                default:
                    cout << "Please enter a valid choice..";
                }
            }
        }
        break;
        case DOUBLE:
        {
            cout << "Enter the size of stack : ";
            cin >> size;
            Stack<double> s1(size);
            while ((choice = menu()) != EXIT)
            {
                switch (choice)
                {
                case PUSH:
                    s1.push();
                    break;
                case POP:
                    s1.pop();
                    break;
                case PEEK:
                    s1.peek();
                    break;
                case EMPTY:
                    s1.isEmpty();
                    break;
                case FULL:
                    s1.isFull();
                    break;
                case STACK:
                    s1.print();
                    break;
                default:
                    cout << "Please enter a valid choice..";
                }
            }
        }
        break;
        case box:
        {
            cout << "Enter the size of stack : ";
            cin >> size;
            Stack<BOX> s1(size);
            while ((choice = menu()) != EXIT)
            {
                switch (choice)
                {
                case PUSH:
                    s1.push();
                    break;
                case POP:
                    s1.pop();
                    break;
                case PEEK:
                    s1.peek();
                    break;
                case EMPTY:
                    s1.isEmpty();
                    break;
                case FULL:
                    s1.isFull();
                    break;
                case STACK:
                    s1.print();
                    break;
                default:
                    cout << "Please enter a valid choice..";
                }
            }
        }
        break;
        }
    }
    cout << "Successfully Exited.." << endl;
}