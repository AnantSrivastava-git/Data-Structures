#include<stdio.h>
#include<stdlib.h>

struct list{
    int data;
    struct list* next;
};

struct list* listcreation (){
    struct list *newnode,*temp,*head=NULL;
    int value,addnode;
    do{
    newnode=(struct list *)(malloc(sizeof(struct list)));
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
    
    return head;
    }


void displayList(struct list* head) {
    struct list* temp = head;
        
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
        
    printf("NULL\n");
}

void add_two_numbers(struct list * head){
    struct list* num1, *num2;
    num1 = head;
    num2 = head;
    printf("Enter the position of the nodes whose values you want to add...");
    int pos1, pos2;
    scanf("%d %d", &pos1, &pos2);

    for(int i=1;i<pos1; i++){
        num1 = num1->next;
    }

    for(int i=1;i<pos2; i++){
        num2 = num2->next;
    }

    printf("%d",num1->data + num2->data);
}


int main()
{
    struct list *head=NULL;
    head = listcreation ();
    displayList(head);
    add_two_numbers(head);
    return 0;
}