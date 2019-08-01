/* CS261- Worksheet 17 - Q. 0*/
/* Name: Ryan Farran
 * Date: 07/10/2019
 * Solution description:
 *      This assignment...
 */

#include "LinkedListStack.h" //scopes to implementation file
#include <assert.h> //needed for assert()
#include <stdlib.h> //is not needed
//#include <time.h> //is not needed
//#include <math.h> //is not needed

/*
struct link
{ //Here is the link, which represents each node in the LinkedListStack
    TYPE value; //It's value is of type TYPE
    struct link* next; //It has one pointer variable, next, pointing in sequence to an "older" position in the LInkedListStack
};

struct linkedListStack
{
    struct link* firstLink; //Sentinel pointer pointing to the firstlink (top of stack) in the LinkedListStack
}\
*/
 
void linkedListStackInit(struct linkedListStack* s)
{
    s->firstLink = 0; //No nodes are created, list is empty, and s->firstLink points to NULL (0)
}

void linkedListStackFree(struct linkedListStack* s)
{ //This function continuously "pops" elements off of the stack until linkedListStackIsEmpty returns true
    while (!linkedListStackIsEmpty(s))
    { //While stack is not empty, pop an element off of the stack
        linkedListStackPop(s);
    }
    printf("\nlinkedListStack has been freed...\n\n");
}

void linkedListStackPush (struct linkedListStack *s, TYPE d)
{
    printf("Pushing %d...\t", d);
    struct link* newLink = (struct link*) malloc(sizeof(struct link)); //link pointer variable of size sizeof(struct link)
    assert(newLink != 0); //Ensures that newLink does not point to NULL (uses #include <assert.h>)
    /* Fix me */
    newLink->value = d;
    if (linkedListStackIsEmpty(s) == 0)
    { //If list is not empty (returns 0), then connect newLink's next pointer to firstLink->next to insert node at the top of the stack
        newLink->next = s->firstLink;
    }
    else
    { //Else if list is empty, then connect newLink's next pointer to 0 (NULL) to show that it is the end of the stack (linkedList)
        newLink->next = 0;
    }
    //In both cases, s->firstLink should now point to the newLink
    s->firstLink = newLink;
    printf("PUSHED!\n");
}

TYPE linkedListStackTop(struct linkedListStack *s)
{
    /* Fix me */
    TYPE returnValue = -1;
    if (linkedListStackIsEmpty(s) == 0)
    {
        returnValue = s->firstLink->value;
    }
    return returnValue;
}

void linkedListStackPop(struct linkedListStack *s)
{
    /* Fix me */
    printf("Popping %d...\t", linkedListStackTop(s));
    s->firstLink->value = -87000; //set to random, outlandish number so if ever accessed again we can tell it's a bad access
    free(s->firstLink);
    s->firstLink = s->firstLink->next;
    printf("POP!\n");
}

int linkedListStackIsEmpty(struct linkedListStack *s)
{
    /* Fix me */
    int boolean = 1;
    if (!(s->firstLink == 0))
    {
        boolean = 0;
    }
    return boolean;
}

void printLinkedListStack(struct linkedListStack *s)
{
    printf("\nTOP of stack...\n");
    if (linkedListStackIsEmpty(s) == 0)
    {
        struct link linkIter;
        struct link* linkPtr = &linkIter;
        linkPtr = s->firstLink;
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
    printf("BOTTOM of stack...\n\n");
}
