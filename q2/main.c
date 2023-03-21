#include <stdio.h>
#include <stdlib.h>

/**************************************************
Program:       q2.c
date:          30/9/2021
by :           Mike Mico

purpose:       compute oldest and youngest child
*****************************************************/
void main()
{
    int hasChild,age,highest,lowest;
    lowest = 1000;
    highest =  -1;
    hasChild = 1 ;


        printf("do you have any children? (1 for yes ,elso for no )\n");
        scanf ("%d", &hasChild);

        while (age != -1 && hasChild == 1)
        {
            printf("how old is your child?(enter -1 if no more children)\n");
            scanf ("%d", &age);

            if (age == -1)
            {
                break;
            }

            if (age > highest)
            {
                highest = age;
            }

            if (age < lowest)
            {
                lowest = age;
            }
    }
    if ( lowest == 1000)
        {
            printf("you have no children \n",highest);
        }
    if (lowest != 1000)
        {
            printf("oldest child is %d years old \n",highest);
            printf("youngest child is %d years old \n",lowest);
        }

    return 0;
}
