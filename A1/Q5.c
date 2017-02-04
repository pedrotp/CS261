/* CS261- Assignment 1 - Q.5 */
/* Name: Pedro Torres Picon
 * Date: 01/22/2017
 * Solution description: This program takes a string from std input and prints
 * it out in sticky caps (https://en.wikipedia.org/wiki/Sticky_caps)
 */

#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

/*********************************************************************

** Function: sticky()
** Description: converts a word to sticky caps
** Parameters: an array of chars
** Pre-Conditions: array is filled with a null terminated string
** Post-Conditions: none

*********************************************************************/

void sticky(char* word){
     /*Convert to sticky caps*/
     int i = 0;
     char current = word[i];
     while (current != 0) {
       if (i%2) {
         if (word[i] > 64 && word[i] < 91) {
           word[i] = toLowerCase(word[i]);
         }
       } else {
         if (word[i] > 96 && word[i] < 123) {
           word[i] = toUpperCase(word[i]);
         }
       }

       i++;
       current = word[i];
     }
};

/*********************************************************************

** Function: main()
** Description: reads a word from stdin, calls sticky() with the word,
and prints the word in sticky caps
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none

*********************************************************************/

int main(){
    /*Read word from the keyboard using scanf*/
    char word[128];
    printf("\nHi there, please enter a word: ");
    scanf("%s", word);

    /*Call sticky*/
    sticky(word);

    /*Print the new word*/
    printf("\nStickyfied: %s\n\n", word);

    return 0;
};
