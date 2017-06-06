/*
 * Localcard.h
 *
 *  Created on: Apr 9, 2017
 *      Author: New
 */

#ifndef LOCALCARD_H_
#define LOCALCARD_H_

#include "CreditCard.h"

class Localcard: public virtual CreditCard {

public:
	Localcard();
	bool payBill( Account& );

};

#endif /* LOCALCARD_H_ */
