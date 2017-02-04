/* CS261- Assignment 1 - Q.2 */
/* Name: Pedro Torres Picon
 * Date: 01/22/2017
 * Solution description: This is a program that illustrates the difference of
 * passing an argument by reference vs by value.
 */

#include <stdio.h>
#include <stdlib.h>

/*********************************************************************

** Function: foo()
** Description: manipulates three values passed as arguments
** Parameters: three integers, two passed by reference and one by value
** Pre-Conditions: three values declared previously
** Post-Conditions: returns a value that should be stored

*********************************************************************/

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a *= 2;

    /*Set b to half its original value*/
    *b /= 2;

    /*Assign a+b to c*/
    c = *a + *b;

    /*Return c*/
    return c;
}

/*********************************************************************

** Function: main()
** Description: declares three values and calls foo, passing those values
appropriately as parameters
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none

*********************************************************************/

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5,
        y = 6,
        z = 7;

    /*Print the values of x, y and z*/
    printf("\nBefore foo: x = %d, y = %d, z = %d\n", x, y, z);

    /*Call foo() appropriately, passing x,y,z as parameters*/
    int r = foo(&x, &y, z);

    /*Print the value returned by foo*/
    printf("\nfoo returned: %d\n", r);

    /*Print the values of x, y and z again*/
    printf("\nAfter foo: x = %d, y = %d, z = %d\n\n", x, y, z);

    return 0;
}

/* Q: Is the return value different than the value of z?  Why?
   A: Yes, the return value of foo is different than the final
   value of z, because z was passed to foo by value, so it was
   not modified. In contrast, x and y were passed by reference,
   so the original values were modified by foo. */
