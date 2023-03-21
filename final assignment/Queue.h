#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef QUEUE
#define QUEUE

#include "S2Node.h"
#include "Stack.h"
/* **********************************************************
Program:  	Queue.h
Purpose:    To define a queue of S2Nodes which contain either
            an integer or a character value
Date:		Programmed on November 17th, 2021
Author:		Programmed by Dr. Jeffrey Mark McNally, revised by Mike Mico
************************************************************ */

/* **********************************************************
Structure Definition for Queue
          A stack  contains a head and a tail.
		  It is a First in, first out structure
************************************************************ */
typedef struct Queue
{
	s2Node* head;
	s2Node* tail;

}queue;


queue* createQueue()
{
	queue* newQueue = (queue*) malloc( sizeof(queue) );
	newQueue->head = NULL;
	newQueue->tail = NULL;

	return  newQueue;
}

//initialize methods
void enQueueDouble(queue* myQ, double num);
void enQueueChar(queue* myQ, char myChar);
double deQueueDouble(queue* myQ);
char deQueueChar(queue* myQ);
bool isEmptyQueue(queue* myQ);
bool isHeadDouble(queue* myQ);
bool isHeadChar(queue* myQ);

void enQueueDouble(queue* myQ, double num)
{
	//initialize variables
    s2Node* newnode;
    s2Node* current;
    current = myQ->tail;

    //make sure to set boolean value as true to show our newnode is an int
    //make a dummy char to fill the parameters
    newnode = createS2Node(num,'_',true);
    //condition 1 - if the queue is empty
    if(isEmptyQueue(myQ))
    {
        myQ->head = newnode;
        myQ->tail = newnode;
    }
    //any other condition
    else
    {
        current->next = newnode;
        myQ->tail = newnode;
    }
}

void enQueueChar(queue* myQ, char myChar)
{
	//initialize variables
    s2Node* newnode;
    s2Node* current;
    current = myQ->tail;

    //set boolean value to false and num value can be a dummy like 0
    newnode = createS2Node(0.0,myChar,false);
    //condition 1- if queue is empty
    if(isEmptyQueue(myQ))
    {
        myQ->head = newnode;
        myQ->tail = newnode;
    }
    //other conditions
    else
    {
        current->next = newnode;
        myQ->tail = newnode;
    }
}

// this method is ONLY being called when the top node is a char

double deQueueDouble(queue* myQ)
{
	//initialize variablees
    s2Node* current = myQ->head;

    double value = current->num;
	myQ->head = current->next;
    destroy(current);
    return value;

}


// this method is ONLY being called when the top node is a char

char deQueueChar(queue* myQ)
{
	//initialize variables
    s2Node* current = myQ->head;

    char thisChar = current->symbol;
    myQ->head = current->next;
    destroy(current);
    return thisChar;

}

//method to check if the queue is empty
bool isEmptyQueue(queue* myQ)
{
    if (myQ->head ==NULL)
        return true;
    else
        return false;
}

//method to check if the head is a double
bool isHeadDouble(queue* myQ)
{
    if (myQ->head->isNum)
        return true;
    else
        return false;
}

//method to check if the head is a character
bool isHeadChar(queue* myQ)
{
    if (!myQ->head->isNum)
        return true;
    else
        return false;

}

//print the queue from head to tail
void printQ(queue* myQ)
{
	//initialize variables
	s2Node* curr;
	curr = myQ->head;

	//condition 1 - if queue is empty
	if (isEmptyQueue(myQ))
		printf("queue is empty \n");
    //queue is not empty
	else
	{
	    //loop through the queue
		while(curr != NULL )
		{
		    //check whether the current is a num or char then print accordingly
			if (curr->isNum )
				printf("%.2lf ",curr->num);
			else
                printf("%c ",curr->symbol);
			curr = curr->next;
		}
	}
	printf("\n");
}

#endif

