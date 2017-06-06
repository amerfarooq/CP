#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
using namespace std;

class Matrix{

public:

	Matrix();
	Matrix(int, int);
	Matrix(const Matrix &);


	float &operator()(int &i, int &j);
	float &operator()(int &i, int &j)const;
	Matrix& operator=(const Matrix &);
	Matrix operator+(const Matrix &);
	Matrix operator-(const Matrix &);
	Matrix operator*(const Matrix &);
	Matrix& operator++(int);
	void operator+=(const Matrix&);
	void operator-=(const Matrix&);

	float get(int, int) const;
	void set(int, int, float);

	friend ostream& operator<<(ostream& input, const Matrix&);
	friend istream& operator>>(istream& ouput, Matrix&);

	Matrix& assign(const Matrix &);

	Matrix add(const Matrix &);
	Matrix subtract(const Matrix &);
	Matrix multiply(const Matrix &);//multiplies two Matrices and returns the result ------------
	Matrix multiplyElement(const Matrix &);
	Matrix add(float);
	Matrix multiply(float);

	void input();
	void display();

	~Matrix();


private:

	float** m_Array;
	int m_Rows;
	int m_Cols;
	void _initializeArray(int, int);
	void _deallocateArray();
	void _copyArray(const Matrix&);
	bool _isInitialised() const ;
	bool _isValid(int, int) const;
	float _rowColMultiply(float*&, float*, int);
	float* _formColPtr( const Matrix&, int);

};

#endif
