#include<stdio.h>
#include<string.h>
int strlenght(const char *string);
int main(){
 
    printf("%d\n",strlenght("stringlenght test"));
    printf("%d\n",strlenght(""));
    printf("%d\n",strlenght("saniya"));
}

    int strlenght(const char *string){
	
        const char *lastadd=string;
        while(*lastadd);
        ++lastadd;
        return lastadd-string;
}
    

