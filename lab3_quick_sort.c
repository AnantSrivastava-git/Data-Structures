#include<stdio.h>

int quick_sort(int a[], int low, int high){
    int pivot=a[high];
    int i=low-1,temp;
if (low >= high) return 0;
else{    
    for(int j=low;j<high;j++){
        if(a[j]<pivot){
            i++;
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
    temp=a[high];
    a[high]=a[i+1];
    a[i+1]=temp;

    quick_sort(a, low, i-1);
    quick_sort(a, i+1, high);}
}

int main()
{
    int a[10]={7,8,3,5,4,1,2,6,10,9},min,temp;


    quick_sort(a,0,9);

    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
