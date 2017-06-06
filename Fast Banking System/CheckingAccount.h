#ifndef CHECKINGACCOUNT_H_
#define CHECKINGACCOUNT_H_

#include "Account.h"

class CheckingAccount: virtual public Account {

public:
	CheckingAccount();
	CheckingAccount( double );

};

#endif /* CHECKINGACCOUNT_H_ */
