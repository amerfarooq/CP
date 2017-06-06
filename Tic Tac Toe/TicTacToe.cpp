#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "TicTacToe.h"

using namespace std;

TicTacToe :: TicTacToe(){
	srand(time(NULL));
	initializeBoard();
	setPlayerNumber();
	startGame();
	int newGame = -1;
	cout << endl << "Press 1 to play new game. Press 0 to exit: ";
	cin >> newGame;
	if ( newGame == 1){
		TicTacToe T2;
	}
}

void TicTacToe :: initializeBoard(){
	m_Board = new int* [3];
	for ( int i = 0; i < 3; ++i ){
		m_Board[i] = new int[3];
		for ( int j = 0; j < 3; ++j ){
			m_Board[i][j] = 0;
		}
	}
}

void TicTacToe :: printBoard(){
	cout << endl;
	string dashedLine = "\n- - - -\n";
	for ( int i = 0; i < 3; ++i ){
		for ( int j = 0; j < 3; ++j){
			cout << m_Board[i][j] << " ";
			if ( j != 2 ){  cout << "|";  }
		}
		if ( i != 2 ){  cout << dashedLine;  }
	}
}

bool TicTacToe :: checkIfValidMove( int t_x, int t_y ){
	if ( t_x < 0 or t_x > 2 or t_y < 0 or t_y > 2 ){  return false;  }
	else if ( m_Board[t_x][t_y] > 0 ){  return false;  }
	else{  return true;  }
}

int TicTacToe :: checkForWin(){

	for ( int i = 0; i < 3; ++i ){
		if ( ( m_Board[i][0] == m_Board[i][1] ) and ( m_Board[i][1] == m_Board[i][2] ) and ( m_Board[i][0] != 0 ) and ( m_Board[i][1] != 0 ) and ( m_Board[i][2] != 0 ) ){
			return m_Board[i][0];
		}
	}
	for ( int i = 0; i < 3; ++i ){
		if ( ( m_Board[0][i] == m_Board[1][i] ) and ( m_Board[1][i] == m_Board[2][i] ) and ( m_Board[0][i] != 0 ) and ( m_Board[1][i] != 0 ) and ( m_Board[2][i] != 0 ) ){
			return m_Board[0][i];
		}
	}
	if ( ( m_Board[0][0] == m_Board[1][1] ) and ( m_Board[1][1] == m_Board[2][2] ) and ( m_Board[0][0] != 0 ) and ( m_Board[1][1] != 0 ) and ( m_Board[2][2] != 0 ) ){
		return m_Board[0][0];
	}
	if ( ( m_Board[0][2] == m_Board[1][1] ) and ( m_Board[1][1] == m_Board[2][0] ) and ( m_Board[0][2] != 0 ) and ( m_Board[1][1] != 0 ) and ( m_Board[2][0] != 0 ) ){
		return m_Board[0][2];
	}

	return 0;
}

bool TicTacToe :: checkForDraw(){
	for ( int i = 0; i < 3; ++i ){
		for ( int j = 0; j < 3; ++j ){
			if ( m_Board[i][j] == 0 ){
				return false;
			}
		}
	}
	return true;
}

bool TicTacToe :: isGameOver(){
	if ( checkForWin() != 0 ){
		cout << "\n\nPlayer " << checkForWin() << " wins the game! ";
		return true;
	}
	else if ( checkForDraw() ){
		cout << "\nStalemate!";
		return true;
	}
	return false;
}

void TicTacToe :: setPlayerNumber(){
	cout << "Do you want to be Player 1 or Player 2? Enter 1 or 2 to indicate your choice!" << endl;
	while ( true ){
		cout << "Enter Player Number: ";
		cin >> humanPlayerNum;
		if ( humanPlayerNum == 1 ){
			computerPlayerNum = 2;
			return;
		}
		else if ( humanPlayerNum == 2 ){
			computerPlayerNum = 1;
			return;
		}
		else{
			cout << "\nInvalid Player Number!";
		}
	}
}

void TicTacToe :: computerMove(){
	while ( true ){
		int x = rand() % 3;
		int y = rand() % 3;
		if ( checkIfValidMove( x, y) ){
			m_Board[x][y] = computerPlayerNum;
			return;
		}
	}
}

void TicTacToe :: playerMove(){
	int x = 0, y = 0;
	cout << endl;
	cout << "\nYour move!";
	cout << endl;
	while ( true ){
		cout << "\nX: ";
		cin >> x;
		cout << "\nY: ";
		cin >> y;
		if ( checkIfValidMove( x, y ) ){
			m_Board[x][y] = humanPlayerNum;
			break;
		}
		else if ( !checkIfValidMove( x, y) ){  cout << "\nInvalid Move!\n";  }
	}
}

void TicTacToe :: startGame(){
	while( true ){
		if ( humanPlayerNum == 1){
			printBoard();
			playerMove();
			if ( isGameOver() ){  return;  }
			computerMove();
			if ( isGameOver() ){  return;  }
		}
		else{
			computerMove();
			if ( isGameOver() ){  return;  }
			printBoard();
			playerMove();
			if ( isGameOver() ){  return;  }
		}
	}
}

TicTacToe :: ~TicTacToe(){
	for ( int i = 0; i < 3; ++i ){
		delete[] m_Board[i];
	}
	delete[] m_Board;
}
