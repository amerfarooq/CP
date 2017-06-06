#ifndef STRING_H_
#define STRING_H_

#include <iostream>
#include <stdlib.h>
using namespace std;

class String{

public:

	String();

	String( char *str );

	String( const String &str );

	String( int size );

	String& operator=( const String &str );

	String& operator=( char *str );

	char& operator[]( int index );

	char& operator[]( int index ) const;

	bool operator!();

	bool operator!() const;

	bool operator==( const String &str ) const;

	String operator*( int multiplend );

	int length();

	String operator+( const String &str );

	String operator+( const char &str );

	String operator+( char *&str );

	String operator-( const String &str );

	int operator()( char letter );

	int operator()( const String &str );

	friend ostream& operator<<( ostream &output, const String &str );

	friend istream& operator>>( istream &input, String &str );

	~String();

private:

	char *m_Array;
	int m_Size;

	void m_Initialize();

	int m_GetLength( const char *str ) const ;

	void m_CopyCStr( const char *str );

	void m_CopyStrObj( const String &str );

	void m_Delete();

	bool m_isStrPresent( const String& str, int index );

};


#endif
