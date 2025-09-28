#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{
private:
	static void _PrintClientRecordBalanceLine(clsBankClient Client)
	{
		cout << setw(12) << left << "";
		cout << "| " << setw(25) << Client.GetAccountNumber();
		cout << "| " << setw(40) << Client.GetFullName();
		cout << "| " << setw(12) << Client.GetAccountBalance();
		cout << "\n";
	}

public:
    static void ShowTotalBalancesList()
    {
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t  Balances List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);
    
        cout << "\n";
        cout << setw(12) << left << "";
        cout << "____________________________________________________________________________________________\n\n";

        cout << setw(12) << left << "";
        cout << "| " << setw(25) << "Account Number";
        cout << "| " << setw(40) << "Client Name";
        cout << "| " << setw(12) << "Balance";

        cout << "\n";
        cout << setw(12) << left << "";
        cout << "____________________________________________________________________________________________\n\n";

        if (vClients.size() == 0)
        {
            cout << clsUtil::Tabs(5) << "(No Clients Available in the System)\n";
        }
        else
        {
            for (clsBankClient& Client : vClients)
            {
                _PrintClientRecordBalanceLine(Client);
            }
        }

        cout << setw(12) << left << "";
        cout << "____________________________________________________________________________________________\n\n";

        float TotalBalances = clsBankClient::GetTotalBalances();

        cout << setw(12) << left << "";
        cout << clsUtil::Tabs(7) << "  Total Balances = " << TotalBalances << "\n";
        
        cout << setw(12) << left << "";
        cout << clsUtil::Tabs(4) << "( " << clsUtil::NumberToText(TotalBalances) << ")\n\n";

    }

};

