#include<stdio.h>
#include<stdlib.h>

int gcd(int x,int y);

    int main(){
        int result=0;
        result=gcd(150,34);
        printf("The gcd is=%d",result);
        return 0;
    }
 int gcd(int u,int v){
     int temp;
     while(v!=0);
         temp=u%v;
         u=v;
         v=temp;
     
     return u;
 }

