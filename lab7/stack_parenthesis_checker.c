#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
};

#define N 100
int stack[N];

int pusharray(int top, int val)
{
    if (top == -1)
    {
        top++;
        stack[top] = val;
    }
    else if (top == N - 1)
    {
        printf("Stack is full");
        return top;
    }
    else
    {
        top++;
        stack[top] = val;
    }
    return top;
}

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

int main()
{
    struct list *head = NULL;
    head = listcreation();
    displayList(head);
    int k = 3, n = 6;
    // printf("Enter the size of group of nodes");
    // scanf("%d", &k);
    struct list *start = head, *temp, *fast, *temp2;

    int top = -1;
    temp = start;
    for (int c = 0; c < n / k; c++)
    {
        for (int i = 0; i < k; i++)
        {
            top = pusharray(top, temp->data);
            temp = temp->next;
        }
        temp = start;
        for (int i = 0; i < k; i++)
        {
            temp->data = stack[top];
            top--;
            temp = temp->next;
        }
        start = temp;
    }

    displayList(head);
    return 0;
}