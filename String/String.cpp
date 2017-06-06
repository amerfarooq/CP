#include "String.h"
#include <iostream>
#include <stdlib.h>
using namespace std;


String :: String()
:m_Size(0)
{
	m_Initialize();
}

String :: String( char *str ){
	m_Size = m_GetLength( str );
	m_Initialize();
	m_CopyCStr( str );
}

String :: String( const String &str ){
	m_Size = str.m_Size;
	m_Initialize();
	m_CopyStrObj( str );
}

String :: String( int size ){
	m_Size = size + 1;
	m_Initialize();
	m_Array[m_Size - 1] = '\0';
}

String& String ::  operator=( const String &str ){
	m_Delete();
	m_Size = str.m_Size;
	m_Initialize();
	m_CopyStrObj( str );
}

String& String :: operator=( char *str ){
	m_Delete();
	m_Size = m_GetLength( str );
	m_Initialize();
	m_CopyCStr( str );
	return *this;
}

char& String :: operator[]( int index ){
	if ( index >= m_Size - 1 or index < 0 ){
		cerr << "Incorrect Index";
		exit(1);
	}
	else
		return m_Array[index];
}

char& String :: operator[]( int index ) const {
	if ( index >= m_Size - 1 or index < 0 ){
		cerr << "Incorrect Index";
		exit(1);
	}
	else
		return m_Array[index];
}

bool String :: operator!(){
	if ( m_Size == 0 ){
		return true;
	}
	else{
		for ( int i = 0; i < m_Size - 1; ++i ){
			if ( m_Array[i] != ' ' )
				return false;
		}
		return true;
	}
}

bool String :: operator!() const {
	if ( m_Size == 0 ){
		return true;
	}
	else{
		for ( int i = 0; i < m_Size - 1; ++i ){
			if ( m_Array[i] != ' ' )
				return false;
		}
		return true;
	}
}

bool String :: operator==( const String &str ) const {
	if ( m_Size != str.m_Size ){
		return false;
	}

	for ( int i = 0; i < m_Size - 1; ++i ){
		if ( m_Array[i] != str[i] ){
			return false;
		}
	}
	return true;
}

String String :: operator*( int multiplend ){
	String temp;

	if ( multiplend > 1 ){
		for ( int i = 0; i < multiplend; ++i ){
			temp = temp + (*this);
		}
		return temp;
	}
	else if ( multiplend == 1 ){
		return *this;
	}
	else{
		cerr << "Invalid Multiplend";
		exit(1);
	}
}

int String :: length(){
	return m_Size;
}

String String :: operator+( const String &str ){
	if ( m_Size == 0 and str.m_Size != 0 ){
		return str;
	}
	else if ( ( m_Size == 0 and str.m_Size == 0 ) or ( m_Size != 0 and str.m_Size == 0 ) ){
		return *this;
	}
	else{
		String temp = *this;

		temp.m_Size += ( str.m_Size - 1 );
		temp.m_Delete();
		temp.m_Initialize();

		for ( int i = 0; i < m_Size - 1; ++i ){
			temp.m_Array[i] = m_Array[i];
		}
		for ( int i = m_Size - 1, j = 0; i < temp.m_Size; ++i, ++j ){
			temp.m_Array[i] = str.m_Array[j];
		}
		return temp;
	}
}

String String :: operator+( const char &str ){
	if ( m_Size == 0 ){
		String temp = *this;

		temp.m_Size = 2;
		temp.m_Initialize();
		temp.m_Array[0] = str;
		temp.m_Array[1] = '\0';

		return temp;
	}
	else{
		String temp = *this;

		temp.m_Delete();
		++temp.m_Size;
		temp.m_Initialize();

		for ( int i = 0; i < temp.m_Size - 2; ++i ){
			temp.m_Array[i] = m_Array[i];
		}
		temp.m_Array[temp.m_Size - 2] = str;
		temp.m_Array[temp.m_Size - 1] = '\0';

		return temp;
	}

}

String String :: operator+( char *&str ){
	if ( m_Size == 0 ){
		String temp =  *this;

		temp.m_Size = m_GetLength( str );
		temp.m_Initialize();
		temp.m_CopyCStr( str );

		return temp;
	}
	else{
		String temp = *this;
		return temp + str;
	}
}

String String :: operator-( const String &str ){
	if ( !(*this) or !str ){
		return *this;
	}
	else{
		String temp;

		for ( int i = 0; i < m_Size; ++i ){
			if ( m_Array[i] == str[0] ){
				if ( m_isStrPresent( str, i ) ){
					i += (str.m_Size - 2);
				}
				else
					temp = temp + m_Array[i];
			}
			else{
				temp = temp + m_Array[i];
			}
		}
		return temp;
	}
}

int String :: operator()( char letter ){
	for ( int i = 0; i < m_Size; ++i ){
		if ( m_Array[i] == letter ){
			return i;
		}
	}
	cerr << "Not found!";
	exit(1);
}

int String :: operator()( const String &str ){
	for ( int i = 0; i < m_Size - 1; ++i ){
		if ( m_isStrPresent( str, i ) )
			return i;
	}
	cerr << "Not found!";
	exit(1);
}

ostream& operator<<( ostream &output, const String &str ){
	output << str.m_Array;
	return output;
}

istream& operator>>( istream &input, String &str ){
	char *ip = new char[500];
	input.getline( ip, 500 );
	str = ip;
	return input;
}

String :: ~String(){
	m_Delete();
}


void String :: m_Initialize(){
	m_Array = new char[m_Size];
	for ( int i = 0; i < m_Size; ++i ){
		m_Array[i] = ' ';
	}
}

int String :: m_GetLength( const char *str ) const {
	int i = 0;
	while ( str[i] != '\0' ){  ++i;  }
	return i + 1;
}

void String :: m_CopyCStr( const char *str ){
	if ( m_GetLength(str) == m_Size ){
		for ( int i = 0; i < m_Size; ++i ){
			m_Array[i] = str[i];
		}
	}
	else{
		return;
	}
}

void String :: m_CopyStrObj( const String &str ){
	if ( m_Size == str.m_Size ){
		for ( int i = 0; i < m_Size; ++i ){
			m_Array[i] = str.m_Array[i];
		}
	}
	else
		return;
}

void String :: m_Delete(){
	delete[] m_Array;
}

bool String :: m_isStrPresent( const String& str, int index ){
	for ( int i = index, j = 0; i < index + str.m_Size - 1; ++i, ++j ){
		if ( (*this)[i] != str[j] )
			return false;
	}
	return true;
}














