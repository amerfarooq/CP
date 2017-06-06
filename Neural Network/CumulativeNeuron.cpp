/*
 * CumulativeNeuron.cpp
 *
 *  Created on: Apr 23, 2017
 *      Author: New
 */

#include "CumulativeNeuron.h"

CumulativeNeuron::CumulativeNeuron( int x, int y, double attenuation )
: Neuron( x, y, attenuation )
{
	setNeuronType( "CumulativeNeuron" );
}

void CumulativeNeuron::fire( double signal, Neuron* neuron ) {
	accumulate( signal );

	/* Checks if signal received is from an attached neuron. If so, records that
	 * it has sent its signal */
	if ( isSignalReceived( neuron ) ){
		setSignalReceived( neuron );
	}
	// If signals from all neurons received, calls propogate.
	if ( areAllSignalsReceived() ) {
		propogate();
	}
}

void CumulativeNeuron::operator+=( Neuron* neuron ) {
	m_PointingTo.push_back( neuron );
	neuron->m_PointedBy.push_back( this );

	if ( neuron->getNeuronType() == "CumulativeNeuron" ) {
		CumulativeNeuron* cPtr = dynamic_cast < CumulativeNeuron* > ( neuron );
		cPtr->m_ReceivedSignals.push_back( false );
	}
}

void CumulativeNeuron::accumulate( double signal ) {
	incrementSignal( signal );
}

void CumulativeNeuron::propogate() {
	/* Since propogate is called when all signals are received,
	 * it sets the signal to the provided formula, and resets
	 * all received signals to false.
	 */
	setSignal( ( 1 / ( 1 + exp(-signal() ) ) ) * getAttenuation() );

	if ( m_PointingTo.size() == 0 ) {
		setAllSignalsFalse();
		return;
	}
	else {
		for ( unsigned int i = 0; i < m_PointingTo.size(); ++i ) {

			if ( m_PointingTo[i]->getNeuronType() == "CumulativeNeuron" )
				m_PointingTo[i]->fire( signal(), this );
			else
				m_PointingTo[i]->fire( signal() );
		}
		setAllSignalsFalse();
	}
}

bool CumulativeNeuron::isSignalReceived( Neuron* neuron ) {
	/* Checks if neuron is pointing to (this) CumulativeNeuron */
	for ( unsigned int i = 0; i < m_PointedBy.size(); ++i ) {
		if ( neuron == m_PointedBy[i] ) {
			return true;
		}
	}
	return false;
}

void CumulativeNeuron::setSignalReceived( Neuron* neuron ) {
	/* Called after isSignalReceived returns true, meaning that a
	 * neuron pointing to (this) CumulativeNeuron is sending its
	 * signal. Thus, the receivedSignals index at which this neuron
	 * is located is set to true, indicating it's signal has been
	 * received.
	 */
	for ( unsigned int i = 0; i < m_PointedBy.size(); ++i ) {
		if ( neuron == m_PointedBy[i] ) {
			m_ReceivedSignals[i] = true;
		}
	}
}

bool CumulativeNeuron::areAllSignalsReceived() {
	/* Loops over signalsReceived vector and checks if
	 * all indexes are true i.e CumulativeNeuron has
	 * received signal from all connected neurons.
	 */
	if ( m_ReceivedSignals.size() == 0 )     // If neuron not pointed by any other neuron
		return false;
	else {
		for ( unsigned int i = 0; i < m_ReceivedSignals.size(); ++i ) {
			if ( m_ReceivedSignals[i] == false ) {
				return false;
			}
		}
		return true;
	}
}

void CumulativeNeuron::setAllSignalsFalse() {
	/* Called after propogate is called to set all
	 * indexes of ReceivedSignals to false, so
	 * signals can be received once again.
	 */
	for ( unsigned int i = 0; i < m_ReceivedSignals.size(); ++i ) {
		m_ReceivedSignals[i] = false;
	}
}

ostream& operator<<( ostream& output, const CumulativeNeuron& cneuron ) {
	cneuron.display();
	return output;
}

void CumulativeNeuron::display() const {
	cout << "\nSignal: " << signal() << endl;
}
