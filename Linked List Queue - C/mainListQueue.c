/* CS261- Worksheet 18 */
/* Name: Ryan Farran
 * Date: 07/12/2019
 */

#include <stdio.h>
#include "listQueue.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, let's demonstrate a listQueue!!!\n\n");
    
    struct listQueue listQueueInstance;
    struct listQueue* lQPtr = &listQueueInstance;
    
    listQueueInit(lQPtr);
    
    listQueueAddBack(lQPtr, 1);
    listQueueAddBack(lQPtr, 2);
    listQueueAddBack(lQPtr, 3);
    listQueueAddBack(lQPtr, 4);
    listQueueAddBack(lQPtr, 5);
    
    printListQueue(lQPtr);
    
    listQueueFront(lQPtr);
    
    listQueueRemoveFront(lQPtr);
    
    printListQueue(lQPtr);
    
    listQueueFront(lQPtr);
    
    listQueueAddBack(lQPtr, 6);
    listQueueRemoveFront(lQPtr);
    listQueueRemoveFront(lQPtr);
    printListQueue(lQPtr);
    
    
    return 0;
}
