#include <stdio.h>

int deleteatspecific(int b[], int size);
int insertatspecific(int b[], int size);
int sort(int b[], int size);
void sortingateven(int b[], int size);
void sortingatodd(int b[], int size);
void sorting_even_or_odd_elements(int b[], int size);

int main()
{
    int size;
    printf("Enter the size of the array ");
    scanf("%d",&size);
    int a[size], operation;
    for(int i=0;i<size;i++){
    printf("Enter the %d element of the array ",i+1);
    scanf("%d",&a[i]);
    }
    printf("Enter the function to be invoked\n");
    scanf("%d", &operation);

    switch (operation)
    {

    case 1:
        insertatspecific(a, sizeof(a) / sizeof(a[0]));
        break;

    case 2:
        deleteatspecific(a, sizeof(a) / sizeof(a[0]));
        break;

    case 3:
        sort(a, sizeof(a) / sizeof(a[0]));
        break;

    case 4:
        sortingateven(a, sizeof(a) / sizeof(a[0]));
        break;

    case 5:
        sortingatodd(a, sizeof(a) / sizeof(a[0]));
        break;

    case 6:
        sorting_even_or_odd_elements(a, sizeof(a) / sizeof(a[0]));
        break;
    }
    
    return 0;
}


int deleteatspecific(int b[], int size)
{
    int k;
    printf("\nEnter the index to be deleted\n");
    scanf("%d", &k);
    for (int i = k; i < size; i++)
    {
        b[i] = b[i + 1];
    }
    size--;
    for (int i = 0; i < size; i++)
    {
        if (b[i] != 0)
        {
            printf("%d ", b[i]);
        }
    }
}

int insertatspecific(int b[], int size)
{ 
    size++;
    int k;
    printf("\nEnter the index to be inserted\n");
    scanf("%d", &k);
    int num;
    printf("Enter the number to be inserted\n");
    scanf("%d", &num);
    for (int i = size - 1; i >= k; i--)
    {
        b[i + 1] = b[i];
    }
    b[k] = num;
    for (int i = 0; i < size; i++)
    {
        if (b[i] != 0)
            printf("%d ", b[i]);
    }
}

int sort(int b[], int size)
{
    int temp, j;
    for (int i = 1; i < size; i++)
    {
        temp = b[i];
        for (int j = i - 1; j >= 0 && b[j] > temp; j--)
        {
            b[j + 1] = b[j];
        }
        b[j + 1] = temp;
    }
    for (int i = 0; i < size; i++)
    {
        if (b[i] != 0)
            printf("%d ", b[i]);
    }
}

void sortingateven(int b[], int size)
{

    // passing the even index elements to new array

    int size2 = ((size - 1) / 2) + 1;
    int c[size2], k = 0;
    for (int i = 0; i < size; i += 2)
    {
        if (b[i] != 0)
        {
            c[k] = b[i];
            k++;
        }
    }

    // sorting new array containing the even index elements

    for (int i = 0; i < k - 1; i++)
    {
        int temp;
        for (int j = 0; j < k - i - 1; j++)
        {
            if (c[j] > c[j + 1])
            {
                temp = c[j + 1];
                c[j + 1] = c[j];
                c[j] = temp;
            }
        }
    }

    // inserting the sorted array containing the even index integers

    k = 0;
    for (int i = 0; i < size; i += 2)
    {
        b[i] = c[k];
        k++;
    }

    for (int i = 0; i < size; i++)
    {
        if (b[i] != 0)
            printf("%d ", b[i]);
    }
}


void sortingatodd(int b[], int size)
{

    // passing the odd index elements to new array

    int size2 = ((size - 1) / 2) + 1;
    int c[size2], k = 0;
    for (int i = 1; i < size; i += 2)
    {
        if (b[i] != 0)
        {
            c[k] = b[i];
            k++;
        }
    }

    // sorting new array containing the odd index elements

    for (int i = 0; i < k - 1; i++)
    {
        int temp;
        for (int j = 0; j < k - i - 1; j++)
        {
            if (c[j] > c[j + 1])
            {
                temp = c[j + 1];
                c[j + 1] = c[j];
                c[j] = temp;
            }
        }
    }

    // inserting the sorted array containing the odd index integers

    k = 0;
    for (int i = 1; i < size; i += 2)
    {
        b[i] = c[k];
        k++;
    }

    for (int i = 0; i < size; i++)
    {
        if (b[i] != 0)
            printf("%d ", b[i]);
    }
}


void sorting_even_or_odd_elements(int b[], int size){
    int c[size],idx[size],k=0,choice;
    printf("Enter the choice for sorting 1. even or 2. odd elements ");
    scanf("%d",&choice);

    for(int i=0;i<size;i++){
        if(b[i]%2==0 && choice==1){
            c[k]=b[i];
            idx[k]=i;
            k++;
        }
        else if(b[i]%2!=0 && choice==2){
            c[k]=b[i];
            idx[k]=i;
            k++;
        }
    }
    for (int i = 0; i < k - 1; i++)
    {
        int temp;
        for (int j = 0; j < k - i - 1; j++)
        {
            if (c[j] > c[j + 1])
            {
                temp = c[j + 1];
                c[j + 1] = c[j];
                c[j] = temp;
            }
        }
    }
k=0;
    for(int i=0;i<size;i++){
        if(idx[k]==i){
            b[i]=c[k];
            k++;
        }
    }
        for (int i = 0; i < size; i++)
    {
        if (b[i] != 0)
            printf("%d ", b[i]);
    }
}
