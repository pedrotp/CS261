/* CS261- Assignment 1 - Q.1 */
/* Name: Pedro Torres Picon
 * Date: 01/22/2017
 * Solution description: This program generates a dynamic array of structs, fills them,
 * prints them and then deallocates the memory for them
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

/*********************************************************************

** Function: allocate()
** Description: Allocates memory for 10 students and returns the pointer
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns a pointer to the allocated memory

*********************************************************************/

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student *ptr = malloc(10 * sizeof(struct student));
     /*return the pointer*/
     return ptr;
};

/*********************************************************************

** Function: generate()
** Description: Generates random and unique ID and scores for ten students,
ID being between 1 and 10, scores between 0 and 100
** Parameters: a pointer to a student struct
** Pre-Conditions: the pointer should be pointing to previously allocated
memory, should not point to NULL
** Post-Conditions: the structs now have random values

*********************************************************************/

void generate(struct student* students){

     int ids[10] = {0,1,2,3,4,5,6,7,8,9};
     int idsLength = 10;

     for (int i = 0; i < 10; i++) {
       /*Assign a random id to student from the ids array, and delete it from the array*/
       int id = rand() % idsLength;
       students[i].id = ids[id];
       ids[id] = ids[idsLength - 1];
       idsLength--;

       /*Generate random score fro 0 to 100*/
       students[i].score = rand() % 101;
     }

};

/*********************************************************************

** Function: output()
** Description: Outputs information about the ten students to stdout
** Parameters: a pointer to a student struct
** Pre-Conditions: pointer should point to previously allocated memory,
all the structs should have values in their member variables
** Post-Conditions: none

*********************************************************************/

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
      printf("\nALL SCORES:\n");
      for (int i = 0; i < 10; i++) {
        printf("Id%u Score: %u\n", students[i].id, students[i].score);
      }
};

/*********************************************************************

** Function: summary()
** Description: Computes and print the minimum, maximum and average
scores of the ten students
** Parameters: a pointer to a student struct
** Pre-Conditions: pointer should point to previously allocated memory,
all the structs should have values in their member variables
** Post-Conditions: none

*********************************************************************/

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     printf("\nSCORE SUMMARY:\n");

     /*Compute max & min, and add all scores together for avg*/
     int max = 0;
     int min = 100;
     int sum = 0;

     for (int i = 0; i < 10; i++) {
       if (students[i].score > max) {
         max = students[i].score;
       }
       if (students[i].score < min) {
         min = students[i].score;
       }
       sum = sum + students[i].score;
     }

     /*Compute average*/
     float avg = sum / 10;

     /*Print summary values*/
     printf("Max score: %u\n", max);
     printf("Min score: %u\n", min);
     printf("Avg score: %.1f\n\n", avg);

};

/*********************************************************************

** Function: deallocate()
** Description: Deallocates memory from stud
** Parameters: a pointer to a student struct
** Pre-Conditions: none
** Post-Conditions: none

*********************************************************************/

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     if (stud != 0) {
       free(stud);
     }
}

/*********************************************************************

** Function: main()
** Description: declares the original stud pointer and calls all the
functions
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none

*********************************************************************/

int main(){
    struct student* stud = NULL;

    /*call allocate*/
    stud = allocate();

    /*call generate*/
    generate(stud);

    /*call output*/
    output(stud);

    /*call summary*/
    summary(stud);

    /*call deallocate*/
    deallocate(stud);

    return 0;
};
