/*
 * TravelKit.h
 *
 *  Created on: Apr 9, 2017
 *      Author: New
 */

#ifndef TRAVELKIT_H_
#define TRAVELKIT_H_

#include "Hotel.h"
#include "Transport.h"
#include "CombinedOffers.h"
using namespace std;

class TravelKit {

public:
	TravelKit();
	TravelKit( string, string );

	void initializeOptions() ;

	double price() const ;

	void AddOption( const TravellingOptions& );

	void Cancel();

	friend ostream& operator<<( ostream&, const TravelKit& );

private:
	string m_Departure;
	string m_Destination;
	static const int SIZE = 20;
	int m_TotalOptions;   // To be used as a counter for m_TravelOptions.
	const TravellingOptions* m_TravelOptions[SIZE];

};

#endif /* TRAVELKIT_H_ */
