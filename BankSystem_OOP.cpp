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
    string AccountNumber = clsInputValidate::ReadString("Please enter Account Number: ");

    while (clsBankClient::IsClientExist(AccountNumber))
    {
        string ErrorMessage = "Client with Account Number [" + AccountNumber + "] exist, choose anoter one: ";
        AccountNumber = clsInputValidate::ReadString(ErrorMessage);
    }

    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

    cout << "Adding new Client:" << endl;
    cout << "__________________" << endl;
    ReadClientInfo(NewClient);

    clsBankClient::enSaveResult SaveResult;
    SaveResult = NewClient.Save();

    switch (SaveResult)
    {
    case clsBankClient::enSaveResult::svSucceeded:
        cout << "Account Added Successfully!" << endl;
        NewClient.Print();  
        break;  
    case clsBankClient::enSaveResult::svFailedEmptyObject:
        cout << "Error: Failed to save because account is empty" << endl;
        break;
    case clsBankClient::enSaveResult::svFailedAccountNumberExists:
        cout << "Error: Failed to save because account number exist!" << endl;
        break;
    }
}

int main()
{
    AddNewClient();

    return 0;
}