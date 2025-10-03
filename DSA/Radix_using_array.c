#include <stdio.h>
#include <stdlib.h>

int get_max(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

void count_sort(int a[], int n, int pos)
{
    int count[10] = {0}, b[n];
    // Initializing the counts
    for (int i = 0; i < n; i++)
    {
        count[(a[i] / pos) % 10]++;
    }

    // Cummulative Count array
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    //
    for (int i = n - 1; i >= 0; i--)
    {
        b[--count[(a[i] / pos) % 10]] = a[i];
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}

void radix_sort(int a[], int n)
{
    int max = get_max(a, n);
    for (int pos = 1; max / pos > 0; pos *= 10)
    {
        count_sort(a, n, pos);
    }
}

int main()
{
    int n = 10;
    int a[10] = {8, 677, 342, 88, 95, 210, 125, 172, 403, 1};
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    radix_sort(a, n);
    printf("\nSorted Array\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}