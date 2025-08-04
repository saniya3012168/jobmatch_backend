#include<stdio.h>

int mul(int x,int y){

    int result=x*y;
    return result;
}

int main(void){

    int result=0;
    result=mul(10,20);
    printf("result =%d",result);
	
    return 0;
}

