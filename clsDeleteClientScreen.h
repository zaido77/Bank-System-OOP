#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsDeleteClientScreen : protected clsScreen
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
    static void ShowDeleteClientScreen()
    {
        _DrawScreenHeader("\t  Delete Client Screen");

        string AccountNumber = clsInputValidate::ReadString("\nPlease Enter Account Number: ");
        
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            string Message = "Account Number Is Not Found, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString(Message);
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        cout << "\nAre you sure you want to delete this client? [y/n]? ";
        char Answer = 'Y';
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (Client.Delete())
            {
                cout << "\nClient Deleted Succesfully\n";
                _PrintClient(Client);
            }
            else
            {
                cout << "\nError: Client was not Deleted\n";
            }
        }
    }

};

