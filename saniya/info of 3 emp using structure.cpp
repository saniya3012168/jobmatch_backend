#include<stdio.h>
#include<stdlib.h>
struct employee{
  char name[30];
  char date[20];
  float salary;
};
int main(){
    struct employee emp1={"abc","12/2/2012",50000.00};
    printf("\nName=%s",emp1.name);
     printf("\nHire date=%s",emp1.date);
      printf("\nSalary=%f",emp1.salary);
     
      struct employee emp2={"xyz","13/3/2013",60000.00};
    printf("\n\nName=%s",emp2.name);
     printf("\nHire date=%s",emp2.date);
      printf("\nSalary=%f",emp2.salary);
     
       struct employee emp3={"prq","14/4/2014",70000.00};
    printf("\n\nName=%s",emp3.name);
     printf("\nHire date=%s",emp3.date);
      printf("\nSalary=%f",emp3.salary);
     
    return 0;
}

