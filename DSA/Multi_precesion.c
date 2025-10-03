#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create_node(int d)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = d;
    newnode->next = NULL;
    return newnode;
}

struct node *create_list(char str[], int n)
{
    struct node *head = NULL, *temp = NULL;
    for (int i = 0; i < n; i++)
    {
        int digit = (int)str[i] - 48;
        temp = create_node(digit);
        temp->next = head;
        head = temp;
    }
    return head;
}

void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node *sub(struct node *head1, struct node *head2)
{
    struct node *temp1 = head1, *temp2 = head2, *head3 = NULL, *temp3 = NULL;
    int borrow = 0;
    int diff;
    while (temp2 != NULL)
    {
        diff = temp1->data - temp2->data - borrow;
        if (diff < 0)
        {
            borrow = 1;
            diff += 10;
        }
        else
        {
            borrow = 0;
        }

        if (head3 == NULL)
        {
            head3 = create_node(diff);
            temp3 = head3;
        }
        else
        {
            struct node *buffer;
            buffer = create_node(diff);
            temp3->next = buffer;
            temp3 = buffer;
        }
        temp2 = temp2->next;
        temp1 = temp1->next;
    }
    while (temp1 != NULL)
    {
        diff = temp1->data - borrow;
        if (diff < 0)
        {
            borrow = 1;
            diff += 10;
        }
        else
        {
            borrow = 0;
        }

        struct node *buffer;
        buffer = create_node(diff);
        temp3->next = buffer;
        temp3 = buffer;
        temp1 = temp1->next;
    }

    return head3;
}

int main()
{
    struct node *head1 = NULL, *head2 = NULL, *head3 = NULL;
    int n;
    printf("Enter the size of the number\n");
    scanf("%d", &n);

    char str1[n];
    printf("Enter the number\n");
    scanf("%s", str1);
    head1 = create_list(str1, n);
    display(head1);

    char str2[n];
    printf("Enter the number\n");
    scanf("%s", str2);
    head2 = create_list(str2, n);
    display(head2);

    head3 = sub(head1, head2);
    display(head3);
}


// struct node *add(struct node *head1, struct node *head2)
// {
//     struct node *temp1 = head1, *temp2 = head2, *head3 = NULL, *temp3 = NULL;
//     int carry = 0;
//     int sum;
//     while (temp2 != NULL)
//     {
//         sum = temp1->data + temp2->data + carry;
//         if (sum < 9)
//         {
//             carry = sum%10;
//             sum = sum/10;
//         }
//         else
//         {
//             carry = 0;
//         }

//         if (head3 == NULL)
//         {
//             head3 = create_node(sum);
//             temp3 = head3;
//         }
//         else
//         {
//             struct node *buffer;
//             buffer = create_node(sum);
//             temp3->next = buffer;
//             temp3 = buffer;
//         }
//         temp2 = temp2->next;
//         temp1 = temp1->next;
//     }
//     while (temp1 != NULL)
//     {
//         sum = temp1->data + carry;
//         if (diff < 0)
//         {
//             borrow = 1;
//             diff += 10;
//         }
//         else
//         {
//             borrow = 0;
//         }

//         struct node *buffer;
//         buffer = create_node(diff);
//         temp3->next = buffer;
//         temp3 = buffer;
//         temp1 = temp1->next;
//     }

//     return head3;
// }