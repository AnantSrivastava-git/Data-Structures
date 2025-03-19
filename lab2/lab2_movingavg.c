#include <stdio.h>

int main()
{
    int a[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int i=0,numb,num,sum=0,avg;
    printf("Enter the number\n");
    scanf("%d",&numb);
    num=numb-1;
    while(i<num){
        int j=0;
        while(j<=i){
            sum=sum+a[j];
            j++;
        }
        avg=sum/(i+1);
        sum=0;
        i++;  
    printf("%d ",avg);
    }
    int k=0;
    while(i>=num && i<15){
       for(int j=0+k;j<=num+k;j++) {
        sum=sum+a[j];
        }
       avg=sum/numb;
       sum=0;
       k++;
       i++;
       printf("%d ",avg);
    }

    return 0;
}

