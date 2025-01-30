#include<stdio.h>
int main()
{
    int a[10]={7,8,3,5,4,1,2,6,10,9},min,temp;
    for(int i=1;i<10;i+=2){
        min=i;
        for(int j=i;j<10;j+=2){
            if(a[j]<a[min]){
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }


    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
