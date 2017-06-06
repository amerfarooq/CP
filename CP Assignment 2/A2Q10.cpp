using namespace std;
#include <iostream>

int product(int x, int y){
  
  if (y == 0){
    
    return 0;
    
  }
  
  else{
    
    return x + product(x, y-1);
    
  }
  
}

int main(){
	
	int num;
	cout << "Enter number: ";
	cin >> num;
	
	int pow;
	cout << "Enter power: ";
	cin >> pow;
	
	cout << endl << product(num,pow);
	
}	