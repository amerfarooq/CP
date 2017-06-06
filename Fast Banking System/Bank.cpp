#include "Bank.h"
using namespace std;

int Bank::uniqueAccountCounter = 10224;
int Bank::uniqueCardCounter = 5023;

Bank :: Bank() {
	m_BankName = "";
	m_AccountCounter = 0;
	m_AccountHolders = new AccountHolder[10];
	m_AccountCapacity = 10;
}

Bank :: Bank( string name ) {
	m_BankName = name;
	m_AccountCounter = 0;
	m_AccountHolders = new AccountHolder[10];
	m_AccountCapacity = 10;
}

Bank :: Bank( const Bank& bank ) {
	m_BankName = bank.getBankName();
	m_AccountCapacity = bank.m_AccountCapacity;
	m_AccountCounter = bank.m_AccountCounter;
	m_AccountHolders = new AccountHolder[m_AccountCapacity];

	for ( int i = 0; i < m_AccountCounter; ++i ) {
		m_AccountHolders[i] = bank.m_AccountHolders[i];
	}
}

const Bank& Bank :: operator=( const Bank& bank ) {
	m_BankName = bank.m_BankName;
	m_AccountCapacity = bank.m_AccountCapacity;
	m_AccountCounter = bank.m_AccountCounter;

	delete m_AccountHolders;
	m_AccountHolders = new AccountHolder[m_AccountCapacity];

	for ( int i = 0; i < m_AccountCounter; ++i ) {
		m_AccountHolders[i] = bank.m_AccountHolders[i];
	}
	return *this;
}

int Bank :: generateAccountID() {
	int temp = uniqueAccountCounter;
	++uniqueAccountCounter;
	return temp;
}

int Bank :: generateCardID() {
	int temp = uniqueCardCounter;
	++uniqueCardCounter;
	return temp;
}

//void Bank :: deleteAccount() {
//	/*  Locates CNIC of account to be deleted. If CNIC found, deletes accountHolders array and makes a new one
//	 * 	of the same capacity. Loops till before the index of the account to be deleted ( i.e. deletionIndex )
//	 * 	and copies accountHolders from previous array ( in temp ) to new one. Then starts another loop with 2 counters:
//	 * 	one starting from deletion index which is used to insert accountHolders into the newly made array,
//	 * 	while the second one starts from deletionIndex + 1 to skip over the deletedObject. The for loop
//	 * 	runs till capacity - 1 since there is no need to access the newly created space at the end of the
//	 * 	new array since effectively, all accounts are being shifted one place leftwards.
//	 */
//	cout << "Deleting Account" << endl;
//	string CNIC;
//
//	cout << "Enter CNIC of Account Holder: ";
//	cin >> CNIC;
//
//	for (  int i = 0; i < m_AccountCounter; ++i ) {
//		if ( m_AccountHolders[i].getCNIC() == CNIC ) {
//			cout << "CNIC FOUND!" << endl;
//			int deletionIndex = i;
//			Bank temp = *this;
//
//			delete[] m_AccountHolders;
//			cout << "Deleted" << endl;
//			m_AccountHolders = new AccountHolder[m_AccountCapacity];
//			cout << "New mem  taken" << endl;
//
//			// Copying accountHolders from before the deletionIndex
//			for ( int i = 0; i < deletionIndex; ++i ) {
//				cout << "First Loop!" << endl;
//				m_AccountHolders[i] = temp.m_AccountHolders[i];
//				cout << "Copied Before Ones" << endl;
//			}
//			// Copying accountHolders after the deletionIndex
//			for ( int tempCount = deletionIndex + 1, newCount = deletionIndex; newCount < m_AccountCapacity - 1; ++tempCount, ++newCount ) {
//				cout << "Second Loop!" << endl;
//				m_AccountHolders[newCount] = m_AccountHolders[tempCount];
//				cout << "Copied After Ones" << endl;
//			}
//			// Current accountCounter has to be decremented since a new space is created.
//			--m_AccountCounter;
//
//			cout << "\nAccount Deleted Successfully!" << endl;
//			return;
//		}
//		else {
//			cout << "\nERROR: Account Does Not Exist!" << endl;  // In case account not found
//			return;
//		}
//	}
//}

void Bank :: createNewAccount() {
	if ( m_AccountCounter == m_AccountCapacity )
		doubleAccountCapacity();

	AccountHolder* newAccount = nullptr;
	bool isCnicUnique = false;

	while ( !isCnicUnique ) {
		newAccount = new AccountHolder;
		newAccount->initialize();

		for ( int i = 0; i < m_AccountCounter; ++i ) {
			if ( newAccount->getCNIC() == m_AccountHolders[i].getCNIC() ) {
				cout << "\nERROR: Provided CNIC already associated with another account! Please Try Again!" << endl;
				cin.ignore();
				break;
			}
			isCnicUnique = true;
		}
		if ( m_AccountCounter == 0 )
			break;
	}
	m_AccountHolders[m_AccountCounter] = *newAccount;
	newAccount->accessAccount().assignID( generateAccountID() );
	newAccount->accessCard().assignCardID( generateCardID() );
	++m_AccountCounter;

	cout << "\nThank you for joining Bank " << m_BankName << "!" << endl << endl
			<< "Your Account Number is: " << newAccount->accessAccount().getID() << endl
			<< "Your Credit Card Number is: " << newAccount->accessCard().getCardID()
			<< endl;
}

void Bank :: displayAllCustomersInfo() const {
	if ( m_AccountCounter == 0 ) {
		cout << "\nNo Customers Have Joined the Bank!" << endl;
		return;
	}
	for ( int i = 0; i < m_AccountCounter; ++i ) {
		m_AccountHolders[i].display();
	}
	cout << "\nTotal Customers: " << m_AccountCounter << endl;
}

void Bank :: displayCustomerInfo() {
	string CNIC;

	cout << "Enter CNIC of Account Holder: ";
	cin >> CNIC;
	cout << endl;

	for ( int i = 0; i < m_AccountCounter; ++i ) {
		if ( m_AccountHolders[i].getCNIC() == CNIC ) {
			m_AccountHolders[i].display();
			return;
		}
	}
	cout << "\nERROR: Account Does Not Exist!" << endl;  // In case account not found
}

void Bank :: generateMiniStatment() {
	string CNIC;

	cout << "Enter CNIC of Account Holder: ";
	cin >> CNIC;
	cout << endl;

	for ( int i = 0; i < m_AccountCounter; ++i ) {
		if ( m_AccountHolders[i].getCNIC() == CNIC ) {
			m_AccountHolders[i].accessAccount().getMiniStatment();
			return;
		}
	}
	cout << "\nERROR: Account Does Not Exist!" << endl;  // In case account not found
}

void Bank :: generateTransactionHistory() {
	string CNIC;

	cout << "Enter CNIC of Account Holder: ";
	cin >> CNIC;
	cout << endl;

	for ( int i = 0; i < m_AccountCounter; ++i ) {
		if ( m_AccountHolders[i].getCNIC() == CNIC ) {
			m_AccountHolders[i].accessAccount().getTransactionHistory();
			return;
		}
	}
	cout << "\nERROR: Account Does Not Exist!" << endl;  // In case account not found
}

void Bank :: deposit() {
	int depositAmount;
	string CNIC;

	cout << "Enter CNIC of Account Holder: ";
	cin >> CNIC;
	cout << "Enter Amount to Deposit: ";
	cin >> depositAmount;

	for ( int i = 0; i < m_AccountCounter; ++i ) {
		if ( m_AccountHolders[i].getCNIC() == CNIC ) {
			// If deposit successful
			if ( m_AccountHolders[i].accessAccount().deposit( depositAmount ) ) {
				cout << "\nDeposit Successful!" << endl;
				return;
			}
			// In case deposit is unsuccessful, premature return;
			return;
		}
	}
	cout << "\nERROR: Account Does Not Exist!" << endl;  // In case account not found
}

// this function sucks
void Bank :: withdraw() {
	int withdrawAmount;
	string CNIC;

	cout << "Enter CNIC of Account Holder: ";
	cin >> CNIC;

	int option;
	while ( true ) {
		cout << "\nPress 1 to use Credit Card" << endl;
		cout << "Press 2 to Withdraw Directly" << endl;
		cout << "Option: ";
		cin >> option;
		cout << endl;
		if ( option == 1 or option == 2 )
			break;
		else
			cout << "Incorrect Option! Try Again" << endl;
	}

	cout << "Enter Amount to Withdraw: ";
	cin >> withdrawAmount;

	for ( int i = 0; i < m_AccountCounter; ++i ) {
		if ( m_AccountHolders[i].getCNIC() == CNIC ) {

			// If withdrawal through card.
			if ( option == 1 ) {

				// Ensuring withdrawal amount does not exceed withdrawal limit.
				if ( withdrawAmount > m_AccountHolders[i].accessCard().getWithdrawalLimit() ) {
					cout << "\nERROR: Amount Exceeds Withdrawal Limit of Credit Card" << endl;
					return;
				}
				else {
					// If amount can be withdrawan, it will be. Otherwise, bill payment is handled.
					if ( m_AccountHolders[i].accessAccount().withdraw( m_AccountHolders[i].accessCard(), withdrawAmount ) ) {
						cout << "\nWithdrawal Successful!" << endl;
						return;
					}

					// Checking if the Bill is due and giving the user the option to pay it.
					if ( m_AccountHolders[i].accessCard().isBillDue() ) {
						string billPaymentOption;

						while ( true ) {
							cout << "Would you like to pay the Credit Card Bill? Enter Y or N: ";
							cin >> billPaymentOption;

							if ( billPaymentOption == "Y" or billPaymentOption == "N" ) {
								break;
							}
							else {
								cout << "\nInvalid Option! Try Again!" << endl;
							}
						}
						// If Bill paid, withdraw the original amount. Else output error.
						if ( billPaymentOption == "Y" ) {
							if ( m_AccountHolders[i].accessCard().payBill( m_AccountHolders[i].accessAccount() ) ) {

								m_AccountHolders[i].accessAccount().withdraw( m_AccountHolders[i].accessCard(), withdrawAmount );
								cout << "\nWithdrawal Successful!" << endl;
								return;
							}
							else
								return;
						}
						// In case "N" is entered
						else {
							return;
						}
					}
					return;
				}
			}
			// If withdrawal is to be direct
			else {
				if ( m_AccountHolders[i].accessAccount().withdraw( withdrawAmount ) ) {
					cout << "\nWithdrawal Successful!" << endl;
					return;
				}
				else
					return;
			}
		}
	}
	cout << "\nERROR: Account Does Not Exist!" << endl;  // In case account not found
}

void Bank :: getBalance() {
	string CNIC;

	cout << "Enter CNIC of Account Holder: ";
	cin >> CNIC;

	for ( int i = 0; i < m_AccountCounter; ++i ) {
		if ( m_AccountHolders[i].getCNIC() == CNIC ) {
			cout << "\nAccount Balance: " << m_AccountHolders[i].accessAccount().getBalance() << " PKR" << endl;
			return;
		}
	}
	cout << "\nERROR: Account Does Not Exist!" << endl;  // In case account not found
}

void Bank :: getPoints() {
	string CNIC;

	cout << "Enter CNIC of Account Holder: ";
	cin >> CNIC;

	for ( int i = 0; i < m_AccountCounter; ++i ) {
		if ( m_AccountHolders[i].getCNIC() == CNIC ) {
			if ( m_AccountHolders[i].accessCard().getType() != "Visa" ) {
				cout << "\nERROR: Credit Card is not a VISA Card" << endl;
				return;
			}
			else {
				cout << "\nYour Points are: " << m_AccountHolders[i].accessCard().getPoints() << endl;
				return;
			}
		}
	}
	cout << "\nERROR: Account Does Not Exist!" << endl;  // In case account not found
}

int Bank :: menu() const {
	int menuOption = 0;

	while ( true ) {
		cout << "\n---------------" << endl;
		cout <<   "| System Menu |";
		cout << "\n---------------" << endl;
		cout << "1. Make New Account" << endl;
		//cout << "2. Delete Existing Account" << endl;
		cout << "2. Display All Customers Information" << endl;
		cout << "3. Display Customer Information" << endl;
		cout << "4. Deposit into Account" << endl;
		cout << "5. Withdraw from Account" << endl;
		cout << "6. Generate Account Ministatement" << endl;
		cout << "7. Generate Account Transaction History" << endl;
		cout << "8. Inquire Account Balance" << endl;
		cout << "9. Get Account Number" << endl;
		cout << "10. Get Points (only for VISA)" << endl;
		cout << "11. Exit" << endl;
		cout << "\nOption: ";
		cin >> menuOption;
		cout << endl;

		if ( menuOption > 11 or menuOption <= 0 )
			cout << "\nIncorrect Option! Try Again." << endl;
		else {
			return menuOption;
		}
	}
	cout <<  "\nMalfunction in Bank::menu" << endl;
	return 0;
}

void Bank :: getAccountNumber() {
	string CNIC;

	cout << "Enter CNIC of Account Holder: ";
	cin >> CNIC;

	for ( int i = 0; i < m_AccountCounter; ++i ) {
		if ( m_AccountHolders[i].getCNIC() == CNIC ) {
			cout << "\nAccount ID: " << m_AccountHolders[i].accessAccount().getID() << endl;
		}
		return;
	}
	cout << "\nERROR: Account Does Not Exist!" << endl;  // In case account not found
}

void Bank :: accessBankingSystem() {

	while ( true ) {
		switch ( menu() ) {

		case 1:
			cout << "\n--------------------" << endl;
			cout <<   "| Creating Account |" << endl;
			cout <<   "--------------------" << endl;
			cin.ignore();
			createNewAccount();
			break;
//
//		case 2:
//			cout << "\n--------------------" << endl;
//			cout <<   "| Deleting Account |" << endl;
//			cout <<   "--------------------" << endl;
//			deleteAccount();
//			break;

		case 2:
			cout << "\n----------------------------------------" << endl;
			cout <<   "| Displaying all Customers Information |" << endl;
			cout <<   "----------------------------------------" << endl;
			displayAllCustomersInfo();
			break;

		case 3:
			cout << "\n-----------------------------------" << endl;
			cout <<   "| Displaying Customer Information |" << endl;
			cout <<   "-----------------------------------" << endl;
			displayCustomerInfo();
			break;

		case 4:
			cout << "\n--------------" << endl;
			cout <<   "| Depositing |" << endl;
			cout <<   "--------------" << endl;
			deposit();
			break;

		case 5:
			cout << "\n---------------" << endl;
			cout <<   "| Withdrawing |" << endl;
			cout <<   "---------------" << endl;
			withdraw();
			break;

		case 6:
			cout << "\n----------------------------" << endl;
			cout <<   "| Generating Ministatement |" << endl;
			cout <<   "----------------------------" << endl;
			generateMiniStatment();
			break;

		case 7:
			cout << "\n----------------------------------" << endl;
			cout <<   "| Generating Transaction History |" << endl;
			cout <<   "----------------------------------" << endl;
			generateTransactionHistory();
			break;

		case 8:
			cout << "\n-------------------" << endl;
			cout <<   "| Getting Balance |" << endl;
			cout <<   "-------------------" << endl;
			getBalance();
			break;

		case 9:
			cout << "\n-------------------------" << endl;
			cout <<   "| Getting Accout Number |" << endl;
			cout <<   "-------------------------" << endl;
			getAccountNumber();
			break;

		case 10:
			cout << "\n------------------" << endl;
			cout <<   "| Getting Points |" << endl;
			cout <<   "------------------" << endl;
			getPoints();
			break;

		case 11:
			cout << "\n------------------" << endl;
			cout <<   "| Exiting System |" << endl;
			cout <<   "------------------" << endl;
			return;
			break;


		default:
			cout << "\n------------------" << endl;
			cout <<   "| Invalid Option |" << endl;
			cout <<   "------------------" << endl;
		}
	}
}

string Bank :: getBankName() const {
	return m_BankName;
}

void Bank :: doubleAccountCapacity() {
	Bank temp = *this;

	m_AccountCapacity *= 2;
	delete m_AccountHolders;
	m_AccountHolders = new AccountHolder[m_AccountCapacity];

	for ( int i = 0; i < temp.m_AccountCapacity; ++i ) {
		m_AccountHolders[i] = temp.m_AccountHolders[i];
	}
}

