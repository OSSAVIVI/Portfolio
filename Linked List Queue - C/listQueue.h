/* CS261- Worksheet 18 */
/* Name: Ryan Farran
 * Date: 07/12/2019
 */

#ifndef LISTQUEUE_H
#define LISTQUEUE_H

#ifndef __TYPE
#define __TYPE
#define TYPE int
#endif

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct link
{
    TYPE value;
    struct link* next;
};

struct listQueue
{
    struct link* firstLink;
    struct link* lastLink;
};

void listQueueInit(struct listQueue *q);

void listQueueAddBack(struct listQueue *q, TYPE e);

TYPE listQueueFront(struct listQueue *q);

void listQueueRemoveFront(struct listQueue *q);

int listQueueIsEmpty(struct listQueue *q);

void printListQueue(struct listQueue *q);

#endif /* LISTQUEUE_H */
