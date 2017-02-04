#include <stdio.h>

int main () {

	float input;
	float itoC; // stores the result if converting inches to centimeters
	float ctoI; // stores the result if converting centimeters to inches

	printf("\nPlease enter a number: ");
	scanf("%f", &input);

	itoC = input * 2.54;
	ctoI = input * 0.393701;

	printf("\n%.2f inches is equal to %.2f centimeters", input, itoC);
	printf("\n%.2f centimeters is equal to %.2f inches\n\n", input, ctoI);

	return 0;

}
