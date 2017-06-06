/*
 * Mastercard.cpp
 *
 *  Created on: Apr 9, 2017
 *      Author: New
 */

#include <string>
#include "Mastercard.h"
using namespace std;

Mastercard::Mastercard() {
	setInterestRate( 0.18 );
	setWithdrawalLimit( 50000 );
	setType( "Mastercard" );
}
