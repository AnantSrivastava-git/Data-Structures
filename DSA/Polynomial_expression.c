#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int expo;
    struct node *next;
};

struct node *create_node(int c, int e)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coeff = c;
    newnode->expo = e;
    newnode->next = NULL;
    return newnode;
}

struct node *create_poly(int n)
{
    struct node *head = NULL, *temp = NULL, *tmp = NULL;
    int c, e;
    while (n > 0)
    {
        printf("Enter the coefficient\n");
        scanf("%d", &c);
        printf("Enter the exponent\n");
        scanf("%d", &e);
        if (head == NULL)
        {
            head = create_node(c, e);
            temp = head;
        }
        else
        {
            tmp = create_node(c, e);
            temp->next = tmp;
            temp = tmp;
        }
        n--;
    }
    return head;
}

void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf(" +%dx^%d ", temp->coeff, temp->expo);
        temp = temp->next;
    }
    printf("\n");
}

struct node *eval(struct node *head)
{
    struct node *temp = head, *temp2 = head, *temp3 = NULL;
    while (temp != NULL)
    {
        temp2 = temp;
        while (temp2->next != NULL)
        {
            if (temp->expo == temp2->next->expo)
            {
                temp->coeff = temp->coeff + temp2->next->coeff;
                temp3 = temp2->next;
                temp2->next = temp2->next->next;
                free(temp3);
            }
            else
            {
                temp2 = temp2->next;
            }
        }
        temp = temp->next;
    }
    return head;
}

struct node *add_poly(struct node *head1, struct node *head2)
{
    struct node *temp1 = head1, *temp2 = head2, *head3 = NULL, *temp3 = NULL;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (head3 == NULL)
        {
            head3 = create_node(temp1->coeff + temp2->coeff, temp1->expo);
            temp3 = head3;
        }
        else
        {
            struct node *buffer;
            buffer = create_node(temp1->coeff + temp2->coeff, temp1->expo);
            temp3->next = buffer;
            temp3 = buffer;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while (temp1 != NULL)
    {
        struct node *buffer;
        buffer = create_node(temp1->coeff, temp1->expo);
        temp3->next = buffer;
        temp3 = buffer;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        struct node *buffer;
        buffer = create_node(temp2->coeff, temp2->expo);
        temp3->next = buffer;
        temp3 = buffer;
        temp2 = temp2->next;
    }
    return head3;
}

struct node *poly_mul(struct node *head1, struct node *head2)
{
    struct node *temp1 = head1, *temp2, *head3 = NULL, *temp3 = NULL;
    while (temp1 != NULL)
    {
        temp2 = head2;
        while (temp2 != NULL)
        {
            if (head3 == NULL)
            {
                head3 = create_node(temp1->coeff * temp2->coeff, temp1->expo + temp2->expo);
                temp3 = head3;
            }
            else
            {
                struct node *buffer;
                buffer = create_node(temp1->coeff * temp2->coeff, temp1->expo + temp2->expo);
                temp3->next = buffer;
                temp3 = buffer;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return head3;
}

int main()
{
    printf("Enter the size of polynomial expression 1\n");
    int n, m;
    scanf("%d", &n);
    struct node *head1, *head2;
    head1 = create_poly(n);
    head1 = eval(head1);
    display(head1);
    printf("Polynomial 2\n");
    printf("Enter the size of polynomial expression 1\n");
    scanf("%d", &m);
    head2 = create_poly(m);
    head2 = eval(head2);
    display(head2);
    printf("\n|ADDED POLYNOMIAL|\n");
    struct node *head3;
    head3 = add_poly(head1, head2);
    display(head3);
    printf("\n|MULTIPLYED POLYNOMIAL|\n");
    struct node *head4;
    head4 = poly_mul(head1, head2);
    display(head4);
    head4 = eval(head4);
    display(head4);
}