/*
 * AccountHolder.h
 *
 *  Created on: Apr 9, 2017
 *      Author: New
 */

#ifndef ACCOUNTHOLDER_H_
#define ACCOUNTHOLDER_H_
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "Mastercard.h"
#include "Visa.h"
#include "LocalCard.h"
#include "Person.h"

class AccountHolder: public Person {

public:
	void initialize();
	void display() const;

	void initializeAccount();
	void initializeCard();
	Account& accessAccount();
	CreditCard& accessCard();

	~AccountHolder();

private:
	Account* m_Account;
	CreditCard* m_Card;

};

#endif /* ACCOUNTHOLDER_H_ */
