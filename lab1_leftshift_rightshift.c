# include<stdio.h>

void leftshift(int b[], int size,int indx);
void rightshift(int b[], int size,int indx);

int main()
{
    int a[] = {1, 2, 1, 2, 2, 3, 3, 4, 5, 6, 6};
    int size = sizeof(a) / sizeof(a[0]),indx,choice;

    printf("Enter the choice of shift you want to happen ");
    printf("Enter the 1 for leftshift and 2 rightshift ");
    scanf("%d",&choice);

    printf("Enter the index you want the shift to happen ");
    scanf("%d",&indx);

    if(choice==1)
    leftshift(a,size,indx);

    if(choice==2)
    rightshift(a,size,indx);

    return 0;
}
void leftshift(int b[], int size, int indx){
    int c[indx];
    for(int i=0;i<indx;i++){
        c[i]=b[i];
    }
    
    for(int i=indx;i<size;i++){
        b[i-indx]=b[i];
    }

    for(int i=0;i<indx;i++){
        b[size -indx +i]=c[i];
    }

    for(int i=0;i<size;i++){
        printf("%d ",b[i]);
    }
}

void rightshift(int b[], int size,int indx){
        int c[indx],count=0;
    for(int i=size-indx;i<size;i++){
        c[count]=b[i];
        count++;
    }
    
    for(int i=size-indx;i>=0;i--){
        b[i+indx]=b[i];
    }

    for(int i=0;i<indx;i++){
        b[i]=c[i];
    }

    for(int i=0;i<size;i++){
        printf("%d ",b[i]);
    }
}
