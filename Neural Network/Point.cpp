/*
 * Point.cpp
 *
 *  Created on: Apr 23, 2017
 *      Author: New
 */

#include "Point.h"

Point::Point( int x, int y ) {
	m_X =  x;
	m_Y = y;
}

double Point::distance( const Point& point ) const {
	/*Calculates distance using ( ( (x2 - x1)^2 + (y2 - y2)^2 ) ^ 0.5 ) */

	return pow ( pow( m_X - point.getX(), 2 ) + pow( m_Y - point.getY(), 2 ), 0.5 );
}

int Point::getX() const {
	return m_X;
}

int Point::getY() const {
	return m_Y;
}

ostream& operator<<( ostream& output, const Point& point ) {
	output << "(" << point.getX() << ", " << point.getY() << ")";
	return output;
}

