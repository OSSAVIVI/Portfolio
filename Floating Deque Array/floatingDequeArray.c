/* CS261- Worksheet 20 Dynamic Array Deque and Queue
 * Name: Ryan Farran
 * Date: 07/14/2019 */

#include "floatingDequeArray.h"

void _dequeSetCapacity(struct deque *d, int newCap)
{
    int i;
    /* Create a new underlying array*/
    TYPE *newData = (TYPE*)malloc(sizeof(TYPE)*newCap);
    assert(newData != 0);
    /* copy elements to it */
    int j = d->beg;
    for(i = 0; i < d->size; i++)
    {
        newData[i] = d->data[j];
        j = j + 1;
        if(j >= d->capacity)
            j = 0;
    }
    /* Delete the oldunderlying array*/
    free(d->data);
    /* update capacity and size and data*/
    d->data = newData;
    d->capacity = newCap;
    d->beg = 0;
}

void dequeFree(struct deque *d)
{
    free(d->data); d->size = 0; d->capacity = 0;
}

void dequeInit(struct deque *d, int initCapacity)
{
    d->size = d->beg = 0;
    d->capacity = initCapacity;
    assert(initCapacity > 0);
    d->data = (TYPE*)malloc(initCapacity * sizeof(TYPE));
    assert(d->data != 0);
}

int dequeSize(struct deque *d)
{
    return d->size;
}

void dequeAddFront(struct deque *d, TYPE newValue)
{
    if (d->size >= d->capacity)
    {
        _dequeSetCapacity(d, 2*d->capacity);
    }
    if (d->beg <= 0)
    {
        d->data[d->capacity -1] = newValue;
        d->beg = d->capacity - 1;
    }
    else
    {
        d->data[d->beg - 1] = newValue;
        d->beg--;
    }
    d->size++;
}

void dequeAddBack(struct deque *d, TYPE newValue)
{
    if (d->size >= d->capacity)
    {
        _dequeSetCapacity(d, 2* d->capacity);
    }
    if ((d->beg + d->size) >= d->capacity)
    {
        d->data[0] = newValue;
    }
    else
    {
        d->data[d->size] = newValue;
    }
    d->size++;
}

TYPE dequeFront(struct deque *d)
{
    TYPE returnValue;
    if (d->size > 0)
    {
        returnValue = d->data[d->beg];
    }
    else
    {
        printf("This list is EMPTY, so we can't return the FRONT!\n");
        printf("Returning error code -68000\n");
        returnValue = -68000;
    }
    return returnValue;
}

TYPE dequeBack(struct deque *d)
{
    TYPE returnValue;
    if (d->size > 0)
    {
        int index = d->beg + d->size -1;
        if (index > d->capacity)
        {
            index -= d->capacity;
            returnValue = d->data[index];
        }
    }
    else
    {
        printf("This list is EMPTY, so we can't return the BACK!\n");
        printf("Returning error code -86000\n");
        returnValue = -86000;
    }
    
    return returnValue;
}

void dequeRemoveFront(struct deque *d)
{
    assert(d->size > 0);
    if (d->beg == d->capacity - 1)
    {
        d->beg = 0;
        d->beg = 0;
    }
    else
    {
        d->beg = 0;
        d->beg++;
    }
}

void dequeRemoveBack(struct deque *d)
{
    assert(d->size > 0);
    d->size--;
}

void printDeque(struct deque *d)
{
    if (d->size > 0)
    {
        for (int index = d->beg, count = 1; count <= d->size; count++)
        {
            printf("%d ", d->data[index]);
            index++;
            if (index == d->capacity)
            {
                index = 0;
            }
        }
        printf("\n");
    }
    else
    {
        printf("This list is EMPTY, so we can't PRINT it!\n");
    }
}
