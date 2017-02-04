/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string
	pre: s is not null
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
	pre: s is not null
	post:
*/
int isBalanced(char* s)
{

	// create a new array
	DynArr *dyn;
	dyn = newDynArr(2);
	// create a char to hold the current character
	char cur;

	while ((cur = nextChar(s))) { // run the loop while we get a valid character

		if (cur == '(' || cur == '[' || cur == '{') {

			pushDynArr(dyn, cur); // if cur is an opening bracket, push it to dyn

		} else if (cur == ')' || cur == ']' || cur == '}') {

			/*if cur is a closing bracket, and there are no opening brackets in dyn,
			then we can assume the string is not balanced*/
			if (isEmptyDynArr(dyn)) return 0;

			// otherwise, get the item stored in dyn, and make sures it corresponds
			char top = topDynArr(dyn);

			switch (cur) {

				case ')':
					if (top != '(') return 0;
					break;

				case ']':
					if (top != '[') return 0;
					break;

				case '}':
					if (top != '{') return 0;
					break;

				default:
					break;

			}
			popDynArr(dyn);
		}
	}

	// at the end there should be no opening brackets left in dyn
	return isEmptyDynArr(dyn);
}

int main(int argc, char* argv[]){

	char* s=argv[1];
	int res;

	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else
		printf("The string %s is not balanced\n",s);

	return 0;
}
