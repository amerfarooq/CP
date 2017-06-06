/*
 * ComplexCumulativeNeuron.cpp
 *
 *  Created on: Apr 27, 2017
 *      Author: New
 */

#include "ComplexCumulativeNeuron.h"

ComplexCumulativeNeuron::ComplexCumulativeNeuron( int x, int y, double attenuation )
: Neuron( x, y, attenuation ),
  ComplexNeuron( x, y, attenuation ),
  CumulativeNeuron( x, y, attenuation )
{
	setNeuronType( "ComplexCumulativeNeuron" );
}

void ComplexCumulativeNeuron::fire( double signal, Neuron* neuron )  {
	accumulate( signal );

	/* Checks if signal received is from an attached neuron. If so, records that
	 * it has sent its signal */
	if ( isSignalReceived( neuron ) ){
		setSignalReceived( neuron );
	}
	/* If signals from all neurons received, calls propogate. */
	if ( areAllSignalsReceived() ) {
		propogate();
	}
}

void ComplexCumulativeNeuron::accumulate( double signal ) {
	incrementSignal( signal );
}


void ComplexCumulativeNeuron::propogate() {
	setSignal( ( 1 / ( 1 + exp(-signal() ) ) ) * getAttenuation() );

	if ( m_PointingTo.size() == 0 ) {
		setAllSignalsFalse();
		return;
	}
	else {
		for ( unsigned int i = 0; i < m_PointingTo.size(); ++i ) {

			double fwdSignal = signal() * m_AttenuationFactors[i];

			if ( m_PointingTo[i]->getNeuronType() == "CumulativeNeuron" or
				 m_PointingTo[i]->getNeuronType() == "ComplexCumulativeNeuron" )
			{
				m_PointingTo[i]->fire( fwdSignal, this );
			}
			else {
				m_PointingTo[i]->fire( fwdSignal );
			}
		}
		setAllSignalsFalse();
	}
}

void ComplexCumulativeNeuron::attach( double attenuation, Neuron* neuron ) {
	m_PointingTo.push_back( neuron );
	m_AttenuationFactors.push_back( attenuation );
	neuron->m_PointedBy.push_back( this );

	if ( neuron->getNeuronType() == "CumulativeNeuron" ) {
		CumulativeNeuron* cPtr = dynamic_cast < CumulativeNeuron* > ( neuron );
		cPtr->m_ReceivedSignals.push_back( false );
	}
	else if ( neuron->getNeuronType() == "ComplexCumulativeNeuron" ) {
		ComplexCumulativeNeuron* cPtr = dynamic_cast < ComplexCumulativeNeuron* > ( neuron );
		cPtr->m_ReceivedSignals.push_back( false );
	}
}

void ComplexCumulativeNeuron::display() const {
	CumulativeNeuron::display();
}

ostream& operator<<( ostream& output, const ComplexCumulativeNeuron& ccNeuron ) {
	ccNeuron.display();
	return output;
}
