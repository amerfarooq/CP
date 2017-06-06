#include "Visa.h"
#include <iostream>

Visa::Visa() {
	setInterestRate( 0.1 );
	setWithdrawalLimit( 100000 );
	setType( "Visa" );
}

bool Visa :: incrementWithdrawalAmount( double amount ) {
	if ( isAmountCorrect( amount ) ) {
		if ( isBillDue() ) {
			return false;
		}
		else {
			if ( incrementWithdrawalCounter() ) {
				setWithdrawalAmount( getWithdrawalAmount() + amount );
				incrementNoOfPoints( amount );
				return true;
			}
			else {
				return false;
			}
		}
	}
	else {
		cout << "ERROR: " << "incrementWithdrawalAmount called with incorrect amount" << endl;
		return false;
	}
}
//
//
//	if ( isAmountCorrect( amount) ) {
//		if ( isBillDue() ){
//			cerr << "Credit Card Bill is due!\n";
//			return false;
//		}
//		else {
//			if ( incrementWithdrawalCounter() ) {
//				setWithdrawalAmount( getWithdrawalAmount() + amount );  // 1 point per 1 Rs.
//				m_NoOfPoints += amount;
//				return true;
//			}
//			else {
//				cerr << "Credit Card Bill is due!\n";
//				return false;
//			}
//		}
//	}
//}

