#include <stdio.h>
#include<stdlib.h>

#define N 6
int stack[6];

struct stack{
    int data;
    struct stack* next;
};

struct stack2{
    int data;
    struct stack2* next;
    struct stack2* prev;
};

int pusharray (int top, int val){
    if(top == -1){
        top++;
        stack[top] = val;
    }
    else if(top == N-1){
        printf("Stack is full");
        return top;
    }
    else{
        top++;
        stack[top] = val;
    }
    return top;
}

int poparray(int top){
    if(top == -1){
        printf("Stack is empty");
        return top;
    }
    else{
        top--;
    }
    return top;
}

void display_stackarray( int top ){
    for(int i = top; i>=0 ; i--){
        printf("%d",stack[i]);
    }
}


struct stack* pushll (){
struct stack *newnode,*temp,*top=NULL;
int value,addnode;
do{
newnode=(struct stack *)(malloc(sizeof(struct stack)));
printf("Enter the value you want to insert in node\n");
scanf("%d",&value);
newnode->data=value;
newnode->next=NULL;

if(top==NULL){
    top=newnode;
    temp=newnode;
}
else{
    newnode->next = temp;
    temp=newnode;
    top = newnode;
}

printf("Do you want to enter another new node ?\n");
printf("Press 1 for YES or 0 for NO!\n");
scanf("%d",&addnode);    

}while(addnode);

return top;
}

struct stack *popll(struct stack *top){
    if(top==NULL){
        printf("The Stack is empty");
        return top;
    }
    else{
        struct stack* temp;
        temp= top;
        top= temp->next;
        free(temp);
    }
    return top;
}



struct stack2* pushdll (){
    struct stack2 *newnode,*temp,*top=NULL;
    int value,addnode;
    do{
    newnode=(struct stack2 *)(malloc(sizeof(struct stack2)));
    printf("Enter the value you want to insert in node\n");
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    
    if(top==NULL){
        top=newnode;
        temp=newnode;
    }
    else{
        newnode->next = temp;
        temp->prev = newnode;
        temp=newnode;
        top = newnode;
    }
    
    printf("Do you want to enter another new node ?\n");
    printf("Press 1 for YES or 0 for NO!\n");
    scanf("%d",&addnode);    
    
    }while(addnode);
    
    return top;
    }

    struct stack2 *popdll(struct stack2 *top){
        if(top==NULL){
            printf("The Stack is empty");
            return top;
        }
        else{
            struct stack2* temp;
            temp= top;
            top= temp->next;
            top->prev=NULL;
            free(temp);
        }
        return top;
    }

int main()
{
    // using array
    int top = -1,val,choice;
    do{
    printf("Enter the valued to be pushed:\n");
    scanf("%d",&val);
    top = pusharray(top,val);

    printf("Do you want to push more?\n");
    scanf("%d",&choice);
    }while (choice == 1);
    
    display_stackarray(top);

    printf("\n");

    do{
    top = poparray(top);
    display_stackarray(top);
    printf("\nDo you want to pop more?\n");
    scanf("%d",&choice);
    }while(choice == 1);

// Using linked list

    struct stack* topll = pushll(),*temp1;
    temp1 = topll;
    while(temp1!=NULL){
        printf("%d",temp1->data);
        temp1=temp1->next;
    }


    do{
        topll = popll(topll);
        temp1 = topll;
        while(temp1!=NULL){
            printf("%d",temp1->data);
            temp1=temp1->next;
        }
        printf("\nDo you want to pop more?\n");
        scanf("%d",&choice);
        }while(choice == 1);

// using doubly linked list
    struct stack2* topdll = pushdll(),*temp;
    temp = topdll;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
    do{
        topdll = popdll(topdll);
        temp = topdll;
        while(temp!=NULL){
            printf("%d",temp->data);
            temp=temp->next;
        }
        printf("\nDo you want to pop more?\n");
        scanf("%d",&choice);
        }while(choice == 1);


    return 0;
}
