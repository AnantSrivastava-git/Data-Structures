#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
};

struct list *listcreation()
{
    struct list *newnode, *temp, *head = NULL;
    int value, addnode;
    do
    {
        newnode = (struct list *)(malloc(sizeof(struct list)));
        printf("Enter the value you want to insert in node\n");
        scanf("%d", &value);
        newnode->data = value;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to enter another new node ?\n");
        printf("Press 1 for YES or 0 for NO!\n");
        scanf("%d", &addnode);

    } while (addnode);

    return head;
}

void displayList(struct list *head)
{
    struct list *temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

struct list *reverse_k_nodes(int k, struct list *start)
{
    struct list *currentnode, *prevnode, *temp, *nextnode;
    temp = start;
    prevnode = NULL;
    currentnode = temp;
    nextnode = temp;

    for (int i = 0; i < k; i++)
    {

        nextnode = currentnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    start = prevnode;
    temp->next = currentnode;
    return start;
}

int main()
{
    struct list *head = NULL;
    head = listcreation();
    displayList(head);
    int k = 3, n = 6;
    // printf("Enter the size of group of nodes");
    // scanf("%d", &k);
    struct list *start = head, *temp,*fast,*temp2;

    for (int i = 0; i < 2; i++)
    {   
        temp = start;
        fast = start;
        for (int j = 1; j < k; j++)/*kuch ho toh 0 krde*/
        {
            temp = temp->next;
            fast = fast->next;
        }
        temp = temp->next;
        start = reverse_k_nodes(k, start);
        if(i==1){
            head = start;
        }
        temp2 = start;
        while(temp2->next!=NULL){
            temp2 = temp2->next;
        }

        temp2 ->next = fast;
        start = temp;
    }


    displayList(head);

    return 0;
}