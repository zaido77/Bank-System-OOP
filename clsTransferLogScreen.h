#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;

class clsTransferLogScreen : protected clsScreen
{
private:
	static void _PrintTransferLogRecord(clsBankClient::stTranferLogRecord TranferLogRecord)
	{
		cout << setw(8) << left << "";
		cout << "| " << setw(22) << TranferLogRecord.DateTime;
		cout << "| " << setw(8) << TranferLogRecord.SourceAccNumber;
		cout << "| " << setw(8) << TranferLogRecord.DestinationAccNumber;
		cout << "| " << setw(10) << TranferLogRecord.Amount;
		cout << "| " << setw(10) << TranferLogRecord.SourceAccBalance;
		cout << "| " << setw(10) << TranferLogRecord.DestinationAccBalance;
		cout << "| " << setw(10) << TranferLogRecord.UserName;
		cout << "\n";
	}

public:
	static void ShowTransferLogScreen()
	{
        vector<clsBankClient::stTranferLogRecord> vTransferLogRecords = clsBankClient::GetTranferLogList();

        string Title = "      Transfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vTransferLogRecords.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n";
        cout << setw(8) << left << "";
        cout << "________________________________________________________________________________________________\n\n";

        cout << setw(8) << left << "";
        cout << "| " << setw(22) << "Date/Time";
		cout << "| " << setw(8) << "S.Acct";
		cout << "| " << setw(8) << "D.Acct";
		cout << "| " << setw(10) << "Amount";
		cout << "| " << setw(10) << "S.Balance";
		cout << "| " << setw(10) << "D.Balance";
		cout << "| " << setw(10) << "User";

        cout << "\n";
        cout << setw(8) << left << "";
        cout << "________________________________________________________________________________________________\n\n";

        if (vTransferLogRecords.size() == 0)
        {
            cout << clsUtil::Tabs(5) << "(No Trasnfers Available in the System)\n";
        }
        else
        {
            for (const clsBankClient::stTranferLogRecord& TransferLogRecord : vTransferLogRecords)
            {
                _PrintTransferLogRecord(TransferLogRecord);
            }
        }

        cout << setw(8) << left << "";
        cout << "________________________________________________________________________________________________\n\n";

	}
};

