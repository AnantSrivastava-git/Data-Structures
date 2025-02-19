#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* linked_list_creation(struct node*head)
{ 
    struct node *newnode,*temp;
    int value,addnode;
    do{
    newnode=(struct node *)(malloc(sizeof(struct node)));
    printf("\nEnter the value you want to insert in node\n");
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

    return head;
}

void print( struct node* head){
    if(head==NULL){
        printf("Empty linked List");
        return;
    }
    struct node* temp;
    temp=head;
    while(temp!=NULL){
        printf("%d ", temp-> data);
        temp=temp-> next;
    }
    printf("\n");
}

int main()
{
    struct node *head1 = NULL,*head2=NULL,*temp;
    head1=linked_list_creation(head1);
    print(head1);
    head2=linked_list_creation(head2);
    print(head2);
    temp=head1;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head2;
    print(head1);
    return 0;
}
