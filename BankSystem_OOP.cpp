#pragma warning(disable : 4996) // ctime()

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip> //setw
#include <vector>  // vector
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
    Client.SetAccountBalance(clsInputValidate::ReadPositiveDblNumber("Balance is not positive, Enter again: "));
}

void UpdateClient()
{
    vector<clsBankClient> vClients = clsBankClient::LoadClientsDataFromFile();

    string AccountNumber = clsInputValidate::ReadString("Enter Account Number To Update: ");
    clsBankClient Client = clsBankClient::Find(AccountNumber);
    
    while (Client.IsEmpty())
    {
        AccountNumber = clsInputValidate::ReadString("Account Number is not found, choose another one: ");
        Client = clsBankClient::Find(AccountNumber);
    }
    
    Client.Print();

    cout << "\n\nUpdate Client Info:\n";
    cout << "\n___________________\n\n";
    ReadClientInfo(Client);

    Client.Update(vClients);
    clsBankClient::SaveClientsDataToFile(vClients);
    cout << "\nAccount Updated Succesfully!\n";

    Client.Print();

}

int main()
{
    UpdateClient(); 

    return 0;
}