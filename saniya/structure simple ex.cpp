#include<stdio.h>
#include<stdlib.h>
int main(){

struct date{

    int day;
    int month;
    int year;
};

struct date today;
today.day=27;
today.month=10;
today.year=2005;
printf("Date of birth =%d/%d/%d",today.day,today.month,today.year);
}

