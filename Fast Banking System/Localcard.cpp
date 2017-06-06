/*
 * Localcard.cpp
 *
 *  Created on: Apr 9, 2017
 *      Author: New
 */

#include "Localcard.h"
#include "Account.h"
#include <iostream>

Localcard::Localcard() {
	setInterestRate( 0.25 );
	setWithdrawalLimit( 10000 );
	setType( "Localcard" );
}

void Localcard :: payBill( Account& account ) {
	if ( isBillDue() ) {
		if ( account.withdraw( getBillAmount() ) ) {
			setWithdrawalAmount( 0 );
			setBillAmount( 0 );
			setbillDueStatus( false );
			setNoOfWithdrawals( 0 );

			incremenetBalancePaidCounter();
			if ( getBalancePaidCounter() ==  3 ){
				setWithdrawalLimit( 15000 );
				setInterestRate( 0.20 );
			}
			cout << "Credit Card Bill Paid!\n\n";
			return;
		}
		else {
			cout << "ERROR: " << "Credit Card Bill cannot be paid!" << endl << endl;
		}
	}
	else {
		cerr << "Bill is not yet due" << endl;
	}
}
