#include<stdio.h>

    void multiplication(int x,int y){
        int result=x*y;
        printf("\nThe product=%d",result);
    }
	
int main(void){
    multiplication(10,20);
    multiplication(20,30);
	
    return 0;
}

