#include<iostream>
using namespace std;

class Distance
{
    private :
    float feet;
    float inches;

    public :

    Distance()
    {
        this->feet = 0;
        this->inches = 0;
    }

    Distance(float feet, float inches)
    {
        this->feet = feet;
        this->inches = inches;
    }

    Distance operator+(Distance &p)
    {
        Distance overload;
        overload.feet = this->feet + p.feet;
        overload.inches = this->inches + p.inches;
        return overload;
    }

    Distance operator++() //pre increment that takes no arguments
    {
        Distance pre;
        pre.feet = this->feet;
        pre.inches = ++this->inches;
        return pre;
    }

    Distance operator++(int a) // post increment that takes an int argument
    {
        Distance post;
        post.feet = this->feet;
        post.inches = this->inches++;
        return post;
    }

    friend bool operator==(Distance &, Distance &);
    friend Distance operator--(Distance &);
    friend Distance operator--(Distance &, int);
    friend void operator<<(ostream &, Distance &);
    friend void operator>>(istream &, Distance &);
};

void operator<<(ostream &out, Distance &p)
{
    out <<p.feet<<" feet, "<<p.inches<<" inches"<<endl;
}

void operator>>(istream &in, Distance &p)
{
    cout<<"Enter Feets : ";
    in>>p.feet;
    cout<<"Enter Inches : ";
    in>>p.inches;
}

Distance operator--(Distance &p) //pre increment that takes no arguments
{
    Distance pre;
    pre.feet = p.feet;
    pre.inches = --p.inches;
    return pre;
}

Distance operator--(Distance &p, int a)
{
    Distance Post;
    Post.feet = p.feet;
    Post.inches = p.inches--;
    return Post;
}

bool operator==(Distance &p1, Distance &p2)
{
    if(p1.feet == p2.feet && p1.inches == p2.inches)
    return true;
    else
    return false;
}

int main()
{
    Distance d1(10, 20);
    Distance d2(30, 40);

    cout<<"**Testing '+' Operator**"<<endl;
    Distance d3 = d1 + d2; // + operator tested and ok
    cout<<d3; // << operator tested and ok

    cout<<"**Testing '>>' and '<<' Operators**"<<endl;
    Distance d4;
    cin>>d4;
    cout<<d4;

    cout<<"**Testing '==' Operator**"<<endl;
    if(d3 == d4) // == operator tested and ok
    cout<<"Both are equal."<<endl;

    cout<<"**Testing '++pre' Operator**"<<endl;
    Distance d5;
    d5 = ++d2;
    cout<<"**Pre Incremented d2**"<<endl;
    cout<<d5;
    cout<<"**After Incremented**"<<endl;
    cout<<d2;
    cout<<"**Pre decremented d1**"<<endl;
    d5 = --d1;
    cout<<d5;
    cout<<"**After decremented**"<<endl;
    cout<<d1;

    d5 = d3++;
    cout<<d5;
    cout<<d3;
}