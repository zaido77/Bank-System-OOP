#pragma warning(disable : 4996) // ctime()

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>  // to is upper, lower, digit, punct
#include <fstream> // Files
#include "clsBankClient.h"
#include "clsUtil.h"
using namespace std;

void PrintClientRecordBalanceLine(clsBankClient Client)
{
    cout << left;
    cout << "| " << setw(15) << Client.GetAccountNumber();
    cout << "| " << setw(20) << Client.GetFullName();
    cout << "| " << setw(12) << Client.GetAccountBalance();

    cout << "\n";
}

void ShowTotalBalancesList()
{
    vector<clsBankClient> vClients = clsBankClient::GetClientsList();

    cout << clsUtil::Tabs(4) << "Balances List (" << vClients.size() << ") Clients.\n";
    cout << "____________________________________________________________________________________________\n\n";

    cout << left;
    cout << "| " << setw(15) << "Account Number";
    cout << "| " << setw(20) << "Client Name";
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
            PrintClientRecordBalanceLine(Client);
        }
    }

    cout << "____________________________________________________________________________________________\n\n";
 
    float TotalBalances = clsBankClient::GetTotalBalances();

    cout << clsUtil::Tabs(4) << "Total Balances = " << TotalBalances << "\n";
    cout << clsUtil::Tabs(3) << "( " << clsUtil::NumberToText(TotalBalances) << ")\n\n";

}

int main()
{
    ShowTotalBalancesList();

    return 0;
}