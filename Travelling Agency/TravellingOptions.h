
#ifndef TRAVELLINGOPTIONS_H_
#define TRAVELLINGOPTIONS_H_
#include <iostream>
using namespace std;

class TravellingOptions {

public:

	TravellingOptions();
	TravellingOptions( string, double );

	string name() const ;
	virtual double price() const ;

	void display( ostream& ) const ;
	friend ostream& operator<<( ostream&, const TravellingOptions& );

	virtual ~TravellingOptions();

protected:
	void setName( string );
	void setBasePrice( double );

private:
	string m_Name;
	double m_BasePrice;

};

#endif
