/*
 * CumulativeNeuron.h
 *
 *  Created on: Apr 23, 2017
 *      Author: New
 */

#ifndef CUMULATIVENEURON_H_
#define CUMULATIVENEURON_H_

#include "Neuron.h"
#include <math.h>

class CumulativeNeuron: virtual public Neuron {

	friend class ComplexNeuron;
	friend class ComplexCumulativeNeuron;
	friend class Neuron;

public:
	CumulativeNeuron( int, int, double = 1 );

	void fire( double, Neuron* = nullptr );
	void accumulate( double );
	void propogate();

	void operator+=( Neuron* );

	void display() const ;
	friend ostream& operator<<( ostream&, const CumulativeNeuron& );

	CumulativeNeuron( const CumulativeNeuron& ) = delete;
	void operator=( const CumulativeNeuron& ) = delete;

protected:
	vector < bool > m_ReceivedSignals;

	bool isSignalReceived( Neuron* );
	void setSignalReceived( Neuron* );
	bool areAllSignalsReceived();
	void setAllSignalsFalse();
};

#endif /* CUMULATIVENEURON_H_ */
