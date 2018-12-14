#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 3
#define COL 4

bool arrayEqual(int a[ROW][COL], int b[ROW][COL], int m, int n){
	int i, j;
	for (i=0; i<ROW; i++){
		for (j=0; j<COL; j++){
			if (a[i][j]!= b[i][j]){
				printf("false\n");
				return false;
			}
		}
	}
	printf("true\n");
	return true;
}

int main(int argc, const char * argv[]){

	//const int ROW = 3;
	//const int COL = 4;


	int a[ROW][COL] = {
		{0, 1,1,3} ,
		{4, 2,3,4} ,						
		{8,8,8,8} ,
	};

	int b[ROW][COL] = {
		{0, 1,1,1} ,
		{4, 2,2,2} ,
	        {8, 6,6,6},
	};

	arrayEqual(a, b, ROW, COL);
	return 0;
}
