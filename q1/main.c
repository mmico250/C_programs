#include <stdio.h>
#include <stdlib.h>
/**************************************************
Program:       q1.c
date:          30/9/2021
by :           Mike Mico

purpose:       date checker
*****************************************************/
void main()
{
    int month, day, valid, year , newDate;
    newDate = 1;
    char *monthname = "";
    char *suffix="th";

    do
    {
    printf("what is month? \n");
    scanf("%d", &month);

    printf("what is day? \n");
    scanf("%d", &day);



        switch (month)
        {
        case 1:
            valid = 1;
            monthname = "January";
            break;
        case 2:
            valid = 1;
            monthname = "February";
            break;
        case 3:
            valid = 1;
            monthname = "March";
            break;
        case 4:
            valid = 1;
            monthname = "April";
            break;
        case 5:
            valid = 1;
            monthname = "May";
            break;
        case 6:
            valid = 1;
            monthname = "June";
            break;
        case 7:
            valid = 1;
            monthname = "July";
            break;
        case 8:
            valid = 1;
            monthname = "August";
            break;
        case 9:
            valid = 1;
            monthname = "September";
            break;
        case 10:
            valid = 1;
            monthname = "October";
            break;
        case 11:
            valid = 1;
            monthname = "November";
            break;
        case 12:
            valid = 1;
            monthname = "December";
            break;
        default:
            valid = 0;
        }

        switch (day)
        {
        case 1:
            suffix ="st";
            break;
        case 21:
            suffix = "st";
            break;
        case 31:
            suffix = "st";
            break;
        case 2:
            suffix ="nd";
            break;
        case 22:
            suffix = "nd";
            break;
        case 3:
            suffix ="rd";
            break;
        case 23:
            suffix = "rd";
            break;
        default:
            suffix ="th";
            break;
        }
        if (month ==2)
        {
            printf("what year is it?(after 2000)");
            scanf("%d", &newDate);
            if (newDate % 4 ==0)
            {
                if (day >0 && day <= 29)
                    valid == 1;
                else
                    valid == 0;
            }
            if (newDate % 4 !=0)
            {
                if (day >0 && day <= 28)
                    valid == 1;
                else
                    valid == 0;
            }
        }

        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 )
        {
            if (day >0 && day <= 31)
                    valid == 1;
                else
                    valid == 0;
        }


        if (month == 4 || month == 6 || month == 9 || month == 11  )
        {
            if (day >0 && day <= 30)
                    valid == 1;
                else
                    valid == 0;
        }


        if (valid == 1)
        {
            printf("this is the %d%s of %s \n", day, suffix, monthname);
        }

        if (valid == 0)
        {
            printf("this is not a valid date \n");
        }
        printf("Do you have another date to enter?(1 for yes,any other number for no) \n");
        scanf("%d", &newDate);

    }while (newDate == 1);
    return 0;
}
