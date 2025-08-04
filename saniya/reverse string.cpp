#include<stdio.h>
#include<string.h>
int main(){

    int i,l;
    char str[100];
    printf("Enter your stirng=");
    scanf("%s",&str);
    l=strlen(str);
	
    printf("\nThe reverse string is=\n");
	
    for(i=l;i>=0;i--){
        printf("%c",str[i]);
		}
    
}

