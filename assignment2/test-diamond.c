#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "square.h"
#include "diamond.h"

void clearInputBuffer(){
	while (getchar() != '\n');
}

int main(){

	int **square;
	int num=0;

	printf("Problem 3:\n");
	while ( num%2 == 0 || num <2 || num>10){
		printf("Please enter the size of the diamond [an odd number between 3 and 9 (inclusive)]: ");
		scanf("%d", &num);
		clearInputBuffer();
	}	
	allocateNumberSquare(num, &square);
	initializeNumberSquare((const int) num, square);
	printNumberDiamond((const int) num, square);
	deallocateNumberSquare(num, &square);
	//deallocateNumberTriangle((const int) height, &triangle);
	return 0;
}
