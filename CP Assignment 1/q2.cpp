#include <iostream>
#include <fstream>
#include <math.h>  
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


void fread(string, string[], const int &);
int wordLength(char *);
void initialiseBlanks(char *, int);
int checkGuess(char, char *, char *, int, int*, int);
int compareGuessedOriginalWords(char *, char *, int);
void printGuessedWord(char *word, int size);
void printHangman(int);
int checkRepeatLetter(char, char*, int);
void initialiseGuessedWord(char *, char *, int, int*, int);
void generateRepeatNumbers(int *, int, int);
int verifyRepeatNumberArray(int *, int);
void initialiseRepeatPositions(int, int, int *);
int skippingRepeatPosition(int, int *, int);


const char *hangman[18]={
" ____________..______.",
"| .__________))______|",
"|H| / /      ||",
"| |/ /       ||",
"|A| / 	     ||.---.",
"| |/ 	     |/  _  \\",
"|N| 	     ||  `/,|",
"| |          (\\\\`_.",
"|G| 	    .-`---.",
"| | 	   /Y . . Y\\",
"| | 	  // |   | \\\\",
"| |	 //  | . |  \\\\",
"|M|    ( )   |   |    ( )",
"| |          || ||",
"|A|          || ||",
"| |          || ||",
"|N|         / | ||  ",
"|_|        |_/ /_| ",    };
const int nwords = 4000;
string words[4000];


int main(){
	
	srand(time(NULL));
	fread("1-4000.txt", words, nwords);
	
	int noOfTries = 6;
	char *randomWord = &words[rand() % 3999 + 1][0];
	int lenOfWord = wordLength(randomWord);
	char *guessedWord = new char[lenOfWord + 1];
	char userGuesses[7];
	initialiseBlanks(userGuesses, 6);
	userGuesses[6] = '\0';
	int noOfPreDisplayedLetters = int (ceil(0.333 * lenOfWord));
	int repeatPositions[noOfPreDisplayedLetters];
	initialiseGuessedWord(guessedWord, randomWord, lenOfWord, repeatPositions, noOfPreDisplayedLetters);
		
	int noOfUserGuess = 0;
	int hangmanCounter = 0;
	
	while (noOfTries > 0){
		if (compareGuessedOriginalWords(randomWord, guessedWord, lenOfWord) == 1){
			cout << "\nYou've correctly guessed the word! You win!" << endl;
			break;
		}
	    char userGuess;
	 	printGuessedWord(guessedWord, lenOfWord);

	 	while(true){		
	 	    cin >> userGuess;
			if (checkRepeatLetter(userGuess, userGuesses, noOfUserGuess) == 0){
				cout << "\nYou've already entered this letter before! Try again! ";
			}
			else{
				noOfUserGuess++;
				break;
			}
		}
		if (checkGuess(userGuess, randomWord, guessedWord, lenOfWord, repeatPositions, noOfPreDisplayedLetters) == 1){		
			cout << "That's correct!" << endl;
		}
		else if (checkGuess(userGuess, randomWord, guessedWord, lenOfWord, repeatPositions, noOfPreDisplayedLetters) == 0){
		
			noOfTries --;
			
			cout << "\nI'm afarid that's incorrect!" << endl;
			printHangman(hangmanCounter);
			hangmanCounter += 3;
			
			if(noOfTries == 0 ){
				cout << "\nGame Over! Your word was " << randomWord;
			}	
			else{
				cout << "You only have " << noOfTries << " tries remaining." << endl;
			}
		}
	}
	
	delete[] guessedWord;
	
return 0;
}

void initialiseBlanks(char *word, int size){
	for (int i = 0; i < size; ++i){
		word[i] = '_';
	}
	word[size] = '\0';
}

void generateRepeatNumbers(int *arr, int noOfPositions, int size){ 
	for (int i = 0; i < noOfPositions; ++i){
			arr[i] = rand() % (size-1) + 1;
	}
}

int verifyRepeatNumberArray(int *arr, int size){ 
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size && j != i; ++j){
			if (arr[i] == arr[j]){
				return 0;
			}
		}
	}
	return 1;
}

void initialiseRepeatPositions(int noOfPositions, int size, int *repeatPositionArray){
	generateRepeatNumbers(repeatPositionArray, noOfPositions, size);
	while(verifyRepeatNumberArray(repeatPositionArray, noOfPositions) != 1){
		generateRepeatNumbers(repeatPositionArray, noOfPositions, size);
	}
}

void initialiseGuessedWord(char *guessedWord, char *word, int size, int *repeatPositionArray, int noOfPreDisplayedLetters){
	initialiseBlanks(guessedWord, size);
	initialiseRepeatPositions(noOfPreDisplayedLetters, size, repeatPositionArray);
	for (int i = 0; i < noOfPreDisplayedLetters; ++i){
		guessedWord[repeatPositionArray[i]] = word[repeatPositionArray[i]];
	}
}

void fread( string fname, string words[], const int &nwords ){
    ifstream ifile( fname.c_str(),ios::in );
    if ( !ifile ){
		cout<<" Couldn’t read the file " << fname;
		exit(-1);
	}
	int count = 0;
	while( ifile && count < nwords ){
		ifile >> words[count++];
	}	
	ifile.close();
}

int wordLength(char *word){
	int i = 0;
	while (word[i] != '\0'){  ++i;  }
	return i;
}

int checkGuess(char letter, char *randomWord, char *guessedWord, int size, int *repeatPositionArray, int repeatPositionArrSize){

	bool correctLetter = false;
	int i = 0;
	while (i < size){
		if (skippingRepeatPosition(i, repeatPositionArray, repeatPositionArrSize) == 0){
			++i;
			continue;
		}
		if (randomWord[i] == letter){
			correctLetter = true;
			guessedWord[i] = letter;
		}
		++i;
	}
	if (correctLetter){
		return 1;
	}
	else{
		return 0;
	}
}

int compareGuessedOriginalWords(char *randomWord, char *guessedWord, int size){
	for (int i = 0; i < size; ++i){
		if (randomWord[i] != guessedWord[i]){  return 0;  }
	}
	return 1;
}

void printGuessedWord(char *word, int size){
	for (int i = 0; i < size; ++i){  cout << word[i] << " ";  }
	cout << "\n\nMake a guess! ";
}

void printHangman(int startingPoint){
	for (int i = 0; i < startingPoint; ++i){  cout << hangman[i] << endl;  }
	for (int i = startingPoint; i < startingPoint + 3; ++i){  cout << hangman[i] << endl;  }
	cout << "\n\n\n";
}

int skippingRepeatPosition(int index, int *arr, int size){
	for (int i = 0; i < size; ++i){
		if (arr[i] == index){  return 0;  }
	}
	return 1;
}

int checkRepeatLetter(char letter, char *alreadyGuessedLetters, int pos){
	for (int i = 0; i < 6; ++i){
		if (alreadyGuessedLetters[i] == letter){  return 0;  }
	}
	alreadyGuessedLetters[pos] = letter;
	return 1;
}
