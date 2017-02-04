/* CS261- Assignment 1 - Q.4 */
/* Name: Pedro Torres Picon
 * Date: 01/22/2017
 * Solution description: This program uses what we've learned from Q1 and Q3 to
 * create and print a list of students with id's and scores, and sort them based
 * on one of their attributes (scores)
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

/*********************************************************************

** Function: sort()
** Description: sorts an array of student structs in ascending order,
based on their score property
** Parameters: a pointer to an array of student structs and an int
representing the size of the array
** Pre-Conditions: array is filled with n strudent structs
** Post-Conditions: none

*********************************************************************/

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
		 int swapped = 1;
		 while (swapped) {
			 swapped = 0;
			 for (int i = 1; i < n; i++) {
				 if (students[i-1].score > students[i].score) {
					 // swap
					 struct student temp = students[i-1];
					 students[i-1] = students[i];
					 students[i] = temp;
					 swapped = 1;
				 }
			 }
			 n--;
		 }
};

/*********************************************************************

** Function: main()
** Description: declares an int n and a dynamic array of n student structs,
fills the array, prints it, sorts the array using sort() and prints it again
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none

*********************************************************************/

int main(){
    /*Declare an integer n and assign it a value.*/
		int n = 12;

    /*Allocate memory for n students using malloc.*/
		struct student *students = malloc(n * sizeof(struct student));

    /*Generate random and unique IDs and random scores for the n students, using rand().*/

		/*Create an array of all the ids from 0 to n-1*/
		int *ids = malloc(n * sizeof(int));
		for (int i = 0; i < n; i++) {
			ids[i] = i;
		}
		int idsLength = n;

		for (int i = 0; i < n; i++) {
			/*Assign a random id to student from the ids array, and delete it from the array*/
			int id = rand() % idsLength;
			students[i].id = ids[id];
			ids[id] = ids[idsLength - 1];
			idsLength--;

			/*Generate random score fro 0 to 100*/
			students[i].score = rand() % 101;
		}

    /*Print the contents of the array of n students.*/
		printf("\nUNSORTED:\n");
		for (int i = 0; i < n; i++) {
			printf("Id%u Score: %u\n", students[i].id, students[i].score);
		}

    /*Pass this array along with n to the sort() function*/
		sort(students, n);

    /*Print the contents of the array of n students.*/
		printf("\nSORTED:\n");
		for (int i = 0; i < n; i++) {
			printf("Id%u Score: %u\n", students[i].id, students[i].score);
		}

		/*Deallocate memory for the dynamic arrays*/
		if (ids != 0) {
			free(ids);
		}

		if (students != 0) {
			free(students);
		}

    return 0;
};
