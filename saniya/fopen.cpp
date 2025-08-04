#include<stdio.h>
#include<stdlib.h>
#define FILENAME"saniya.txt"

int main(){
FILE *fp=NULL;
char ch;
int linecount=0;

fp=fopen(FILENAME,"r");
if(fp==NULL){
printf("File does not exist");
return -1;
}
while((ch=fgetc(fp))!=EOF){
if(ch=='\n')
linecount++;
}
fclose(fp);
fp=NULL;
printf("Total no of lines=%d\n",linecount);
return 0;
}

