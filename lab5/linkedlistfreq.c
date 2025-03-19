#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* linked_list_creation(struct node* head) { 
    struct node *newnode, *temp;
    int value, addnode;
    
    do {
        newnode = (struct node *)(malloc(sizeof(struct node)));
        printf("\nEnter the value you want to insert in node: ");
        scanf("%d", &value);
        newnode->data = value;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to enter another new node? ");
        scanf("%d", &addnode);    

    } while (addnode);

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
    struct node *head1 = NULL, *temp1,*temp2;
    head1 = linked_list_creation(head1);
    print(head1);
    
    temp1 = head1;
    int A[100] = {0};
    int i=0;
    while (temp1 != NULL) {
        count=0;
        temp2=head1;
        while(temp2 !=NULL){
        if(temp1->data==temp2->data){
            count++;
        }
        temp2 = temp2->next;
    }
    printf("%d has %d freq\n",temp1->data,count);
    temp1 = temp1->next;
    }
    return 0;
}