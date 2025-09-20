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

void UpdateClient()
{
    string AccountNumber = clsInputValidate::ReadString("Please enter Account Number: ");

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        AccountNumber = clsInputValidate::ReadString("Account Number not found, choose anoter one: ");
    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);
    Client.Print();

    cout << "\nUpdate Client Info:";
    cout << "\n___________________\n";
    ReadClientInfo(Client);

    clsBankClient::enSaveResult SaveResult;

    SaveResult = Client.Save();

    switch (SaveResult)
    {
    case clsBankClient::enSaveResult::svSucceeded:
        cout << "\nAccount Updated Successfully\n";
        Client.Print();
        break;
    case clsBankClient::enSaveResult::svFailedEmptyObject:
        cout << "\nError: Account was not saved because it's Empty";
        break;
    }
}

int main()
{
    UpdateClient();

    return 0;
}