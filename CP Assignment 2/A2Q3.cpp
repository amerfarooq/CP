#include <iostream>
using namespace std;

void printLine(int n){
	
	if (n == 0){
		cout << "*" << endl;
	}
	
	else{
		cout << " ";
		printLine(n-1);
	}
	
}

void PrintPatternQ3(int start, int end){
	
	if (start == end){
		printLine(start);
		return;
	}
	
	else{
		
		printLine(start);
		PrintPatternQ3(start + 1, end);
		printLine(start);
		
	}
	
}



int main() {

	PrintPatternQ3(1,15);

return 0;
}