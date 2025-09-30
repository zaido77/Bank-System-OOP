#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;

class clsUsersListScreen : protected clsScreen
{
private:
    static void _PrintUserRecordLine(clsUser User)
    {
        cout << setw(8) << left << "";
        cout << "| " << setw(12) << User.GetUsername();
        cout << "| " << setw(20) << User.GetFullName();
        cout << "| " << setw(12) << User.GetPhone();
        cout << "| " << setw(20) << User.GetEmail();
        cout << "| " << setw(9) << User.GetPassword();
        cout << "| " << setw(12) << User.GetPermissions();
        cout << "\n";
    }

public:
    static void ShowUsersList()
    {
        vector<clsUser> vUsers = clsUser::GetUsersList();

        string Title = "\t  Users List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n";
        cout << setw(8) << left << "";
        cout << "________________________________________________________________________________________________\n\n";

        cout << setw(8) << left << "";
        cout << "| " << setw(12) << "User Name";
        cout << "| " << setw(20) << "Full Name";
        cout << "| " << setw(12) << "Phone";
        cout << "| " << setw(20) << "Email";
        cout << "| " << setw(9) << "Password";
        cout << "| " << setw(12) << "Permissions";

        cout << "\n";
        cout << setw(8) << left << "";
        cout << "________________________________________________________________________________________________\n\n";

        if (vUsers.size() == 0)
        {
            cout << clsUtil::Tabs(5) << "(No Users Available in the System)\n";
        }
        else
        {
            for (clsUser& User : vUsers)
            {
                _PrintUserRecordLine(User);
            }
        }

        cout << setw(8) << left << "";
        cout << "________________________________________________________________________________________________\n\n";
    }

};