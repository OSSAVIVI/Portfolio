/* CS261- Worksheet 20 Dynamic Array Deque and Queue
 * Name: Ryan Farran
 * Date: 07/14/2019 */

#ifndef FLOATINGDEQUEARRAY_H
#define FLOATINGDEQUEARRAY_H

#ifndef __TYPE
#define __TYPE
#define TYPE int
#endif

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct deque
{
    TYPE* data;
    int capacity;
    int size;
    int beg;
};

void _dequeSetCapacity (struct deque *d, int newCap);
void dequeFree (struct deque *d);
void dequeInit (struct deque *d, int initCapacity);
int dequeSize (struct deque *d);
void dequeAddFront (struct deque *d, TYPE newValue);
void dequeAddBack (struct deque *d, TYPE newValue);
TYPE dequeFront (struct deque *d);
TYPE dequeBack (struct deque *d);
void dequeRemoveFront (struct deque *d);
void dequeRemoveBack (struct deque *d);
void printDeque(struct deque *d);

#endif /* FLOATINGDEQUEARRAY_H */
