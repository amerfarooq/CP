/*
 * Account.h
 *
 *  Created on: Apr 9, 2017
 *      Author: New
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include "Transactions.h"
#include "CreditCard.h"
#include <iostream>
using namespace std;

class Account {

public:
	Account();
	Account( double );

	bool deposit( double );
	bool withdraw( CreditCard&, double );
	bool withdraw( double );
	void withdrawByCard( double );
	void getMiniStatment() const ;
	double getBalance() const ;
	void getTransactionHistory() const ;
	string getType() const ;
	void setType( string );
	void levyCharges( double );
	void assignID( int );
	int getID() const ;
	void setInterestRate( double );

private:
	size_t m_AccountID;
	string m_Type;
	double m_InterestRate;
	double m_Balance;
	int m_NoOfTransactions;
	static const int TRANSACTION_LIMIT = 50;
	Transaction m_Transactions[TRANSACTION_LIMIT];

};

#endif /* ACCOUNT_H_ */
