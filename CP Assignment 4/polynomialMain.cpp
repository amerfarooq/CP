#include <iostream>
#include "Polynomial.h"
using namespace std;

int main() {

	int degA, degB;
	cout << "Enter degree of polynomial A: ";
	cin >> degA;

	Polynomial A( degA );

	cout << "Enter coefficients of A:\n";
	cin >> A;

	cout << "Enter degree of polynomial B: ";
	cin >> degB;

	Polynomial B( degB );

	cout << "Enter coefficients of B:\n";
	cin >> B;

	int option;
	cout << "Press 1 to ADD. Press 2 to SUBTRACT: ";
	cin >> option;

	switch ( option ){

	case 1:
	{
		Polynomial X = A + B;
		cout << "\nAnswer is: " << X;
		break;
	}

	case 2:
	{
		int option2;
		cout << "Press 3 for A - B. Press 4 for B - A: ";
		cin >> option2;

		switch ( option2 ){

			case 3:
			{
				Polynomial X = A - B;
				cout << "\nAnswer is: " << X;
				break;
			}
			case 4:
			{
				Polynomial X = B - A;
				cout << "\nAnswer is: " << X;
				break;
			}
			default:
				cerr << "Incorrect Option";

			}
		break;
	}
	default:
			cerr << "Incorrect Option";
	}

}
