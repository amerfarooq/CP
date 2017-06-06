/*
 * CreditCard.cpp
 *
 *  Created on: Apr 9, 2017
 *      Author: New
 */

#include <stdlib.h>
#include "CreditCard.h"
#include "Account.h"
#include <iostream>
using namespace std;

CreditCard :: CreditCard() {
	m_InterestRate = 0;
	m_NoOfWithdrawals = 0;
	m_NoOfTimesBalancePaid = 0;
	m_TotalWithdrawalAmount = 0;
	m_BillAmount = 0;
	m_WithdrawalLimit = 0;
	m_NoOfPoints = 0;
	m_IsBillDue = false;
	m_Type = "CreditCard";
	m_CardID = 0;
}


// Mutators.

void CreditCard :: setInterestRate( double rate ) {
	if ( rate < 0 )
		cout << "Interest Rate cannot be set to less than 0!\n";
	else if ( rate == 0 )
		cout << "Interest Rate cannot be set to 0!\n";
	else
		m_InterestRate = rate;
}

void CreditCard :: setWithdrawalLimit( double limit ) {
	if ( limit < 0 )
		cout << "Withdrawal Limit cannot be set to less than 0!\n";
	else if ( limit == 0 )
		cout << "Withdrawal Limit cannot be set to 0!\n";
	else
		m_WithdrawalLimit = limit;
}

void CreditCard :: setType( string type ) {
	m_Type = type;
}

void CreditCard :: setbillDueStatus( bool status ) {
	m_IsBillDue = status;
}

void CreditCard :: setBillAmount( double amount ) {
	if ( amount < 0 )
		cout << "ERROR: " << "Cannot set Bill Amount lesser than 0!\n";
	else
		m_BillAmount = amount;
}

void CreditCard :: setWithdrawalAmount( double amount ) {
	if ( amount < 0 )
		cout << "ERROR: " << "Setting Invalid Withdrawal Amount!\n";
	else
		m_TotalWithdrawalAmount = amount;
}

void CreditCard :: setNoOfWithdrawals( int totalWithdrawals ) {
	if ( totalWithdrawals < 0 )
		cout << "CreditCard :: setNoOfWithdrawals called with -ve value!\n";
	else
		m_NoOfWithdrawals = totalWithdrawals;
}

// Accessors.

string CreditCard :: getType() const {
	return m_Type;
}

int CreditCard :: getCardID() const {
	return m_CardID;
}

double CreditCard :: getBillAmount() const {
	return m_BillAmount;
}

int CreditCard :: getBalancePaidCounter() {
	return m_NoOfTimesBalancePaid;
}

bool CreditCard :: isBillDue() const {
	return m_IsBillDue;
}

double CreditCard :: getWithdrawalLimit() const {
	return m_WithdrawalLimit;
}

int CreditCard :: getPoints() const {
	return m_NoOfPoints;
}

// Core Functions.

void CreditCard :: assignCardID( int id ) {
	m_CardID = id;
}

void CreditCard :: generateBill() {
	// Only called when Bank::withdrawal detects noOfWithdrawals = 5 and then sets billDue = true;
	if ( m_IsBillDue )
		m_BillAmount = m_TotalWithdrawalAmount + ( m_InterestRate * m_TotalWithdrawalAmount );
	else
		cout << "ERROR: " << "Bill is not yet due\n";
}

void CreditCard :: incrementNoOfPoints( int points ) {
	m_NoOfPoints += points;
}

bool CreditCard :: payBill( Account& account ) {
	if ( m_IsBillDue ) {
		if ( account.withdraw( m_BillAmount ) ) {  // If amount can be withdrawn from Account
			m_TotalWithdrawalAmount = 0;
			m_BillAmount = 0;
			m_IsBillDue = false;
			m_NoOfWithdrawals = 0;
			++m_NoOfTimesBalancePaid;
			cout << "\nCredit Card Bill Paid!" << endl;
			return true;
		}
		else {
			cout << "\nERROR: Credit Card Bill not paid!" << endl;
			return false;
		}
	}
	else {
		cout << "ERROR: " << "Bill is not yet due\n";
		return false;
	}
}

bool CreditCard :: isAmountCorrect( double amount ) {
	if ( amount < 0 ) {
		return false;
	}
	else if ( amount == 0 ) {
		return false;
	}
	else
		return true;
}

bool CreditCard :: incrementWithdrawalAmount( double amount ) {
	if ( isAmountCorrect( amount ) ) {    // Checks if amount is correct.
		if ( m_IsBillDue ) {
			return false;
		}
		else {
			if ( incrementWithdrawalCounter() ) {  // Increments noOfWithdrawals. If this can be achieved, returns true.
				m_TotalWithdrawalAmount += amount;
				return true;
			}
			else {
				return false;
			}
		}
	}
	else {
		cout << "\nERROR: Invalid Amount!" << endl;
		return false;
	}
}

bool CreditCard :: incrementWithdrawalCounter() {
	if ( m_NoOfWithdrawals < WITHDRAWAL_LIMIT ) {
		++m_NoOfWithdrawals;
		return true;
	}
	else if ( m_NoOfWithdrawals == WITHDRAWAL_LIMIT ){
		m_IsBillDue = true;
		generateBill();
		return false;
	}
	else {
		cout << "ERROR: " << "Invalid Number of Withdrawals!\n";
		return false;
	}
}

void CreditCard :: incremenetBalancePaidCounter() {
	++m_NoOfTimesBalancePaid;
}

double CreditCard :: getWithdrawalAmount() const {
	return m_TotalWithdrawalAmount;
}

CreditCard :: ~CreditCard() {}
