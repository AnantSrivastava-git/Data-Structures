#include <stdio.h>

int main()
{
    int n;
    printf("Enter array size\n");
    scanf("%d", &n);

    int A[n];
  
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < n / 2; i++) 
    {
        int max = i, min = i; 

        for (int j = i + 1; j < n - i; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
            if (A[j] > A[max])
            {
                max = j;
            }
        }
        if (min != i)
        {
            int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
            if (max == i)
            {
                max = min;
            }
        }
        if (max != n - i - 1)
        {
            int temp2 = A[n - i - 1];
            A[n - i - 1] = A[max];
            A[max] = temp2;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}
