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

struct list* append (struct list *head, struct list *ptr){
    struct list *temp = head;  
    struct list *newnode=(struct list *)(malloc(sizeof(struct list)));
    newnode->data=ptr ->data;
    newnode->next=NULL;      
    if(head==NULL){
        return newnode;
    }
 
    while(temp->next != NULL){
        temp= temp->next;
    }
    temp->next = newnode;
        return head;
    }

    
    struct list* traverse (struct list *head){
            struct list *temp = head , *evenhead = NULL, *oddhead = NULL;
            
            while(temp!=NULL){
                if(temp->data %2 == 0)
                evenhead = append(evenhead, temp);

                else if(temp->data %2 != 0)
                oddhead = append(oddhead, temp);
                temp = temp->next;
            }
            displayList(evenhead);
            displayList(oddhead);
            return head;
            }



    

int main()
{
    struct list *head=NULL;
    head = listcreation ();
    displayList(head);
    traverse(head);

    return 0;
}
