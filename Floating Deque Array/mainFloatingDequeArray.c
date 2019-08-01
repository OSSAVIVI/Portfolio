/* CS261- Worksheet 20 Dynamic Array Deque and Queue
 * Name: Ryan Farran
 * Date: 07/14/2019 */

#include <stdio.h>
#include "floatingDequeArray.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, welcome to Worksheet 20: Dynamic Array Deque and Queue\n");
           
    struct deque exampleDeque;
    struct deque* dequePtr = &exampleDeque;
    
    dequeInit(dequePtr, 10);
    
    dequeAddBack(dequePtr, 2);
    dequeAddBack(dequePtr, 4);
    dequeAddBack(dequePtr, 6);
    dequeAddBack(dequePtr, 8);
    dequeAddBack(dequePtr, 10);
        printDeque(dequePtr);
    
    dequeRemoveBack(dequePtr);
        printDeque(dequePtr);
    
    dequeAddFront(dequePtr, 0);
    dequeAddFront(dequePtr, -2);
    dequeAddFront(dequePtr, -4);
        printDeque(dequePtr);
    
    dequeRemoveBack(dequePtr);
    dequeRemoveBack(dequePtr);
        printDeque(dequePtr);
    
    dequeAddBack(dequePtr, 6);
    dequeAddBack(dequePtr, 8);
    dequeAddBack(dequePtr, 10);
        printDeque(dequePtr);
    
    printf("The FRONT of the deque is %d\n", dequeFront(dequePtr));
    printf("The BACK of the deque is %d\n", dequeBack(dequePtr));
    
    return 0;
}
