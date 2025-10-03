#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsUpdateClientScreen : protected clsScreen
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
        Client.SetLastName(clsInputValidate::ReadString("Enter Last Name: "));
        Client.SetEmail(clsInputValidate::ReadString("Enter Email: "));
        Client.SetPhone(clsInputValidate::ReadString("Enter Phone: "));
        Client.SetPinCode(clsInputValidate::ReadString("Enter Pin Code: "));

        cout << "Enter Account Balance: ";
        Client.SetAccountBalance(clsInputValidate::ReadPositiveFloatNumber("Balance is not positive, Enter again: "));
    }

public:
    static void ShowUpdateClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClient))
        {
            return;
        }

        _DrawScreenHeader("\t  Update Client Screen");

        string AccountNumber = clsInputValidate::ReadString("\nPlease Enter Account Number: ");

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            string Message = "Account Number Is Not Found, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString(Message);
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        cout << "\nAre you sure you want to update this client? [y/n]? ";
        char Answer = 'Y';
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";
            _ReadClientInfo(Client);

            clsBankClient::enSaveResults SaveResult;
            SaveResult = Client.Save();

            switch (SaveResult)
            {
            case clsBankClient::enSaveResults::svSucceeded:
                cout << "\nAccount Updated Successfully\n";
                _PrintClient(Client);
                break;
            case clsBankClient::enSaveResults::svFailedEmptyObject:
                cout << "\nError: Account was not saved because it's Empty";
                break;
            }
        }
    }

};

