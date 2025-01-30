#include<stdio.h>
int main()
{
    int a[10]={7,8,3,5,4,1,2,6,10,9};
    int temp,j;
    // insertion
    for(int i=2;i<10;i+=2){
        temp=a[i];
        for(j=i-2;j>=0 && temp<a[j];j-=2){
            a[j+2]=a[j];
        }
         a[j+2]=temp;
    }
    for(int i=0; i<10;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
