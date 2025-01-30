#include <stdio.h>
#include <math.h>

float avg(int b[][5], int rows, int columns);

int main()
{
    int a[5][5] = {{1, 2, 1, 4, 3}, {2, 1, 3, 2, 4}, {1, 10, 9, 6, 4}, {7, 1, 10, 10, 11}, {5, 4, 3, 1, 2}};
    int b[5][5] = {{1, 2, 1, 4, 3}, {2, 1, 3, 2, 4}, {1, 10, 9, 6, 4}, {7, 1, 10, 10, 11}, {5, 4, 3, 1, 2}};

    int rows = 1, columns = 1;
    while (rows < 4)
    {
        columns=1;
        while (columns < 4)
        {
            b[rows][columns] = trunc(avg(a, rows, columns));
            columns++;
        }
        rows++;
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}

float avg(int b[][5], int rows, int columns)
{
    int sum = 0;
    for (int i = rows - 1; i <= rows + 1; i++)
    {
        for (int j = columns - 1; j <= columns+1; j++)
        {
            sum = sum + b[i][j];
        }
    }
    float avg = sum / 9.0;
    return avg;
}
