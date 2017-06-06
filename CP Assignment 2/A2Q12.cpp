#include <iostream>
using namespace std;

int factorial(int n){

	if(n == 0 || n == 1){
		return 1;
	}
	
	else{
		return n * factorial(n-1);
	}
}

long permute(int n, int r){

	return factorial(n)/factorial(n-r);

}


int main(){

	cout << permute(6,3);

return 0;
}