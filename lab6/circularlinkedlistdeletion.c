#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* listcreation (){
    struct Node *newnode,*temp,*head=NULL;
    int value,addnode;
    do{
    newnode=(struct Node *)(malloc(sizeof(struct Node)));
    printf("Enter the value you want to insert in node\n");
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=NULL;
    
    if(head==NULL){
        head=newnode;
        temp=newnode;
    }
    else{
        temp->next = newnode;
        temp=newnode;
    }
    
    printf("Do you want to enter another new node ?\n");
    printf("Press 1 for YES or 0 for NO!\n");
    scanf("%d",&addnode);    
    
    }while(addnode);
    temp ->next = head;
    return temp;
    }


void display(struct Node* last) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = last->next;  
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}


struct Node* deleteBegin(struct Node* last) {
    if (last == NULL) {
        printf("List is empty, nothing to delete\n");
        return NULL;
    }

    struct Node* head = last->next;
    if (head == last) {  
        free(head);
        return NULL;
    }

    last->next = head->next;
    free(head);
    return last;
}


struct Node* deleteAtIndex(struct Node* last, int index) {
    if (last == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct Node *temp = last->next, *prev = last;
    int count = 0;

    do {
        count++;
        prev = temp;
        temp = temp->next;
    } while (temp != last->next);

    if (index < 0 || index >= count) {
        printf("Invalid index\n");
        return last;
    }

    if (index == 0) {  
        return deleteBegin(last);
    }

    temp = last->next;
    prev = NULL;
    for (int i = 0; i < index; i++) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    if (temp == last) {  
        last = prev;
    }

    free(temp);
    return last;
}


struct Node* deleteEnd(struct Node* last) {
    if (last == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct Node *temp = last->next, *prev = last;
    if (temp == last) {  
        free(last);
        return NULL;
    }

    while (temp->next != last->next) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = last->next;
    free(temp);
    return prev;
}


int main() {
    struct Node* last = NULL;

    last = listcreation();

    printf("Original Circular Linked List: \n");
    display(last);

    // Delete from the beginning
    last = deleteBegin(last);
    printf("\nAfter deleting from beginning:\n");
    display(last);

    // Deleting from index 
    int indx;
    scanf("%d",&indx);
    last = deleteAtIndex(last, indx);
    printf("\nAfter deleting from index 2:\n");
    display(last);

    // Deleting from the end
    last = deleteEnd(last);
    printf("\nAfter deleting from the end:\n");
    display(last);

    return 0;
}
