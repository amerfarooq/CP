#include <iostream>
using namespace std;

void initialiseMagicArray(int **, int);
int nextRowPosition(int, int);
int nextColumnPosition(int, int );
int checkingPositionStatus(int, int, int **);
void printMagicArray(int **, int);
void deallocateMagicArray(int **, int);
int calculateMagicNumber(int **, int);

int main(){
	
cout << "\n\nEnter size of the Magic Square (only ODD numbers applicable): ";
int size;

//Taking size of magic number from user
while (true){

	cin >> size;
	cout << endl << endl;
	
	if (size % 2 == 0){
		
		cout << "\nI said only odd numbers! Try again: ";
		
	}
	
	else{
		
		break;
		
	}
}

int **magicArray = new int *[size];
int row = 0;
int col = (size-1)/2;
initialiseMagicArray(magicArray, size);
magicArray[row][col] = 1;


for (int i = 2; i < size*size + 1; ++i){
	
	if (checkingPositionStatus(nextRowPosition(row, size), nextColumnPosition(col, size), magicArray) == 0){
		
		row = row + 1;
		magicArray[row][col] = i;
		
	}
	
	else {
		
		row = nextRowPosition(row, size);
		col = nextColumnPosition(col, size);
		magicArray[row][col] = i;
		
	}
	
}

printMagicArray(magicArray, size);
deallocateMagicArray(magicArray, size);

return 0;              	
}

int calculateMagicNumber(int **magicArray, int size){  

	int sum = 0;
	for (int i = 0; i < size; ++i){

		sum += magicArray[0][i];
	
	}
	
	return sum;
}

void initialiseMagicArray(int **magicArray, int size){  //Initialises all indexes of magicArray to 0

	for (int i = 0; i < size; ++i){
	
		magicArray[i] = new int[size];
	
		for (int j = 0; j < size; ++j){
		
			magicArray[i][j] = 0;
		}
	}	
}

void deallocateMagicArray(int **magicArray, int size){
	
	for (int i = 0; i < size; ++i){

			delete[] magicArray[i];
	}
		
	delete[] magicArray;		
}

int nextRowPosition(int row, int size){
	
	if (row - 1 >= 0){
		return row - 1;
	}
	
	else{
		return size - 1;
	}
}

int nextColumnPosition(int col, int size){
	
	if (col + 1 <= size-1){
		return col + 1;
	}
	
	else{
		return 0;
	}
}

int checkingPositionStatus(int row, int col, int **magicArray){
	
	if (magicArray[row][col] > 0){
		return 0;
	}
	
	else{
		return 1;
	}
}

void printMagicArray(int **magicArray, int size){
	
	for (int i = 0; i < size; ++i){
		
		for (int j = 0; j < size; ++j){
			
			cout << magicArray[i][j] << "    ";
			
		}
		
		cout << endl << endl << endl;
	}

	cout << "The magic number is " << calculateMagicNumber(magicArray, size) << endl << endl;
	
}