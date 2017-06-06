/*
 * ComplexNeuron.h
 *
 *  Created on: Apr 26, 2017
 *      Author: New
 */

#ifndef COMPLEXNEURON_H_
#define COMPLEXNEURON_H_

#include "Neuron.h"

class ComplexNeuron: virtual public Neuron {

	friend class ComplexCumulativeNeuron;

public:
	ComplexNeuron( int, int, double = 1 );

	void attach( double, Neuron* );
	virtual void fire( double, Neuron* = nullptr );

	void display() const ;
	friend ostream& operator<<( ostream&, const Neuron& );

	ComplexNeuron& operator=( const Neuron& ) = delete;
	ComplexNeuron( const Neuron& ) = delete;

protected:
	vector < double > m_AttenuationFactors;
	virtual void propogate( double );
	virtual void accumulate( double );

};

#endif /* COMPLEXNEURON_H_ */
