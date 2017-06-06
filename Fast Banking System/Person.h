/*
 * Person.h
 *
 *  Created on: Apr 9, 2017
 *      Author: New
 */

#ifndef PERSON_H_
#define PERSON_H_
#include <iostream>
#include <string>
using namespace std;

class Person {

public:

	Person() = default;

	bool setFirstName( string );
	bool setMiddleName( string );
	bool setLastName( string );
	bool setCNIC( string );
	bool setAddress( string );
	bool setPhoneNumber( string );
	bool setDateOfBirth( string );

	string getFirstName() const ;
	string getMiddleName() const ;
	string getLastName() const ;
	string getCNIC() const ;
	string getAddress() const ;
	string getPhoneNum() const ;
	string getDateOfBirth() const ;

	void initialize();
	void display() const ;

	friend ostream& operator<<( ostream&, const Person& );
	friend istream& operator>>( istream&, Person& );

private:
	string m_FirstName;
	string m_MiddleName;
	string m_LastName;
	string m_CNIC;
	string m_Address;
	string m_PhoneNumber;
	string m_DateOfBirth;

};

#endif /* PERSON_H_ */
