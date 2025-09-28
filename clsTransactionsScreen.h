#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
using namespace std;

class clsTransactionsScreen : protected clsScreen
{
private:
	enum enTransactionsMenuOptions {
		eDeposit = 1, eWithdraw = 2, 
        eTotalBalances = 3, eMainMenu = 4
	};

    static short _ReadTransactionsMenuOption()
    {
        cout << setw(37) << "" << "Choose what do you want to do [1 to 4]? ";
        return clsInputValidate::ReadShortNumberBetween(1, 4, "Enter Number between 1 to 4? ");
    }

    static void _GoBackToTransactionsMenu()
    {
        cout << "\nPress any key to go back to Transactions Menu..." << endl;
        system("pause>0");
        ShowTransactionsMenu();
    }

    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        cout << "Total Balances Screen will be here" << endl;
    }

    static void _PerformTransactionsMenuOption(enTransactionsMenuOptions TransactionsMenuOption)
    {
        switch (TransactionsMenuOption)
        {
        case enTransactionsMenuOptions::eDeposit:
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenu();
            break;

        case enTransactionsMenuOptions::eWithdraw:
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenu();
            break;

        case enTransactionsMenuOptions::eTotalBalances:
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenu();
            break;

        case enTransactionsMenuOptions::eMainMenu:
            break;

        }
    }

public:

	static void ShowTransactionsMenu()
	{
        system("cls");
        _DrawScreenHeader("\t Transactions Screen");

        cout << setw(37) << "" << "===========================================\n";
        cout << setw(37) << "" << "             Transactions Menue\n";
        cout << setw(37) << "" << "===========================================\n";
        cout << setw(37) << "" << "   [1] Deposit.\n";
        cout << setw(37) << "" << "   [2] Withdraw.\n";
        cout << setw(37) << "" << "   [3] Total Balances.\n";
        cout << setw(37) << "" << "   [4] Main Menu.\n";
        cout << setw(37) << "" << "===========================================\n";

        _PerformTransactionsMenuOption((enTransactionsMenuOptions)_ReadTransactionsMenuOption());
	}

};

