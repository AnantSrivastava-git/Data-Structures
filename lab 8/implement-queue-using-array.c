#include <stdio.h>
#include <stdlib.h>

#define N 8
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x){
    if(rear == N-1){
        printf("\nQueue is full\n");
    }

    else if(front == -1 && rear == -1){
        front=0;
        rear=0;
        queue[rear] = x;
    }

    else{
        rear++;
        queue[rear] = x;
    }
}

void dequeue(){
    if(front == -1){
        printf("\nQueue is Empty\n");
    }

    else if(front == rear){
        front = -1;
        rear = -1;
    }

    else{
        front++;
    }
}

void display(){
    for (int i=front; i<N;i++){
        printf("%d",queue[i]);
}
printf("\n");
}

int main(){

    enqueue(8);
    enqueue(7);
    enqueue(6);
    enqueue(5);
    enqueue(4);
    enqueue(3);
    enqueue(2);
    enqueue(1);
    display();
    dequeue();
    display();
    dequeue();
    display();
    
    return 0;
}