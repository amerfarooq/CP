#include <iostream>
using namespace std;


void printBoard(char **b, int size, int start = 0, int end = 0){
	
	if (start == size)
		return;
	
	else if (end == size){
		cout << endl;
		printBoard(b, size, ++start);
		return;
	}
	
	else{
		cout << b[start][end] << " ";
		printBoard(b, size, start, ++end);
	}
}

void initalizeBoard(char **b, int size, int start = 0, int end = 0){
	
	if (start == size)
		return;
	
	else if (end == size){
		initalizeBoard(b, size, ++start);
	}
	
	else{
		
		if (end == 0){
			b[start] = new char[size];
		}
		
		b[start][end] = 'o';
		initalizeBoard(b, size, start, ++end);
	}	
}
	
void eliminiateRow(char **b, int size, int row, int qC /*Queen Column*/, int col = 0){
	
	if (col == size)
		return;
	
	else{
		
		if (col != qC){
			b[row][col] = '_';
			eliminiateRow(b, size, row, qC, ++col);
		}
		
		else{
			eliminiateRow(b, size, row, qC, ++col);
		}
	}
}

void eliminiateColumnn(char **b, int size, int col, int qR /*Queen Row*/, int row = 0){
	
	if (row == size)
		return;
	
	else{
		
		if (row != qR){
			b[row][col] = '_';
			eliminiateColumnn(b, size, col, qR, ++row);
		}	
		
		else{
			eliminiateColumnn(b, size, col, qR, ++row);
		}
	}
}

void findRightSP(int &row, int &col){
	
	if (row > col){
		row = row - col;
		col = 0;
	}
	
	else if (col > row){
		col = col - row;
		row = 0;
	}
	
	else{
		row = 0;
		col = 0;
	}
	
}

void findLeftSP(int &row, int &col, int size){
	
	if (col == size - 1 or row == 0)
		return;
		
	else
		--row;
		++col;
		findLeftSP(row, col, size);
		
}

void eliminateRightDiagonal(char **b, int size, int row, int col, int qR, int qC){
	
	if (row > col){
		
		if (row == size)
			return;
		
		else if (row != qR and col != qC){
			b[row][col] = '_';
			eliminateRightDiagonal(b, size, ++row, ++col, qR, qC);
		}
		
		else{
			eliminateRightDiagonal(b, size, ++row, ++col, qR, qC);
		}
		
	}
	
	else if (col > row){
		
		if (col == size)
			return;
		
		else if (row != qR and col != qC){
			b[row][col] = '_';
			eliminateRightDiagonal(b, size, ++row, ++col, qR, qC);
		}
		
		else{
			eliminateRightDiagonal(b, size, ++row, ++col, qR, qC);
		}
		
	}
	
	else{

		if (row == size)
			return;
		
		else if (row != qR and col != qC){
			b[row][col] = '_';
			eliminateRightDiagonal(b, size, ++row, ++col, qR, qC);
		}
		
		else{
			eliminateRightDiagonal(b, size, ++row, ++col, qR, qC);
		}
		
	}
	
}

void eliminateLeftDiagonal(char **b, int size, int row, int col, int qR, int qC){
	
	if (row == size)
		return;
	
	else if (row != qR and col != qC){
		b[row][col] = '_';
		eliminateLeftDiagonal(b, size, ++row, --col, qR, qC);
	}
	
	else{
		eliminateLeftDiagonal(b, size, ++row, --col, qR, qC);
	}
	
}

void eliminatePositions(char **b, int size, int row, int col, int qR, int qC){
	
	eliminiateRow(b, size, row, qC);
	eliminiateColumnn(b, size, col, qR);
	
	int rRP, rCP; //rRP = Right(Diagonal) Row(Start) Position
	rRP = row;
	rCP = col;
	findRightSP(rRP, rCP);
	eliminateRightDiagonal(b, size, rRP, rCP, qR, qC);
	
	int lRP, lCP;
	lRP = row;
	lCP = col;
	findLeftSP(lRP, lCP, size);
	eliminateLeftDiagonal(b, size, lRP, lCP, qR, qC);
	
}

void nQueens(char **b, int n = 9, int r = 0, int c = 0, int initalRow = 0, int initalCol = 0){

	b[r][c] = 'Q';
	eliminatePositions(b, n, r, c, r, c);
	
	if(initalRow == n){
		printBoard(b, n);
		return;
	}
	
	else if(initalCol == n)
			nQueens(b, n, r, c, ++initalRow, 0);
	

	else if (b[initalRow][initalCol] == 'o'){
		
		b[initalRow][initalCol] = 'Q';
		eliminatePositions(b, n, initalRow, initalCol, initalRow, initalCol);
		nQueens(b, n, r, c, initalRow, ++initalCol);
	
	}
	
	else
		nQueens(b, n, r, c, initalRow, ++initalCol);

}

int main() {
    
    int size = 9;
	char **b = new char*[size];
	initalizeBoard(b, size);
	
	nQueens(b, size, 8,4);


return 0;   
}
