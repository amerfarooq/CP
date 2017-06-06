/*
 * Transport.cpp
 *
 *  Created on: Apr 8, 2017
 *      Author: New
 */

#include "Transport.h"
using namespace std;

// Public Methods.

Transport :: Transport()
	: m_IsTripLong( false )
	{}


Transport :: Transport( string name, double basePrice, bool isTripLong /* = false */ )
	: TravellingOptions( name, basePrice )
{
	m_IsTripLong = isTripLong;
}

double Transport :: price() const {
	if ( m_IsTripLong )
		return LONG_TARIFF + TravellingOptions::price();
	else
		return BASIC_TARIFF + TravellingOptions::price();
}


// Protected Methods.

void Transport :: setTripToLong() {
	m_IsTripLong = true;
}

void Transport :: setTripToShort() {
	m_IsTripLong = false;
}

bool Transport :: isTripLong() const {
	return m_IsTripLong ? true : false;
}


// Friend Methods.

ostream& operator<<( ostream& output, const Transport& transport ) {
	transport.display( output );
	return output;
}
