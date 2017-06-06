/*
 * Hotel.h
 *
 *  Created on: Apr 8, 2017
 *      Author: New
 */

#ifndef HOTEL_H_
#define HOTEL_H_
#include <iostream>
#include <string>
#include "TravellingOptions.h"

class Hotel: public virtual TravellingOptions {

public:
	Hotel();
	Hotel( string, double, int, double );

	virtual double price() const override;

	friend ostream& operator<<( ostream& output, const Hotel& hotel );

protected:
	void setTotalNights( int );
	int getTotalNights() const ;

	void setPricePerNight( double );
	double getPricePerNight() const ;

private:
	int m_TotalNights;
	double m_PricePerNight;
};

#endif /* HOTEL_H_ */
