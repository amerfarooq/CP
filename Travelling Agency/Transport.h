/*
 * Transport.h
 *
 *  Created on: Apr 8, 2017
 *      Author: New
 */

#ifndef TRANSPORT_H_
#define TRANSPORT_H_
#include <iostream>
#include "TravellingOptions.h"
using namespace std;

class Transport: public virtual TravellingOptions {

public:
	Transport();
	Transport( string , double, bool = false );

	double price() const override;

	friend ostream& operator<<( ostream&, const Transport& );

protected:
	void setTripToLong();
	void setTripToShort();
	bool isTripLong() const ;

private:
	static const int LONG_TARIFF = 1500;
	static const int BASIC_TARIFF = 200;
	bool m_IsTripLong;

};

#endif /* TRANSPORT_H_ */
