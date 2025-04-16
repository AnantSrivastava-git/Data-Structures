#include <stdio.h>
#include <stdlib.h>

#define N 6
int queue[N];
int front =-1;
int rear = -1;

void enqueue(int x){

    if((rear+1)%N == front){
        printf("Queue is full");

    }

    if (front == -1 && rear == -1){
        front++;
        rear = (rear+1)%N;
        queue[rear] = x;
    }

    else{
        rear = (rear+1)%N;
        queue[rear] = x;
    }
}

void dequeue(){
    if(front == rear){
        printf("Empty queue\n");
        front = -1;
        rear = -1;
    }
    else
    front = (front+1)%N;
}

void display(){
    int i = front;
    while(i!=rear){
        printf("%d",queue[i]);
        i = (i+1)%N;
    }
    printf("%d",queue[rear]);
    printf("\n");

}

int main()
{
    enqueue(8);
    enqueue(7);
    enqueue(6);
    enqueue(5);
    enqueue(4);
    enqueue(3);
    display();

    dequeue();
    display();
    enqueue(2);
    display();
    dequeue();
    display();
    dequeue();
    display();
    
    return 0;
}
 