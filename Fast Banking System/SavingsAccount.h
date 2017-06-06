/*
 * SavingsAccount.h
 *
 *  Created on: Apr 9, 2017
 *      Author: New
 */

#ifndef SAVINGSACCOUNT_H_
#define SAVINGSACCOUNT_H_

#include "Account.h"

class SavingsAccount: public Account {

public:
	SavingsAccount();
	SavingsAccount( double, int, double = 0.05 );  // Profit Rate = 0.05 by Default

	void setDepositPeriod( int );
	int getDepositPeriod() const ;

private:
	int m_DepositPeriod;  // In months.
};

#endif /* SAVINGSACCOUNT_H_ */
