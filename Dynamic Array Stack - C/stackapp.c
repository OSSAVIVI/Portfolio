/* CS261 - Assignment 2: Amortized Analysis and Dynamic Array Application
 * Name: Ryan Farran
 * Date: 07/17/2019 */

/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: 	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */
    int booleanValue = 0;
    
    DynArr* dyn;
    dyn = newDynArr(100); //plenty of room, mate
    
    if (s != 0 && s != NULL)
    {
        char nextValue = '!';
        do
        {
            nextValue = nextChar(s);
            
            if (nextValue == '(' || nextValue == '{' || nextValue == '[')
            {
                pushDynArr(dyn, nextValue);
            }
            else if (nextValue == ')' && topDynArr(dyn) == '(')
            {
                popDynArr(dyn);
            }
            else if (nextValue == '}' && topDynArr(dyn) == '{')
            {
                popDynArr(dyn);
            }
            else if (nextValue == ']' && topDynArr(dyn) == '[')
            {
                popDynArr(dyn);
            }
            else if (nextValue == ')' || nextValue == '}' || nextValue == ']')
            {
                pushDynArr(dyn, '!');//This is just used to ensure the array is not empty to signal an imbalance
            }
            
        } while (nextValue != '\0');
            
        if (isEmptyDynArr(dyn) == 1)
        {
            booleanValue = 1;
        }
    }
    else
    {
        printf("Sorry, but the string is empty!\n");
        printf("Returning 0...\n");
    }
    freeDynArr(dyn);
    
	return booleanValue;
}

int main(int argc, char* argv[]){
	
	char* s=argv[1]; //if you change "argv[1] to a string it works
	int res;
	
	printf("Assignment 2.a\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
    
	
	return 0;	
}

