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



void deleteatspecific(struct node* head,struct node* tail, int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    if (pos == 1) {
            head = head->next;
            if (head != NULL) head->prev = NULL;
            free(temp);
            return;
        }

    for (int i = 1; temp != NULL && i < pos; i++)
        temp = temp->next;
    
        if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    free(temp);
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

    int position;
    printf("Enter position: "); 
    scanf("%d", &position); 
    deleteatspecific(head1,tail1,position);
    print(head1);
    return 0;
}