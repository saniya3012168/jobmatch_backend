#include<iostream>
#include<string.h>
using namespace std;
struct node{
int prn;
char name[20];
struct node* next;
};

node*create(){
node*head,*p;
head=new node;
int n;
cout<<"Enter no. of members in club=";
cin>>head->prn;
cout<<"Enter name of president=";
cin>>head->name;
head->next=NULL;
p=head;
for(int i=1;i<n-1;i++){
p->next=new node;
p=p->next;
cout<<"Enter prn no. of member=";
cin>>p->prn;
cout<<"Enter name of member=";
cin>>p->name;
p->next=NULL;
}
p->next=new node;
p=p->next;
cout<<"Enter prn no. of secretary=";
cin>>p->prn;
cout<<"Enter name of secretary=";
cin>>p->name;
p->next=NULL;
return(head);

}
void display(node *head){
node *p;
cout<<"INFO of pinnacle club="<<endl;
p=head;
while(p->next!=NULL){
cout<<"\n"<<p->prn<<"\t"<<p->name;
p=p->next;
}
}
node *insert(node *head){
node *p,*q;
p=new node;
int loc;
cout<<"Enter location=";
cin>>loc;
cout<<"Enter prn no. of member=";
cin>>p->prn;
cout<<"Enter name of member=";
cin>>p->name;

if(loc==1){
head=p;
p->next=head;
return(head);
}

else{
q=head;
for(int i=0;i<loc-1;i++){
if(q!=NULL){
q=q->next;
}
}
p->next=q->next;
q->next=p;
return(head);
}
}
int main(){
node*head;
//head=create();
head=insert(head);
display(head);
return 0;
}


