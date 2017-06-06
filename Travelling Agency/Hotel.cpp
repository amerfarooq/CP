/*
 * Hotel.cpp
 *
 *  Created on: Apr 8, 2017
 *      Author: New
 */

#include "Hotel.h"

// Public Methods.

Hotel :: Hotel()
	: m_TotalNights{},
	  m_PricePerNight{}
	{}



Hotel :: Hotel( string name, double basePrice, int totalNights, double pricePerNight )
	: TravellingOptions( name, basePrice )
{
	setTotalNights( totalNights );
	setPricePerNight( pricePerNight );
}

double Hotel :: price() const {
	return ( m_TotalNights * m_PricePerNight ) + TravellingOptions::price();
}


// Protected Methods.

void Hotel :: setTotalNights( int totalNights ) {
	if ( totalNights <= 0 ) {
		cerr << "Length of stay must be greater than 0 days!";
		exit(1);
	}
	else
		m_TotalNights = totalNights;
}

int Hotel :: getTotalNights() const {
	return m_TotalNights;
}

void Hotel :: setPricePerNight( double price ) {
	if ( price <= 0 ) {
		cerr << "Price per night must be greater than 0!";
		exit(1);
	}
	else
		m_PricePerNight = price;
}

double Hotel :: getPricePerNight() const {
	return m_PricePerNight;
}

// Friend Methods.

ostream& operator<<( ostream& output, const Hotel& hotel ) {
	hotel.display( output );
	return output;
}
