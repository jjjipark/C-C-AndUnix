#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "maze.hpp"
#include "utils.hpp"

int main( int argc, const char* argv[] )
{
	if( argc != 2 ){
		std::cerr << "error; no input file name\n" << std::endl;
		return 1;
	}

	std::ifstream mazeFile (argv[1]);
	int numberOfTestCases = 0;
	mazeFile >> numberOfTestCases;  // read num of maze

	for (int testCaseNumber = 0; testCaseNumber < numberOfTestCases; testCaseNumber++ ){
		int mazeSize = 0;
		mazeFile >> mazeSize; //read mazeSize from file

		Maze maze(mazeSize);  //new Maze object

		maze.readFromFile(mazeFile);
		
		std::cout << "ENTER" << std::endl;
		
		std::string direction[] = {"UP", "LEFT", "DOWN", "RIGHT"};
		//std::vector<string> myvector (4);

		int row, col;

		do{
			
			maze.getCurrentPosition(row, col);
			maze.step();
			std::cout << direction[maze.getPoint()] << std::endl;
		}while ( !maze.atExit());
		

		std::cout << "EXIT" << std::endl;
		std::cout << "***" << std::endl;
	}

	return 0;
}
