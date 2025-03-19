# include<stdio.h>

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
    int indx=0;
    int b[size];

  
    for(int i=size-1;i>=0;i--){
        b[indx]=a[i];
        indx++;
    }
    for(int i=0;i<size;i++){
        printf("%d ",b[i]);
    }

    return 0;
}
