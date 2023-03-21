#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"
#include "Queue.h"
#include "S2Node.h"
#include "postfix.h"

#define pi 3.14

/* **********************************************************
Program:  	driver.c
Purpose:    test postfix methods,queue methods and stack methods
Date:		Programmed on December 5th, 2021
Author:		Programmed by Mike Mico
************************************************************ */



int main(int argc, char *argv[]) {
/*
	s2Node* tester = createS2Node(42, '_', true);
	printS2Node(tester);
	//free(tester);

	s2Node* tester2 = createS2Node(0, 'a', false);
	printS2Node(tester2);

	stack* thisStack = createStack();

	pushDouble(thisStack,43);
	pushDouble(thisStack,23);
	pushDouble(thisStack,11);
	pushChar(thisStack,'+');
	pushChar(thisStack,'-');

	printf("we are popping %c \n",popChar(thisStack));
	printf("we are popping %c \n",popChar(thisStack));
	printf("we are popping %lf \n",popDouble(thisStack));
	printf("we are popping %lf \n",popDouble(thisStack));
	printf("we are popping %lf \n",popDouble(thisStack));
	printf("we are popping %lf \n",popDouble(thisStack));
*/

	queue* thisQ = createQueue();


	queue* newQ ;

// 1 A

	enQueueDouble(thisQ,3);
	enQueueChar(thisQ,'*');
    enQueueDouble(thisQ,4);
	enQueueChar(thisQ,'+');
	enQueueDouble(thisQ,5);
	enQueueChar(thisQ,'+');
	enQueueDouble(thisQ,2);
	enQueueChar(thisQ,'*');
	enQueueDouble(thisQ,6);
	enQueueChar(thisQ,'-');
	enQueueDouble(thisQ,3);

	printf("equation 1 is \n");

   	printQ(thisQ);
    printf(" \n");

   	newQ = postfix(thisQ);
   	printf("postfix notation \n");
   	printQ(newQ);
    printf(" \n");
   	thisQ = createQueue();
//1 B

	enQueueDouble(thisQ,3);
	enQueueChar(thisQ,'*');
	enQueueChar(thisQ,'(');
    enQueueDouble(thisQ,4);
	enQueueChar(thisQ,'+');
	enQueueDouble(thisQ,5);
	enQueueChar(thisQ,')');
	enQueueChar(thisQ,'^');
	enQueueDouble(thisQ,2);
	enQueueChar(thisQ,'*');
	enQueueDouble(thisQ,6);
	enQueueChar(thisQ,'-');
	enQueueDouble(thisQ,3);

    printf("equation 2 is \n");

   	printQ(thisQ);
    printf(" \n");
   	newQ = postfix(thisQ);
   	printf("postfix notation \n");
   	printQ(newQ);


//	free(tester);
//	free(tester2);
	return 0;
}
