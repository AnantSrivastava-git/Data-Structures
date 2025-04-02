#include <stdio.h>
#include <stdlib.h>

#define N 6
char stack[6];

int pusharray(int top, char val)
{
    if (top == -1)
    {
        top++;
        stack[top] = val;
    }
    else if (top == N - 1)
    {
        printf("Stack is full");
        return top;
    }
    else
    {
        top++;
        stack[top] = val;
    }
    return top;
}

int poparray(int top)
{
    if (top == -1)
    {
        printf("Stack is empty");
        return top;
    }
    else
    {
        top--;
    }
    return top;
}

char peek(int top)
{
    return stack[top];
}

void display_stackarray(int top)
{
    for (int i = top; i >= 0; i--)
    {
        printf("%c", stack[i]);
    }
}

void parenthesischecker(int top)
{
    int count1 = 0, count2 = 0, count3 = 0;
    while (top != -1)
    {
        if (peek(top) == '}')
        {
            count1++;
            top = poparray(top);
        }
        else if (peek(top) == ']')
        {
            count2++;
            top = poparray(top);
        }
        else if (peek(top) == ')')
        {
            count3++;
            top = poparray(top);
        }
        else 
        break;
    }

    while(top!=-1){
        if (peek(top) == '{')
        {
            count1--;
            top = poparray(top);
        }
        else if (peek(top) == '[')
        {
            count2--;
            top = poparray(top);
        }
        else if (peek(top) == '(')
        {
            count3--;
            top = poparray(top);
        }
        else 
        break;
    }


    if(count1 !=0 || count2 !=0 || count3 !=0 ){
        printf("Invalid");
    }
    else
    printf("Perfect");
}

int main()
{
    
    int top = -1, choice;
    char val;
    do
    {
        printf("Enter the valued to be pushed:\n");
        scanf(" %c", &val);
        top = pusharray(top, val);

        printf("Do you want to push more?\n");
        scanf("%d", &choice);
    } while (choice == 1);

    display_stackarray(top);

    printf("\n");

    parenthesischecker(top);

    return 0;
}
