#pragma once

#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsUpdateUserScreen : protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n__________________________________\n";
        cout << "\nFirstName      : " << User.GetFirstName();
        cout << "\nLastName       : " << User.GetLastName();
        cout << "\nFull Name      : " << User.GetFullName();
        cout << "\nEmail          : " << User.GetEmail();
        cout << "\nPhone          : " << User.GetPhone();
        cout << "\nUser Name      : " << User.GetUsername();
        cout << "\nPassword       : " << User.GetPassword();
        cout << "\nPermissions    : " << User.GetPermissions();
        cout << "\n__________________________________\n";
    }

    static short _ReadPermissionsToSet()
    {
        char Answer = 'n';
        cout << "Do you want to give full access? [y/n]? ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
            return clsUser::enPermissions::pAll;

        short Permissions = 0;

        cout << "\nDo you want to give access to:\n";

        cout << "\nShow Clients List? [y/n]? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions += clsUser::enPermissions::pListClients;

        cout << "\nAdd New Client? [y/n]? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions += clsUser::enPermissions::pAddNewClient;

        cout << "\nDelete Client? [y/n]? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions += clsUser::enPermissions::pDeleteClient;

        cout << "\nUpdate Client? [y/n]? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions += clsUser::enPermissions::pUpdateClient;

        cout << "\nFind Client? [y/n]? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions += clsUser::enPermissions::pFindClient;

        cout << "\nTransactions? [y/n]? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions += clsUser::enPermissions::pTransactions;

        cout << "\nManage Users? [y/n]? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions += clsUser::enPermissions::pManageUsers;

        cout << "\nLogin Register? [y/n]? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions += clsUser::enPermissions::pLoginRegister;

        cout << "\nUpdate Currency Rate? [y/n]? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions += clsUser::enPermissions::pUpdateCurrencyRate;

        return Permissions;
    }

    static void _ReadUserInfo(clsUser& User)
    {
        User.SetFirstName(clsInputValidate::ReadString("\nEnter First Name: "));
        User.SetLastName(clsInputValidate::ReadString("Enter Last Name: "));
        User.SetEmail(clsInputValidate::ReadString("Enter Email: "));
        User.SetPhone(clsInputValidate::ReadString("Enter Phone: "));
        User.SetPassword(clsInputValidate::ReadString("Enter Password: "));

        cout << "\nEnter Permissions:\n";
        User.SetPermissions(_ReadPermissionsToSet());
    }

public:
    static void ShowUpdateUserScreen()
    {
        _DrawScreenHeader("\t  Update User Screen");

        string UserName = clsInputValidate::ReadString("\nPlease Enter User Name: ");

        while (!clsUser::IsUserExist(UserName))
        {
            string Message = "User Name Is Not Found, Choose another one: ";
            UserName = clsInputValidate::ReadString(Message);
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);

        cout << "\nAre you sure you want to update this user? [y/n]? ";
        char Answer = 'Y';
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";
            _ReadUserInfo(User);

            clsUser::enSaveResults SaveResult;
            SaveResult = User.Save();

            switch (SaveResult)
            {
            case clsUser::enSaveResults::svSucceeded:
                cout << "\nUser Updated Successfully\n";
                _PrintUser(User);
                break;
            case clsUser::enSaveResults::svFailedEmptyObject:
                cout << "\nError: User was not saved because it's Empty";
                break;
            }
        }
    }

};

