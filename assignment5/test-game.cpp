#include "game.hpp"

using namespace std;

typedef vector<int> Row;
typedef vector<Row> Matrix;


int main(){

	int x_position = 0;
	int y_position = 0;
	int iter = 0;
	int step = 0;

	cout << "Please enter the size of the grid (int int): ";
	cin >> x_position;
	cin >> y_position;

	cout << "Please enter the number of steps (int): ";
	cin >> step;

	Game game(x_position, y_position, step);

	Matrix *InitializeM = new Matrix(y_position , Row(x_position));
	//Matrix *tempM
	
	game.RandomMatrix(*InitializeM);
	game.printMatrix(*InitializeM);
	cout << endl;

	iter = 1;
	while(iter <= step){
		cout << "Step " << iter << ":" << endl;
		//*tempM = *InitializeM;		
		game.simulation(*InitializeM);
		game.printMatrix(*InitializeM);
		//game.simulation(*tempM);
		//game.printMatrix(*tempM);
		iter++;
	}

	return 0;


}	
