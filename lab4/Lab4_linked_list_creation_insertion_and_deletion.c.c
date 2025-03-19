#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

    struct node* insert(){
        struct node *latestnode;
        latestnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the value you want to insert ");
        scanf("%d",&latestnode->data);
        latestnode->next=NULL;
        return latestnode;
    }


void linked_list_creation(int a)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = a;
    newnode->next = NULL;

    if(head==NULL){
        head=newnode;
        return;
    }


    struct node *temp=head;
    while(temp->next !=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}

void print(){
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
}

int main()
{
    linked_list_creation(10);
    linked_list_creation(20);
    linked_list_creation(30);
    linked_list_creation(40);
    linked_list_creation(50);

    // insert at start

    struct node * nnode;
    nnode=insert();
    int choice;
    printf("Enter the choice\n");
    printf(" 1 for insertion at start \n 2 for insertion at specified position \n 3 for at last\n");
    scanf("%d",&choice);

    if(choice==1){
    nnode->next=head;
    head=nnode;
    }
    else if( choice ==2){
        printf("Enter the position other than 1st, where you want to insert the new node ");
        int indx,i=0;
        scanf("%d",&indx);
        struct node* temp2;
        temp2=head;
        while(indx>i){
            temp2=temp2-> next;
            i++;
        }
        nnode->next=temp2->next;
        temp2->next=nnode;
    }
    else{
        struct node* temp2;
        temp2=head;
        while(temp2->next!=NULL){
            temp2=temp2-> next;
        }
        temp2->next=nnode;
        nnode->next;
    }

    printf("Deletion starts here!!!");

    // deletion at start
    choice=0;
    scanf("%d",&choice);

    if(choice==1){
        struct node* temp2;
        temp2=head;
        head=head->next;
        free(temp2);
    }
    else if(choice==2){
        printf("Enter the position other than 1st, where you want to delete the node ");
        int indx,i=0;
        scanf("%d",&indx);
        struct node* temp2,*temp3;
        temp2=head;
        temp3=NULL;
        while(indx>i){ 
            temp3=temp2;
            temp2=temp2->next;
            i++;
        }
        temp3->next=temp2->next;
        free(temp2);
    }
    else{
        struct node* temp2,*temp3;
        temp2=head;
        while(temp2->next!=NULL){
            temp3=temp2;
            temp2=temp2-> next;
        }
        temp3->next=NULL;
        free(temp2);
    }
    

    print();
    return 0;
}
