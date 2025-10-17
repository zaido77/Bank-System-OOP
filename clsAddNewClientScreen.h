#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsAddNewClientScreen : protected clsScreen
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
		
	static void _ReadClientInfo(clsBankClient& Client)
	{
		Client.SetFirstName(clsInputValidate::ReadString("\nEnter First Name: "));
		Client.SetLastName(clsInputValidate::ReadString ("Enter Last Name: "));
		Client.SetEmail(clsInputValidate::ReadString("Enter Email: "));
		Client.SetPhone(clsInputValidate::ReadString("Enter Phone: "));
		Client.SetPinCode(clsInputValidate::ReadString("Enter Pin Code: "));

		cout << "Enter Account Balance: ";
		Client.SetAccountBalance(clsInputValidate::ReadPositiveNumber<float>("Balance is not positive, Enter again: "));
	}

public:
    static void ShowAddNewClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;
        }

        _DrawScreenHeader("\tAdd New Client Screen");

        string AccountNumber = clsInputValidate::ReadString("\nPlease Enter Account Number: ");
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            string Message = "Account Number Is Already Used, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString(Message);
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
            cout << "\nAccount Added Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        case clsBankClient::enSaveResults::svFailedEmptyObject:
            cout << "\nError account was not saved because it's Empty\n";
            break;

        case clsBankClient::enSaveResults::svFailedAccountNumberExists:
            cout << "\nError account was not saved because account number is used!\n";
            break;
        }
    }
};

