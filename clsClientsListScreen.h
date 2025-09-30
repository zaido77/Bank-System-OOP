#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtil.h"
using namespace std;

class clsClientsListScreen : protected clsScreen
{
private:
	static void _PrintClientRecordLine(clsBankClient Client)
	{
		cout << setw(8) << left << "";
		cout << "| " << setw(15) << Client.GetAccountNumber();
		cout << "| " << setw(20) << Client.GetFullName();
		cout << "| " << setw(12) << Client.GetPhone();
		cout << "| " << setw(20) << Client.GetEmail();
		cout << "| " << setw(10) << Client.GetPinCode();
		cout << "| " << setw(12) << Client.GetAccountBalance();
		cout << "\n";
	}

public:
	static void ShowClientsList()
	{
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t  Clients List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);
        
        cout << "\n";
        cout << setw(8) << left << "";
        cout << "________________________________________________________________________________________________\n\n";

        cout << setw(8) << left << "";
        cout << "| " << setw(15) << "Account Number";
        cout << "| " << setw(20) << "Client Name";
        cout << "| " << setw(12) << "Phone";
        cout << "| " << setw(20) << "Email";
        cout << "| " << setw(10) << "Pin Code";
        cout << "| " << setw(12) << "Balance";

        cout << "\n";
        cout << setw(8) << left << "";
        cout << "________________________________________________________________________________________________\n\n";

        if (vClients.size() == 0)
        {
            cout << clsUtil::Tabs(5) << "(No Clients Available in the System)\n";
        }
        else
        {
            for (clsBankClient& Client : vClients)
            {
                _PrintClientRecordLine(Client);
            }
        }

        cout << setw(8) << left << "";
        cout << "________________________________________________________________________________________________\n\n";
    }

};