#include <iostream>
using namespace std;

void deleteFile (char ***, char **, int *, int, const int);
int lenOf (char *);
void displayFileList (char **, int);
int mainMenu();
void createFile (char ***, char **, int *, int &);
void createOrEditLine (char ***, int , int );
void copyFile (char ***, char **, int *, int &, const int);
void editFile (char ***, char **, int *, int &, const int);
void shiftLineLeft (char ***, int , int , int , int );
void shiftLineRight (char ***, int , int , int, int);
void replaceWord( char ***, char *, char *, int , int , int );
int determineReplacee( char ***, int , int, char *, int );
void editWords(char ***, char *, char *, int , int *);
void displayFile(char ***, char **, int *, int, const int);
int getFilePosition (char **, const int);


int main() {

	int fileNum = 0;
	const int maxNoOfFiles = 20;
	int noOfLinesPerFile[maxNoOfFiles];
	char ***fileList = new char**[maxNoOfFiles]; 
	char **fileNameList = new char*[maxNoOfFiles];

	bool terminateProgram = false;
	while(!terminateProgram){
		switch (mainMenu()){
		
			case 1:
				createFile(fileList, fileNameList, noOfLinesPerFile, fileNum);
				break;
		
			case 2:
				displayFile(fileList, fileNameList, noOfLinesPerFile, fileNum, maxNoOfFiles);
				break;

			case 3:
				editFile(fileList, fileNameList, noOfLinesPerFile, fileNum, maxNoOfFiles);
				break;
		
			case 4:
				copyFile (fileList, fileNameList, noOfLinesPerFile, fileNum, maxNoOfFiles);
				break;
		
			case 5:
				deleteFile (fileList, fileNameList, noOfLinesPerFile, fileNum, maxNoOfFiles);
				break;
		
			case 6:
				displayFileList(fileNameList, fileNum);
				break;
		
			case 7:
				terminateProgram = true;
				break;
		
			default:
				cout << "\nIncorrect Option. Try again!";
		}	
	}
return 0;
}

//MISCELLANEOUS FUNCTIONS

int getFilePosition (char **fileNameList, const int maxNoOfFiles){
	cout << "\nEnter the files name: ";
	char *userFileInput = new char[32];		
	cin.getline(userFileInput, 33);
	
	for (int i = 0; i < maxNoOfFiles; ++i){
		
		if (lenOf(userFileInput) == lenOf(fileNameList[i])){
			
			for (int j = 0; j < lenOf(userFileInput); ++j){
				if (userFileInput[j] != fileNameList[i][j]){
						return 0;
				}
			}
			return i;
		}
	}
}	

int lenOf (char *string){
	int counter = 0;
	
	while (string[counter] != '\0'){
		counter++;
	}
	return counter;
}

void deleteFile (char ***fileList, char **fileNameList, int *noOfLinesPerFile, int noOfFiles, const int maxNoOfFiles){
	int fileDeleteChoice;
	
	cout << "\nPress 1 to Enter File Name || Press 2 to Enter File Number: ";
	cin >> fileDeleteChoice;
	cin.ignore();
	
	int fileDeleteNum;
	switch (fileDeleteChoice){
		
		case 1:
			fileDeleteNum = getFilePosition(fileNameList, maxNoOfFiles);
			break;
		
		case 2:
			displayFileList( fileNameList, noOfFiles);
			cout << "\nEnter the number of the file you want to edit: ";
			cin >> fileDeleteNum;
	
		default:
			cout << "\nIncorrect Option! ";
			
	}

	for (int i = 0; i < noOfLinesPerFile[fileDeleteNum]; ++i){
		
		delete[] fileList[fileDeleteNum][i];
	}
	
	delete[] fileList[fileDeleteNum];
	
	//char *deletedMsg =
	fileNameList[fileDeleteNum] = "FILE DELETED"; 
	noOfLinesPerFile[fileDeleteNum] = 0;
	
	cout << "\nFile deleted successfully!";
}	


//DISPLAY FUNCTIONS

void displayFileList (char **fileNameList, int noOfFiles){

	cout << "\n-----FILE LIST----- \n";
	cout << "------------------- \n";
	for (int i = 0; i < noOfFiles; ++i){
		cout << i << "  " << fileNameList[i] << endl;
	}
	
}	

void displayFile(char ***fileList, char **fileNameList, int *noOfLinesPerFile, int noOfFiles, const int maxNoOfFiles){
	int displayFileChoice;
	cout << "\nPress 1 to Enter File Name || Press 2 to Enter File Number: ";
	cin >> displayFileChoice;
	cin.ignore();
	
	int displayNum;
	switch (displayFileChoice){
	
		case 1:
			displayNum = getFilePosition(fileNameList, maxNoOfFiles);
			break;
	
		case 2:
			displayFileList(fileNameList, noOfFiles);
			cout << "\nWhich file do you wish to view? Enter the files number: ";
			cin >> displayNum;
			cin.ignore();
			
	
	}
	cout << "\n" << fileNameList[displayNum] << "\n" << "----------------\n\n";
	for (int i = 0; i < noOfLinesPerFile[displayNum]; ++i){
		cout << i + 1 << ". " << fileList[displayNum][i] << endl;
	}
}

int mainMenu(){
	
	int mainMenuChoice;
	cout << endl << endl;
	cout << "Press 1. To create a new file. \n";
	cout <<	"Press 2. To view a file. \n";
	cout <<	"Press 3. To edit a file. \n";
	cout <<	"Press 4. To copy an exisiting file to a new file. \n";
	cout <<	"Press 5. To delete an exisiting file. \n";
	cout <<	"Press 6. To view list of all files with the names. \n";
	cout <<	"Press 7. To Exit. \n";
	cout << "\nOption: ";
	cin >> mainMenuChoice;
	cin.ignore();
	
	return mainMenuChoice;
}	


//CREATION FUNCTIONS

void createFile (char ***fileList, char **fileNameList, int *noOfLinesPerFile, int &fileNum){
	
	//Recording name of new file
	char *fileName = new char[16];
	cout << "\nEnter name of file: ";
	cin.getline(fileName, 17);
	
	fileNameList[fileNum] = fileName;
	
	//Recording number of lines in new file
	int noOfLines;
	cout << "Enter number of lines: ";
	cin >> noOfLines;
	
	noOfLinesPerFile[fileNum] = noOfLines;
	
	fileList[fileNum] = new char*[noOfLines];
	cin.ignore();

	cout << endl;
	if (fileNum == 0){
		
		cout << "\nEach line can hold a maximum of 60 letters. Any extra letters are discarded. \n\n";
		
	}
	for (int lineNum = 0; lineNum < noOfLines; lineNum++){
		
		cout << lineNum + 1 << ". ";
		
		char *lineCharacters = new char[100];
		cin.getline(lineCharacters, 61);
		fileList[fileNum][lineNum] = lineCharacters;
		
	}
	fileNum++;
}

void createOrEditLine (char ***fileList, int fileNum, int lineNum){
	cout << "\nEnter new line: ";
	
	char *editedLine = new char[60];
	cin.getline(editedLine, 61);
	fileList[fileNum][lineNum] = editedLine;
}

void copyFile (char ***fileList, char **fileNameList, int *noOfLinesPerFile, int &fileNum, const int maxNoOfFiles){
	
	int fileCopyChoice;
	cout << "\nPress 1 to Enter File Name || Press 2 to Enter File Number: ";
	cin >> fileCopyChoice;
	cin.ignore();
	
	int fileCopyNum;
	switch (fileCopyChoice){
		
		case 1:
			fileCopyNum = getFilePosition(fileNameList, maxNoOfFiles);
			break;
		
		case 2:
			displayFileList(fileNameList, fileNum);
			cout << "\nEnter the number of the file you want to copy: ";
			cin >> fileCopyNum;
			cin.ignore();
	}
	
	cout << "\n\nEnter the name of the new file: ";
	char *newFileName = new char[16];
	cin.getline(newFileName, 17);
	fileNameList[fileNum] = newFileName;
	
	fileList[fileNum] = new char *[noOfLinesPerFile[fileCopyNum]];
	noOfLinesPerFile[fileNum] = noOfLinesPerFile[fileCopyNum];

	for (int i = 0; i < noOfLinesPerFile[fileCopyNum]; ++i){
		fileList[fileNum][i] = new char[100];
		for (int j = 0; j < 100; ++j){
			fileList[fileNum][i][j] = fileList[fileCopyNum][i][j];
		}
	}
	cout << "\n\nFile has been successfully copied!" << endl;
	fileNum++;
}	


//EDITING FUNCTIONS

void editFile (char ***fileList, char **fileNameList, int *noOfLinesPerFile, int &fileNum, const int maxNoOfFiles){
	
	int editFileChoice;
	cout << "\nPress 1 to Enter File Name || Press 2 to Enter File Number: ";
	cin >> editFileChoice;
	cin.ignore();
	
	int fileEditNum;
	switch (editFileChoice){
		
		case 1:
			fileEditNum = getFilePosition(fileNameList, maxNoOfFiles);
			break;
		
		case 2:
			displayFileList( fileNameList, fileNum);
			cout << "\nEnter the number of the file you want to edit: ";
			cin >> fileEditNum;
	
	}
	int userChoiceEditMenu;
	
	cout << "\nPress 1 to edit lines. \n" << "Press 2 to replace words. \n";
	cout << "\nOption: ";
	cin >> userChoiceEditMenu;

	switch (userChoiceEditMenu){
		
		case 1: {
		
			int lineNum;
			cout << "\n" << fileNameList[fileEditNum] << " has " << noOfLinesPerFile[fileEditNum] << " lines. Which line do you want to edit? ";
			cin >> lineNum;
			cin.ignore();
			createOrEditLine(fileList, fileEditNum, lineNum - 1);
			break;
		}		
		case 2: {
		
			char *replacee = new char[32];
			cout << "\nEnter the word to be replaced: ";
			cin.ignore();
			cin.getline(replacee, 33);
			
			char *replacer = new char[32];
			cout << "\nReplace " << replacee << " with: ";
			cin.getline(replacer, 33);
			
			editWords(fileList, replacer, replacee, fileEditNum, noOfLinesPerFile);
			break;
		}	
	}
			 
}

void shiftLineLeft (char ***fileList, int fileNum, int lineNum, int spacesToShift, int startPosition){
	
	for (int i = 0; i < spacesToShift; ++i){
		for (int j = startPosition; fileList[fileNum][lineNum][j] != '\0'; ++j){
		
			if ( (fileList[fileNum][lineNum][j + 1] == '\0') ){
				fileList[fileNum][lineNum][j] = fileList[fileNum][lineNum][j + 1];
				break;
			}
			fileList[fileNum][lineNum][j] = fileList[fileNum][lineNum][j + 1];
		}
	}
}

void shiftLineRight (char ***fileList, int fileNum, int lineNum, int spacesToShift, int startPosition){
	
	if (fileList[fileNum][lineNum][startPosition] == '\0'){
		for (int i = startPosition; i < startPosition + spacesToShift; ++i){
			fileList[fileNum][lineNum][i] = ' ';
		}
		fileList[fileNum][lineNum][startPosition + spacesToShift] = '\0';
		return;
	}
	
	int terminatingCharacterPosition = startPosition + 1;
	
	while (fileList[fileNum][lineNum][terminatingCharacterPosition] != '\0'){
		terminatingCharacterPosition++;
	}
	for (int j = 0; j < spacesToShift; ++j){
		for (int i = terminatingCharacterPosition + j; i >= startPosition + j; --i){
			fileList[fileNum][lineNum][i + 1] = fileList[fileNum][lineNum][i];
		}
	}
}

void replaceWord( char ***fileList, char *replacee, char *replacer, int fileNum, int lineNum, int startPosition){

	if (lenOf(replacee) == lenOf(replacer)){
		for (int i = startPosition, j = 0; i < (startPosition + lenOf(replacee)); ++i, ++j){
			fileList[fileNum][lineNum][i] = replacer[j];
		}
	}
	
	else if (lenOf(replacee) > lenOf(replacer)){
		for (int i = startPosition, j = 0; i < (startPosition + lenOf(replacer)) ; ++i, ++j){
			fileList[fileNum][lineNum][i] = replacer[j];
		}
		shiftLineLeft (fileList, fileNum, lineNum, lenOf(replacee) - lenOf(replacer), startPosition + lenOf(replacer));
	}

	else if (lenOf(replacee) < lenOf(replacer)){
		for (int i = startPosition, j = 0; i < startPosition + lenOf(replacee); ++i, ++j){
			fileList[fileNum][lineNum][i] = replacer[j];
		}
		
	 	shiftLineRight (fileList, fileNum, lineNum, lenOf(replacer) - lenOf(replacee), startPosition + lenOf(replacee));
		
		cout << " ";
		for (int i = startPosition + lenOf(replacee), j = lenOf(replacee); i < startPosition + lenOf(replacer); ++j, ++ i);
			fileList[fileNum][lineNum][i] = replacer[j];
		 }

	 }
}

int determineReplacee( char ***fileList, int fileNum, int lineNum, char *replacee, int startPosition){
int len = lenOf(replacee);
	
	for (int i = startPosition, j = 0; i < startPosition + len; ++i, ++j){
		if (fileList[fileNum][lineNum][i] != replacee[j]){
			return 0;
		}
	}
	return 1;
}

void editWords(char ***fileList, char *replacer, char *replacee, int fileNum, int *noOfLines){
	
	for (int i = 0; i < noOfLines[fileNum]; ++i){
		for (int j = 0; fileList[fileNum][i][j] != '\0'; ++j){
			if (replacee[0] == fileList[fileNum][i][j]){
				
				if (determineReplacee(fileList, fileNum, i, replacee, j) == 1){
					
					replaceWord(fileList, replacee, replacer, fileNum, i, j);
					
				}
			}
		}
	}
}