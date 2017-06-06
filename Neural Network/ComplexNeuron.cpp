/*
 * ComplexNeuron.cpp
 *
 *  Created on: Apr 26, 2017
 *      Author: New
 */

#include "ComplexNeuron.h"
#include "ComplexCumulativeNeuron.h"

ComplexNeuron::ComplexNeuron( int x, int y, double attenuation )
: Neuron( x, y, attenuation )
{
	m_Signal = 0;
	setNeuronType( "ComplexNeuron" );
}

void ComplexNeuron::attach( double attenuation, Neuron* neuron ) {
	m_PointingTo.push_back( neuron );
	m_AttenuationFactors.push_back( attenuation );   // Store the attenuation of connected neuron.

	neuron->m_PointedBy.push_back( this );

	/* Checks if neuron being pointed to is a CumulativeNeuron or ComplexCumulativeNeuron.
	 * If it is either, converts neuron to (Complex)CumulativeNeuron* and sets
	 * the signalRecieved index at which the neuron is being inserted
	 * to false, indicating it hasn't sent its signal to the (Complex)CumulativeNeuron.
	 */
	if ( neuron->getNeuronType() == "CumulativeNeuron" ) {
		CumulativeNeuron* cPtr = dynamic_cast < CumulativeNeuron* > ( neuron );
		cPtr->m_ReceivedSignals.push_back( false );
	}
	else if ( neuron->getNeuronType() == "ComplexCumulativeNeuron" ) {
		ComplexCumulativeNeuron* cPtr = dynamic_cast < ComplexCumulativeNeuron* > ( neuron );
		cPtr->m_ReceivedSignals.push_back( false );
	}
}

void ComplexNeuron::fire( double signal, Neuron* neuron ) {
	/* If not pointing to anything, does nothing */
	if ( m_PointingTo.size() != 0 ) {
		propogate( signal );
	}
}

void ComplexNeuron::accumulate( double signal ) {
	Neuron::accumulate( signal );
}

void ComplexNeuron::propogate( double signal ) {
	/* Signal fired at PointingTo neurons differs for
	 * every neuron since attenuation for each connected
	 * neuron is different. Hence, signal to be fired
	 * is calculated here.
	 */
	for ( unsigned int i = 0; i < m_PointingTo.size(); ++i ) {

		double fwdSignal = signal * m_AttenuationFactors[i];

		if ( m_PointingTo[i]->getNeuronType() == "ComplexCumulativeNeuron" or
			 m_PointingTo[i]->getNeuronType() == "CumulativeNeuron" )
		{
			m_PointingTo[i]->fire( fwdSignal, this );
		}
		else {
			m_PointingTo[i]->fire( fwdSignal );
		}
	}
}

void ComplexNeuron::display() const {
	Neuron::display();
}

ostream& operator<<( ostream& output, const ComplexNeuron& neuron ) {
	neuron.Neuron::display();
	return output;
}
