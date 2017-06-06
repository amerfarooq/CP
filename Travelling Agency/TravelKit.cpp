/*
 * TravelKit.cpp
 *
 *  Created on: Apr 9, 2017
 *      Author: New
 */

#include "TravelKit.h"
#include <iostream>
using namespace std;


TravelKit::TravelKit()
: m_Departure {},
  m_Destination {},
  m_TotalOptions( 0 )
  {
	  initializeOptions();
  }

TravelKit :: TravelKit( string departure, string destination )
: m_Departure( departure ),
  m_Destination( destination ),
  m_TotalOptions( 0 )
  {
	initializeOptions();
  }

void TravelKit :: initializeOptions() {
	for ( int i = 0; i < SIZE; ++i ) {
		m_TravelOptions[i] = nullptr;
	}
}

double TravelKit :: price() const {
	if ( m_TotalOptions == 0 ) {
		return  0;
	}
	else {
		double total = 0;

		for ( int i = 0; i < m_TotalOptions; ++i ) {
			total += m_TravelOptions[i] -> price();  // Get price of TravellingOptions object.
		}
		return total;
	}
}

void TravelKit :: AddOption( const TravellingOptions& travelOption ) {
	if ( m_TotalOptions < SIZE ) {
		m_TravelOptions[m_TotalOptions] = &travelOption;
		++m_TotalOptions;
	}
	else {
		cerr << "Limit of Traveling Options reached!";
	}
}

void TravelKit :: Cancel() {
	m_TotalOptions = 0;
	for ( int i = 0; i < m_TotalOptions; ++i ) {
		m_TravelOptions[i] = nullptr;
	}
}

// Friend Functions.

ostream& operator<<( ostream& output, const TravelKit& travelKit ) {
	if ( travelKit.m_TotalOptions == 0 ) {
		output << "Travel from " << travelKit.m_Departure << " to " << travelKit.m_Destination << ": You have not reserved yet!" << endl;
		return output;
	}
	else {
		output << "Travel from " << travelKit.m_Departure << " to " << travelKit.m_Destination << ", with Options: " << endl;
		for ( int i = 0; i < travelKit.m_TotalOptions; ++i ) {
			output << "  - " << *(travelKit.m_TravelOptions[i]);
		}
		output << "Total Price: " << travelKit.price() << " PKR" << endl << endl;
		return output;
	}
}
