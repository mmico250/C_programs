/**************************************
Program:       asgn2q3.c
date:          25/10/2021
by :           Mike Mico

purpose:       make points and sort
*****************************************/

#include <stdio.h>
#include <stdlib.h>

void printPoint(int * a,int * b,int position)
{
    printf("point %d is ( %d, %d )\n" ,position+1 ,a[position],b[position]);
}

void printArray(int* a,int* b)
{
    for(int i=0;i<25;i++)
        printPoint(a,b,i);
}

void sort(int*a,int*b)
{
    int temp;
    for(int i=0;i<24;i++)
    {
        for(int j=i+1; j<25;j++)
        {
            if (a[j] < a[i])
            {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
    for(int i=0;i<24;i++)
    {
        for(int j=i+1;j<25;j++)
        {
            int k=0;
            int lowest;
            while (a[i]==a[j] && k<24)
            {
                lowest=b[j];
                if (b[j]<b[i])
                {
                    temp=b[j];
                    b[j]=b[i];
                    b[i]=temp;
                }
                k++;
            }
        }
    }
}
int main()
{
    int x[25];
    int y[25];
    int randNum;
    int range;
    time_t t;

    srand((unsigned)time(&t));
    for(int i=0;i<25;i++)
    {
        randNum = rand() % 2;
        if (randNum > 0)
        {
             x[i] = rand() % 21;
             y[i] = rand() % 21;
        }

        else
        {
             x[i] = -1 * rand() % 21;
             y[i] = -1 * rand() % 21;
        }
    }
    printArray(x,y);
    printf("\n\n");

    sort(x,y);
    printArray(x,y);
    return 0;
}
