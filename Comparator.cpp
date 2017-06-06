#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class AdderCircuit{

private:
    int m_A;
    int m_B;
    int m_carry;
    int m_sum;
    int m_fwdCarry;

public:

    AdderCircuit( int t_A = 0, int t_B = 0, int t_carry = 0 )
    : m_A( t_A ),
      m_B( t_B ),
      m_carry( t_carry ),
      m_sum( 0 ),
      m_fwdCarry( 0 )
    {
    }

    void calculateSum(){

        if ( m_A == m_B ) {
            if ( m_carry == 0 ) {
                if ( m_A == 1 and m_B == 1 ) {  m_sum = 0; m_fwdCarry = 1;  }
                else if( m_A == 0 and m_B == 0) {  m_sum = 0; m_fwdCarry = 0; }
            }

            else if ( m_carry == 1 ) {
                if ( m_A == 1 and m_B == 1 ) {  m_sum = 1; m_fwdCarry = 1; }
                else if ( m_A == 0 and m_B == 0 ) {  m_sum = 1; m_fwdCarry = 0; }
            }
        }

        else if ( m_A != m_B  ){
            if ( m_carry == 1 ) {  m_sum = 0; m_fwdCarry = 1;  }
            else if ( m_carry == 0 ) {  m_sum = 1; m_fwdCarry = 0; }
        }
    }

    int getCarry() const {  return m_fwdCarry;  }

    int getSum() const {  return m_sum;  }

    void setInputsAndCarry( int t_A, int t_B, int t_carry = 0 ){
        m_A = t_A;
        m_B = t_B;
        m_carry = t_carry;
        calculateSum();
    }

    void setCarry( int t_c ){  m_fwdCarry = t_c;  }

    void printSumAndCarry(){
        calculateSum();
        cout << "\nSum is " << m_sum << ", Carry is " << m_fwdCarry << "\n";
    }
};

class ComparatorCircuit{

private:
	string m_A;
	string m_B;
	string notA;
	string notB;
	int len;
	int *xNorArray;

public:

	ComparatorCircuit( string t_A = "", string t_B = "" ){
		m_A = t_A;
		m_B = t_B;
		len = m_A.length();
		notA = invertString ( m_A );
		notB = invertString ( m_B );
		xNorArray = new int [len];
	}

	string invertString ( const string& t_str ) const {
		string newStr = "";
		for ( int i = 0; i < t_str.length(); ++i ){
			if ( t_str[i] == '0' ){  newStr += "1";  }
				else if ( t_str[i] == '1' ){  newStr += "0";  }
		}
	return newStr;
	}

	bool andGate( const char t_A, const char t_B ) const {
		if ( (t_A == t_B) and (t_A == '1') ){  return true;  }
		else{  return false;  }
	}

	bool isGreater() const {
		for ( int i = 0; i < len; ++i ){

			if ( andGate( m_A[i], notB[i] ) ){
				bool greater = true;
				for ( int j = 0; j != i; ++j ){
					if ( xNorArray[j] == 0 ){
						greater = false;
					}
				}
				if ( greater ){  return true;  }
			}
		}
		return false;
	}

	bool isSmaller() const{
		for ( int i = 0; i < len; ++i ){

			if ( andGate( notA[i], m_B[i] ) ){
				bool greater = true;
				for ( int j = 0; j != i; ++j ){
					if ( xNorArray[j] == 0 ){
						greater = false;
					}
				}
				if ( greater ){  return true;  }
			}
		}
		return false;
	}

	bool isEqual(){
		bool isNumEqual = true;
		for ( int i = 0; i < len; ++i ){
			if ( m_A[i] != m_B[i] ){
				xNorArray[i] = 0;
				isNumEqual = false;
			}
			else{
				xNorArray[i] = 1;
			}
		}
		if ( isNumEqual ){  return true;  }
		else{  return false;  }
	}

	~ComparatorCircuit(){
		delete[] xNorArray;
	}
};

void printArray(int [], int );
void singleAdder( int, int, int = 0 );
void parallelAdder( string, string );
void halfSubtractor( int, int);
void fullSubtractor( string, string );
void comparator( int, int );
string reverseString ( string );
string convertIntegerToBinary( int );

int main() {

    int choice, a, b, c;
    int A, B;
    cout << "Which circuit do you want to use:\n\n1. Half Adder\n2. Single Full Adder\n3. Parallel Full Adder\n4. Half Subtractor\n5. Full Subtractor\n6. Comparator\n\nOption: ";
    cin >> choice;

    if( choice == 1 ){
        cout << "\nEnter digit 1: ";
        cin >> a;
        cout << "Enter digit 2: ";
        cin >> b;
        singleAdder( a, b);
    }

    else if( choice == 2 ){
        cout << "\nEnter digit 1: ";
        cin >> a;
        cout << "Enter digit 2: ";
        cin >> b;
        cout << "Enter carry: ";
        cin >> c;
        singleAdder( a, b, c );
    }

    else if( choice == 3 ){
        cout << "\nEnter number 1: ";
        cin >> A;
        cout << "Enter number 2: ";
        cin >> B;
        if ( A > 255 or B > 255 or ( (A + B) > 255) ){ cout << "Only 8 bit numbers are supported! " << endl;  }
        else {  parallelAdder( convertIntegerToBinary(A), convertIntegerToBinary(B) );  }
    }

    else if( choice == 4 ){
        cout << "\nEnter digit 1: ";
        cin >> a;
        cout << "Enter digit 2: ";
        cin >> b;
        halfSubtractor( a, b);
    }

    else if( choice == 5 ){
        cout << "\nEnter number 1: ";
        cin >> A;
        cout << "Enter number 2: ";
        cin >> B;
        if ( A > 255 or B > 255 or ( (A + B) > 255) ){ cout << "Only 8 bit numbers are supported! " << endl;  }
        else {  fullSubtractor( convertIntegerToBinary(A), convertIntegerToBinary(B) );  }
    }

    else if( choice == 6 ){
    	cout << "\nEnter number 1: ";
    	cin >> A;
    	cout << "Enter number 2: ";
    	cin >> B;
    	if ( A > 255 or B > 255 or ( (A + B) > 255) ){ cout << "Only 8 bit numbers are supported! " << endl;  }
    	else{  comparator( A, B);  }
    }

    else{
        cout << "\nIncorrect Input!";
        return 0;
    }

    return 0;
}

void singleAdder( int t_A, int t_B, int t_carry ){
    if ( ( t_A > 1 or t_A <  0 ) or ( t_B > 1 or t_B <  0 ) ){
      cout << "Only Binary Numbers can be entered! " << endl;
      return;
    }
    AdderCircuit F1( t_A, t_B, t_carry );
    F1.printSumAndCarry();
}

void parallelAdder( string t_A, string t_B ){

    int finalAnswer[ t_A.length() ];
    int numA = stoi( t_A, nullptr);
    int numB = stoi( t_B, nullptr);
    AdderCircuit F2;

    for ( int i = t_A.length() - 1;  i >= 0;  --i ){
        F2.setInputsAndCarry( numA % 10, numB % 10, F2.getCarry() );
        finalAnswer[i] = F2.getSum();
        numA /= 10;
        numB /= 10;
    }
    printArray( finalAnswer,  t_A.length() );
}

void halfSubtractor( int t_A, int t_B ){
    if ( ( t_A > 1 or t_A <  0 ) or ( t_B > 1 or t_B <  0 ) ){
        cout << "Only Binary Numbers can be entered! " << endl;
        return;
    }
    if ( t_A == t_B ){
        cout << "\nDifference is 0, Borrow is 0\n";
    }
    else if ( t_A == 1 and t_B == 0 ){
        cout << "Difference is 1, Borrow is 0\n";
    }
    else if ( t_A == 0 and t_B == 1 ){
        cout << "\nDifference is 1, Borrow is 1\n";
    }
}

void fullSubtractor( string t_inputA, string t_inputB ){

    int len = t_inputA.length();
    int numBArray[ len ];
    int finalAnswer[ len ];

    for ( int i = 0; i < len; ++i){
        if ( t_inputB[i] == '1'){
            numBArray[i] = 0;
        }
        else{
            numBArray[i] = 1;
        }
    }

    int numA = stoi( t_inputA, nullptr );
    AdderCircuit F3;
    F3.setCarry(1);

    for ( int i = len - 1;  i >= 0;  --i ){
        F3.setInputsAndCarry( numA % 10, numBArray[i], F3.getCarry() );
        finalAnswer[i] = F3.getSum();
        numA /= 10;
    }

    printArray( finalAnswer,  len );
}

void comparator( int t_inputA, int t_inputB ){
	ComparatorCircuit C( convertIntegerToBinary( t_inputA ), convertIntegerToBinary( t_inputB ) );
	if ( C.isEqual() ){  cout << "\n" << t_inputA << " is equal to " << t_inputB << endl;  }
	else if ( C.isGreater() ){ cout << "\n" << t_inputA << " is greater than " << t_inputB << endl;  }
	else if ( C.isSmaller() ){  cout << "\n" << t_inputA << " is smaller than " << t_inputB << endl;  }
}

void printArray(int arr[], int len ){
    cout << "\nAnswer: ";
    for ( int i = 0; i < len; ++i ){  cout << arr[i];  }
}

string reverseString ( string myStr ){

	string newStr = "";
	for ( int i = myStr.length() - 1, j = 0;  i >= 0;  --i, ++j ){
		newStr += myStr[i];
	}
	return newStr;
}

string convertIntegerToBinary( int t_Num ){

	string myStr = "";
	for ( int  i = t_Num; i >= 1; i /= 2 ){
		myStr += to_string( i % 2 );
	}
	string extraZeros = "";
	if ( myStr.length() < 8 ){
	    for ( int i = 0; i < 8 - myStr.length(); ++i ){
	        extraZeros += "0";
	    }
	}
	return extraZeros  + reverseString( myStr );
}
