#pragma warning(disable : 4996) // ctime()

#include <iostream>
#include <string>
#include <cctype>  // to is upper, lower, digit, punct
#include <fstream> // Files
#include "clsBankClient.h"
#include "C:/Users/User/source/repos/Testing/Testing/clsInputValidate.h"
using namespace std;

void ReadClientInfo(clsBankClient& Client)
{
    Client.SetFirstName(clsInputValidate::ReadString("Enter First Name: "));
    Client.SetLastName(clsInputValidate::ReadString("Enter Last Name: "));
    Client.SetEmail(clsInputValidate::ReadString("Enter Email: "));
    Client.SetPhone(clsInputValidate::ReadString("Enter Phone: "));
    Client.SetPinCode(clsInputValidate::ReadString("Enter Pin Code: "));

    cout << "Enter Account Balance: ";
    Client.SetAccountBalance(clsInputValidate::ReadPositiveFloatNumber("Balance is not positive, Enter again: "));
}

void AddNewClient()
{
    clsBankClient Client;

    cout << "Adding New Client" << endl;
    cout << "_________________" << endl;
    ReadClientInfo(Client);

    clsBankClient::enSaveResult SaveResult;
    SaveResult = Client.Save();

    switch (SaveResult)
    {
    case clsBankClient::enSaveResult::svFailedEmptyObject:
        cout << "Account not saved because it is empty!" << endl;
        break;
    case clsBankClient::enSaveResult::svUpdateSucceeded:
        cout << "Account Updated Succesfully!" << endl;
        break;
    case clsBankClient::enSaveResult::svAddSucceeded:
        cout << "Account Added Succesfully!" << endl;
        break;
    }
    
}

int main()
{
    AddNewClient();
   

    return 0;
}