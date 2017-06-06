/*
 * Transactions.h
 *
 *  Created on: Apr 9, 2017
 *      Author: New
 */

#ifndef TRANSACTIONS_H_
#define TRANSACTIONS_H_
#include <iostream>
using namespace std;

class Transaction {

public:
	Transaction();
	Transaction( char, const double&, bool = false, string = " " );
	friend ostream& operator<<( ostream&, const Transaction& );

private:
	string m_TransactionComment;
	char m_Type;
	double m_Amount;
	bool m_IsCardTransaction;
};

#endif /* TRANSACTIONS_H_ */
