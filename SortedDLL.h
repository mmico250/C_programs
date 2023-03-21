#include <stdio.h>
#include <stdlib.h>
#include "DLLnode.h"
#include <stdbool.h>

/************************************************************

Program:       SortedDLL.h
date:          16/11/2021
by :           Mike Mico

purpose:       define a sorted doubly linked list

**************************************************************/

/***************************************************

define a sorted doubly linked list
has two node pointers, the head ant the tail

******************************************************/
typedef struct SortedDoublyLinkedList
{
	node* head;
	node* tail;
}DLL;

/***************************************************

initialize the list 

******************************************************/

DLL* makeList()
{
	DLL* myList = (DLL*) malloc(sizeof(DLL));
	//our list must initially be null(empty)
	myList->head = NULL;
	myList->tail = NULL;
	
	return myList;
}

/***************************************************

check if list is empty by checking if head is NULL

******************************************************/

bool isEmpty(DLL* myList)
{
	if(myList->head == NULL)
		return true;
	else
 		return false;
}

/***************************************************

search for an element and return true if found

******************************************************/

bool search(DLL* myList,int value)
{
	//create a node for list traversal current
	node* current;
	current = myList->head;
	//make a bool that is false until element is found
	bool found = false;
	//loop through list 
	while(current != NULL)
	{
		//true only when the element is found 
		if(current->data == value)
			found=true;
		current = current->next;
	}
	return found;
}

/***************************************************

count how many times a number appears in the list

******************************************************/

int count(DLL* myList,int value)
{
	////create a node for list traversal current
	node* current;
	current = myList->head;
	//create a counter that starts at 0
	int counter=0;
	//loop and increment when element is found
	while(current != NULL)
	{
		if(current->data == value)
			counter++;
		current = current->next;
	}
	return counter;
}

/***************************************************

print list

******************************************************/

void printList(DLL* myList)
{
	//create node for traversal
	node* current = myList->head;
	//loop through list printing the data value
	while(current != NULL)
	{
		printf("%d ",current->data);
		current = current->next;
	}
	printf("\n ");
}

void printRList(DLL* myList)
{
	//create node for traversal
	node* current = myList->tail;
	//loop through list printing the data value
	while(current != NULL)
	{
		printf("%d ",current->data);
		current = current->prev;
	}
	printf("\n ");
}

/***************************************************

remove all elements in list and free memory

******************************************************/
void removeAll(DLL* myList)
{
	//initialize variables
	node* temp;
	
	node* current= myList->head;
	while(current != NULL)
	{
		//store the current
		temp = current;
		//set dummy values
		current->data = 0;
		current->prev = NULL;
		current = current->next;
		//current changed but we can still free the node by calling the method free temp
		freeNode(temp);
		
	}
	
	printf("removed all");
	free(myList);
}

/***************************************************

insert element into sorted doubly linked list

******************************************************/

void Insert(DLL* myList,int value)
{
	//initialize variables
	node* newNode;
	
	node* current;
	node* newCurrent;
	
	node* temp;
	node* tempNext;
	node* tempPrev;

	//largest is variable storing he next number after our new node
	node* largest;
	//largestBefore stores the number before our new node
	node* largestBefore;
	
	newNode = createNode(value);
	
	current = myList->head;
	newCurrent = myList->head;
	//if inserting into empty list, head and tail will be the new node
	if (isEmpty(myList))
	{
		myList->head = newNode;
		myList->tail = newNode;
	}
	else
	{
		//if not empty find the position of the node that would point to the new node
		//in a list like 2 3 4 8, if we want to insert 5, our largest will be 8 and largest before is 4
		//below is the calculations to find largest and largestBefore
		//this is to find largest
		while (current != NULL)
		{	
		    // check if our val is less than current data and the greater than the next
		    //next must not be null to avoid segmentation fault
			if (value < current->data && current->next != NULL && value > current->next->data)
			{
				largest = current;
			}	
			else if (value < current->data && current->next == NULL)
			{
				largest = current;
				
			}
			current = current->next;
		}
		//to find largest before
		while (newCurrent != NULL)
		{
			//changes only when our value is greater
			if (value > newCurrent->data)
			{
				largestBefore = newCurrent;
			}
			newCurrent = newCurrent->next;
		}
		//condition 2 to insert
		//if inserting at start and our value is not equal to the head
		if (largest->prev == NULL && value != myList->head->data )
		{
			//initialize variables to store the head
			temp = myList->head;
			//insert at the start
			temp->prev = newNode;
			newNode->next=temp;
			myList->head = newNode;	
			myList->tail = temp;
		}
		//condition 2 to insert
		//if inserting at start and our value is equal to the head
		else if (value == myList->head->data)
		{
			//store head
			temp = myList->head;
			//insert at start
			temp->prev = newNode;
			newNode->next=temp;
			myList->head = newNode;
			
		}	
		//condition 3 to insert
		//insert between list
		else if (largest->prev != NULL && largestBefore->next != NULL )
		{
			//store variables around new node
			temp=largestBefore;
			tempNext = largestBefore->next;
			tempPrev = largestBefore->prev;
			
			//insert between
					
			temp->next = newNode;
		    newNode->prev = temp;
			newNode->next = tempNext;
			tempNext->prev = newNode;
		}
		//condition 4 to insert
		//if inserting at end of list
		else if (largestBefore->next == NULL )		
		{
			//store variable
			temp = largestBefore;
			//insert at end
			largestBefore->next = newNode;
			newNode->prev = temp;
			newNode->next = NULL;
			myList->tail = newNode;			
		}
	}
}

void removeElement(DLL* myList,int value)
{
	//return if element does not exist in list
	if (!search(myList,value))
	{
		printf("value %d not in list \n",value);
			return;
	}
	//declare variables
	node* temp = NULL;
	node* tempPrev;
	node* tempNext;
	node* current = myList->head;
	//find element to remove 
	//assign it to temp
	while(current != NULL)
	{
		if(current->data == value)
		{
			temp = current;
		}
		current = current->next;
		if (temp !=NULL)
			current = NULL;
	}
	//store the nodes around it
	tempPrev = temp->prev;
	tempNext = temp->next;
	
	
	//condition 1 to delete
	//delete first element
	if (temp->data == myList->head->data)
	{
		//make next element the head and adjust pointers
		tempNext->prev = NULL;
		myList->head = tempNext;
		//free the deleted node
		freeNode(temp);
	}
	
	else if (temp == myList->tail )
	{
		//adjust the prev and next nodes to exclude temp
		tempPrev->next = NULL;
		myList->tail = tempPrev;
		//free temp
		freeNode(temp);
	}
	else
	{
		//make tail be the previous node
		//make the node point to null
		tempPrev->next = tempNext;
		tempNext->prev = tempPrev;
		//free temp
		freeNode(temp);
	}
	
}

