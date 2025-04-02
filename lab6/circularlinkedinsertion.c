#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    
    if (head == NULL) {
        newNode->next = newNode;  
        return newNode;
    }

    struct Node* temp = head;
    
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;  
    newNode->next = head;  
    head = newNode;

    return head;
}


struct Node* insertAtIndex(struct Node* head, int data, int index) {
    if (index == 0) {
        return insertAtBeginning(head, data);
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = head;

    int count = 0;
    while (temp->next != head && count < index - 1) {
        temp = temp->next;
        count++;
    }

    if (count < index - 1) {
        printf("Invalid Index!\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    
    if (head == NULL) {
        newNode->next = newNode;  
        return newNode;
    }

    struct Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;  
    newNode->next = head;  

    return head;
}


void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(head)\n");
}


int main() {
    struct Node* head = NULL;
    int choice, data, index;

    while (1) {
        printf("\nCircular Linked List Menu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Any Index\n");
        printf("3. Insert at End\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                printf("Enter index: ");
                scanf("%d", &index);
                head = insertAtIndex(head, data, index);
                break;
            case 3:
                printf("Enter value to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("Exited\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
