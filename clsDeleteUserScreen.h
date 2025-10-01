#pragma once

#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsDeleteUserScreen : protected clsScreen
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
    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("\t  Delete User Screen");

        string UserName = clsInputValidate::ReadString("\nPlease Enter User Name: ");

        while (!clsUser::IsUserExist(UserName))
        {
            string Message = "User Name Is Not Found, Choose another one: ";
            UserName = clsInputValidate::ReadString(Message);
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);

        cout << "\nAre you sure you want to delete this user? [y/n]? ";
        char Answer = 'Y';
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (User.Delete())
            {
                cout << "\nUser Deleted Succesfully\n";
                _PrintUser(User);
            }
            else
            {
                cout << "\nError: User was not Deleted\n";
            }
        }
    }

};

