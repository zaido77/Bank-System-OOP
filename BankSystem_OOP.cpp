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

void DeleteClient()
{
    string AccountNumber = clsInputValidate::ReadString("Please enter Account Number: ");

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        string ErrorMessage = "Account Number not exist, choose anoter one: ";
        AccountNumber = clsInputValidate::ReadString(ErrorMessage);
    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);
    Client.Print();

    char Answer = 'Y';
    cout << "Are you sure you want to delete this client? [y/n]? ";
    cin >> Answer;

    if (toupper(Answer) == 'Y')
    {
        clsBankClient::enSaveResult SaveResult;
        SaveResult = Client.Delete();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResult::svSucceeded:
            cout << "Account Deleted Successfully!" << endl;
            Client.Print();
            break;
        case clsBankClient::enSaveResult::svFailedEmptyObject:
            cout << "Error: Failed to save because account is empty" << endl;
            break;
        case clsBankClient::enSaveResult::svFailedAccountNumberExists:
            cout << "Error: Failed to save because account number exist!" << endl;
            break;
        }
    }
    else
    {
        return;
    }
}

int main()
{
    DeleteClient();

    return 0;
}