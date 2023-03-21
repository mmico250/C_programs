#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"


/* **********************************************************
Program:  	postfix.h
Purpose:    convert expressions from infix to postfix
Date:		Programmed on December 5th, 2021
Author:		Programmed by Mike Mico
************************************************************ */

queue* postfix(queue* myQ)
{
	//initialize variables
	stack* stck = createStack();
	queue* emptyQ = createQueue();
	s2Node* cur = myQ->head;
	bool closedBracket = false;

    //if we have an empty queue return it
	if(isEmptyQueue(myQ))
		return emptyQ;
    //loop through the queueu
	while(cur != NULL)
	{
		//is a number
		if(cur->isNum)
		{
			cur = cur->next;
			enQueueDouble(emptyQ,deQueueDouble(myQ));
		}

		//is a character
		else
		{
			if(isEmptyStack(stck))
			{
				cur = cur->next;
				pushChar(stck,deQueueChar(myQ));
			}

			else
			{
				if(cur->precedence  >  stck->top->precedence )
				{
					//not brackets
					if(cur->precedence != 4)
                    {
                        cur = cur->next;
                        pushChar(stck,deQueueChar(myQ));
                    }
					//open bracket

					else if(cur->precedence == 4)
					{
                        if(closedBracket == false)
                        {
                            cur = cur->next;
                            pushChar(stck,deQueueChar(myQ));
                            stck->top->precedence = 0;
                            closedBracket = true;
                        }
                        else
                        {
                            while (stck->top->precedence != 0)
                            {
                                enQueueChar(emptyQ,popChar(stck));
                            }
                            popChar(stck);
                            closedBracket = false;

                        }
					}
					//close bracket
			    }
			    //precedence is less
		   		else
		    	{
                    while (stck->top != NULL)
                    {
                        if(stck->top->symbol == '(' || stck->top->symbol == ')')
                            popChar(stck);
                        else
                            enQueueChar(emptyQ,popChar(stck));
                    }
				}
			}
		}

	}


	while (stck->top != NULL)
	{
		if(stck->top->symbol == '(' || stck->top->symbol == ')')
            popChar(stck);
        else
            enQueueChar(emptyQ,popChar(stck));
	}

    return emptyQ;

}
