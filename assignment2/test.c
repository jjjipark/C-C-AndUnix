#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "square.h"
#include "triangle.h"
#include "diamond.h"

void clearInputBuffer(){
	while (getchar() != '\n');
}

int main(){

	int size=0;
	int **square;
	int **triangle;
	int height = 0;
	int num=0;


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
	printf("\n");

	printf("Problem 2:\n");
	while (height < 1 || height  >6){
		printf("Please enter the height of the triangle [1-5]: ");
		scanf("%d", &height);
		clearInputBuffer();
	}
	
	allocateNumberTriangle(height, &triangle);
	initializeNumberTriangle((const int) height, triangle);
	printNumberTriangle((const int) height, triangle);
	deallocateNumberTriangle(height, &triangle);
	printf("\n");


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


