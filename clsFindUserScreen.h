#pragma once

#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindUserScreen : protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n__________________________________\n";
        cout << "\nFirst Name     : " << User.GetFirstName();
        cout << "\nLast Name      : " << User.GetLastName();
        cout << "\nFull Name      : " << User.GetFullName();
        cout << "\nEmail          : " << User.GetEmail();
        cout << "\nPhone          : " << User.GetPhone();
        cout << "\nUser Name      : " << User.GetUsername();
        cout << "\nPassword       : " << User.GetPassword();
        cout << "\nPermissions    : " << User.GetPermissions();
        cout << "\n__________________________________\n";
    }

public:
    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\t  Find User Screen");

        string UserName = clsInputValidate::ReadString("\nPlease Enter User Name: ");

        while (!clsUser::IsUserExist(UserName))
        {
            string Message = "User Name Is Not Found, Choose another one: ";
            UserName = clsInputValidate::ReadString(Message);
        }

        clsUser User = clsUser::Find(UserName);

        if (!User.IsEmpty())
        {
            cout << "\nUser Found!\n";
            _PrintUser(User);
        }
        else
        {
            cout << "\nUser was not found!\n";
        }

    }

};

