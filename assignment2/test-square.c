#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "square.h"

void clearInputBuffer(){
	while (getchar() != '\n');
}

int main(){

	int size=0;
	int **square;

	printf("Problem 1:\n ");
	
	while (size< 2 || size > 11){
		printf("Please enter the size of the square [2-10]: ");
		scanf("%d", &size);
		clearInputBuffer();
	}
	
	allocateNumberSquare(size, &square);
	initializeNumberSquare((const int) size, square);
	printNumberSquare((const int) size, square);
	deallocateNumberSquare(size, &square);

	return 0;
}
