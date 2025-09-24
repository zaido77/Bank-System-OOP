#pragma warning(disable : 4996) // ctime()

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>  // to is upper, lower, digit, punct
#include <fstream> // Files
#include "clsBankClient.h"
#include "C:/Users/User/source/repos/Testing/Testing/clsInputValidate.h"
#include "C:/Users/User/source/repos/Testing/Testing/clsUtil.h"
using namespace std;

void PrintClientRecordLine(clsBankClient Client)
{
    cout << left;
    cout << "| " << setw(15) << Client.GetAccountNumber();
    cout << "| " << setw(20) << Client.GetFullName();
    cout << "| " << setw(12) << Client.GetPhone();
    cout << "| " << setw(20) << Client.GetEmail();
    cout << "| " << setw(10) << Client.GetPinCode();
    cout << "| " << setw(12) << Client.GetAccountBalance();

    cout << "\n";
}

void ShowClientsList()
{
    vector<clsBankClient> vClients = clsBankClient::GetClientsList();

    cout << clsUtil::Tabs(4) << "Client List (" << vClients.size() << ") Clients.\n";
    cout << "____________________________________________________________________________________________\n\n";

    cout << left;
    cout << "| " << setw(15) << "Account Number";
    cout << "| " << setw(20) << "Client Name";
    cout << "| " << setw(12) << "Phone";
    cout << "| " << setw(20) << "Email";
    cout << "| " << setw(10) << "Pin Code";
    cout << "| " << setw(12) << "Balance";

    cout << "\n____________________________________________________________________________________________\n\n";

    if (vClients.size() == 0)
    {
        cout << clsUtil::Tabs(4) << "(No Clients Available in the System)\n";
    }
    else
    {
        for (clsBankClient& Client : vClients)
        {
            PrintClientRecordLine(Client);
        }
    }

    cout << "____________________________________________________________________________________________\n\n";
    
}

int main()
{
    ShowClientsList();

    return 0;
}