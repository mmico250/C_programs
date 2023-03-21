#include <stdio.h>
#include <stdlib.h>

typedef struct SortedDoublyLinkedList
{
	node* head;
}DLL;

typedef struct Node node;

DLL* createNode(int data)
{
	node* newNode = (node*) malloc(sizeof(node));
	newNode->data = 0;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	return newNode;
}
