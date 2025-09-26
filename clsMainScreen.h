#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsClientsListScreen.h"
#include "clsAddNewClientScreen.h"
using namespace std;

class clsMainScreen : protected clsScreen
{
private:
    enum enMainMenuOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eExit = 8
    };

    static short _ReadMainMenuOption()
    {
        cout << setw(37) << "" << "Choose what do you want to do [1 to 8]? ";
        return clsInputValidate::ReadShortNumberBetween(1, 8, "Enter Number between 1 to 8? ");
    }

    static void _GoBackToMainMenue()
    {
        cout << "\n\tPress any key to go back to Main Menu...\n";
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
        cout << "\nDelete Client Screen Will be here...\n";

    }

    static void _ShowUpdateClientScreen()
    {
        cout << "\nUpdate Client Screen Will be here...\n";

    }

    static void _ShowFindClientScreen()
    {
        cout << "\nFind Client Screen Will be here...\n";

    }

    static void _ShowTransactionsMenu()
    {
        cout << "\nTransactions Menue Will be here...\n";

    }

    static void _ShowManageUsersMenu()
    {
        cout << "\nUsers Menue Will be here...\n";

    }

    static void _ShowEndScreen()
    {
        cout << "\nEnd Screen Will be here...\n";

    }

    static void _PerformMainMenuOption(enMainMenuOptions MainMenuOption)
    {
        switch (MainMenuOption)
        {
        case enMainMenuOptions::eListClients:
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenuOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenuOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenuOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenuOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenuOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenu();
            break;

        case enMainMenuOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenu();
            break;

        case enMainMenuOptions::eExit:
            system("cls");
            _ShowEndScreen();
            //Login();
            break;
        }

    }

public:

    static void ShowMainMenu()
    {
        system("cls");
        _DrawScreenHeader("\t     Main Screen");

        cout << setw(37) << "" << "===========================================\n";
        cout << setw(37) << "" << "               Main Menue\n";
        cout << setw(37) << "" << "===========================================\n";
        cout << setw(37) << "" << "        [1] Show Clients List.\n";
        cout << setw(37) << "" << "        [2] Add New Client.\n";
        cout << setw(37) << "" << "        [3] Delete Client.\n";
        cout << setw(37) << "" << "        [4] Update Client Info.\n";
        cout << setw(37) << "" << "        [5] Find Client.\n";
        cout << setw(37) << "" << "        [6] Transactions.\n";
        cout << setw(37) << "" << "        [7] Manage Users.\n";
        cout << setw(37) << "" << "        [8] Logout.\n";
        cout << setw(37) << "" << "===========================================\n";

        _PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
    }

};

