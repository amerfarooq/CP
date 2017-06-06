#include "Matrix.h"
#include <iostream>
using namespace std;

int main(void) {
	Matrix M1(2,2);
	Matrix M2(2,3);

	cin >> M1;
	cin >> M2;
	cout << M1*M2;


}
