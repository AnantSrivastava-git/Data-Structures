#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int get_max(struct node *head)
{
    int max = head->data;
    struct node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data > max)
        {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

struct node *create_node(int data)
{
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insert_at_end(struct node **head, int data)
{
    struct node *newnode = create_node(data);
    if (*head == NULL)
    {
        *head = newnode;
        return;
    }
    else
    {
        struct node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

struct node *concat(struct node *list1, struct node *list2)
{
    if (list1 == NULL)
        return list2;
    struct node *temp = list1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = list2;
    return list1;
}

 void radix_sort(struct node **head)
{
    // get max
    int max = get_max(*head);
    int pos = 1;
    while (max / pos > 0)
    {

        // initialize buckets -- this is kind of like count array, yeh array of pointers hai, jisme basic logic yeh hai ki jitni baar koi digit same mili its will be a case of collision and so us index pe jo list hogi vo usme newnode declare honge eg --- 677->87->07

        struct node *buckets[10] = {NULL};
        struct node *temp = *head;
        // Distribute the node in the bucktes
        while (temp != NULL)
        {
            int digit = (temp->data / pos) % 10;
            insert_at_end(&buckets[digit], temp->data);
            temp = temp->next;
        }

        // merge the buckets back
        int i = 0;
        struct node *newhead = NULL;
        while (i < 10)
        {
            newhead = concat(newhead, buckets[i]);
            i++;
        }

        *head = newhead;
        pos *= 10;
    }
}

void print(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
     struct node *head = NULL;
    insert_at_end(&head, 170);
    insert_at_end(&head, 45);
    insert_at_end(&head, 75);
    insert_at_end(&head, 90);
    insert_at_end(&head, 802);
    insert_at_end(&head, 24);
    insert_at_end(&head, 2);
    insert_at_end(&head, 66);

    printf("Original list: ");
    print(head);

    radix_sort(&head);

    printf("Sorted list: ");
    print(head);

    return 0;
}
