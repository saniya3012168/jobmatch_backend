#include<stdio.h>

void greatest(int x,int y){
  
    if(x>y){
        printf("\nGreatest no=%d",x);
    }
	else{
        printf("\nGreatest no=%d",y);
		}
 }

int main(void){
    greatest(4,6);
   greatest(5,-5);
   
    return 0;
}

