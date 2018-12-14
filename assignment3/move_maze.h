#ifndef __MOVE_MAZE_H_
#define __MOVE_MAZE_H_
#include <stdbool.h>

int *StartPoint(int mazeSize, char **maze);
int moveRight(int point);
int moveLeft(int point);
void move(int mazeSize, char **maze,int *x, int *y);
bool checkWall(int mazeSize, char **maze,int x, int y, int point);

void mazeSolve(int mazeSize, char **maze, int x, int y);

#endif
