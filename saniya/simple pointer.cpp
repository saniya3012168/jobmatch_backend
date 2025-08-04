#include<stdio.h>
int main(){

   int x=10;
   int *p=NULL;
   p=&x;
   
   printf("Address of pointer=%p",&p);
   printf("\nValue of pointer pointing=%d",*p);
   printf("\nvalue of pointer=%p",p);
   printf("\nSize of pointer=%d",sizeof(*p));
}

