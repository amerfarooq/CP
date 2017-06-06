/*
 * SavingsAccount.cpp
 *
 *  Created on: Apr 9, 2017
 *      Author: New
 */

#include "SavingsAccount.h"

SavingsAccount :: SavingsAccount() {
	setType( "Savings Account" );
	m_DepositPeriod = 0;
	setInterestRate( 0.05 );
}

SavingsAccount :: SavingsAccount( double balance, int depositPeriod, double profit )
: Account( balance )
{
	setInterestRate( 0.05 );
	setType( "Savings Account" );
	setDepositPeriod( depositPeriod );
}

void SavingsAccount :: setDepositPeriod( int months ) {
	if ( months <= 0 )
		cout << "\nInvalid Deposit Period!" << endl;
	else
		m_DepositPeriod = months;
}

int SavingsAccount :: getDepositPeriod() const {
	return m_DepositPeriod;
}
