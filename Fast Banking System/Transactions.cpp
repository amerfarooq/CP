#include <iostream>
#include "Transactions.h"
using namespace std;

Transaction :: Transaction() {
	m_Type = {};
	m_Amount = 0;
	m_TransactionComment = "";
	m_IsCardTransaction = false;
}

Transaction :: Transaction( char type, const double& amount, bool IsCredit, string comment )
{
	m_TransactionComment = comment;
	m_Type = type;
	m_Amount = amount;
	m_IsCardTransaction = IsCredit;
}

ostream& operator<<( ostream& output, const Transaction& trans ) {
	if ( trans.m_Type == 'C' ) {
		output << "  -Credit: " << trans.m_Amount << " PKR" << endl;
		output << "             " << trans.m_TransactionComment << endl;
	}
	else {
		if ( trans.m_IsCardTransaction ) {
			output << "  -Debit via Credit Card: " << trans.m_Amount << " PKR " << endl;
			output << "             " << trans.m_TransactionComment << endl;
		}
		else {
			output << "  -Debit: " << trans.m_Amount << " PKR " << endl;
			output << "             " << trans.m_TransactionComment << endl;
		}
	}
	return output;
}

