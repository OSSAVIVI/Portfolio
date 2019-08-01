/* CS261- Worksheet 17 - Q. 0*/
/* Name: Ryan Farran
 * Date: 07/10/2019
 * Solution description:
 *      This assignment...
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedListStack.h"

// this main function contains some
int main(int argc, char* argv[]){
    
    struct linkedListStack lls;
    struct linkedListStack* llsPtr = &lls;
    linkedListStackInit(llsPtr);
    
    printf("Testing linkedListStack...\n\n");
    linkedListStackPush(llsPtr, 3);
    linkedListStackPush(llsPtr, 4);
    linkedListStackPush(llsPtr, 10);
    linkedListStackPush(llsPtr, 5);
    linkedListStackPush(llsPtr, 6);
    
    printLinkedListStack(llsPtr);
    
    linkedListStackPop(llsPtr);
    
    printLinkedListStack(llsPtr);
    
    printf("The top of the stack's value is %d\n\n", linkedListStackTop(llsPtr));
    
    linkedListStackFree(llsPtr);
    
    return 0;
}
