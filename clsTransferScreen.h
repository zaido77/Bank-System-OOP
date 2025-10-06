#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;

class clsTransferScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n__________________________________\n";
		cout << "\nFull Name      : " << Client.GetFullName();
		cout << "\nAccount Number : " << Client.GetAccountNumber();
		cout << "\nAccount Balance: " << Client.GetAccountBalance();
		cout << "\n__________________________________\n";
	}

	static string _ReadAccountNumber(string Message)
	{
		string AccountNumber = clsInputValidate::ReadString(Message);

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with Account Number [" << AccountNumber << "] does not exist.\n";
			AccountNumber = clsInputValidate::ReadString(Message);
		}

		return AccountNumber;
	}

	static float ReadAmount(clsBankClient SourceClient)
	{
		cout << "\nEnter Transfer Amount: ";
		float Amount = clsInputValidate::ReadPositiveFloatNumber();

		while (Amount > SourceClient.GetAccountBalance())
		{
			cout << "Amount Exceeds the available Balance, Enter another Amount: ";
			Amount = clsInputValidate::ReadPositiveFloatNumber();
		}

		return Amount;
	}

public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t    Transfer Screen");

		string AccountNumber = _ReadAccountNumber("\nEnter Account Number to Transfer From: ");
		clsBankClient SourceClient = clsBankClient::Find(AccountNumber);
		_PrintClient(SourceClient);


		AccountNumber = _ReadAccountNumber("\nEnter Account Number to Transfer To: ");
		while (AccountNumber == SourceClient.GetAccountNumber())
		{
			AccountNumber = _ReadAccountNumber("\nClient cannot transfer to himself, Enter another Account Number: ");
		}
		clsBankClient DestinationClient = clsBankClient::Find(AccountNumber);
		_PrintClient(DestinationClient);
		

		float Amount = ReadAmount(SourceClient);

		char Answer = 'n';
		cout << "\nAre you sure you want to perform this operation? [y/n]? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient))
			{
				cout << "\nTransfer Done Succesfully!\n";
			}
			else
			{
				cout << "\nTransfer Failed\n";
			}

			_PrintClient(SourceClient);
			_PrintClient(DestinationClient);
		}
		
	}

};