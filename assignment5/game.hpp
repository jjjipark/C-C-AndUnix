#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>


class Game{

	typedef std::vector<int> Row;
	typedef std::vector<Row> Matrix;

public:
	Game(const int x_size, int y_size, int numOfstep);

	void RandomMatrix(Matrix &matrix1);
	void simulation(Matrix &matrixS);
	void printMatrix(Matrix matrix);

	int x_size(){return x;}
	int y_size() {return y;}

	int x; //number of cols
	int y; //number of rows
	int Steps; //num of iterations of game
	int iter;
	int size;


};

#endif
