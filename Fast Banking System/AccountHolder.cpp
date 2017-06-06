/*
 * AccountHolder.cpp
 *
 *  Created on: Apr 9, 2017
 *      Author: New
 */

#include "AccountHolder.h"

void AccountHolder :: initialize() {
	Person :: initialize();
	initializeAccount();
	initializeCard();
}

void AccountHolder :: initializeAccount() {
	while( true ) {
		int userOption;
		cout << "Which account would you prefer to open?\n  1. Savings Account\n  2. Checking Account\n\nOption: ";
		cin >> userOption;
		cout << endl;

		double initialBalance = 0;
		cout << "Enter Opening Balance: ";
		cin >> initialBalance;

		switch ( userOption ) {
			case 1: {
				int depositPeriod;

				cout << "Enter Deposit Period (in months): ";
				cin >> depositPeriod;

				m_Account = new SavingsAccount( initialBalance, depositPeriod );
				return;
				break;
			}
			case 2: {
				m_Account = new CheckingAccount( initialBalance );
				return;
				break;
			}
			default:
				cout << "\nInvalid Option! Try again!\n" << endl;
		}
	}
}

void AccountHolder :: initializeCard() {
	while( true ) {
		int userOption;
		cout << "\nWhich type of Credit Card would you prefer?\n  1. MasterCard\n  2. Visa\n  3. Local Card\n\nOption: ";
		cin >> userOption;
		cout << endl;

		switch ( userOption ) {
			case 1:
				m_Card = new Mastercard;
				return;
				break;

			case 2:
				m_Card = new Visa;
				return;
				break;

			case 3:
				m_Card = new Localcard;
				return;
				break;

			default:
				cout << "\nInvalid Option. Try again!" << endl;
		}
	}
}

void AccountHolder :: display() const {
	Person :: display();
	cout << "\nAccount Type: " << m_Account->getType();
	cout << "\nAccount Number: " << m_Account->getID();
	cout << "\nCredit Card Type: " << m_Card->getType();
	cout << "\nCredit Card Number: " << m_Card->getCardID();
	cout << "\nBalance: " << m_Account->getBalance() << " PKR" << endl << endl;
}

Account& AccountHolder :: accessAccount() {
	return *m_Account;
}

CreditCard& AccountHolder :: accessCard() {
	return *m_Card;
}

AccountHolder :: ~AccountHolder() {
	delete m_Account;
	delete m_Card;
}

