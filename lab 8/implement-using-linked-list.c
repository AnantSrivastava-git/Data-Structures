#include <stdio.h>
#include <stdlib.h>

struct queue_node
{
    int data;
    struct queue_node * next;

}*front = NULL,*rear = NULL;

void enqueue(){
    struct queue_node *newnode;
    newnode= (struct queue_node *)(malloc(sizeof(struct queue_node)));
    printf("Enter the value to be inserted\n");
    scanf("%d",&newnode->data);
    newnode->next = NULL;

    if(front == NULL && rear == NULL){
        front = newnode;
        rear = newnode;
    }

    else{
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue (){
    struct queue_node * temp = front;
    printf("\n\nDequeued node =\n Value  = %d\n\n", front->data);
    front = front->next;
    free(temp);
}

void display(){
    struct queue_node * temp = front;
    while(temp!= NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice;
    do{
        enqueue();
        printf("Enter 1 to continue insertion or 0 to exit!\n");
        scanf("%d",&choice);

    }while(choice);

    display();

    dequeue();
    display();
    return 0;
}
