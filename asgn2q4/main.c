#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void removeVowel(char* current);

int main()
{
    char familyName[20];
    char firstName[20];
    char* otherNames;
    char* user;
    char* formalName;
    char* initials;
    int decide=1;
    char thisName[20];
    int mcount;

    otherNames=" ";
    printf("Enter last name \n");
    scanf("%s",familyName);
    printf("Enter first name \n");
    scanf("%s",firstName);
    //do
    //{
        printf("do you have other names? 1 for Y or 0 for N \n");
        scanf("%d",&decide);

        printf("Enter other names \n");
        scanf("%s",thisName);
        mcount++;

        otherNames = strtok(thisName," ");


        printf("do you have other names? 1 for Y or 0 for N \n");
        scanf("%d",&decide);

    //}while (decide == 1);


    combined= strcat(familyName,", ");
    combined= strcat(combined,firstName);

    printf("Enter new last name \n");
    scanf("%s",familyName);

    printf("%s \n",combined);
    printf("%d \n",mcount);
    printf(" middle names are %s \n",otherNames);
    return 0;
}

void removeVowel(char* current)
{
    int length  = strlen(current);
    for (int i=0;i<length-1;i++)
    {
        for(int j=i+1;j<length;j++)
        {
            if curr
        }
    }
}
