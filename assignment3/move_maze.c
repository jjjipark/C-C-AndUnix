#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int *StartPoint(int mazeSize, char **maze){

	//find start x,y coordinate
	int *xy;
	xy = (int *) malloc(sizeof (int) *2);
	//int x, y;
	//
	for (int i=0; i<mazeSize; i++){
		for (int j=0; j<mazeSize; j++){
			if (maze[i][j] =='x'){
				xy[0] = i;
				xy[1] = j;

				//x = i;
				//y = j;
			}
		}
	}
	//return x,y; can't return two vals.. 
	return xy; 
}

void move(int mazeSize, char **maze, int *x, int*y, int point){

	//UP
	if (point==0){
		*x -=1;
		printf("UP\n");
	}
	else if(point==1){
		*y -=1;
		printf("LEFT\n");
	}

	else if (point==2){
		*x += 1;
		printf("DOWN\n");
	}
	else if (point ==3){
		*y += 1;
		printf("RIGHT\n");
	}
}


int Right(int point){
	point +=3;
	point = point % 4;
	return point;
}

int Left(int point){
	point +=1;
	point = point % 4;
	return point;
}

bool  checkWall(int mazeSize, char **maze, int x, int y, int point){
	if(point == 3){
		if (y< mazeSize && maze[x][y+1] != '@'){
			return 1;    // check wall on right, return 1 if no wall otherwise return 0
		}
		return 0;
		
	}

	if (point == 0){
		if (x >= 0 && maze[x-1][y]!= '@'){
			return 1;
		}
		
		return 0;
		
	}
	if (point == 2){
		if (x < mazeSize && maze[x+1][y] !='@'){
			return 1;
		}
		return 0;
	}

	if (point == 1){
		if (y >= 0 && maze[x][y-1] != '@'){
			return 1;
		}
		return 0;
	}

	return -1;
}

void mazeSolve(int mazeSize, char **maze, int x, int y){

	int done = 0;
	int point = 0;

	while (done !=1){
		point = Right(point);
		
		while(checkWall(mazeSize, maze, x, y, point)!=1){
			point = Left(point); //change direction
		}
		move(mazeSize, maze, &x, &y, point); //print movement
		if (x==0|| y==0){   //exit
			done=1;
		}
		if (x == mazeSize-1 || y == mazeSize-1){
			//exit
			done = 1;
		}
	}
}

