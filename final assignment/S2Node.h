#ifndef S2NODE
#define S2NODE
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/* **********************************************************
Program:  	Queue.h
Purpose:    To define a queue of S2Nodes which contain either
            an integer or a character value
Date:		Programmed on November 17th, 2021
Author:		Programmed by Dr. Jeffrey Mark McNally, revised by Mike Mico
************************************************************ */


/* **********************************************************
Structure Definition for Snode
          A Snode of this type can hold either an integer or a character
          We use a boolean variable (isNum) to say which but have space for both
                  isNum == true  means this node contains an integer
                  isNum == false means this node contains a characer
				                 which can only be +, -, *, /, ^, (, or )
		  If the contents are a character, we assign a precedence according to
		             +    1
		             -    1
		             *    2
		             /    2
		             ^    3
		             (    4
		             )    4
************************************************************ */
typedef struct S2Node
{
    double num;
    char symbol;
    int precedence;
    bool isNum;
	struct S2Node* next;
}s2Node;



/* **********************************************************
Program:  	Snode.h
Purpose:    To define a Singly Linked Node which contains either
            an double or a character value
Date:		Programmed on November 9th, 2019
Author:		Programmed by Dr. Jeffrey Mark McNally
************************************************************ */
s2Node* createS2Node(double inNum, char inChar, bool isNum)
{
    s2Node* newNode = (s2Node*) malloc(sizeof(s2Node));
    newNode->isNum = isNum;
	//printf("creating a node with a %s \n", (newNode->isNum) ? "number": "character");
	newNode->num = inNum;
    newNode->symbol = inChar;
    //printf("num = %lf  and char is %c \n", newNode->num, newNode->symbol);

    if (isNum)
	{
        newNode->isNum = isNum;
        //printf("making a node with double % \n", newNode->num);
	}
	else
    {
        //printf("making a node with character %c \n", newNode->symbol);
		switch (newNode->symbol)
		{
			case '+':
			case '-':
				newNode->precedence  = 1;
				break;
			case '*':
			case '/':
				newNode->precedence  = 2;
				break;
			case '^':
				newNode->precedence  = 3;
				break;
			default:
				newNode->precedence  = 4;
		}
	}
    newNode->next = NULL;
    return newNode;
}



void printS2Node(s2Node* current)
{
	printf("Boolean is %s:  contains ", (current->isNum) ? "true": "false");
    if (current->isNum)
	    printf("%lf", current->num);
	else
    	printf("%c",  current->symbol);
    printf(" at %9d with a next at %9d \n\n", current, current->next);
}

void destroy(s2Node* current)
{
    current->num = rand();
    current->symbol = rand();
    current->next = NULL;
    free(current);
}



#endif

