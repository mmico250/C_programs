/**************************************
Program:       asgn2q5.c
date:          25/10/2021
by :           Mike Mico

purpose:       create a doubling array
*****************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct DoublingArray
{
    int * x;
    int size;
}doublingArray;

doublingArray* makeDoublingArray( int* x,int size)
{

    doublingArray* thisA= (doublingArray*) malloc(sizeof(doublingArray));

    thisA->x = x;
    thisA->size = size;
    return thisA;
}

void addE(doublingArray* thisA,int E,int index)
{
    int* tempA;

    if (index < thisA->size)
    {

        thisA->x[index] = E;
    }
    if (index >= thisA->size)
    {

        tempA = (int*) calloc(sizeof(int),thisA->size * 2);
        for (int i=0; i<thisA->size ;i++)
        {
            tempA[i] = thisA->x[i];
        }
        printf("\n");
        printf("doubling array ... \n");
        tempA[index] = E;

        for (int i=0;i<=thisA->size ;i++)
        {
            thisA->x = tempA;
        }

        thisA->size = thisA->size * 2;

    }
    return;
}

void search(doublingArray* thisA, int E)
{
    int n=thisA->size;
    int found = 0;
    for(int i=0; i<n; i++)
    {
        if (thisA->x[i] == E)
        {
            printf("Element found at index %d \n",i);
            found = 1;
        }
    }
    if (found == 0)
        printf("element not found \n");
}

void removeE(doublingArray* thisA, int E)
{
    int n=thisA->size;
    int found = 0;
    for(int i=0; i<n; i++)
    {
        if (thisA->x[i] == E)
        {
            thisA->x[i] = NULL;
            found = 1 ;
        }

    }
    if (found == 0)
        printf("element not in array \n");
}

void sort(doublingArray* thisA)
{
    int n=thisA->size;
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(thisA->x[j] < thisA->x[i])
            {
                if (thisA->x[j] ==0)
                {
                    j++;
                    return;
                }
                temp = thisA->x[j];
                thisA->x[j] = thisA->x[i];
                thisA->x[i] = temp;
            }
        }
    }
}

void printDA(doublingArray* thisA)
{
    printf("array is -> ");
    for (int i=0;i< thisA->size  ;i++)
    {
        printf("%d ",thisA->x[i]);
    }
    printf("\n");
}
void freeDA(doublingArray* thisA)
{
    thisA->size = 0;
    thisA->x = 0;
    free(thisA->x);
    free(thisA->size);
}

int main()
{
    int n=2;
    int* x[n-1];
    doublingArray* DA = makeDoublingArray(x,n);
    addE(DA,1,0);
    printDA(DA);
    addE(DA,2,1);
    printDA(DA);
    addE(DA,3,2);
    printDA(DA);
    addE(DA,4,3);
    printDA(DA);
    addE(DA,5,4);
    printDA(DA);
    addE(DA,6,5);
    addE(DA,8,8);
    sort(DA);

    removeE(DA,8);
    printDA(DA);
    search(DA,8);
    freeDA(DA);
    printDA(DA);

    return 0;
}
