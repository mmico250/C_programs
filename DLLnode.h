#include <stdio.h>
#include <stdlib.h>

/************************************************************

Program:       DLLnode.h
date:          16/11/2021
by :           Mike Mico

purpose:       ddefine a DLL node

**************************************************************/

/***************************************************

define a DLL node
the node contains integer data and points to 2 other nodes
next and prev.

******************************************************/
struct Node
{
	int data;
	//pointer to the next node in list
	struct Node* next;
    //pointer to previous node in list
	struct Node* prev;
};

typedef struct Node node;

/***************************************************

instantiate a DLL node
bring in an integer parameter and assign the DLL data to be this integer
next and prev instantiated as NULL.

******************************************************/
node* createNode(int data)
{
	//allocate space for the created node
	node* newNode = (node*) malloc(sizeof(node));
	//data is brought in, the rest are null
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	return newNode;
}

/***************************************************

free a node

******************************************************/
void freeNode(node* thisnode)
{
	//set to garbage
	thisnode->data = 0;
	thisnode->next = NULL;
	thisnode->prev = NULL;
	//free the memory
	free(thisnode);
}


