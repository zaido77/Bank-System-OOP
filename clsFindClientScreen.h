#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindClientScreen : protected clsScreen
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

public:
    static void ShowFindClientScreen()
    {
        _DrawScreenHeader("\t  Find Client Screen");

        string AccountNumber = clsInputValidate::ReadString("\nPlease Enter Account Number: ");

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            string Message = "Account Number Is Not Found, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString(Message);
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        if (!Client.IsEmpty())
        {
            cout << "\nClient Found!\n";
            _PrintClient(Client);
        }
        else
        {
            cout << "\nClient was not found!\n";
        }

    }

};

