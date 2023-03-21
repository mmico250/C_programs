#include <stdio.h>
#include <stdlib.h>

void swap();

int main()
{
    int x=10;
    int y=20;
    swap(x,y);
    printf ("x %d \n y %d",x,y);
    return 0;
}
void swap(int a, int b)
{
    int c,d;
    c=a;
    d=b;
    a=d;
    b=c;
    return 0;
}
