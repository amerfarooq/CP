/*
 * Person.cpp
 *
 *  Created on: Apr 9, 2017
 *      Author: New
 */

#include "Person.h"
#include <iostream>
using namespace std;


// Helper Functions.

// Returns true if string only has digits
bool isDigits( const string &str ) {
    return str.find_first_not_of( "0123456789" ) == std::string::npos;
}

// Mutators.

bool Person :: setFirstName( string name ) {
	if ( name.length() != 0 ) {
		m_FirstName = name;
		return true;
	}
	else {
		cout << "\nInvalid First Name!" << endl << endl;
		return false;
	}
}

bool Person :: setMiddleName( string name ) {
	if ( name.length() != 0 ) {
		m_MiddleName = name;
		return true;
	}
	else {
		cout << "\nInvalid Middle Name!" << endl << endl;
		return false;
	}
}

bool Person :: setLastName( string name ) {
	if ( name.length() != 0 ) {
		m_LastName = name;
		return true;
	}
	else {
		cout << "\nInvalid Last Name!" << endl << endl;
		return false;
	}
}

bool Person :: setCNIC( string CNIC ) {
	if ( CNIC.length() == 4 and isDigits( CNIC ) ) {
		m_CNIC = CNIC;
		return true;
	}
	else {
		cout << "\nInvalid CNIC! CNIC must consist of 4 digits!" << endl << endl;
		return false;
	}
}

bool Person :: setAddress( string address ) {
	if ( address.length() != 0 ) {
		m_Address = address;
		return true;
	}
	else {
		cout << "\nInvalid Address!" << endl << endl;
		return false;
	}
}

bool Person :: setPhoneNumber( string number ) {
	if ( number.length() == 5 and isDigits( number) ) {
		m_PhoneNumber = number;
		return true;
	}
	else {
		cout << "\nInvalid Phone Number! Number must consist of 5 digits!" << endl << endl;
		return false;
	}
}

bool Person :: setDateOfBirth( string dob ) {
	if ( dob.length() != 0 ) {
		m_DateOfBirth = dob;
		return true;
	}
	else {
		cout << "\nInvalid Date of Birth!" << endl << endl;
		return false;
	}
}

// TODO implement check for getters in case string is uninitialized.
// Accessors.

string Person :: getFirstName() const {
	return m_FirstName;
}

string Person :: getMiddleName() const {
	return m_MiddleName;
}

string Person :: getLastName() const {
	return m_LastName;
}

string Person :: getCNIC() const {
	return m_CNIC;
}

string Person :: getAddress() const {
	return m_Address;
}

string Person :: getPhoneNum() const {
	return m_PhoneNumber;
}

string Person :: getDateOfBirth() const {
	return m_DateOfBirth;
}

// I/O Functions.

void Person :: initialize() {
	string fname, mname, lname, address, cnic, phone, dob;

	while ( true ) {
		cout << "\nEnter First Name: ";
		getline( cin, fname );
		if ( setFirstName( fname ) )
			break;
	}

	while ( true ) {
		cout << "Enter Middle Name: ";
		getline( cin, mname );
		if ( setMiddleName( mname ) )
			break;
	}

	while ( true ) {
		cout << "Enter Last Name: ";
		getline( cin, lname );
		if ( setLastName( lname ) )
			break;
	}

	while ( true ) {
		cout << "Enter Address: ";
		getline( cin, address );
		if ( setAddress( address ) )
			break;
	}

	while ( true ) {
		cout << "Enter CNIC: ";
		getline( cin, cnic );
		if ( setCNIC( cnic ) )
				break;
	}

	while ( true ) {
		cout << "Enter Phone Number: ";
		getline( cin, phone );
		if ( setPhoneNumber( phone ) )
			break;
	}

	while ( true ) {
		cout << "Enter Date of Birth (dd/mm/yy): ";
		getline( cin, dob );
		if ( setDateOfBirth( dob ) )
			break;
	}
	cout << endl;
}

void Person :: display() const {

	cout << "First Name: " << m_FirstName;

	cout << "\nMiddle Name: " << m_MiddleName;

	cout << "\nLast Name: " << m_LastName;

	cout << "\nAddress: " << m_Address;

	cout << "\nCNIC: " << m_CNIC;

	cout << "\nPhone Number: " << m_PhoneNumber;

	cout << "\nDate of Birth: " << m_DateOfBirth;

}

istream& operator>>( istream& input, Person& person ) {
	person.initialize();
	return input;
}

ostream& operator<<( ostream& output, const Person& person ) {
	person.display();
	return output;
}
