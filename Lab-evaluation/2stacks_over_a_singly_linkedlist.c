#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int stack_id;
    struct node *next;
};

struct node *head =NULL,* top1 =NULL, *top2 = NULL;

void push1(int x){
    struct node *newnode, *temp;
        newnode = (struct node *)(malloc(sizeof(struct node)));
        newnode->data = x;
        newnode->stack_id = 1;
        newnode->next = NULL;

        if(head == NULL){
            head = newnode;
        }
        else{
            newnode->next = head;
            head = newnode;
        }
}

void push2 (int x)
{
    struct node *newnode, *temp;
        newnode = (struct node *)(malloc(sizeof(struct node)));
        newnode->data = x;
        newnode->stack_id = 2;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            top2 = newnode;
            temp = newnode;
        }
        else
        { 
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newnode;
            top2 = newnode;
            temp = newnode;
        }
}

void pop1(){
    struct node * temp;
    if(head == NULL || head->stack_id!=1){
        printf("Stack 1 is empty");
        return;
    }
    temp = head;
    head =head ->next;
    printf("Element %d Poppped!!\n",temp->data);
    free(temp);
}


void pop2(){
    struct node * temp = head,*prev;
    while(temp->next !=NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp->stack_id != 2){
        printf("Stack 2 is empty");
    }
    else{
        if(prev->stack_id !=2){
            prev->next= NULL;
            printf("Element %d Poppped now stack 2 is empty!!\n",temp->data);
            free(temp);
            
        }
        else{
            top2 = prev;
            prev->next= NULL;
            printf("Element %d Poppped!!\n",temp->data);
            free(temp);
        }
    }
}

void displaystack()
{
    struct node *temp = head;

    while (temp != NULL)
    {
        printf("%d Stack-ID %d->\n", temp->data, temp->stack_id);
        temp = temp->next;
    }

    printf("NULL\n");
}


int main(){
    push1(10);
    push1(20);
    push2(30);
    push2(60);
    push2(70);
    push2(80);
    push1(40);
    push1(50);    
    displaystack();
    pop1();
    displaystack();
    pop2();
    displaystack();

}