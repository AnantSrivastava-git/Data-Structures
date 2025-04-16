#include <stdio.h>
#include <stdlib.h>

struct token
{
    int age;
    char name[15];
    struct token * next;
    int pos;

}*front = NULL,*rear = NULL;

void enqueue(int position){
    struct token *newpatient;
    newpatient= (struct token *)(malloc(sizeof(struct token)));
    printf("Enter the age of the patient\n");
    scanf("%d",&newpatient->age);
    printf("Enter the name of the patient\n");
    scanf("%s",newpatient->name);
    newpatient->next = NULL;
    newpatient->pos = position; 

    if(front == NULL && rear == NULL){
        front = newpatient;
        rear = newpatient;
    }

    else{
        rear->next = newpatient;
        rear = newpatient;
    }
}

void dequeue (){
    struct token * temp = front;
    printf("\nDequeued Patient =\n Name = %s\n Age  = %d\n\n", front->name, front->age);
    front = front->next;
    free(temp);
    struct token * flag = front;
    while(flag !=NULL){
        flag->pos = flag->pos -1;
        flag = flag->next;
    }
}

void display(){
    struct token * temp = front;
    while(temp!= NULL){
        printf("%s \t %d\n",temp->name, temp->pos);
        temp = temp->next;
    }
}

int main()
{
    int choice,pos = 1;
    do{
        enqueue(pos);
        printf("To enter the patient details PRESS 1 or PRESS 0 to exit!\n");
        scanf("%d",&choice);
        pos++;

    }while(choice);

    display();

    dequeue();
    display();
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct token
{
    int age;
    char name[15];
    struct token * next;
    int pos;

}*front = NULL,*rear = NULL;

void enqueue(int position){
    struct token *newpatient;
    newpatient= (struct token *)(malloc(sizeof(struct token)));
    printf("Enter the age of the patient\n");
    scanf("%d",&newpatient->age);
    printf("Enter the name of the patient\n");
    scanf("%s",newpatient->name);
    newpatient->next = NULL;
    newpatient->pos = position; 

    if(front == NULL && rear == NULL){
        front = newpatient;
        rear = newpatient;
    }

    else{
        rear->next = newpatient;
        rear = newpatient;
    }
}

void dequeue (){
    struct token * temp = front;
    printf("\nDequeued Patient =\n Name = %s\n Age  = %d\n\n", front->name, front->age);
    front = front->next;
    free(temp);
    struct token * flag = front;
    while(flag !=NULL){
        flag->pos = flag->pos -1;
        flag = flag->next;
    }
}

void display(){
    struct token * temp = front;
    while(temp!= NULL){
        printf("%s \t %d\n",temp->name, temp->pos);
        temp = temp->next;
    }
}

int main()
{
    int choice,pos = 1;
    do{
        enqueue(pos);
        printf("To enter the patient details PRESS 1 or PRESS 0 to exit!\n");
        scanf("%d",&choice);
        pos++;

    }while(choice);

    display();

    dequeue();
    display();
    return 0;
}
