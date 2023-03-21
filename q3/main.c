#include <stdio.h>
#include <stdlib.h>

/**************************************************
Program:       q3.c
date:          30/9/2021
by :           Mike Mico

purpose:       check if number has no more than 4 d.p
*****************************************************/
void main()
{
    double num;
    double tempnum;
    int abs;
    double absDouble;

    printf("enter random  double number between 10 and 20 with no more than 4 decimal places !\n");
    scanf("%lf",&num);

    tempnum= num * 10000;
    abs= (int) (num * 10000);
    absDouble = (double)abs;

    if (num >=10.0 && num <= 20 )
    {
        if ( tempnum - absDouble > 0)
        {
        printf("invalid input \n");
        }
        if ( tempnum - absDouble == 0)
        {
        printf("thank you \n");

        }
    }
    if (num < 10.0 || num > 20)
        printf("invalid input \n");

    return 0;
}
