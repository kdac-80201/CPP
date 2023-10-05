#include<iostream>
#define SIZE 5
using namespace std;

class Stack
{
    private :
    int top;
    int size;
    int *arr;

    public:

    Stack()
    {
        this->top = 0;
        this->arr = NULL;
        this->size = 5;
    }

    Stack(Stack &s)
    {
        this->top = s.top;
        this->size =  s.size;
        this->arr = new int[s.size];
        for(int i = 0; i<this->top; i++)
        {
            this->arr[i] = s.arr[i];
        }
    }
    
    Stack(int size)
    {
        this->top = 0;
        if(size > 0) 
        {
            this->arr = new int[size];
            this->size = size;

        }
        else
        {
            this->arr = new int[SIZE];
            this->size = 5;
        }
    }
    void push()
    {
        if(this->top == this->size)
        cout<<"Stack is full."<<endl;
        else
        {
            int a;
            cout<<"Enter a value : ";
            cin>>a;
            this->arr[top] = a;
            this->top++;
        }
    }
    void pop()
    {
        if(this->top == 0) 
        cout<<"Stack is empty."<<endl;
        else
        {
            this->arr[top-1] = 0;
            top--;
            cout<<"Popped one element."<<endl;
        }
    }
    void peek()
    {
        if(this->top == 0) 
        cout<<"Stack is empty."<<endl;
        else
        cout<<"Peek is : "<<this->arr[top-1]<<endl;
    }
    void isEmpty()
    {
        if(top == 0)
        cout<<"Stack is empty."<<endl;
        else
        cout<<"Stack is not empty."<<endl;
    }
    void isFull()
    {
        if(this->top == this->size)
        cout<<"Stack is full."<<endl;
        else
        cout<<"Stack is not full."<<endl;
    }
    void print()
    {
        if(top == 0)
        cout<<"Stack is empty."<<endl;
        else
        {
            cout<<"Values are : "<<endl;
            for(int i = this->top-1 ; i>=0 ; i--)
            cout<<arr[i]<<endl;
        }
        cout<<endl;
    }

    void operator=(Stack &s)
    {
        this->top = s.top;
        this->size =  s.size;
        this->arr = new int[s.size];
        for(int i = 0; i<this->top; i++)
        {
            this->arr[i] = s.arr[i];
        }
    }

    ~Stack()
    {
        delete[] arr;
    }
};

int menu()
{
    int choice;
    cout<<"**STACK**"<<endl;
    cout<<"0 : To Exit"<<endl;
    cout<<"1 : To Push"<<endl;
    cout<<"2 : To Pop"<<endl;
    cout<<"3 : Peek"<<endl;
    cout<<"4 : Check Empty"<<endl;
    cout<<"5 : Check Full"<<endl;
    cout<<"6 : See Stack"<<endl;
    cout<<"----------------"<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;
    cout<<endl;
    return choice;
}

int main()
{
    int size;
    cout<<"Enter the size of stack : ";
    cin>>size;
    Stack s1(size);
    int choice;
    while((choice = menu())!= 0)
    {
        switch(choice)
        {
            case 1 : s1.push();
                     break;
            case 2 : s1.pop();
                     break;
            case 3 : s1.peek();
                     break;
            case 4 : s1.isEmpty();
                     break;
            case 5 : s1.isFull();
                     break;
            case 6 : s1.print();
                     break;
            default : cout<<"Please enter a valid choice..";
        }
    }
    Stack s2 = s1;
    Stack s3;
    s3 = s2;
    cout<<"Successfully Exited.."<<endl;
}