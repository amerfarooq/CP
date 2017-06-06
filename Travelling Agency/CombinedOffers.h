/*
 * CombinedOffers.h
 *
 *  Created on: Apr 8, 2017
 *      Author: New
 */

#ifndef COMBINEDOFFERS_H_
#define COMBINEDOFFERS_H_

#include "Hotel.h"
#include "Transport.h"

class CombinedOffers: public Hotel, public Transport {

public:
	CombinedOffers();
	CombinedOffers( string , double, int, double, bool = false  );

	double price() const override;

	friend ostream& operator<<( ostream&, const CombinedOffers& );

};

#endif /* COMBINEDOFFERS_H_ */
