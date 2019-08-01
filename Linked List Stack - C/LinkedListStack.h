/* CS261- Worksheet 17 - Q. 0*/
/* Name: Ryan Farran
 * Date: 07/10/2019
 * Solution description:
 *      This assignment...
 */

#ifndef LINKEDLISTSTACK_H
#define LINKEDLISTSTACK_H

#ifndef __TYPE
#define __TYPE
#define TYPE int
#endif

#ifndef LT
#define LT(A, B) ((A) < (B))
#endif

#ifndef EQ
#define EQ(A, B) ((A) == (B))
#endif

#include <stdio.h>

//typedef struct linkedListStack linkedListStack; //Is this the way of hiding the data structure from the interace you've been hinting at?

struct link
{ //Here is the link, which represents each node in the LinkedListStack
    TYPE value; //It's value is of type TYPE
    struct link* next; //It has one pointer variable, next, pointing in sequence to an "older" position in the LInkedListStack
};

struct linkedListStack
{
    struct link* firstLink; //Sentinel pointer pointing to the firstlink (top of stack) in the LinkedListStack
};

void linkedListStackInit(struct linkedListStack * s);

void linkedListStackFree(struct linkedListStack *s);

void linkedListStackPush(struct linkedListStack *s, TYPE d);

TYPE linkedListStackTop(struct linkedListStack *s);

void linkedListStackPop(struct linkedListStack *s);

int linkedListStackIsEmpty(struct linkedListStack *s);

void printLinkedListStack(struct linkedListStack *s);

#endif /* LINKEDLISTSTACK_H */
