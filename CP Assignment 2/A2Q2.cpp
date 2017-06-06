#include <iostream>
using namespace std;

float PiValue(int n){
	
	if (n==1){
		return -4.0;
	}
	
	else{
		return -(4.0/n) - PiValue(n-2);
	}
	
}



int main() {


	cout << PiValue(1875);


return 0;
}