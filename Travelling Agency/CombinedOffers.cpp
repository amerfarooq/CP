/*
 * CombinedOffers.cpp
 *
 *  Created on: Apr 8, 2017
 *      Author: New
 */

#include "CombinedOffers.h"
using namespace std;

CombinedOffers::CombinedOffers() {}

CombinedOffers :: CombinedOffers( string name,
								  double basePrice,
								  int lengthOfStay,
								  double pricePerNight,
								  bool isTripLong /* = false */ )

: TravellingOptions( name, basePrice ),
  Hotel( name, basePrice, lengthOfStay, pricePerNight ),
  Transport( name, basePrice, isTripLong )
{
}

double CombinedOffers :: price() const {
	return 0.75 * ( Hotel::price() + Transport::price() ) ;
}

ostream& operator<<( ostream& output, const CombinedOffers& cOffer ) {
	cOffer.display( output );
	return output;
}
