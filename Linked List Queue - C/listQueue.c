/* CS261- Worksheet 18 */
/* Name: Ryan Farran
 * Date: 07/12/2019
 */

#include "listQueue.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void listQueueInit(struct listQueue *q)
{
    struct link* lnk = (struct link*) malloc(sizeof(struct link));
    assert(lnk != 0); /* lnk is the sentinel */
    lnk->next = 0;
    q->firstLink = q->lastLink = lnk;
}

void listQueueAddBack(struct listQueue *q, TYPE e)
{
    struct link* newLink = (struct link*) malloc(sizeof(q)); //Declare new link and allocate memory
    assert(newLink != 0); //ensure malloc worked properlya nd that newLink does not equal null (0)
    newLink->value = e; //Assign TYPE e to newlink->value
    printf("ADDING %d to BACK of QUEUE!\n", e);
    if (listQueueIsEmpty(q) == 1)
    { //Condition if list IS EMPTY
        q->firstLink->next = newLink; //Sentinel (after firstLink) points to newLink
        q->lastLink = newLink; //lastLink points to newLin, too, since there is only one element
        newLink->next = 0; //set newLink to null (0)
    }
    else
    {
        newLink->next = q->lastLink->next; //set newLink's next value to the current last value's next pointer (should be null, or 0)
        q->lastLink->next = newLink; //set current last link's next pointer to newLink
        q->lastLink = newLink; //Finally, make lastLink point to newLink
    }
    
}

TYPE listQueueFront(struct listQueue *q)
{
    printf("Front of QUEUE: %d\n", q->firstLink->next->value);
    return q->firstLink->next->value;
}

void listQueueRemoveFront(struct listQueue *q)
{
    if (listQueueIsEmpty(q) == 1)
    {
        printf("\nSorry, mate, but this list is empty...\n");
    }
    else
    {
        printf("\nREMOVING %d from FRONT of QUEUE\n", q->firstLink->next->value);
        q->firstLink->next->value = 0; //first link (after sentinel) is set to 0 prior to freeing
        free(q->firstLink->next); //free link after sentinel (first link)
        q->firstLink->next = q->firstLink->next->next;
    }
}

int listQueueIsEmpty(struct listQueue *q)
{
    int booleanValue = 0;
    if (q->firstLink == q->lastLink)
    {
        booleanValue = 1;
    }
    return booleanValue;
}

void printListQueue(struct listQueue *q)
{
    printf("\nFRONT of queue...\n");
    if (listQueueIsEmpty(q) == 0)
    {
        struct link linkIter;
        struct link* linkPtr = &linkIter;
        linkPtr = q->firstLink->next;
        int count = 1;
        do
        {
            printf("Link #%d's value is %d\n", count, linkPtr->value);
            linkPtr = linkPtr->next;
            count++;
        }
        while (linkPtr != 0);
        free(linkPtr);
    }
    else
    {
        printf("LinkedListStack is empty\n");
    }
    printf("BACK of queue...\n\n");
}
