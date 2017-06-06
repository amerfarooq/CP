#include "Array.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

void Array :: _initializeArray( int t_size ){
	m_Len = t_size;
	m_Array = new int[m_Len];
	for ( int i = 0; i < m_Len; ++i ){
		m_Array[i] = 0;
	}
}

void Array :: _deallocateArray(){
	delete[] m_Array;
}

int Array :: _countDigit( int t_Digit ) const {
	int total = 0;
	for ( int i = 0; i < m_Len; ++i ){
		if ( m_Array[i] == t_Digit ){
			++total;
		}
	}
	return total;
}

bool Array :: _isSorted() const {
	for ( int i = 0; i < m_Len - 1; ++i ){
		if ( m_Array[i] > m_Array[i+1] ){
			return false;
		}
	}
	return true;
}

void Array :: _exchange( int t_IndexA, int t_IndexB ){
	int temp = m_Array[t_IndexA];
	m_Array[t_IndexA] = m_Array[t_IndexB];
	m_Array[t_IndexB] = temp;

}

Array :: Array(){
	_initializeArray(0);
}

Array :: Array( int t_Len ){
	_initializeArray(t_Len);
}

Array :: Array( int* t_Arr, int t_size ){
	_initializeArray(t_size);
	for ( int i = 0; i < m_Len; ++i ){
		m_Array[i] = t_Arr[i];
	}
}

Array :: Array( const Array& t_ArrObj ){
	_initializeArray(t_ArrObj.m_Len);
	for ( int i = 0; i < m_Len; ++i ){
		m_Array[i] = t_ArrObj.m_Array[i];
	}
}

int Array :: getAt( int t_Index ){
	if ( t_Index >= m_Len or t_Index < 0 ){
		cerr << "Index out of range!";
		exit(1);
	}
	else
		return m_Array[t_Index];
}

int& Array :: operator []( int t_Index ){
	if ( t_Index >= m_Len or t_Index < 0 ){
			cerr << "Index out of range!";
			exit(1);
		}
		else
			return m_Array[t_Index];
}

int& Array :: operator[]( int index ) const {
	if ( index >= m_Len or index < 0 ){
		cerr << "Index out of range!";
		exit(1);
	}
	else
		return m_Array[index];
}

const Array& Array :: operator=( const Array& arr ){
	copy( arr );
	return *this;
}

Array Array :: operator+( const Array &arr ){
	if ( m_Len != arr.m_Len ){
		cerr << "Cannot add arrays of unequal sizes";
		exit(1);
	}
	else{
		Array temp = *this;

		for ( int i = 0; i < m_Len; ++i ){
			temp.m_Array[i] += arr.m_Array[i];
		}
		return temp;
	}
}

Array Array :: operator-( const Array &arr ){
	if ( m_Len != arr.m_Len ){
		cerr << "Cannot add arrays of unequal sizes";
		exit(1);
	}
	else{
		Array temp = *this;

		for ( int i = 0; i < m_Len; ++i ){
			temp.m_Array[i] -= arr.m_Array[i];
		}
		return temp;
	}
}

Array Array :: operator++(){
	if ( m_Len != 0 ){
		Array temp = *this;

		for ( int i = 0; i < m_Len; ++i ){
			m_Array[i] += 1;
		}
		return temp;
	}
	else{
		cerr << "Cannot add to empty array";
		exit(1);
	}
}

Array Array :: operator++( int ){
	if ( m_Len != 0 ){
		for ( int i = 0; i < m_Len; ++i ){
			m_Array[i] += 1;
		}
		return *this;
	}
	else{
		cerr << "Cannot add to empty array";
		exit(1);
	}
}

Array& Array :: operator--( int ){
	if ( m_Len != 0 ){
		for ( int i = 0; i < m_Len; ++i ){
			m_Array[i] -= 1;
		}
		return *this;
	}
	else{
		cerr << "Cannot add to empty array";
		exit(1);
	}
}

bool Array :: operator==(const Array &t_ArrObj ) const {
	if ( m_Len != t_ArrObj.m_Len ){
		return false;
	}
	else{
		for ( int i = 0; i < m_Len; ++i ){
			if ( m_Array[i] != t_ArrObj.m_Array[i] )
				return false;
		}
		return true;
	}
}

bool Array :: operator!(){
	if ( m_Len == 0 ){
		return true;
	}
	else if ( m_Len > 0 ){
		for ( int i = 0; i < m_Len; ++i ){
			if ( m_Array[i] != 0)
				return false;
		}
	}
	return true;
}

void Array :: operator+=( const Array &arr ){
	*this = *this + arr;
}

void Array :: operator-=( const Array &arr ){
	*this = *this - arr;
}

int Array :: operator()( int idx, int val ){
	return erase( idx, val );
}

ostream& operator<<(ostream& op, const Array &arr){
	for ( int i = 0; i < arr.m_Len; ++i ){
		op << arr.m_Array[i] << " ";
	}
	op << endl;
	return op;
}

istream& operator>>(istream& ip, Array &arr ){
	for ( int i = 0; i < arr.m_Len; ++i ){
		ip >> arr.m_Array[i];
	}
	return ip;
}

void Array :: setAt( int t_Index, int t_Val ){
	if ( t_Index >= m_Len or t_Index < 0 ){
		cerr << "Index out of range!";
		exit(1);
	}
	else
		m_Array[t_Index] = t_Val;
}

int Array :: length(){
	return m_Len;
}

void Array :: display(){
	for ( int i = 0; i < m_Len; ++i ){
		cout << m_Array[i] << " ";
	}
	cout << endl;
}

ostream& operator<<( ostream& ofs, Array& arr ){
	for ( int i = 0; i < arr.length(); ++i ){
		ofs << arr[i] << " ";
	}
	ofs << endl;
	return ofs;
}

Array Array :: subArr( int t_StartPos, int t_SubArrSize ){
	if ( t_StartPos > m_Len  or  t_StartPos < 0 ){
		cerr << "Invalid Starting Position!";
		exit(1);
	}
	else if ( t_SubArrSize > m_Len  or  t_SubArrSize < 0 ){
		cerr << "Invalid Sub-Array Size!";
		exit(1);
	}
	else if ( t_StartPos + t_SubArrSize > m_Len ){
		cerr << "Sub-Array out of bounds!";
		exit(1);
	}
	int newArr[t_SubArrSize];
	for ( int i = t_StartPos, j = 0; j != t_SubArrSize; ++i, ++j ){
		newArr[j] = m_Array[i];
	}
	Array newArrObj(newArr, t_SubArrSize);
	return newArrObj;
}

Array Array :: subArr( int t_StartPos ){
	if ( t_StartPos >= m_Len  or  t_StartPos < 0 ){
		cerr << "Invalid Starting Position!";
		exit(1);
	}
	int newArr[m_Len - t_StartPos] = {0};
	for ( int i = t_StartPos, j = 0; i < m_Len; ++i, ++j ){
		newArr[j] = m_Array[i];
	}
	Array newArrObj(newArr, m_Len - t_StartPos);
	return newArrObj;
}

int* Array :: subArrPointer( int t_StartPos ){
	if ( t_StartPos >= m_Len  or  t_StartPos < 0 ){
		cerr << "Invalid Starting Position!";
		exit(1);
	}
	int* newArr = new int[m_Len - t_StartPos];
	for ( int i = t_StartPos, j = 0; i < m_Len; ++i, ++j ){
		newArr[j] = m_Array[i];
	}
	return newArr;
}

int* Array :: subArrPointer( int t_StartPos, int t_SubArrSize ){
	if ( t_StartPos > m_Len  or  t_StartPos < 0 ){
		cerr << "Invalid Starting Position!";
		exit(1);
	}
	else if ( t_SubArrSize > m_Len  or  t_SubArrSize < 0 ){
		cerr << "Invalid Sub-Array Size!";
		exit(1);
	}
	else if ( t_StartPos + t_SubArrSize > m_Len ){
		cerr << "Sub-Array out of bounds!";
		exit(1);
	}
	int* newArr = new int[t_SubArrSize];
	for ( int i = t_StartPos, j = 0; j != t_SubArrSize; ++i, ++j ){
		newArr[j] = m_Array[i];
	}
	return newArr;
}

void Array :: push_back( int t_Num ){
	Array temp(*this);
	_deallocateArray();
	_initializeArray(m_Len + 1);
	for ( int i = 0; i < temp.m_Len; ++i ){
		m_Array[i] = temp.m_Array[i];
	}
	m_Array[m_Len - 1] = t_Num;
}

int Array :: pop_back(){
	if ( m_Len == 0 ){
		cerr << "Array of Length 0 cannot be pushed back!";
		exit(1);
	}

	int lastNum = m_Array[m_Len - 1];
	Array tempObj(*this);
	_deallocateArray();
	_initializeArray(m_Len - 1);
	for ( int i = 0; i < m_Len; ++i ){
		m_Array[i] = tempObj.m_Array[i];
	}
	return lastNum;
}

int Array :: insert( int t_Index, int t_Val ){
	if ( t_Index < 0 or t_Index >= m_Len ){
		cerr << "Invalid Index!";
		return -1;
	}

	if ( t_Index == m_Len - 1){
		setAt(t_Index, t_Val);
		return 1;
	}

	push_back(m_Array[m_Len - 1]);
	for ( int i = m_Len - 2; i > t_Index; --i ){
		m_Array[i] = m_Array[i-1];
	}
	m_Array[t_Index] = t_Val;
	return 1;
}

int Array :: erase( int t_Index, int t_Val ){
	if ( t_Index < 0 or t_Index >= m_Len ){
		cerr << "Invalid Index!";
		return -1;
	}
	if ( t_Index == m_Len - 1 ){
		pop_back();
		return 1;
	}
	for ( int i = t_Index + 1; i < m_Len; ++i ){
		m_Array[i - 1] = m_Array[i];
	}
	pop_back();
	return 1;
}

void Array :: clear(){
	for ( int i = 0; i < m_Len; ++i ){
		m_Array[i] = 0;
	}
}

int Array :: value( int t_Index ){
	if ( t_Index >= m_Len or t_Index < 0 ){
		cerr << "Index out of range!";
		exit(1);
	}
	else
		return m_Array[t_Index];
}

void Array :: assign( int t_Index, int t_Val ){
	if ( t_Index >= m_Len or t_Index < 0 ){
		cerr << "Index out of range!";
		exit(1);
	}
	else
		m_Array[t_Index] = t_Val;
}

void Array :: copy( const Array& t_ArrObj ){
	_deallocateArray();
	_initializeArray(t_ArrObj.m_Len);
	for ( int i = 0; i < m_Len; ++i ){
		m_Array[i] = t_ArrObj.m_Array[i];
	}
}

void Array :: copy( const int* t_Arr, int t_Size ){
	_deallocateArray();
	_initializeArray(t_Size);
	for ( int i = 0; i < m_Len; ++i ){
		m_Array[i] = t_Arr[i];
	}
}

bool Array :: isEmpty(){
	if ( m_Len == 0 ){
		return true;
	}
	else if ( m_Len > 0 ){
		for ( int i = 0; i < m_Len; ++i ){
			if ( m_Array[i] != 0)
				return false;
		}
	}
	return true;
}

Array Array :: find( int t_Num ){
	if ( _countDigit(t_Num) == 0 ){
		cerr << "Digit not found!";
		exit(1);
	}
	else{
		int indexLen = _countDigit(t_Num);
		int indexes[indexLen];
		for ( int i = 0, j = 0; i < m_Len; ++i, ++j ){
			if ( m_Array[i] == t_Num ){
				indexes[j] = m_Array[i];
			}
		}
		Array indexArr(indexes, indexLen);
		return indexArr;
	}
}

bool Array :: equal( Array t_ArrObj ){
	if ( m_Len != t_ArrObj.m_Len ){
		return false;
	}
	else{
		for ( int i = 0; i < m_Len; ++i ){
			if ( m_Array[i] != t_ArrObj.m_Array[i] )
				return false;
		}
		return true;
	}
}

int Array :: sort(){
	if ( _isSorted() ){
		return 1;
	}
	else{
		for ( int i = 0; i < m_Len - 1; ++i ){
			for ( int j = i + 1; j < m_Len; ++j ){
				if ( m_Array[j] < m_Array[i] ){
					_exchange(i,j);
					j = i;
				}
			}
		}
		return 0;
	}
}

void Array :: reverse(){
	for ( int i = 0, j = m_Len - 1;  i < m_Len/2;  ++i, --j ){
		_exchange(i,j);
	}
}

Array :: ~Array() {
	_deallocateArray();
}


