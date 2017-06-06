/*
 * Point.h
 *
 *  Created on: Apr 23, 2017
 *      Author: New
 */

#ifndef POINT_H_
#define POINT_H_

#include <iostream>
#include <cmath>

using namespace std;


class Point {

public:
	Point( int = 0, int = 0 );

	double distance( const Point& ) const ;

	int getX() const ;
	int getY() const ;

	friend ostream& operator<<( ostream&, const Point& );

private:
	int m_X;
	int m_Y;

};

#endif /* POINT_H_ */
