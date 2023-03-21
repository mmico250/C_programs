#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef STACK
#define STACK

#include "S2Node.h"
/* **********************************************************
Program:  	Queue.h
Purpose:    To define a stack of S2Nodes which contain either
            an integer or a character value
Date:		Programmed on November 17th, 2021
Author:		Programmed by Dr. Jeffrey Mark McNally, revised by Mike Mico
************************************************************ */


/* **********************************************************
Structure Definition for Stack
          A stack  contains a top and nothing else.
		  It is a Last in, first out structure
************************************************************ */
typedef struct Stack
{
	s2Node* top;

}stack;


stack* createStack()
{
	stack* newStack = (stack*) malloc( sizeof(stack) );
	newStack->top = NULL;

	return newStack;
}

/************************************************************
declare methods
*************************************************************/

void pushDouble(stack* myStack, double num);
void pushChar(stack* myStack, char myChar);
double popDouble(stack* myStack);
char popChar(stack* myStack);
bool isEmptyStack(stack* myStack);
bool isTopDouble(stack* myStack);
bool isTopChar(stack* myStack);
double peekDouble(stack* myStack);
char peekChar(stack* myStack);

//push a number to the stack
void pushDouble(stack* myStack, double num)
{
    //initialie variables
    s2Node* newnode;
    s2Node* current;
    current = myStack->top;

    //set isNum boolean to true showing it is a number
    newnode = createS2Node(num,'_',true);
    //condition 1- empty stack
    //make the top our new node
    if(isEmptyStack(myStack))
        myStack->top = newnode;
    //condition 2- not empty staack
    //make the top our new node
    //make it now point to the previous top
    else
    {
        myStack->top = newnode;
        newnode->next = current;
    }
 }

 //push a character to the stack
void pushChar(stack* myStack, char myChar)
{
    //initialize variables
    s2Node* newnode;
    s2Node* current;
    current = myStack->top;

    //create char and macke sure bool isNum is false
    newnode = createS2Node(0.0,myChar,false);
    //condition 1 - empty stack
    //condition 2- not empty staack
    //make the top our new node
    //make it now point to the previous top
    if(isEmptyStack(myStack))
        myStack->top = newnode;
    else
    {
        myStack->top = newnode;
        newnode->next = current;
    }
}

//pop a double from the top of the stack
double popDouble(stack* myStack)
{
    //initialize variables
    s2Node* current;
    current = myStack->top;
    double value;
    //condition 1 - empty stack
    if(isEmptyStack(myStack))
    {
        printf("stack is empty \n");
    }
    // condition 2 - not empty stack
    // store the number we are popping in the variable 'value'
    // make the next value the top
    // destroy the current top
    // return our variable 'value'
    else
    {
        if (current->isNum)
        {
            value = current->num;
            myStack->top = current->next;
            destroy(current);
            return value;
        }
    }
}


char popChar(stack* myStack)
{
    s2Node* current;
    current = myStack->top;
    char thisChar;
    // condition 1 - stack is empty
    if(isEmptyStack(myStack))
    {
        printf("stack is empty \n");
    }
    // condition 2 - not empty stack
    // store the number we are popping in the variable 'thisChar'
    // make the next value the top
    // destroy the current top
    // return our variable 'thisChar'
    else
    {
        if (!current->isNum)
        {
            thisChar = current->symbol;
            myStack->top = current->next;
            destroy(current);
            return thisChar;
        }
    }
}

//check if stack is empty
bool isEmptyStack(stack* myStack)
{
    //if the stack is eempty return true
    //otherwise return false
    if(myStack->top == NULL)
        return true;
    else
        return false;
}

//check if the top is an int
bool isTopDouble(stack* myStack)
{
    //if the top is a double return true
    //otherwise return false
    if (myStack->top->isNum)
        return true;
    else
        return false;

}

//check if the top is a char
bool isTopChar(stack* myStack)
{
    //if the top is a character return true
    //otherwise return false
    if (!myStack->top->isNum)
        return true;
    else
        return false;
}

//return the top if its a double but do not remove it
double peekDouble(stack* myStack)
{
    //condition 1 - empty stack
    if(isEmptyStack(myStack))
    {
        printf("stack is empty \n");
    }
    //condition 2 - not empty
    //if the top is a double return that double
    else
    {
        if (isTopDouble(myStack))
        {
            return myStack->top->num;
        }
    }
}

//return the top if its a character but do not remove it
char peekChar(stack* myStack)
{
    //condition 1 - empty stack
    if(isEmptyStack(myStack))
    {
        printf("stack is empty \n");
    }
    //condition 2 - not empty
    //if the top is a character return that character
    else
    {
        if (isTopDouble(myStack))
        {
            return myStack->top->num;
        }
    }
}

void printStack(stack* myStack)
{
	//initialize variables
	s2Node* Current;
	Current = myStack->top;

	//condition 1 - staack is empty
	if (isEmptyStack(myStack))
		printf("stack is empty \n");
    //condition 2 - not empty
	else
	{
	    //loop through the stack starting at the top
		while(Current != NULL )
		{
		    //check whether current is double or char then print accordingly;
			if (Current->isNum)
				printf("%.2lf ",Current->num);
			else
				printf("%c ",Current->symbol);
			Current = Current->next;
		}
	}
	printf("\n");

}
#endif

