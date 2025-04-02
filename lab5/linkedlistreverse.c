#include<stdio.h>
#include <stdlib.h>

struct node1{
    int data;
    struct node *next;
};


int main()
{
    struct node1 *newnode,*currentnode,*prevnode,*temp,*head=NULL,*nextnode;
    int value,addnode;
    do{
    newnode=(struct node1 *)(malloc(sizeof(struct node1)));
    printf("Enter the value you want to insert in node\n");
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=NULL;

    if(head==NULL){
        head=newnode;
        temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }

    printf("Do you want to enter another new node ?\n");
    printf("Press 1 for YES or 0 for NO!\n");
    scanf("%d",&addnode);    

    }while(addnode);

    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    temp=head;
    prevnode=NULL; 
    currentnode=temp;
    nextnode=temp;

    while(nextnode!=NULL){
    
    nextnode=currentnode->next;
    currentnode->next=prevnode;
    prevnode=currentnode;
    currentnode=nextnode;

    }
    head=prevnode;

    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }


    return 0;
}