/* CS261- Assignment 1 - Q.0 */
/* Name: Pedro Torres Picon
 * Date: 01/22/2017
 * Solution description: This is a program that prints the address,
 * value and pointer address of a given variable.
 */

#include <stdio.h>
#include <stdlib.h>

/*********************************************************************

** Function:fooA
** Description: This function takes a pointer to an int value and
prints out the value, the address of the value, and the address of the
pointer itself
** Parameters: a pointer to an int value
** Pre-Conditions: iptr should be pointing to an int value
** Post-Conditions: none

*********************************************************************/

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
     printf("Value of what iptr points to: %d\n", *iptr);

     /*Print the address pointed to by iptr*/
     printf("Address pointed to by iptr: %p\n", iptr);

     /*Print the address of iptr itself*/
     printf("Address of iptr itself: %p\n", &iptr);
}

/*********************************************************************

** Function: main()
** Description: This is the main function where the x variable is declared,
the address of the x variable is printed, fooA is calle dand the value of
x is then printed
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none

*********************************************************************/

int main(){

    /*declare an integer x*/
    int x = 42;

    /*print the address of x*/
    printf("Address of x: %p\n", &x);

    /*Call fooA() with the address of x*/
    fooA(&x);

    /*print the value of x*/
    printf("Value of x: %d\n", x);

    return 0;
}
