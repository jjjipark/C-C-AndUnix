#include <stdlib.h>
#include <stdio.h>      

/*Print a diamond containing the digits 0-9 nci#*/
void printNumberDiamond(const int size, int **square){


	int i, j, k;
	
	// top half triangle
	for(i=0; i< (size/2)+1; i++){
		for(k=i; k<size/2; k++){
			//space
			printf(" ");
		}
        		for (j=0;j <2*i+1; j++){
			printf("%d", square[i][j]);
		}

		printf("\n");
	}

	for (i=0; i<(size/2); i++){
		for(k=i; k< (2*i+1); k++){
			printf(" ");
		}

		for (j=0; j< size-2- 2*i; j++){
			printf("%d", square[i][j]);
		}
		printf("\n");
	}

}


