#include<iostream>
using namespace std;


class Time{

    int hr;
    int min;
    int sec;

    public:
Time(){
    this->hr = 10;
    this->min = 10;
    this->sec = 10;
}
Time(int hr,int min,int sec){
    this->hr = hr;
    this ->min = min;
    this -> sec = sec;
}

void setHour();
void setMinute();
void setSeconds();

int getHour();
int getMin();
int getSeconds();
void printTime();


};

int Time ::getHour(){
    return this->hr;
}
int Time :: getMin(){
    return this->min;
}
int Time :: getSeconds(){
    return this ->sec;
}
void Time :: printTime(){
cout<< "Time= "<< this->hr << ":" <<this->min <<":" <<this->sec <<endl;
}
void Time :: setHour(){
cout << "Enter Hr ";
cin>> this->hr;
}
void Time :: setMinute(){
    cout<<"Enter Min ";
    cin>> this->min;
}
void Time ::setSeconds(){
    cout<< "Enter seconds";
    cin>> this->sec;
}

int main(){
    // Time t1();
    // Time t2(12,20,25);

    Time **arr = new Time *[5];
    for(int j = 0; j <5 ; j++){
        arr[j] = new Time();
    }
   

    for(int i = 0; i <5 ; i++)
    {
        cout<<"Index: [" << i << "]" <<endl;
        arr[i] ->setHour();
        arr[i] ->setMinute();
        arr[i] -> setSeconds();
    }


    for(int j = 0; j< 5 ; j++){
       cout<<"Time "<< arr[j] ->getHour() <<" : "<< arr[j] ->getMin() << " : " << arr[j] ->getSeconds() <<endl;
    }

    for (int i = 0; i < 5; i++)
    {
        delete arr[i];
    }
    delete[] arr;
    return 0;
    


}