#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include "clsUser.h"
#include "clsScreen.h"
using namespace std;

class clsLoginRegisterScreen : protected clsScreen
{
private:
	static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
	{
		cout << setw(8) << left << "";
		cout << "| " << setw(35) << LoginRegisterRecord.DateTime;
		cout << "| " << setw(20) << LoginRegisterRecord.UserName;
		cout << "| " << setw(20) << LoginRegisterRecord.Password;
		cout << "| " << setw(10) << LoginRegisterRecord.Permissions;
		cout << "\n";
	}

public:
	static void ShowLoginRegisterScreen()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
        {
            return;
        }

        vector<clsUser::stLoginRegisterRecord> vLoginRegisterRecords = clsUser::GetLoginRegisterList();

        string Title = "      Login Register List Screen";
        string SubTitle = "\t    (" + to_string(vLoginRegisterRecords.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        clsUtil::ColorScreen(CurrentUser.Preferences.ScreenColors.Tables());
        cout << "\n";
        cout << setw(8) << left << "";
        cout << "________________________________________________________________________________________________\n\n";

        cout << setw(8) << left << "";
        cout << "| " << setw(35) << "Date/Time";
        cout << "| " << setw(20) << "User Name";
        cout << "| " << setw(20) << "Password";
        cout << "| " << setw(10) << "Permissions";

        cout << "\n";
        cout << setw(8) << left << "";
        cout << "________________________________________________________________________________________________\n\n";
        clsUtil::ColorScreen();

        if (vLoginRegisterRecords.size() == 0)
        {
            cout << clsUtil::Tabs(5) << "(No Logins Available in the System)\n";
        }
        else
        {
            for (const clsUser::stLoginRegisterRecord& LoginRegisterRecord : vLoginRegisterRecords)
            {
                _PrintLoginRegisterRecordLine(LoginRegisterRecord);
            }
        }

        clsUtil::ColorScreen(CurrentUser.Preferences.ScreenColors.Tables());
        cout << setw(8) << left << "";
        cout << "________________________________________________________________________________________________\n\n";
        clsUtil::ColorScreen();

	}
};

