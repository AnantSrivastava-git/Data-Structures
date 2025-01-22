# include<stdio.h>

void duplicates(int b[], int size);

int main()
{
    int a[] = {1, 2, 1, 2, 2, 3, 3, 4, 5, 6, 6};
    int size = sizeof(a) / sizeof(a[0]);

    duplicates(a,size);

    return 0;
}
void duplicates(int b[], int size)
{
    int duplicate,k=0;
    int c[size];
    for(int i=0;i<size;i++){
        duplicate=0;
        for(int j=0;j<size;j++){
            if(b[i]==c[j]){
                duplicate=1;
                break;
            }
        }
        if(duplicate==0){
            c[k]=b[i];
            k++;
        }
    }

    for (int i = 0; i < k; i++)
    {
        printf("%d ", c[i]);
    }

}
