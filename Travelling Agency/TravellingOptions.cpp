/*
 * TravellingOptions.cpp
 *
 *  Created on: Apr 8, 2017
 *      Author: New
 */

#include "TravellingOptions.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

// Public Methods.

TravellingOptions :: TravellingOptions()
	: m_Name{},
	  m_BasePrice{}
	{}

TravellingOptions :: TravellingOptions( string name , double price )
{
	setName( name );
	setBasePrice( price );
}

string TravellingOptions :: name() const {
	return m_Name;
}

double TravellingOptions :: price() const {
	return m_BasePrice;
}

void TravellingOptions :: display( ostream& output ) const {
	output << m_Name << " -> " << price() << " PKR" << endl;
}

TravellingOptions :: ~TravellingOptions() {}

// Protected Methods.

void TravellingOptions :: setName( string name ) {
	if ( name.length() != 0 )
		m_Name = name;
	else{
		cerr << "Incorrect Name!";
		exit(1);
	}
}

void TravellingOptions :: setBasePrice( double price ) {
	if ( price <= 0 ) {
		cerr << "Incorrect Price!";
		exit(1);
	}
	else
		m_BasePrice = price;
}


// Friend Methods.

ostream& operator<<( ostream& output, const TravellingOptions& travelOption ) {
	travelOption.display( output );
	return output;
}
