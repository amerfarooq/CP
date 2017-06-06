/*
 * Visa.h
 *
 *  Created on: Apr 9, 2017
 *      Author: New
 */

#ifndef VISA_H_
#define VISA_H_

#include "CreditCard.h"

class Visa: public virtual CreditCard {

public:
	Visa();

	bool incrementWithdrawalAmount( double );

};

#endif /* VISA_H_ */
