#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;    
};
struct node* head;

struct node* linked_list_creation(struct node* tail) { 
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



void insertatspecific(struct node* tail, int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    struct node *newnode;
    int value;
    newnode = (struct node *)(malloc(sizeof(struct node)));
    printf("\nEnter the value you want to insert in node: ");
    scanf("%d", &value);
    newnode->data = value;
    if (pos == 1) {
        head->prev = newnode;
        newnode->next = head;
        newnode->prev = NULL;

            return;
        }

    for (int i = 1; temp != NULL && i < pos; i++)
        temp = temp->next;

        newnode->next = temp->next;
        newnode->prev = temp;
        if (temp->next != NULL) temp->next->prev = newnode;
        temp->next = newnode;
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
    head = linked_list_creation(tail1);
    print(head);

    int position;
    printf("Enter position: "); 
    scanf("%d", &position); 
    insertatspecific(tail1,position);
    print(head);
    return 0;
}