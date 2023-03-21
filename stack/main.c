#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
typedef struct Stack
{
    int size;
    int* array;
    int top;
}stack;

stack* createStack( int size)
{
    int* x;
    stack* thisStack = (stack*) calloc (sizeof(stack),1);
    thisStack->array = x[size];
    thisStack->size = size;
    thisStack->top = 0;
    return thisStack;
}

bool isFull(stack* st)
{
    bool full = false;
    if (st->top == st->size-1)
        full = true;
    return full;
}

bool isEmpty(stack* st)
{
    bool empty = false;
    if (st->top == 0)
        empty = true;
    return empty;
}

void push(stack* st,int E)
{
    if(!isEmpty(st))
        st->top = E;
    return;
}

void peek(stack* st)
{
    int result;
    result = st->top;
    printf("%d \n",result);
    return ;
}
/*
int main()
{
    printf("Hello world!\n");
    stack* stack1 = createStack(2);
    push(stack1,5);
    push(stack1,2);
    peek(stack1);
    printf("%d",stack1->top);
    return 0;
}
*/

#include<string.h>

int main()
{
    char* str="122";
    int x =atoi(str[0]);
    printf(" x is %d \n",x);
    return;
}
