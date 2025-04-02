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

struct node* deletespecific(struct node* head, int n) {
    if (head == NULL || n < 0) return head;

    struct node *temp = head, *prev = NULL;

    // For deleting the first node
    if (n == 0) {
        head = temp->next;
        free(temp);
        return head;
    }

    // For specific
    for (int i = 0; temp != NULL && i < n; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return head; // Out of bounds

    prev->next = temp->next;
    free(temp);

    return head;
}

int main() {
    int count = 0;
    struct node *head1 = NULL, *temp;
    head1 = linked_list_creation(head1);
    print(head1);
    
    temp = head1;
    int A[100] = {0};

    while (temp != NULL) {
        A[temp->data]++;
        if (A[temp->data] > 1) {
            head1 = deletespecific(head1, count);
        }
        count++;
        temp = temp->next;
    }

    printf("Linked List After Removing Duplicates: ");
    print(head1);

    return 0;
}
