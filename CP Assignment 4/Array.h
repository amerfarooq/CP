#ifndef ARRAY_H_
#define ARRAY_H_
#include <iostream>
using namespace std;

class Array {

public:

	Array();
	Array(int size);
	Array(int *arr, int size);
	Array(const Array &);

	int& operator[](int i);
	int& operator[](int i) const;
	const Array & operator=(const Array&);
	Array operator+(const Array&);
	Array operator-(const Array&);
	Array operator++();
	Array operator++(int);
	Array& operator--(int);
	bool operator==(const Array&)const;
	bool operator!();
	void operator+=(const Array&);
	void operator-=(const Array&);
	int operator()(int idx, int val);

	int length();

	friend ostream& operator<<(ostream& input, const Array&);
	friend istream& operator>>(istream& ouput, Array&);

	~Array();

private:

	int getAt(int i);
	void setAt(int i, int val);
	int value(int idx);
	void assign(int idx, int val);

	void display();//done

	Array subArr(int pos, int siz);
	Array subArr(int pos);
	int* subArrPointer(int pos, int siz);
	int* subArrPointer(int pos);

	void push_back(int a);
	int pop_back();
	int insert(int idx, int val);
	int erase(int idx, int val);

	void clear();
	void copy(const Array& Arr);
	void copy(const int *arr, int siz);

	bool isEmpty();
	Array find(int);
	bool equal(Array);

	int sort();
	void reverse();

	int* m_Array;
	int m_Len;
	void _initializeArray(int);
	void _deallocateArray();
	int _countDigit(int) const;
	bool _isSorted() const;
	void _exchange(int,int);

};


#endif
