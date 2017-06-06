#include "Account.h"
#include <iomanip>
#include <sstream>

Account :: Account() {
	m_AccountID = 0;
	m_Balance = 0;
	m_NoOfTransactions = 0;
	m_Type = "Account";
	m_InterestRate = 0;
}

Account :: Account( double amount ) {
	m_Balance = 0;
	m_NoOfTransactions = 0;
	deposit( amount );
	m_Type = "Account";
	m_AccountID = 0;
	m_InterestRate = 0;
}

bool Account :: deposit( double amount ) {
	if ( amount <= 0 ) {
		cout << "\nERROR: Incorrect Deposit Amount!" << endl;
		return false;
	}
	else {
		if ( m_NoOfTransactions >= TRANSACTION_LIMIT ){
			cout << "\nERROR: " << "Transaction Limit Reached!\n";
			return false;
		}
		stringstream stream;
		stream << fixed << setprecision( 2 ) << amount + m_Balance;
		// Transaction ( Credit/Debit, amount, Card Transaction or Direct, comment )
		m_Transactions[m_NoOfTransactions] = Transaction( 'C', amount, false, "-Balance: " + stream.str() );
		++m_NoOfTransactions;
		m_Balance += amount;

		// If no of transactions are a multiple of 3, interest is given but only if the account is a Savings Account.
		if ( m_NoOfTransactions % 3 == 0 and m_Type == "Savings Account" ) {

			double interestAmount = m_Balance * m_InterestRate;
			stringstream str;
			str << fixed << setprecision( 2 ) << interestAmount;

			m_Balance += amount;
			m_Transactions[m_NoOfTransactions] = Transaction( 'C', interestAmount, false, "-Interest: " + str.str() );
			++m_NoOfTransactions;
		}

		return true;
	}
}

bool Account :: withdraw( CreditCard& card, double amount ) {
	if ( amount > m_Balance ) {
		cout << "\nERROR: Invalid Withdrawal Amount!" << endl;
		return false;
	}
	 // Ensures amount is correct, checks if transaction counter can be incremented
	 // and if it can, adds given amount to withdrawalAmount of card and returns true
	if ( card.incrementWithdrawalAmount( amount ) ) {
		m_Balance -= amount;
		levyCharges( amount );

		stringstream stream;
		stream << fixed << setprecision( 2 ) << m_Balance;

		m_Transactions[m_NoOfTransactions] = Transaction( 'D', amount, true, "-Balance: " + stream.str() );
		++m_NoOfTransactions;
		return true;
	}
	else if ( card.isBillDue() ) {
		cout << "\nERROR: Credit Card Bill of amount: " << card.getBillAmount() << " PKR is due!\n\n" ;
		return false;
	}
	else
		return false;
}

bool Account :: withdraw( double amount ) {
	if ( amount <= 0 ) {
		cout << "\nERROR: Invalid Withdrawal Amount!" << endl;
		return false;
	}
	else if ( amount > m_Balance ) {
		cout << "\nERROR: Withdrawal Amount Exceeds Balance!" << endl;
		return false;
	}
	else {
		if ( m_NoOfTransactions >= TRANSACTION_LIMIT ){
			cout << "\nERROR: Transaction Limit Reached!" << endl;
			return false;
		}
		stringstream stream;
		stream << fixed << setprecision( 2 ) << m_Balance - amount;

		m_Transactions[m_NoOfTransactions] = Transaction( 'D', amount, false, "-Balance: " + stream.str() );
		++m_NoOfTransactions;
		m_Balance -= amount;
		levyCharges( amount );

		return true;
	}
}

double Account :: getBalance() const {
	return m_Balance;
}

void Account :: assignID( int id ) {
	m_AccountID = id;
}

int Account :: getID() const {
	return m_AccountID;
}

void Account :: getMiniStatment() const {
	/* If total transactions > 10, only shows first 10.
	 * Otherwise, outputs till current number of transactions.
	 */
	if ( m_NoOfTransactions == 0 ) {
		cout << "ERROR: " << "No Transaction Record!\n" << endl;
		return;
	}
	if ( m_NoOfTransactions >= 10 ) {
		for ( int i = 0; i < 10; ++i ) {
			cout << m_Transactions[i] << endl;
		}
	}
	else {
		for ( int i = 0; i < m_NoOfTransactions; ++i ) {
			cout << m_Transactions[i] << endl;
		}
	}
}

void Account :: getTransactionHistory() const {
	if ( m_NoOfTransactions == 0 )
		return;

	for ( int i = 0; i < m_NoOfTransactions; ++i ) {
		cout << m_Transactions[i] << endl;
	}
	cout << "\nTotal Transactions: " << m_NoOfTransactions << endl;
}

void Account :: levyCharges( double amount ) {
	if ( amount <= 0 ) {
		cout << "ERROR: " << "Cannot tax incorrect amount!\n";
	}
	else {
		if ( amount > 5000 and amount < 50000 ){
			m_Balance = m_Balance - ( 0.002 * m_Balance );   // >5000 leads to Service Charge of 0.2 %
		}
		else if ( amount > 50000 ){
			m_Balance = m_Balance - ( 0.002 * m_Balance );  // >50,000 leads to Government Tax of 2.5 % on top of Service Charge
			m_Balance = m_Balance - ( 0.025 * m_Balance );
		}
	}
}

string Account :: getType() const {
	return m_Type;
}

void Account :: setType( string type ) {
	m_Type = type;
}

void Account :: setInterestRate( double rate ) {
	if ( rate <= 0 ) {
		cout << "\nInvalid Interest Rate!" << endl;
		return;
	}
	else {
		m_InterestRate = rate;
	}
}
