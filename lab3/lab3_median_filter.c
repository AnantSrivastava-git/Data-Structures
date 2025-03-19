#include <stdio.h>

int median_calculator(int a[][5], int rows, int columns)
{
    int c[9], k = 0;
    for (int i = rows; i < rows + 3; i++)
    {
        for (int j = columns; j < columns + 3; j++)
        {
            c[k] = a[i][j];
            k++;
        }
    }

    int temp;
    for (int i = 0; i < k - 1; i++)
    {
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

    return c[4];

}

int main()
{
    int a[5][5] = {{1, 2, 1, 4, 3}, {2, 1, 3, 2, 4}, {1, 10, 9, 6, 4}, {7, 1, 10, 10, 11}, {5, 4, 3, 1, 2}};
    int b[5][5] = {{1, 2, 1, 4, 3}, {2, 1, 3, 2, 4}, {1, 10, 9, 6, 4}, {7, 1, 10, 10, 11}, {5, 4, 3, 1, 2}};

    int c[9], rows = 0, columns;

    while (rows < 3)
    {
        columns = 0;
        while (columns < 3)
        {
            b[rows+1][columns+1]=median_calculator(a,rows,columns);
            columns++;
        }
        rows++;
    }


    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }

    return 0;
}
