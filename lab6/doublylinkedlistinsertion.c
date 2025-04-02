#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;    
};

struct node* linked_list_creation(struct node* head,struct node* tail) { 
    struct node *newnode,*temp;
    int value, addnode;
    
    do {
        newnode = (struct node *)(malloc(sizeof(struct node)));
        printf("\nEnter the value you want to insert in node: ");
        scanf("%d", &value);
        newnode->data = value;
        newnode->next = NULL;
        newnode->prev = NULL;

        if (head == NULL && tail == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode; 
        }

        printf("Do you want to enter another new node? ");
        scanf("%d", &addnode);    

    } while (addnode);

    return head;
}

struct node* insert( struct node * head){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value you want to insert ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;

    int choice;
    printf("Enter the choice\n");
    printf(" 1 for insertion at start \n 2 for insertion at specified position \n 3 for at last\n");
    scanf("%d",&choice);

    if(choice==1){
    newnode->next=head;
    head ->prev = newnode;
    head=newnode;
    }
    else if( choice ==2){
        printf("Enter the position other than 1st, where you want to insert the new node ");
        int indx,i=1;
        scanf("%d",&indx);
        struct node* temp2;
        temp2=head;
        while(indx>i){
            temp2=temp2-> next;
            i++;
        }
        newnode->prev =temp2->prev;
        newnode->next=temp2;
        temp2->prev->next=newnode;
    }
    else{
        struct node* temp2;
        temp2=head;
        while(temp2->next!=NULL){
            temp2=temp2-> next;
        }
        newnode->prev=temp2;
        temp2->next=newnode;
    }

    return head;
}


void print(struct node* head) {
    if (head == NULL) {
        printf("Empty linked list\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int count = 0;
    struct node *head1 = NULL,*tail1 = NULL, *temp1;
    head1 = linked_list_creation(head1,tail1);
    print(head1);
    head1 = insert(head1);
    print(head1);


    return 0;
}
