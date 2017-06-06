#include <iostream>
using namespace std;

void printLine(int noOfSpaces, int noOfStars){
  
  if (noOfSpaces == 0){
      
      if (noOfStars == 0){
          
		  cout << endl;
          return;
          
      }
    
      else{
          
          cout << "*";
          printLine(noOfSpaces, --noOfStars);
          
      }    
  }
  
  else{
    
    cout << " ";
    printLine (--noOfSpaces , noOfStars);
    
  }
  
}

void PrintPatternQ4(int spaces, int stars, int idk){
    
    if (spaces == 1){
        
    	return;
        
    }
    
    else{
    	
        printLine(spaces, stars);
        PrintPatternQ4(spaces - 1, stars + 2, idk);
        printLine(spaces,stars);
        
    }
  
}


int main() {
    
	PrintPatternQ4(5,1,5);
    
return 0;
}