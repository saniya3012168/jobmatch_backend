#include<stdio.h>
int main(){
    int i=0,j=0;
    int a[2][3]={{1,2,3},{4,5,6}};
	
   for(i=0;i<2;i++){
   
       for(j=0;j<3;j++){
           printf("a[%d][%d]=%d\n",i,j,a[i][j]);
       
   }
   }
   printf("\nElements in matrix form=");
   
   for(i=0;i<2;i++){
     printf("\n");
       for(j=0;j<3;j++){
           printf("%d\t",a[i][j]);
       
   }
   }
   return 0;
}

