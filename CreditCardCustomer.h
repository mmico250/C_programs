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
    if (index<thisA->size)
    {
        thisA->x[index] = E;
    }
    if (index > thisA->size);
    {
        //thisA->x = (int*) calloc(sizeof(int),thisA->size*2);
        printf("doubling array ... \n");
        thisA->size= thisA->size*2;
        thisA->x[index] = E;

    }


}

void search(doublingArray* thisA, int E)
{
    int n=thisA->size;
    for(int i=0; i<n; i++)
    {
        if (thisA->x == E)
            printf("Element found at %d \n",i);
    }
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
    for (int i=0;i<thisA->size;i++)
    {
        printf("%d ",thisA->x[i]);
    }
    printf("\n");
}
void freeDA(doublingArray* thisA)
{
    thisA->size = 0;
    thisA->x = 0;
    free(thisA);
}

int main()
{
    int n=2;
    int* x[n];
    doublingArray* DA = makeDoublingArray(x,n);
    addE(DA,1,0);
    addE(DA,2,1);
    /*
    addE(DA,3,2);
    addE(DA,4,3);
    addE(DA,5,4);
    */
    printDA(DA);

    return 0;
}

