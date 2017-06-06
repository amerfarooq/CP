#include <iostream>
#include <stdlib.h>
#include "Matrix.h"
using namespace std;

void Matrix :: _initializeArray( int Rows, int Cols ){
	m_Array = new float*[Rows];
	for ( int i = 0; i < Rows; ++i ){
		m_Array[i] = new float[Cols];
		for ( int j = 0; j < Cols; ++j ){
			m_Array[i][j] = 0;
		}
	}
}

void Matrix :: _deallocateArray(){
	for ( int i = 0; i < m_Rows; ++i ){
		delete[] m_Array[i];
	}
	delete[] m_Array;
}

void Matrix :: _copyArray( const Matrix& MatrixObj ){
	for ( int i = 0; i < m_Rows; ++i ){
		for ( int j = 0; j < m_Cols; ++j ){
			m_Array[i][j] = MatrixObj.m_Array[i][j];
		}
	}
}

bool Matrix :: _isInitialised() const {
	if ( m_Rows == 0 and m_Cols == 0 ){
		return false;
	}
	return true;
}

bool Matrix :: _isValid( int Row, int Col ) const {
	if ( Row < 0 or
		 Row >= m_Rows or
		 Col >= m_Cols or
		 Col < 0
	    )
	{
		return false;
	}
	return true;
}

float* Matrix :: _formColPtr( const Matrix& MatrixObj, int colNo ){
	float* colPtr = new float[MatrixObj.m_Rows];
	for ( int i = 0; i < MatrixObj.m_Rows; ++i ){
		colPtr[i] = MatrixObj.m_Array[i][colNo];
	}
	return colPtr;
}

float Matrix :: _rowColMultiply(float*& row, float *col, int size ){
	float total = 0;
	for ( int i = 0; i <= size; ++i ){
		total += row[i] * col[i];
	}
	return total;
}

Matrix :: Matrix()
: m_Rows(0),
  m_Cols(0)
{
	_initializeArray(m_Rows, m_Cols);
}

Matrix :: Matrix( int Rows, int Cols ){
	if ( Rows <= 0 or Cols <= 0 ){
		cerr << "Invalid Rows/Columns";
		exit(1);
	}
	m_Rows = Rows;
	m_Cols = Cols;
	_initializeArray(Rows, Cols);
}

Matrix :: Matrix( const Matrix& MatrixObj ){
	m_Rows = MatrixObj.m_Rows;
	m_Cols = MatrixObj.m_Cols;
	_initializeArray( m_Rows, m_Cols );
	_copyArray(MatrixObj);

}

void Matrix :: set( int Row, int Col, float Val ){
	if ( !_isValid(Row, Col) ){
		cerr << "Invalid Row/Column";
		exit(1);
	}
	else
		m_Array[Row][Col] = Val;
}

float& Matrix :: operator()(int &Row, int &Col){
	if ( !_isValid(Row, Col) ){
		cerr << "Invalid Row/Column";
		exit(1);
	}
	else
		return m_Array[Row][Col];
}

Matrix& Matrix :: operator=(const Matrix &MatrixObj ){
	_deallocateArray();
	m_Rows = MatrixObj.m_Rows;
	m_Cols = MatrixObj.m_Cols;
	_initializeArray(m_Rows, m_Cols);
	_copyArray(MatrixObj);
	return *this;
}

Matrix Matrix :: operator+( const Matrix &MatrixObj ){
	if ( m_Rows != MatrixObj.m_Rows or m_Cols != MatrixObj.m_Cols ){
		cerr << "Cannot add matrices of unequal sizes!";
		exit(1);
	}
	Matrix temp = *this;

	for ( int i = 0; i < m_Rows; ++i ){
		for ( int j = 0; j < m_Cols; ++j ){
			temp.m_Array[i][j] += MatrixObj.m_Array[i][j];
		}
	}
	return temp;
}

Matrix Matrix :: operator-( const Matrix &MatrixObj ){
	if ( m_Rows != MatrixObj.m_Rows or m_Cols != MatrixObj.m_Cols ){
		cerr << "Cannot subtract matrices of unequal sizes!";
		exit(1);
	}
	Matrix temp = *this;
	for ( int i = 0; i < m_Rows; ++i ){
		for ( int j = 0; j < m_Cols; ++j ){
			temp.m_Array[i][j] -= MatrixObj.m_Array[i][j];
		}
	}
	return temp;
}

Matrix Matrix :: operator*(const Matrix &MatrixObj){
	if ( m_Cols != MatrixObj.m_Rows ){
		cerr << "Matrix Orders do not permit multiplication";
		exit(1);
	}
	Matrix temp(m_Rows, MatrixObj.m_Cols);
	for ( int i = 0; i < m_Rows; ++i ){
		for ( int j = 0; j < MatrixObj.m_Cols; ++j ){
			temp.m_Array[i][j] = _rowColMultiply( m_Array[i], _formColPtr(MatrixObj, j), m_Rows);
		}
	}
	return temp;
}

Matrix& Matrix:: operator++(int){
	if ( m_Rows == 0 or m_Cols == 0 ){
		cerr << "Cannot increment";
		exit(1);
	}
	else{
		for ( int i = 0; i < m_Rows; ++i ){
			for ( int j = 0; j < m_Cols; ++j ){
				m_Array[i][j] += 1;
			}
		}
	}
	return *this;
}

istream& operator>>( istream& ip, Matrix &matrix){
	if ( !matrix._isInitialised() ){
		cerr << "Cannot take input on an uninitialized Matrix";
		exit(1);
	}
	cout << "Taking inputs for Matrix\n\nEnter value of:\n";
	for( int i = 0; i < matrix.m_Rows; ++i ){
		for ( int j = 0; j < matrix.m_Cols; ++j ){
			cout << "[" << i << "]" << "[" << j << "]" << ": ";
			ip >> matrix.m_Array[i][j];
		}
		cout << endl;
	}
	return ip;
}

ostream& operator<<( ostream& op, const Matrix &matrix ){
	if ( !matrix._isInitialised() ){
		cerr << "Cannot take input on an uninitialized Matrix";
		exit(1);
	}
	for( int i = 0; i < matrix.m_Rows; ++i ){
		for ( int j = 0; j < matrix.m_Cols; ++j ){
			op << matrix.m_Array[i][j] << " ";
		}
		op << endl;
	}
	return op;
}

void Matrix :: operator+=(const Matrix &matrix ){
	*this = *this + matrix;
}

void Matrix :: operator-=( const Matrix &matrix ){
	*this = *this - matrix;
}

float& Matrix :: operator()(int &Row, int &Col) const {
	if ( !_isValid(Row, Col) ){
		cerr << "Invalid Row/Column";
		exit(1);
	}
	else
		return m_Array[Row][Col];
}

float Matrix :: get( int Row, int Col ) const {
	if ( !_isValid(Row, Col) ){
		cerr << "Invalid Row/Column";
		exit(1);
	}
	return m_Array[Row][Col];
}

Matrix& Matrix :: assign( const Matrix& MatrixObj ){
	_deallocateArray();
	m_Rows = MatrixObj.m_Rows;
	m_Cols = MatrixObj.m_Cols;
	_initializeArray(m_Rows, m_Cols);
	_copyArray(MatrixObj);
	return *this;
}

Matrix Matrix :: add( const Matrix& MatrixObj ){
	if ( m_Rows != MatrixObj.m_Rows or m_Cols != MatrixObj.m_Cols ){
		cerr << "Cannot add matrices of unequal sizes!";
		exit(1);
	}
	Matrix temp = *this;
	for ( int i = 0; i < m_Rows; ++i ){
		for ( int j = 0; j < m_Cols; ++j ){
			temp.m_Array[i][j] += MatrixObj.m_Array[i][j];
		}
	}
	return temp;
}

Matrix Matrix :: subtract( const Matrix& MatrixObj ){
	if ( m_Rows != MatrixObj.m_Rows or m_Cols != MatrixObj.m_Cols ){
		cerr << "Cannot subtract matrices of unequal sizes!";
		exit(1);
	}
	Matrix temp = *this;
	for ( int i = 0; i < m_Rows; ++i ){
		for ( int j = 0; j < m_Cols; ++j ){
			temp.m_Array[i][j] -= MatrixObj.m_Array[i][j];
		}
	}
	return temp;
}

Matrix Matrix :: multiply( float Multiplend ){
	Matrix temp = *this;
	for ( int i = 0; i < m_Rows; ++i ){
		for ( int j = 0; j < m_Cols; ++j ){
			temp.m_Array[i][j] *= Multiplend;
		}
	}
	return temp;
}

Matrix Matrix :: multiply( const Matrix& MatrixObj ){
	if ( m_Rows != MatrixObj.m_Cols ){
		cerr << "Matrix Orders do not permit multiplication";
		exit(1);
	}
	Matrix temp(m_Rows, MatrixObj.m_Cols);
	for ( int i = 0; i < m_Rows; ++i ){
		for ( int j = 0; j < MatrixObj.m_Cols; ++j ){
			temp.m_Array[i][j] = _rowColMultiply( m_Array[i], _formColPtr(MatrixObj, j), m_Rows);
		}
	}
	return temp;
}

Matrix Matrix :: multiplyElement( const Matrix& MatrixObj ){
	if ( m_Rows != MatrixObj.m_Rows or m_Cols != MatrixObj.m_Cols ){
		cerr << "Cannot add matrices of unequal sizes!";
		exit(1);
	}
	Matrix temp = *this;
	for ( int i = 0; i < m_Rows; ++i ){
		for ( int j = 0; j < m_Cols; ++j ){
			temp.m_Array[i][j] *= MatrixObj.m_Array[i][j];
		}
	}
	return temp;
}

Matrix Matrix :: add( float Addend ){
	Matrix temp = *this;
	for ( int i = 0; i < m_Rows; ++i ){
		for ( int j = 0; j < m_Cols; ++j ){
			temp.m_Array[i][j] = Addend;
		}
	}
	return temp;
}

void Matrix :: input(){
	if ( !_isInitialised() ){
		cerr << "Cannot take input on an uninitialized Matrix";
		exit(1);
	}
	cout << "Taking inputs for Matrix\n\nEnter value of:\n";
	for( int i = 0; i < m_Rows; ++i ){
		for ( int j = 0; j < m_Cols; ++j ){
			cout << "[" << i << "]" << "[" << j << "]" << ": ";
			cin >> m_Array[i][j];
		}
		cout << endl;
	}
}

void Matrix :: display(){
	if ( !_isInitialised() ){
		cerr << "Cannot take input on an uninitialized Matrix";
		exit(1);
	}
	for( int i = 0; i < m_Rows; ++i ){
		for ( int j = 0; j < m_Cols; ++j ){
			cout << m_Array[i][j] << " ";
		}
		cout << endl;
	}
}

Matrix :: ~Matrix() {
	_deallocateArray();
}

