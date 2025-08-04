#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
void tra(struct node * ptr){
    while(ptr!=NULL){
    printf("%d\n",ptr->data);
    ptr=ptr->next;
	}
}
//insertion at start
struct node * in(struct node * head,int data){
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
//insertion in between
struct node * inbet(struct node * head,int data,int index){
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    struct node * p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
		}
    
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
	}

//insertion at end
struct node * inend(struct node * head,int data){
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    struct node * p=head;
    while(p->next!=NULL){
        p=p->next;
		}
    
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
//insertion after node
struct node * innode(struct node * head,struct node * pre,int data)
    struct node * ptr=(struct node *)malloc(sizeof(struct node))
  
      ptr->data=data
      ptr->next=pre->next
      pre->next=ptr
      return head
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
   
    second->data=11;
    second->next=third;
   
    third->data=22;
    third->next=NULL;
	printf("Linked list befor=\n");
    tra(head);
	printf("linked list after=\n");
	in(head,56);
	tra(head);
	
	inbet(head,22,2);
	tra(head);
	
	inend(head,34);
	tra(head);
	
	innode(head,second,23);
	tra(head);
	
    return 0;
}

