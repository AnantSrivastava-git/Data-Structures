# include<stdio.h>

int insertionsort(int b[], int size);
int bubblesort(int b[], int size);

int main()
{
    int size;
    printf("Enter the size of array ");
    scanf("%d",&size);
    int a[size];

for(int i=0;i<size;i++){
    printf("Enter the %d element of array ",i+1);
    scanf("%d",&a[i]);
}

        int choice;
    printf("\nEnter the choice for sort 1 for bubble else for insertion\n");
    scanf("%d",&choice);
    if (choice == 1)
    {
        int swaps=bubblesort(a, size);
        printf("No of swaps taken are %d \n",swaps);
    }
    else{
        int insertions=insertionsort(a, size);
        printf("No of insertions taken are %d \n",insertions);
    }

    return 0;
}


int insertionsort(int b[], int size)
{
    int temp,j,count=0;
    for (int i = 1; i < size; i++)
    {
        temp = b[i];
        for (j = i - 1; j >= 0 && temp < b[j]; j--)
        {
            b[j + 1] = b[j];
            count++;
        }
        b[j + 1] = temp;
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", b[i]);
    }
    return count;
}

int bubblesort(int b[], int size)
{
    int temp,count=0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i; j < size - i - 1; j++)
        {
            if (b[j] > b[j + 1])
            {
                temp = b[j + 1];
                b[i + 1] = b[j];
                b[j] = temp;
                count++;
            }
        }
    }
    return count;
}
