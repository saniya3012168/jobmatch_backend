#include<stdio.h>
int main(){

    int marks[10],i,n,sum=0;
    float avg;
    printf("Enter no.of elements=");
    scanf("%d",&n);
	
    for(i=0;i<n;i++){
        printf("Enter marks of sub %d=",i+1);
        scanf("%d",&marks[i]);
        sum+=marks[i];
    }
    avg+=sum/n;
    printf("Average of marks =%f",avg);
    return 0;
}

