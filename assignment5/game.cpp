#include "game.hpp"

using namespace std;

//typedef vector<vector<int>> Matrix;
typedef vector<int> Row;
typedef vector<Row> Martix;

Game::Game(int x_size, int y_size, int numOfstep){


	x = x_size;
	y = y_size;
	Steps = numOfstep;
}

void Game::RandomMatrix(Matrix &matrix){
	int x= x_size();
	int y = y_size();

	srand(time(NULL));
	for(int i=1;i < y; i++){
		for(int j=0; j < x; j++){

			int maxR = max(x,y);
			int Randomindex = (rand() % maxR) ;  //1 == sheep, 2== wolf, 3== farmer, other==empty, 0 == kill
			matrix[i][j] = Randomindex;

		}
	}
}
void Game::printMatrix(Matrix matrix1){
	int x = x_size();
	int y = y_size();

	for (int i=0; i< y; i++){
		for( int j = 0; j < x; j++){
			if (matrix1[i][j] ==1){   //sheep when 1
				cout << 'S';
			} else if (matrix1[i][j] ==2){  //wolf when 2
				cout << 'W';
			}
			else if (matrix1[i][j] == 3){
				cout << 'F'; // farmer when 3
			}
			else{
				cout << '.';
			}
		}
		cout << endl;
	}
	cout << endl;
}


void Game::simulation(Martix &matrixS){
	int x = x_size();
	int y = y_size();

	for(int i = 0; i< y; i++){
		for(int j = 0; j < x; j++){
			//int Nbr_firstRow = ( i==0) ? i : i-1;  //if neighbor is in first or last of row and col
			int Nbr_firstRow = (i < 1) ? i : i-1;
			int Nbr_firstCol = ( j < 1) ? j : j-1;
			int Nbr_lastRow = ( i+1 > y-1 ) ? i : i+1;
			int Nbr_lastCol = ( j+1 > x-1 ) ? j : j+1;

	
			int count_sheepNeighbor = 0;
			int count_wolfNeighbor =0;
			int count_farmerNeighbor = 0;
			int count_emptyNeighbor = 0;

	
			int possible_moving_row[8];	// total possible neighbor is 8
			int possible_moving_col[8];  //possible empy cell for farmers

			if (matrixS[i][j] ==1){
				 //sheep
				for(int row = Nbr_firstRow; row <= Nbr_lastRow; row++){
					for( int col = Nbr_firstCol; col <= Nbr_lastCol; col++){
						if (matrixS[row][col] ==1){
							count_sheepNeighbor +=1;   //if neighbor is sheep
							//continue;
						}
						
	
						else if (matrixS[row][col] == 2){
							count_wolfNeighbor +=1;     //if neighbor is wolf
						}
						else if(row==i && col == j){
							continue;
							//current cell we are checking
						}
						else{ //cell is empty
							continue;
						}
					}
				}
				if (count_sheepNeighbor >=3 || count_wolfNeighbor >=1){
					matrixS[i][j] = 0; //sheep killed
				}
			}



	
			else if (matrixS[i][j] ==2){ // wolf
				 for(int row = Nbr_firstRow; row <= Nbr_lastRow; row++){
					 for( int col = Nbr_firstCol; col <= Nbr_lastCol; col++){
						if(row == i && col == j){
							continue;
						}
						 else if (matrixS[row][col] ==2){
							 count_wolfNeighbor +=1;
						 }
						 else if(matrixS[row][col] == 1){
							 count_sheepNeighbor +=1;
						 }
						 else if(matrixS[row][col] == 3){
							 count_farmerNeighbor +=1;
						 }
						 else{
							 continue;
						 }
					 }
				 }
				 if (count_farmerNeighbor >=1 || count_wolfNeighbor>=3){
					 matrixS[i][j] = 0; //wolf killed
				 }
				 else if(count_farmerNeighbor==0 && count_sheepNeighbor ==0 && count_wolfNeighbor==0){
					 matrixS[i][j]=0;  //wolf killed
				 }


			}

			else if (matrixS[i][j] ==3){
				//farmer
		
				for(int row = Nbr_firstRow; row <= Nbr_lastRow; row++){
					for( int col = Nbr_firstCol; col <= Nbr_lastCol; col++){
						if (row==i && col==j){
							continue;
						}

						else if (matrixS[row][col] == 0 || matrixS[row][col] >3 ){
							count_emptyNeighbor +=1;
							possible_moving_row[count_emptyNeighbor-1] = row;
							possible_moving_col[count_emptyNeighbor-1] = col;

						}
						else{
							continue;
						}

					}
				}
				if (count_emptyNeighbor >=1){
					matrixS[i][j] =0; //remove farmer in that place and move it to random neighbor cell
					int randomCell = rand() % (count_emptyNeighbor); //decide random cell
					int randomRow = possible_moving_row[randomCell];
					int randomCol  = possible_moving_col[randomCell];

					matrixS[randomRow][randomCol] = 3;
				}
				else{
					continue;
				}

			}

				//empty
			else{
				for(int row = Nbr_firstRow; row <= Nbr_lastRow; row++){
					for( int col = Nbr_firstCol; col <= Nbr_lastCol; col++){
						if( row==i && col ==j){
							continue;
						}
						else if (matrixS[row][col] ==2){
							count_wolfNeighbor +=1;
						}
						else if(matrixS[row][col] == 3){
							count_farmerNeighbor +=1;
						}
						else if(matrixS[row][col] == 1){
							count_sheepNeighbor +=1;
						}
						else{
							continue;
						}
					}
				}
				if (count_sheepNeighbor ==2){
					matrixS[i][j] ==1; // make sheep by reproduction
				}
				else if(count_wolfNeighbor == 2){
					matrixS[i][j] ==2;
				}
				else if(count_farmerNeighbor == 2){
					matrixS[i][j] ==3;
				}
				else{
					continue;
				}
			
			}
		}
	}
}
