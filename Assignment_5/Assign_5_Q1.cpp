#include<iostream>
using namespace std;

class Student{
    private:
    string name;
    char c;
    int Rollno;
    string Gender;
    float *marks;
    public:
    Student(){
        marks = new float[3];
        this->name = "Noob";
        this->Rollno = 0;
        this->Gender = "";
        
        this ->marks[1] = 0.0;
        this->marks[2] = 0.0;
        this->marks[3] = 0.0;
    }
    void accept(){
        cout<<"********************"<<endl;
        marks = new float[3];
        cout<< "Enter name ";
        cin>>this->name;
        cout<< "Enter Rollno ";
        cin>>this->Rollno;
        cout<<"Enter Gender "; 
        cin>>this->Gender;
        cout<<"Enter Physics Marks ";
        cin>> this->marks[1];
        cout<< "Enter Chemistry Marks ";
        cin>> this->marks[2];
        cout<< "Enter Biology Marks ";
        cin>> this->marks[3];
    }
    void display(){
        cout<<"*************************"<<endl;
        cout<<"Name "<<this->name <<endl;
        cout<< "Rollno "<<this->Rollno<<endl;
        cout<< "Gender " <<this->Gender<<endl;
        cout<< "Physics Marks "<<this->marks[1]<<endl;
        cout<< "Chemistry Marks "<<this->marks[2]<<endl;
        cout<< "Biology "<<this->marks[3]<<endl;
    }
    ~Student(){
        delete marks;
    }
    friend void sortRecords(Student **s1,int count);
    friend int searchRecords(Student **s1,int count,int Rollno);


};


void swap(Student* &a, Student* &b) {
    Student* temp = a;
    a = b;
    b = temp;
}






int searchRecords(Student **ptr,int count,int Sroll)
{
    

    for(int i = 0; i<count; i++){
        if(ptr[i]->Rollno == Sroll)
            return i+1;
    }
    return -1;
    
}
int menu(){
    int choice;
    cout<<"*****************"<<endl;
   
    cout<<"0. Exit"<<endl;
    cout<<"1. Accept"<<endl;
    cout<<"2. Print"<<endl;
    cout<<"3. Search"<<endl;
    cout<<"4. Sort"<<endl;
    cout<<"-----------------"<<endl;
    cout<<"Enter Choice "<<endl;
    cin>>choice;
    return choice;
}



int main(){
    int count;
    cout<<"Enter No of students to add ";
    cin>> count;
    Student **st = new Student*[count];
    for (int i = 0; i < count; i++)
    {
        st[i] = new Student();
    }

    // for (int i = 0; i < count; i++)
    // {
    //     st[i]->accept();
    // }

    // Student s;
    int choice;
    while ((choice = menu()) != 0)
    {
        switch (choice)
    {
    case 1:
    for (int i = 0; i < count; i++)
    {
        st[i]->accept();
    }
        // s.accept();
    break;
    case 2:
    for (int i = 0; i < count; i++)
    {
        st[i]->display();
    }
        break;
    case 3:
        cout<<"Enter the searched student ";
        int Rollno;
        cin >>Rollno ;
        int a;
        a = searchRecords(st,count,Rollno);
        cout<<"Searched val = "<<a<<endl;
        break;
    case 4:
        sortRecords(st,count);
        break;
    default:
    cout<<"Wrong choice Entered"<<endl;
        break;
    }
    } 
    
    for (int k = 0; k < count; k++)
    {
        delete st[k];
    }
    delete[] st;
    return 0;
}



void sortRecords(Student **ptr,int count){
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (ptr[j]->Rollno > ptr[j + 1]->Rollno) {
                swap(ptr[j], ptr[j + 1]);
            }
        }
    }


    for (int i = 0; i < count; i++) {
        cout << ": Rollno " << ptr[i]->Rollno << "\n";
        cout << ": Name " << ptr[i]->name << "\n";
        cout << ": Gender " << ptr[i]->Gender << "\n";
        cout << ": Marks of Physics " << ptr[i]->marks[1] << "\n";
        cout << ": Marks of Chemistry " << ptr[i]->marks[2] << "\n";
        cout << ": Marks of Biology " << ptr[i]->marks[3] << "\n";
    }
}
