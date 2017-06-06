#include <iostream>
#include <string>
using namespace std;

void printLine(int out, int in, bool end = false){
	
    if (out == 0 and in < 0){
		cout << "*";
        return;
    }

	else if (out == 0 and end == false){
		
		cout << "*";
		end = true;
		
	}	
	
	else if (out > 0 and end == false){
		cout << " ";
		printLine(--out, in);
	}
	
	if (end){
		cout << " ";
        printLine(out, --in, true);
	}	
	
}

void PrintPatternQ8(int start, int end){
	
	if(start == 1 and end == 5){
		--start;
		--end;
	}
	
	if(end == 0){
		printLine(end, start);
		cout << endl;
		return;
	}
	
	else{
		
		printLine(end,start);
		cout << endl;
		
		PrintPatternQ8(start +2, end - 1);
		
		printLine(end,start);
		cout << endl;
	}
	
}


int main(){
 
 	PrintPatternQ8(1,5);
  
return 0;  
}
