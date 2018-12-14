#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "move_maze.h"

enum Direction { DOWN, RIGHT, UP, LEFT }; //might be useful

//void mazeSolve( char[][MAX_MAZE_SIZE], const int, const int, int, int, int );

int main( int argc, const char* argv[] )
{
    if( argc != 2 ) { 
        //checks for the input file name
        printf( "error; no input file name\n" );
        return 1;
    }

    FILE *filePointer;
    filePointer = fopen( argv[1], "r" );
    char **maze;

    // You can choose to use static or dynamic memory for your maze data structure
    // An example static array declaration can be:
    //char maze[MAX_MAZE_SIZE][MAX_MAZE_SIZE] = { 0 };

    int numberOfTestCases = 0;
    fscanf( filePointer, "%d\n", &numberOfTestCases );

    for( int testCaseNumber = 0; testCaseNumber < numberOfTestCases; testCaseNumber++ ) {
        int mazeSize = 0;

        int *xy;
        int x, y;

        fscanf( filePointer, "%d\n", &mazeSize );
        //allocate array
        maze = (char **) malloc( mazeSize* sizeof(char *));
        for (int i=0; i<mazeSize; i++){
            (maze)[i] = (char *) malloc( mazeSize* sizeof(char));
        }
        printf( "ENTER\n" );
	
	//initialize
        for (int i=0; i<mazeSize; i++){
            fscanf(filePointer, "%s\n", maze[i]);
        }

	//find enterance
        xy =  StartPoint(mazeSize, maze);
        x = xy[0]; // x-coordinate for enterance
        y = xy[1]; // y- coordinate for enterane
        mazeSolve(mazeSize, maze, x, y);
    
       //... put your code here; Split your code to small/readable functions.
       // Remember to document your code.


        printf( "EXIT\n***\n" );        
    }

    fclose( filePointer );
    return 0;
}
