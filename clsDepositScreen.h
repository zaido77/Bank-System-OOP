#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;

class clsDepositScreen : protected clsScreen
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

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t    Deposit Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with Account Number [" << AccountNumber << "] does not exist.\n";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		float Amount = 0;
		cout << "\nPlease enter deposit amount? ";
		Amount = clsInputValidate::ReadPositiveFloatNumber();

		cout << "\nAre you sure you want to perform this transaction? [y/n]? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			Client.Deposit(Amount);
			cout << "\nAmount Deposited Successfully.\n";
			cout << "\nNew Balance Is: " << Client.GetAccountBalance() << "\n";

		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}


	}

};

