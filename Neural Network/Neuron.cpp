/*
 * Neuron.cpp
 *
 *  Created on: Apr 23, 2017
 *      Author: New
 */

#include "Neuron.h"
#include "CumulativeNeuron.h"

Neuron::Neuron( int x, int y, double attenuation /* = 1 */ )
: m_Position( x, y )
{
	m_Attenuation = attenuation;
	m_Signal = 0;
	setNeuronType( "Neuron" );
}

const Point& Neuron::position() const {
	return m_Position;
}

double Neuron::signal() const {
	return m_Signal;
}

void Neuron::incrementSignal( double signal ) {
	/* For incrementing signal in CumulativeNeuron */
	m_Signal += signal;
}

void Neuron::operator+=( Neuron* neuron ) {
	m_PointingTo.push_back( neuron );
	neuron->m_PointedBy.push_back( this );

	/* Checks if neuron being pointed to is a CumulativeNeuron.
	 * If so, converts neuron to CumulativeNeuron* and sets
	 * the signalRecieved index at which the neuron is being inserted
	 * to false, indicating it hasn't sent its signal to the CumulativeNeuron.
	 */
	if ( neuron->getNeuronType() == "CumulativeNeuron" ) {
		CumulativeNeuron* cPtr = dynamic_cast < CumulativeNeuron* > ( neuron );
		cPtr->m_ReceivedSignals.push_back( false );
	}
}

void Neuron::setNeuronType( string type ) {
	m_Type = type;
}

string Neuron::getNeuronType() const {
	return m_Type;
}

void Neuron::fire( double signal, Neuron* neuron ) {
	accumulate( signal );

	if ( m_PointingTo.size() != 0 ) {
		propogate();
	}
}

void Neuron::accumulate( double signal ) {
	m_Signal = signal * m_Attenuation;
}

void Neuron::propogate() {

	for ( unsigned int i = 0; i < m_PointingTo.size(); ++i ) {

		if ( m_PointingTo[i]->getNeuronType() == "CumulativeNeuron" or
			 m_PointingTo[i]->getNeuronType() == "ComplexCumulativeNeuron" )
		{
			m_PointingTo[i]->fire( m_Signal, this );
		}
		else {
			m_PointingTo[i]->fire( m_Signal );
		}
	}
}

void Neuron::display() const {
	if ( m_PointingTo.size() == 0 ) {
		cout << "\nNot connected to any neurons!" << endl;
		return;
	}
	else {
		cout << "The neuron at position " << m_Position
	      	 << " with an attenuation factor of " << m_Attenuation
			 << " is connected to the following "
			 << "(" << m_PointingTo.size() << ") " << "neuron(s):\n";

		for ( unsigned int i = 0; i < m_PointingTo.size(); ++i ) {
			cout << " - Neuron at position " << m_PointingTo[i]->position() << endl;
		}
	}
}

ostream& operator<<( ostream& output, const Neuron& neuron ) {
	neuron.display();
	return output;
}

void Neuron::setAttenuation( double attenuation ) {
	m_Attenuation = attenuation;
}

double Neuron::getAttenuation() const {
	return m_Attenuation;
}

void Neuron::setSignal( double signal ) {
//	cout << "\nOriginal Signal: " << signal << endl;
//	if ( signal < 0.95 )
//		m_Signal = 0;
//	else
//		m_Signal = 1;
	m_Signal = signal;
}

Neuron::~Neuron() {}
