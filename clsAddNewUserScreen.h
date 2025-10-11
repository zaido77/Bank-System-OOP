#pragma once

#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsAddNewUserScreen : protected clsScreen
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

        cout << "\nCurrency Exchange? [y/n]? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
            Permissions += clsUser::enPermissions::pCurrencyExchange;
        
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
    static void ShowAddNewUserScreen()
    {
        _DrawScreenHeader("\tAdd New User Screen");

        string UserName = clsInputValidate::ReadString("\nPlease Enter User Name: ");
        while (clsUser::IsUserExist(UserName))
        {
            string Message = "User Name Is Already Used, Choose another one: ";
            UserName = clsInputValidate::ReadString(Message);
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);
        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case  clsUser::enSaveResults::svSucceeded:
            cout << "\nUser Added Successfully :-)\n";
            _PrintUser(NewUser);
            break;
        case clsUser::enSaveResults::svFailedEmptyObject:
            cout << "\nError User was not saved because it's Empty\n";
            break;

        case clsUser::enSaveResults::svFailedUserExists:
            cout << "\nError User was not saved because User Name is used!\n";
            break;
        }
    }
};
