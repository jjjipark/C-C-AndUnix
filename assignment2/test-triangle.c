#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "triangle.h"


void clearInputBuffer(){
	while (getchar() != '\n');

}

int main(){


	int **triangle;
	int height = 0;

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
	return 0;
}
