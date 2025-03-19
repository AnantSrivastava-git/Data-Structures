#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* linked_list_creation(struct node*head)
{ 
    struct node *newnode,*temp;
    int value,addnode;
    do{
    newnode=(struct node *)(malloc(sizeof(struct node)));
    printf("\nEnter the value you want to insert in node\n");
    scanf("%d",&value);
    newnode->data=value;
    newnode->next=NULL;

    if(head==NULL){
        head=newnode;
        temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }

    printf("Do you want to enter another new node ?\n");
    printf("Press 1 for YES or 0 for NO!\n");
    scanf("%d",&addnode);    

    }while(addnode);

    return head;
}

void print( struct node* head){
    if(head==NULL){
        printf("Empty linked List");
        return;
    }
    struct node* temp;
    temp=head;
    while(temp!=NULL){
        printf("%d ", temp-> data);
        temp=temp-> next;
    }
    printf("\n");
}

void del_at_pos(struct node* head,int n)
{
    struct node *temp = head;
    struct node *prev = NULL;
    for (int i = 0; i < n; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    printf("Linked List Elements: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data); 
        temp = temp->next;
    }
   
    free(temp);
}

int main()
{
    int count=0;
    struct node *head1 = NULL,*head2=NULL,*temp;
    head1=linked_list_creation(head1);
    print(head1);
    
    struct node *temp=head1;
       
    

    int A[100] = {0};
    
        int c = 0;
    
        while (temp != NULL)
        {
            A[temp->data]++;
            if (A[temp->data] > 1)
            {
                del_at_pos(count,head1);
            }
            c++;
            temp = temp->next;
        }
    return 0;
}
