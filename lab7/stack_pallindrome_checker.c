#include <stdio.h>
#include<stdlib.h>

#define N 100
char stack[N];


int pusharray (int top, char val){
    if(top == -1){
        top++;
        stack[top] = val;
    }
    else if(top == N-1){
        printf("Stack is full");
        return top;
    }
    else{
        top++;
        stack[top] = val;
    }
    return top;
}


void display_stackarray( int top ){
    for(int i = top; i>=0 ; i--){
        printf("%c",stack[i]);
    }
    printf("\n");
}


int main()
{

    char str[20];
    printf("Enter the string you want to check :");
    scanf("%s",str);


    int top = -1,i=0;
    while(str[i] != '\0'){
    top = pusharray(top,str[i]);
    i++;
    }
    
    display_stackarray(top);
    
    int test=1,j=0;
    while(top!=-1){
        if(str[j] != stack[top]){
        test=-1;
        break;
        }
        top--;
        j++;
    }

    if(test == -1)
    printf("Entered string is not a pallindrome\n");
    else
    printf("Success entered string is a pallindrome\n");

    printf("\n");

    return 0;
}
