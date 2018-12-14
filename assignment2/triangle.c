#include <stdio.h>
#include <stdlib.h>
/* Allocate a triangle of height "height" (a 2-D array of int) */
void allocateNumberTriangle(const int height, int ***triangle){

	int i;

	(*triangle) = (int **) malloc((height)* sizeof(int*));
	for (i=0; i< height; i++){
		(*triangle)[i] = (int *) malloc((height*2) * sizeof(int));
	}
}

/* Initialize the 2-D triangle array */
void initializeNumberTriangle(const int height, int **triangle){

	int i, j;
/*	for (i=0; i<height; i++){
		for (j=0; j<2*height -1; j++){
			triangle[i][j] = j;
		}
*/
	for (i=0; i<height; i++){
		for (j=0; j< height*2-1; j++){
			triangle[i][j] = j;
		}
	}

}

/* Print a formatted triangle */
void printNumberTriangle(const int size, int **triangle){

	int i,j, k;
	for (i=0; i<size; i++){
		//print space
		for (j=0; j<size-i; j++){
			printf(" ");
		}
		for (j=0; j< (2*i +1); j++){
			printf("%d", triangle[i][j]);
		}
		for (k=0; k<size-i; k++){
			printf(" ");
		}

		printf("\n");
	}
	

/*	for (i=0; i<(size/2)+1; i++){
		for(k=i; k<size/2; k++){
			printf(" ");
		}
		for(j=0; j<2*i+1; j++){
			printf("%d", triangle[i][j]);
		}
		printf("\n");
	}*/
}

/* Free the memory for the 2-D triangle array */
void deallocateNumberTriangle(const int size, int ***triangle){

	int i;
	for (i=0; i<size; i++){
		//if ((*triangle)[i] !=NULL){
		free((*triangle)[i]);
		}
		//free(NULL);
	free(*triangle);
	}
