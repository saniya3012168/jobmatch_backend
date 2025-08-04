#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void){

   char *str=NULL;
   str=(char*)malloc(15*sizeof(char));
   strcpy(str,"saniya");
   printf("string=%s , Address=%p\n",str,str);
  
   str=(char*)realloc(str,25*sizeof(char));
   strcat(str,".com");
   printf("String=%s , Address=%p\n",str,str);
   
   free(str);
}

