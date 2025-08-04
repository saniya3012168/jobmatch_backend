#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
void tra(struct node * ptr){
    while(ptr!=NULL);
   printf("Element=%d\n",ptr->data);
   ptr=ptr->next;
}

struct node * del(struct node * head){
struct node * ptr=head;
head=head->next;
free(ptr);
return head;
}


struct node * case2(struct node * head,int index){
    struct node * p=head;
    struct node * q=p->next;
    for(int i=1;i<index-1;i++);
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}
struct node * case3(struct node * head){
    struct node * p=head;
    struct node * q=head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
	}

int main(){
    struct node * head;
    struct node * second;
    struct node * third;
    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    head->data=7;
    head->next=second;
    second->data=10;
    second->next=third;
    third->data=17;
    third->next=NULL;
   
    tra(head);
	//head=case2(head,2);
    //head=del(head);s
    head=case3(head);
    tra(head);
}

