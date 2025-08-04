#include<stdio.h>
int main(){

    float hr,bp,ot,p;
	
    printf("Enter the no. of hours employee work=");
    scanf("%f",&hr);
	
     printf("Enter the no. of hours employee work overtime=");
    scanf("%f",&ot);
	
    bp=12*hr;
    printf("\n\n-------------HERE IS SALARY AMOUNT-----------");
    printf("\n\nThe basic payment of employee=$%f",bp);
	
    if(ot>=40){
        p=6*ot;
        printf("\nPayment of employee of overtime=$%f",p);
		}
    
    printf("\nTotal salary of employee=$%f",bp+p);
	
    printf("\n\n-----------------THANK YOU-----------------");
    return 0;
  
}

