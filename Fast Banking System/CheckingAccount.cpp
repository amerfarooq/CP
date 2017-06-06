#include "CheckingAccount.h"
using namespace std;

CheckingAccount :: CheckingAccount() {
	setType( "Checking Account" );
}

CheckingAccount :: CheckingAccount( double initialBalance )
: Account( initialBalance )
{
	setType( "Checking Account" );
}
