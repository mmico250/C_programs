/**************************************
Program:       main.c
date:          25/10/2021
by :           Mike Mico

purpose:       driver for linked list class
*****************************************/

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


int main()
{
    /*************************************
    declare linked list as empty
    **************************************/
    LL* m ;
    node* head = NULL;

    m = makeLL(head);

    /*************************************
    insert elements at the start
    **************************************/
    frontInsert(m,4);
    frontInsert(m,5);
    frontInsert(m,3);
    frontInsert(m,12);
    frontInsert(m,5);
    frontInsert(m,21);
    //backInsert(m,13);

    /*************************************
    test each of our functions in LL
    output has descriptive prints indicating the function
    **************************************/
    printf("original list is \n");
    printList(m);

    printf("searching for element 5\n");
    bool sc = search(m,5);
    if (sc==1)
        printf("element was found \n");
    else
        printf("element not found \n");

    printf("count element 5 \n");
    int num = count(m,5);
    printf("appears %d times\n",num);

    printf("remove element 5 \n");
    removeE(m,5);
    printList(m);

    printf("unsorted list is \n");
    printList(m);
    sort(m);
    printf("sorted list is \n");
    printList(m);

    printf("remove all");
    removeAll(m);
    printList(m);

    return 0;
}
