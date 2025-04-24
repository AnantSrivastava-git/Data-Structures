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

int dequeue(){
    int temp;
    if(front == -1 && rear == -1){
        return - 1;
    }

    else if(front == rear){
        temp = front;
        front = -1;
        rear = -1;
        return queue[temp];
    }

    else{
        temp = front;
        front++;
        return queue[temp];
    }
}

void reverse_queue(){
    int val = dequeue();
    if(val==-1)
    return;
    reverse_queue();
    enqueue(val);
}



void display(){
    for (int i=front; i<=rear;i++){
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
    reverse_queue();
    display();
    
    return 0;
}