#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

vector <string> longestWords;
vector <string> final;

void extractWords( string line, vector<string>& word ) {
	for ( unsigned int i = 0, k = 0; i < line.size(); ++i ) {

		if ( line.at(i) == ' ' or i == line.size() - 1 ) {

			if ( i == line.size() - 1 ) {
				word.push_back( line.substr( k, i - k ));
				return;
			}

			string cut = line.substr( k, i - k );
			word.push_back( cut );
			k = i + 1;
		}
	}
}

void extractLongestWords( vector<string>& word ) {

	int max = word[0].size();
	for ( int i = 0; i < word.size(); ++i ) {
		if ( word[i].size() > max )
			max = word[i].size();
	}

	for ( int i = 0; i < word.size(); ++i ) {
		if ( word[i].size() == max )
			longestWords.push_back( word[i] );
	}
}

void finalLongest() {
	int max = longestWords[0].size();

	for ( int i = 0; i < longestWords.size(); ++i ) {
			if ( longestWords[i].size() > max )
				max = longestWords[i].size();
		}

	for ( int i = 0; i < longestWords.size(); ++i ) {
		if ( longestWords[i].size() == max )
			final.push_back( longestWords[i] );
	}
}

int main() {

//	string fileName
//	cout << "Enter file name: ";
//	cin >> fileName;

	cout << "Using sample.txt for reading." << endl;
	ifstream file( "sample.txt", ios::in );

	if ( !file ) {
		cerr << "File could not be opened!" << endl;
		exit(1);
	}

	vector <string> allLines;
	string line;

	while( getline( file, line ) ) {
		allLines.push_back( line );
	}

	// Sometimes code doesnt even run!

	for ( int i = 0; i < allLines.size(); ++i ) {
		vector<string> w;
		extractWords( allLines[i], w );
		extractLongestWords( w );
		w.clear();
	}

	finalLongest();
	cout << "\nLongest words are: " << endl << endl;
	for ( int i = 0; i < final.size(); ++i ) {
		cout << final[i] << endl;
	}
}