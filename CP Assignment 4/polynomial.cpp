#include "Polynomial.h"
#include <iostream>
using namespace std;


Polynomial :: Polynomial( int degree ){
	m_Initialize( degree );
}

Polynomial :: Polynomial( const Polynomial &obj ){
	m_Initialize( obj.m_Size - 1 );
	for ( int i = 0; i < m_Size; ++i ){
		m_Array[i] = obj.m_Array[i];
	}
}

const Polynomial& Polynomial :: operator=( const Polynomial& obj ){
	m_Delete();
	m_Initialize( obj.m_Size );
	for ( int i = 0; i < m_Size; ++i ){
		m_Array[i] = obj.m_Array[i];
	}
	return *this;
}

bool Polynomial :: operator== ( const Polynomial& obj ){
	if ( m_Size != obj.m_Size ){
		return false;
	}
	else{
		for ( int i = 0; i < m_Size; ++i ){
			if ( m_Array[i] != obj.m_Array[i] )
				return false;
		}
		return true;
	}
}

Polynomial Polynomial :: operator+ ( const Polynomial &obj ){
	if ( m_Size > obj.m_Size )
		return m_AddPolynomials( *this, obj );
	else
		return m_AddPolynomials( obj, *this );
}

Polynomial Polynomial :: operator- ( const Polynomial &obj ){
	if ( m_Size > obj.m_Size )
		return m_AddPolynomials( *this, m_InvertPolynomial( obj ) );
	else
		return m_AddPolynomials( m_InvertPolynomial( obj ), *this );
}

void Polynomial :: operator+= ( const Polynomial &obj ){
	*this = *this + obj;
}

void Polynomial :: operator-= ( const Polynomial &obj ){
	*this = *this - obj;
}

istream& operator>> ( istream &input, Polynomial &obj ){
	for ( int i = obj.m_Size - 1; i > -1; --i ){
		input >> obj.m_Array[i];
	}
	return input;
}

ostream& operator<< ( ostream& output, Polynomial &obj ){
	for ( int i = obj.m_Size - 1; i > -1; --i ){
		if ( obj.m_Array[i] != 0 ){

			int coeffecient = obj.m_Array[i];
			int power = i;

			if ( coeffecient < 0 ){
				if ( coeffecient == -1 ){  //
					if ( power > 0 ){
						output << "x^" << power << " ";
					}
					else if ( power == 1 ){
						output << "x" << " ";
					}
					else if ( power == 0 ){
						output << coeffecient;
					}
				}
				else{
					output << coeffecient;
					if ( power > 0 and power != 1 ){
						output << "x^" << power << " ";
					}
					else if ( power == 1 ){
						output << "x" << " ";
					}
				}
			}

			else if ( coeffecient > 0 ){
				if ( i != obj.m_Size -1 ){
					output << "+";
				}
				if ( coeffecient == 1 ){
					if ( power > 0 ){
						output << "x^" << power << " ";
					}
					else if ( power == 1 ){
						output << "x";
					}
				}
				else{
					output << coeffecient;
					if ( power > 0 and power != 1 ){
						output << "x^" << power << " ";
					}
					else if ( power == 1 ){
						output << "x" << " ";
					}
				}
			}
		}
	}
	return output;
}

Polynomial :: ~Polynomial(){
	m_Delete();
}

void Polynomial :: m_Initialize( int size ){
	m_Size = size + 1;
	m_Array = new int[m_Size];
}

void Polynomial :: m_Delete(){
	delete[] m_Array;
}

Polynomial Polynomial :: m_AddPolynomials( const Polynomial &big, const Polynomial &small ) const {
	Polynomial temp = big;
	for ( int i = 0; i < small.m_Size; ++i ){
		temp.m_Array[i] += small.m_Array[i];
	}
	return temp;
}

Polynomial Polynomial :: m_InvertPolynomial( const Polynomial &obj ) const {
	Polynomial temp = obj;

	for ( int i = 0; i < temp.m_Size; ++i ){
		temp.m_Array[i] *= -1;
	}
	return temp;
}




