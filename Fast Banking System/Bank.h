#ifndef BANK_H_
#define BANK_H_

#include <vector>
#include "AccountHolder.h"
using namespace std;


class Bank {

public:

	Bank();
	Bank( string = " " );
	Bank( const Bank& );

	const Bank& operator=( const Bank& );

	void accessBankingSystem();
	string getBankName() const;

private:
	string m_BankName;
	static int uniqueAccountCounter;
	static int uniqueCardCounter;
	int m_AccountCounter;
	AccountHolder* m_AccountHolders;
	int m_AccountCapacity;     // m_AccountHolders is allocated array of size 10. If array
							   // is filled, size is doubled. AccountCapacity stores size.

	int menu() const;
	static int generateAccountID() ;
	static int generateCardID();
	//void deleteAccount();
	void doubleAccountCapacity();
	void createNewAccount();
	void displayAllCustomersInfo() const;
	void displayCustomerInfo();
	void generateMiniStatment();
	void generateTransactionHistory();
	void withdraw();
	void deposit();
	void getBalance();
	void getAccountNumber();
	void getPoints();

};

#endif
