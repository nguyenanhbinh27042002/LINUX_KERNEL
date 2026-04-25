#include <stdio.h>

typedef struct Calendar
{
    int day;
    int month;
    int year;
}Calendar;

int DayinMonth(int month,int year)
{
    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
            return 30;
        case 2:
            return (year % 400 ==0 || year %4 && year %100 !=0) ? 29 : 28;
        default:
            return -1;
    }
}


int main(void)
{   
    Calendar cal;
    do
    {
        printf("Enter the calendar \n");
        scanf("%d %d %d",&cal.day,&cal.month,&cal.year);
    }
    while(cal.day < 1 || cal.day > DayinMonth(cal.month,cal.year) || cal.month < 1 || cal.month > 12 || cal.year < 1);
    printf("Valid day\n");
    return 0;
}