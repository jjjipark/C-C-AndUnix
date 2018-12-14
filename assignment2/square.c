#include <stdio.h>
#include <stdlib.h>

/* Allocate a square of size "size" (a 2-D array of int) */
void allocateNumberSquare(const int size, int ***square){
	
	int i;
	(*square) = (int **) malloc(size * sizeof(int*));
	for (i=0; i<size; i++){
		(*square)[i] = (int *) malloc(size * sizeof(int));

	}
}

/* Initialize the 2-D square array */
void initializeNumberSquare(const int size, int **square){

	int i, j;

	for (i=0; i<size; i++){
		for (j=0; j<size; j++){
			square[j][i] = i;
		}
	}
}
/* Print a formatted square */
void printNumberSquare(const int size, int **square){
	
	int i,j;
	for (i=0; i<size; i++){
		for (j=0; j<size; j++){
			printf("%d", square[i][j]);
		}
		printf("\n");
		//printf("\n");
	}

}

/* Free the memory for the 2-D square array */
void deallocateNumberSquare(const int size, int ***square){

	int i;
	for (i=0; i<size; i++){
		free((*square)[i]);
	}
	free((*square));
}


