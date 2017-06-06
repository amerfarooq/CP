/*
 * CreditCard.h
 *
 *  Created on: Apr 9, 2017
 *      Author: New
 */

#ifndef CREDITCARD_H_
#define CREDITCARD_H_
#include <string>
using namespace std;

class Account;

class CreditCard {

public:

	CreditCard();

	void generateBill() ;
	virtual bool payBill( Account& ) ;
	void setType( string );
	void assignCardID( int );

	virtual bool incrementWithdrawalAmount( double ); // When Bank::withdrawal called and bill not due, this function increments the withdrawal amount

	bool isBillDue() const ;
	bool isAmountCorrect( double );

	string getType() const ;
	double getWithdrawalLimit() const;
	int getCardID() const ;
	double getBillAmount() const ;
	virtual int getPoints() const;

	virtual ~CreditCard();

protected:

	void setBillAmount( double ) ;
	void setNoOfWithdrawals( int );
	void setbillDueStatus( bool );
	// When Bank::withdrawal called and bill not due, this function increments noOfWithdrawals.
	// If withdrawal amount = 5, sets billDue = true
	void setWithdrawalAmount( double );
	void setWithdrawalLimit( double );
	void setInterestRate( double );

	double getWithdrawalAmount() const ;
	int getBalancePaidCounter();

	void incrementNoOfPoints( int );
	bool incrementWithdrawalCounter();
	void incremenetBalancePaidCounter();


private:
	static const int WITHDRAWAL_LIMIT = 3;   // After limit exceeded, Bill is generated.
	static const int LATE_FEE = 10; // Added to Bill after every withdrawal from Bank::withdrawal in case bill is due.
	double m_InterestRate;
	int m_NoOfWithdrawals;
	double m_TotalWithdrawalAmount;
	double m_WithdrawalLimit;
	int m_NoOfTimesBalancePaid;
	double m_BillAmount;
	bool m_IsBillDue;
	int m_NoOfPoints;
	string m_Type;
	size_t m_CardID;
};

#endif /* CREDITCARD_H_ */
