#include<stdio.h>
#include<stdlib.h>


    struct date{
        int day;
        int month;
        int year;
    };
    int main(){
        struct date today,*datep;
        datep=&today;
		
        datep->month=10;
         datep->day=27;
          datep->year=2005;
          printf("Date =%d/%d/%d",datep->day,datep->month,datep->year);
          return 0;
}

