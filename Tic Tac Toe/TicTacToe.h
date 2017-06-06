#ifndef TICTACTOE_H_
#define TICTACTOE_H_

class TicTacToe{

public:

	TicTacToe();

	void initializeBoard();
	void printBoard();
	void setPlayerNumber();
	bool checkIfValidMove( int, int );
	void computerMove();
	void playerMove();
	bool isGameOver();
	int checkForWin();
	bool checkForDraw();
	void startGame();

	~TicTacToe();

private:

	int** m_Board;
	int humanPlayerNum;
	int computerPlayerNum;

};



#endif
