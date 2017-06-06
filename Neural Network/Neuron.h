///*
// * Neuron.h
// *
// *  Created on: Apr 23, 2017
// *      Author: New
// */
//
//#ifndef NEURON_H_
//#define NEURON_H_
//
//#include <vector>
//#include "Point.h"
//
//class Neuron {
//
//public:
//	Neuron( int, int, double = 1 );
//
//	const Point& position() const ;
//	double signal() const ;
//
//	void operator+=( Neuron* );
//
//	void fire( double );
//	void accumulate( double );
//	void propogate();
//
//	void display() const ;
//	friend ostream& operator<<( ostream&, const Neuron& );
//
//	Neuron& operator=( const Neuron& ) = delete;
//	Neuron( const Neuron& ) = delete;
//
//private:
//	Point m_Position;
//	double m_Signal;
//	double m_Attenuation;
//	vector < Neuron* > m_Neighbors;
//
//};
//
//#endif /* NEURON_H_ */

/*
 * Neuron.h
 *
 *  Created on: Apr 23, 2017
 *      Author: New
 */

#ifndef NEURON_H_
#define NEURON_H_

#include <vector>
#include <string>
#include "Point.h"

class Neuron {

	friend class ComplexCumulativeNeuron;
	friend class CumulativeNeuron;
	friend class ComplexNeuron;

public:
	Neuron( int, int, double = 1 );

	const Point& position() const ;
	double signal() const ;

	void operator+=( Neuron* );

	string getNeuronType() const ;

	virtual void fire( double, Neuron* = nullptr );

	virtual void display() const ;
	friend ostream& operator<<( ostream&, const Neuron& );

	virtual ~Neuron();

	Neuron& operator=( const Neuron& ) = delete;
	Neuron( const Neuron& ) = delete;

protected:
	vector < Neuron* > m_PointedBy;          // Stores addresses of neurons it is being POINTED by
	vector < Neuron* > m_PointingTo;         // Stores addresses of neurons it is POINTING to

	virtual void accumulate( double );
	virtual void propogate();

	void setSignal( double );
	void setAttenuation( double );
	double getAttenuation() const ;
	void incrementSignal( double );
	void setNeuronType( string );

private:
	Point m_Position;
	double m_Signal;
	double m_Attenuation;
	string m_Type;

};

#endif /* NEURON_H_ */
