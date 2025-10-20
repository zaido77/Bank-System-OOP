#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsClientsListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeScreen.h"
#include "clsSettingsScreen.h"
#include "Global.h"
using namespace std;

class clsMainScreen : protected clsScreen
{
private:
    enum enMainMenuOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9,
        eSettings = 10, eExit = 11
    };

    static short _ReadMainMenuOption()
    {
        cout << setw(37) << "" << "Choose what do you want to do [1 to 11]? ";
        return clsInputValidate::ReadNumberBetween<short>(1, 11, "Enter Number between 1 to 11? ");
    }

    static void _GoBackToMainMenu()
    {
        cout << "\nPress any key to go back to Main Menu..." << endl;
        system("pause>0");
        ShowMainMenu();
    }

    static void _ShowAllClientsScreen()
    {
        clsClientsListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenu()
    {
        clsTransactionsScreen::ShowTransactionsMenu();
    }

    static void _ShowManageUsersMenu()
    {
        clsManageUsersScreen::ShowManageUsersMenu();
    }

    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _ShowCurrencyExchangeMenu()
    {
        clsCurrencyExchangeScreen::ShowCurrencyExchangeMenu();
    }

    static void _ShowSettingsScreen()
    {
        clsSettingsScreen::ShowSettingsScreen();
    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
    }

    static void _PerformMainMenuOption(enMainMenuOptions MainMenuOption)
    {
        switch (MainMenuOption)
        {
        case enMainMenuOptions::eListClients:
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenu();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenu();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eLoginRegister:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenu();
            break;

        case  enMainMenuOptions::eCurrencyExchange:
            system("cls");
            _ShowCurrencyExchangeMenu();
            _GoBackToMainMenu();
            break;
        case enMainMenuOptions::eSettings:
            system("cls");
            _ShowSettingsScreen();
            _GoBackToMainMenu();
            break;

        case enMainMenuOptions::eExit:
            system("cls");
            _Logout();
            break;
        }
    }

public:
    static void ShowMainMenu()
    {
        system("cls");
        _DrawScreenHeader("\t     Main Screen");

        clsUtil::ColorScreen(CurrentUser.Preferences.ScreenColors.MenusBorders());
        cout << setw(37) << "" << "===========================================\n";
        cout << setw(37) << "" << "                 Main Menu\n";
        cout << setw(37) << "" << "===========================================\n";
        clsUtil::ColorScreen(CurrentUser.Preferences.ScreenColors.MenusOptions());
        cout << setw(37) << "" << "   [1] Show Clients List.\n";
        cout << setw(37) << "" << "   [2] Add New Client.\n";
        cout << setw(37) << "" << "   [3] Delete Client.\n";
        cout << setw(37) << "" << "   [4] Update Client Info.\n";
        cout << setw(37) << "" << "   [5] Find Client.\n";
        cout << setw(37) << "" << "   [6] Transactions.\n";
        cout << setw(37) << "" << "   [7] Manage Users.\n";
        cout << setw(37) << "" << "   [8] Login Register.\n";
        cout << setw(37) << "" << "   [9] Currency Exchange.\n";
        cout << setw(37) << "" << "   [10] Settings.\n";
        clsUtil::ColorScreen(clsUtil::Red);
        cout << setw(37) << "" << "   [11] Logout.\n";
        clsUtil::ColorScreen(CurrentUser.Preferences.ScreenColors.MenusBorders());
        cout << setw(37) << "" << "===========================================\n";
        clsUtil::ColorScreen();

        _PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
    }

};

