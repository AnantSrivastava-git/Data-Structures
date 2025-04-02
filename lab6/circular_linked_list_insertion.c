#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};


struct Node* listcreation() {
    struct Node *newnode, *temp, *head = NULL;
    int value, addnode;
    do {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the value you want to insert in node: ");
        scanf("%d", &value);
        newnode->data = value;
        newnode->next = newnode->prev = NULL;

        if (head == NULL) {
            head = newnode;
            head->next = head;
            head->prev = head;
            temp = head;
        } else {
            newnode->prev = temp;
            newnode->next = head;
            temp->next = newnode;
            head->prev = newnode;
            temp = newnode;
        }

        printf("Do you want to enter another new node? (1 for YES, 0 for NO): ");
        scanf("%d", &addnode);
    } while (addnode);
    
    return head;
}


struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    
    if (head == NULL) {
        newnode->next = newnode->prev = newnode;
        return newnode;
    }
    
    struct Node* tail = head->prev;
    newnode->next = head;
    newnode->prev = tail;
    tail->next = newnode;
    head->prev = newnode;
    return newnode;  
}


struct Node* insertAtIndex(struct Node* head, int data, int index) {
    if (index == 0) return insertAtBeginning(head, data);
    
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    struct Node* temp = head;
    int count = 0;
    
    do {
        if (count == index - 1) {
            newnode->next = temp->next;
            newnode->prev = temp;
            temp->next->prev = newnode;
            temp->next = newnode;
            return head;
        }
        temp = temp->next;
        count++;
    } while (temp != head);
    
    printf("Index out of range!\n");
    return head;
}


struct Node* insertAtEnd(struct Node* head, int data) {
    if (head == NULL) return insertAtBeginning(head, data);
    
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    struct Node* tail = head->prev;
    
    newnode->next = head;
    newnode->prev = tail;
    tail->next = newnode;
    head->prev = newnode;
    
    return head;
}


void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    head = listcreation();
    displayList(head);

    int val;
    prinf("Enter the value you want to insert");
    scanf("%d",&val);

    printf("\nInsert at the beginning:\n");
    head = insertAtBeginning(head, val);
    displayList(head);

    printf("\nInsert at index:\n");
    int indx;
    prinf("Enter the index you want to insert");
    scanf("%d",&indx);
    head = insertAtIndex(head, val, indx);
    displayList(head);

    printf("\nInsert at the end:\n");
    head = insertAtEnd(head, val);
    displayList(head);

    return 0;
}
