#include<stdio.h>
int main(){
    int a=0,b=1,c=0,n;
    printf("Enter no of terms=");
    scanf("%d",&n);
    printf("The fibonacci series as follows:");
    for(int i=0;i<=n;i++){
        printf("%d\t",c);
        a=b;
        b=c;
       c=a+b;
    }
    return 0;
}

