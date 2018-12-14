#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

#include "maze.hpp"
//#include "utils.hpp"
using namespace std;

Maze::Maze(int size):size(size),point(0)
{
	
	
	//point = 0;
	//msize = size;
//	mSize = size;
	maze = new char*[size];
	for (int i=0; i<size; i++){
		maze[i] = new char[size];
		//memset(maze[i], 0 , size*sizeof(char));
	}

	//allocateMaze();
}  //allocate array


void Maze::turnLeft(){
	point += 1;
	point = point %4;
}

void Maze::turnRight(){
	point +=3;
	point = point%4;
}

bool Maze::checkWall(){
	if (point == 3){
		if (y < size && maze[x][y+1] != '@'){
			return 1;
		}
		return 0;
	}

	if (point == 0){
		if (x >= 0 && maze[x-1][y] != '@'){
			return 1;
		}
		return 0;
	}

	if (point ==2){
		if (x < size && maze[x+1][y] != '@'){
			return 1;
		}
		return 0;
	}

	if (point ==1){
		if (y >= 0 && maze[x][y-1] != '@'){
			return 1;
		}
		return 0;
	}

	return -1;
}

void Maze::move(){
	if (point==0){
		x -=1;
	}
	else if (point == 1){
		y -=1;
	}
	else if (point ==2){
		x +=1;
	}
	else if (point ==3){
		y +=1;
	}
}

bool Maze::atExit(){

	if (x ==0 || x == (size-1)|| y ==0|| y == size-1){
		return true;
	}
	return false;
}

void Maze::step(){

	turnRight();
	while(checkWall() != 1){
		turnLeft();
	}
	move();
}

void Maze::getCurrentPosition(int &row, int &col){
	row = this -> x;
	col = this -> y;
}

void Maze::readFromFile(std::ifstream &f){
	//col = this -> y;
	for(int i=0; i< size; i++){
		for(int j=0; j<size; j++){
			f >> maze[i][j];
		}
	}
	
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(maze[i][j] == 'x'){
				x = i;
				y = j;
			}
		}
	}
}

int Maze::getPoint(){
	return point;
}

