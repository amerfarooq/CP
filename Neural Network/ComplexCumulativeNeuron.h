/*
 * ComplexCumulativeNeuron.h
 *
 *  Created on: Apr 27, 2017
 *      Author: New
 */

#ifndef COMPLEXCUMULATIVENEURON_H_
#define COMPLEXCUMULATIVENEURON_H_

#include "Neuron.h"
#include "CumulativeNeuron.h"
#include "ComplexNeuron.h"

class ComplexCumulativeNeuron: public ComplexNeuron, public CumulativeNeuron {

public:
	ComplexCumulativeNeuron( int, int, double = 1 );

	void fire( double, Neuron* = nullptr );
	void accumulate( double );
	void propogate();

	void attach( double, Neuron* );

	void display() const ;
	friend ostream& operator<<( ostream&, const ComplexCumulativeNeuron& );

	ComplexCumulativeNeuron( const ComplexCumulativeNeuron& ) = delete;
	void operator=( const ComplexCumulativeNeuron& ) = delete;
};

#endif /* COMPLEXCUMULATIVENEURON_H_ */
