/* CS261- Assignment 1 - Q.3 */
/* Name: Pedro Torres Picon
 * Date: 01/22/2017
 * Solution description: This program creates an array of random numbers, prints
 * it, sorts the array and prints it again
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

/*********************************************************************

** Function: sort()
** Description: sorts an array of numbers in ascending order
** Parameters: a pointer to a number array and an int representing the
size of the array
** Pre-Conditions: array is filled with n ints
** Post-Conditions: none

*********************************************************************/

void sort(int* number, int n){
     /*Sort the given array number, of length n*/
     int swapped = 1;
     while (swapped) {
       swapped = 0;
       for (int i = 1; i < n; i++) {
         if (number[i-1]>number[i]) {
           // swap
           int temp = number[i-1];
           number[i-1] = number[i];
           number[i] = temp;
           swapped = 1;
         }
       }
       n--;
     }
};

/*********************************************************************

** Function: main()
** Description: declares n and a dynamic array of n ints, fills the
array prints it, sorts the array using sort() and prints it again
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none

*********************************************************************/

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;

    /*Allocate memory for an array of n integers using malloc.*/
    int *arr = malloc(n * sizeof(int));

    /*Fill this array with random numbers, using rand().*/
    for (int i = 0; i < n; i++) {
      arr[i] = rand() % 100 + 1;
    }

    /*Print the contents of the array.*/
    printf("\nUNSORTED:\n[");
    for (int i = 0; i < n - 1; i++) {
      printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[n-1]);

    /*Pass this array along with n to the sort() function of part a.*/
    sort(arr, n);

    /*Print the contents of the array.*/
    printf("\nSORTED:\n[");
    for (int i = 0; i < n - 1; i++) {
      printf("%d, ", arr[i]);
    }
    printf("%d]\n\n", arr[n-1]);

    /*Deallocate memory for the dynamic array*/
    if (arr != 0) {
      free(arr);
      arr = 0;
    }

    return 0;
};
