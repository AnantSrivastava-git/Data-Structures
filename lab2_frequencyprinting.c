#include <stdio.h>

int max(int b[], int size);

int main()
{
    int a[] = {1, 2, 1, 2, 2, 3, 3, 4, 5, 6, 6};
    int size = sizeof(a) / sizeof(a[0]), count,size2=0;

    int maximum = max(a, size);
    int b[size];

    for (int i = 1; i <= maximum; i++)
    {
        count = 0;
        for (int j = 0; j <size; j++)
        {
            if (a[j] == i)
            {
                count++;
            }
        }
        if (count != 0){
            b[i-1] = count;
            size2++;
            }
    }

    printf("The frequency array for the original array is \n");
    for (int i = 0; i <= size2; i++)
    {
        if(b[i]!=0)
        printf("%d ", b[i]);
    }

    return 0;
}

int max(int b[], int size)
{
    int maximum = b[0];
    for (int i = 0; i < size; i++)
    {
        if (maximum < b[i])
        {
            maximum = b[i];
        }
    }
    return maximum;
}


 

