#include<stdio.h>


struct Date {
int day;
int month;
int year;

};


void initDate(struct Date *ptrDate)
{
    ptrDate ->day = 06;
    ptrDate ->month = 01;
    ptrDate -> year = 2002;
};

void acceptDateFromConsole(struct Date* ptrDate)
{
    printf("Enter Date in DD MM YYYY one by one ");
    scanf("%d%d%d",&ptrDate->day,&ptrDate->month,&ptrDate->year);
};


void printDateOnConsole(struct Date ptrDate)
{
    printf("\nDate = %.2d : %.2d : %.2d",ptrDate.day,ptrDate.month,ptrDate.year);
};


int main(){

     struct Date d1;
     int bool = 1;
 
do
{
    

    int a;
    printf(" Enter 1 to insert\n Enter 2 to disply date\n 3 to Exit\n");

    scanf("%d",&a);
    
    switch (a)
    {
    case 1 :
    acceptDateFromConsole(&d1);
        break;
    case 2 :
    printDateOnConsole(d1);
        break;
    case 3 :
        bool = 0;
        break;
    default :

       initDate(&d1);
       printf("Enter valid value!\n");
       break;
    }
    } while (bool);

}