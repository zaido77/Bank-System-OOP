#pragma once

#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUsersListScreen.h"
using namespace std;

class clsManageUsersScreen : protected clsScreen
{
private:
    enum enManageUsersMenuOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenu = 6,
    };

    static void _GoBackToManageUsersMenu()
    {
        cout << "\nPress any key to go back to Manage Users Menu..." << endl;
        system("pause>0");
        ShowManageUsersMenu();
    }

    static short _ReadManageUsersMenuOption()
    {
        cout << setw(37) << "" << "Choose what do you want to do [1 to 6]? ";
        return clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
    }

    static void _ShowListUsersScreen()
    {
        clsUsersListScreen::ShowUsersList();
    }

    static void _ShowAddNewUserScreen()
    {
        cout << "Here will be add new user screen" << endl;
    }

    static void _ShowDeleteUserScreen()
    {
        cout << "Here will be Delete user screen" << endl;
    }

    static void _ShowUpdateUserScreen()
    {
        cout << "Here will be Update user screen" << endl;
    }

    static void _ShowFindUserScreen()
    {
        cout << "Here will be Find user screen" << endl;
    }

    static void _PerformManageUsersMenuOption(enManageUsersMenuOptions ManageUsersMenuOption)
    {
        switch (ManageUsersMenuOption)
        {
        case enManageUsersMenuOptions::eListUsers:
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenu();
            break;

        case enManageUsersMenuOptions::eAddNewUser:
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenu();
            break;

        case enManageUsersMenuOptions::eDeleteUser:
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenu();
            break;

        case enManageUsersMenuOptions::eUpdateUser:
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenu();
            break;

        case enManageUsersMenuOptions::eFindUser:
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsersMenu();
            break;

        case enManageUsersMenuOptions::eMainMenu:
            break;

        }
    }

public:
	static void ShowManageUsersMenu()
	{
        system("cls");
        _DrawScreenHeader("\t  Manage Users Screen");

        cout << setw(37) << "" << "===========================================\n";
        cout << setw(37) << "" << "             Manage Users Menue\n";
        cout << setw(37) << "" << "===========================================\n";
        cout << setw(37) << "" << "   [1] List Users.\n";
        cout << setw(37) << "" << "   [2] Add New User.\n";
        cout << setw(37) << "" << "   [3] Delete User.\n";
        cout << setw(37) << "" << "   [4] Update User Info.\n";
        cout << setw(37) << "" << "   [5] Find User.\n";
        cout << setw(37) << "" << "   [6] Main Menu\n";
        cout << setw(37) << "" << "===========================================\n";

        _PerformManageUsersMenuOption((enManageUsersMenuOptions)_ReadManageUsersMenuOption());
	}

};

