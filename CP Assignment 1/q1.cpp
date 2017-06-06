#include <iostream>
using namespace std;

void initialiseMorseArray();
void translateToMorse();
void translateStringToMorse(char *);
void translateLetterToMorse(char);
char translateMorseToStr(char *, int);
void translateFromMorse();

char *morseArray[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", 
					 "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
					 "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
					 "-.--", "--..", "-----", ".----", "..----", "...--",
					 "....-", ".....", "-....", "--...", "---..", "----.",
					 ".-.-.-", "--.--", "..--..", ".----.", "-.-.--", "-..-.",
					 "-.--.", "-.--.-", ".-..." };
char characterArray[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
						 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
						 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0',
						 '1', '2', '3', '4', '5', '6', '7', '8', '9',
						 '.', ',', '?', '\'', '!', '/', '(', ')', '&',
						 '\0'};
int sizeOfMorseCodesArray[] = { 2, 4, 4, 3, 1, 4, 3, 4, 2,
								4, 3, 4, 2, 2, 3, 4, 4, 3,
								3, 1, 3, 4, 3, 4, 4, 4, 5,
								5, 5, 5, 5, 5, 5, 5, 5, 5,
								6, 6, 6, 6, 6, 5, 5, 6, 5 };				 

int main(){

	char choice;
	cout << "\nWrite T to translate TO morse. \nF to translate FROM morse. \nN to terminate program: ";
	cin >> choice;
	switch (choice){
		
		case 'T':
			translateToMorse();
			break;
		case 'F':
			translateFromMorse();
			break;
		case 'N':
			break;
		default:
			cout << "\nInvalid expression!" << endl;
	}
}


void translateStringToMorse(char *str){
	
	int i = 0;
	
	cout << "\nThe given word in morse is: ";
	while (str[i] != '\0'){
		
		translateLetterToMorse(str[i]);
		++i;
	}

}

void translateLetterToMorse(char letter){
	
	for (int i = 0; i < sizeof(characterArray); ++i){
		
		if (characterArray[i] == letter){
		
			cout << morseArray[i] << " ";
			return;
		
		}
	}
}

void translateToMorse(){
	
	int sizeOfWord;
	cout << "\nEnter the size of word to be translated to morse: ";
	cin >> sizeOfWord;
	char *word = new char[sizeOfWord + 1];
	
	cout << "\nEnter your word (ONLY UPPERCASE ALPHABETS PERMITTED): ";
	cin >> word;
	
	translateStringToMorse(word);
	return;
	
}

void translateFromMorse(){
	
	int totalMorseCodes;
	int sizeOfMorseCode;
	cout << "\nEnter total number of morse codes: ";
	cin >> totalMorseCodes;
	char finalWord[totalMorseCodes + 1];
	finalWord[totalMorseCodes] = '\0';
	
	for (int i = 0; i < totalMorseCodes; ++i){
		
			cout << "\nEnter size of morse code " << i << ": ";
			cin >> sizeOfMorseCode;
			char *morseCode = new char[sizeOfMorseCode + 1];
			
			cout << "\nEnter morse code: ";
			cin >> morseCode;
			
			finalWord[i] = translateMorseToStr(morseCode, sizeOfMorseCode);
			delete[] morseCode;
	}
	
	cout << "\nYour word is " << finalWord;
}

char translateMorseToStr(char *code, int sizeOfCode){
	
	for (int i = 0; i < 45; ++i){
		
		int counter = 0;
		for (int j = 0; j < sizeOfCode && sizeOfCode == sizeOfMorseCodesArray[i]; ++j){
			
			if (code[j] == morseArray[i][j]){
				counter++;
				continue;
			}
			
			else{
				break;
			}
		}
		
		if (counter == sizeOfCode){
			return characterArray[i];
		}
	}	
}

