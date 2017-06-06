#include <iostream>
#include <string>
using namespace std;

void printLine(int outsideSpace, int insideSpace, bool end = false, bool falseStart = false){
    
	if (outsideSpace > 0 and insideSpace == 0){
		falseStart = true;
	}

    if (outsideSpace == 0 and insideSpace == 0){
		cout << "*";
        return;
    }

	else if (outsideSpace == 0 and end == false){
		
		cout << "*";
		end = true;
		if (falseStart)
			return;
		
	}	
	
	else if (outsideSpace > 0 and end == false){
		cout << " ";
		printLine(--outsideSpace, insideSpace);
	}
	
	if (end){
		cout << " ";
        printLine(outsideSpace, --insideSpace, true);
	}	
}    

void PrintPatternQ7(int start, int limit){
	
	if(limit == -1){
		printLine(start, 0);
		cout << endl;
		return;
	}
	
	else{
		
		printLine(start,limit);
		cout << endl;
		
		PrintPatternQ7(start + 1, limit - 2);
		
		printLine(start,limit);
		cout << endl;
	}
	
}

int main(){
  
  PrintPatternQ7(1,5);
  
return 0;  
}
