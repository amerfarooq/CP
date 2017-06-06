#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
using namespace std;

class Polynomial{

public:

	Polynomial( int = 0 );

	Polynomial( const Polynomial& );

	const Polynomial& operator=( const Polynomial& );

	bool operator== ( const Polynomial&  );

	Polynomial operator+ ( const Polynomial& );

	Polynomial operator- ( const Polynomial& );

	void operator+= ( const Polynomial&);

	void operator-= ( const Polynomial& );

	friend istream& operator>> ( istream&, Polynomial& );

	friend ostream& operator<< ( ostream&, Polynomial&);

	~Polynomial();

private:

	int *m_Array;
	int m_Size;

	void m_Initialize( int );

	void m_Delete();

	Polynomial m_AddPolynomials( const Polynomial&, const Polynomial& ) const;

	Polynomial m_InvertPolynomial( const Polynomial& ) const;

};

#endif
