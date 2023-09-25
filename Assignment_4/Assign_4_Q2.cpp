#include <iostream>
using namespace std;
#define SIZE 5

class Stack
{
    int *arr;
    int top;
    int size;

public:
    Stack(int sz)
    {
        this->top = -1;
        this->size = sz;

        if (sz <= 0)
        {
            this->arr = new int[sz];
            this->size = sz;
        }
        else
        {
            this->arr = new int[SIZE];
            this->size = sz;
        }
    }
    ~Stack(){
       delete[] arr;
    }
    void push()
        {
            if (top == size)
            {
                cout << "Stack is full";
            }
            else
            {
                this->top = top + 1;
                cout << "Enter "<<top <<" element ";;
                int value;
                cin>> value;
                arr[top] = value;
            }
        }
        void peek(){
            if (top == -1)
            {
                cout<< "Stack is empty";
            }
            else
            cout<< "Peeked Element "<<arr[top]<<endl;
        }
        void isEmpty(){
            if (top <= 0)
            {
                cout<< "Stack is empty";
            }
            else
            cout<< "Stack is not empty";
        }
        void pop(){
            if (top == -1)
            {
                cout<< "stack is null";
            }
            else
            {
                cout<< "Poped Elemenet: "<<arr[top]<<endl;
                this ->arr[top] = 0;
                this ->top = top - 1;
            }  
        }
        void print(){
            cout<<"Element of stack "<<endl;
                for(int i = top; i >=0 ; i--){
                    cout<< arr[i] <<endl;
                }
            }
};

int main()
{
    cout << "Enter stack size ";
    int z;
    cin >> z;
    Stack s1(z);
    s1.push();
    s1.push();
    s1.push();
    s1.push();

    s1.peek();

    s1.print();

    s1.pop();

    s1.print();
}