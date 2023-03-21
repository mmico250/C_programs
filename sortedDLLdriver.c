#include <stdio.h>
#include <stdlib.h>
#include "sortedDLL.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/************************************************************

Program:       SortedDLLdriver.c
date:          16/11/2021
by :           Mike Mico

purpose:       define a sorted doubly linked list

**************************************************************/


int main(int argc, char *argv[]) 
{
	DLL* myList = makeList();
	Insert(myList,8);
	Insert(myList,2);
	Insert(myList,3);
	Insert(myList,4);
	Insert(myList,9);
	Insert(myList,12);
	Insert(myList,2);
	Insert(myList,5);
	Insert(myList,12);
	Insert(myList,9);

	printf("count is %d \n",count(myList,2));
	
	printList(myList);
	printRList(myList);
	
    printf("delete 2,2,9,3,12,12,9,2 in this order  \n");
	removeElement(myList,2);
	removeElement(myList,2);
	removeElement(myList,9);
	removeElement(myList,3);
	removeElement(myList,12);
	removeElement(myList,12);
	removeElement(myList,9);
	printf("attempt to delete 2 which doent exist in list anymore \n");
	removeElement(myList,2);
	
	bool sc=isEmpty(myList);
	//printf("%d",sc);
	printList(myList);
	printRList(myList);
	removeAll(myList);
	
	return 0;
}
