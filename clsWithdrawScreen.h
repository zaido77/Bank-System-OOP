#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;

class clsWithdrawScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n__________________________________\n";
		cout << "\nFirstName      : " << Client.GetFirstName();
		cout << "\nLastName       : " << Client.GetLastName();
		cout << "\nFull Name      : " << Client.GetFullName();
		cout << "\nEmail          : " << Client.GetEmail();
		cout << "\nPhone          : " << Client.GetPhone();
		cout << "\nAccount Number : " << Client.GetAccountNumber();
		cout << "\nPin Code       : " << Client.GetPinCode();
		cout << "\nAccount Balance: " << Client.GetAccountBalance();
		cout << "\n__________________________________\n";
	}

	static string _ReadAccountNumber()
	{
		return clsInputValidate::ReadString("\nPlease Enter Account Number: ");
	}

public:

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t    Withdraw Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with Account Number [" << AccountNumber << "] does not exist.\n";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		float Amount = 0;
		cout << "\nPlease enter withdraw amount? ";
		Amount = clsInputValidate::ReadPositiveFloatNumber();
		//Amount = clsInputValidate::ReadDblNumberBetween(1, Client.GetAccountBalance());

		cout << "\nAre you sure you want to perform this transaction? [y/n]? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (Client.Withdraw(Amount))
			{
				cout << "\nAmount Withdrew Successfully!\n";
				cout << "\nNew Balance Is: " << Client.GetAccountBalance() << "\n";
			}
			else
			{
				cout << "\nCannot withdraw, Insuffecient Balance!\n";
				cout << "\nAmount to withdraw is: " << Amount;
				cout << "\nYour Balance is: " << Client.GetAccountBalance() << "\n";
			}

		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}


	}

};

