#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrenciesListScreen.h"
using namespace std;

class clsCurrencyExchangeScreen : protected clsScreen
{
private:
	enum enCurrencyExchangeMenuOptions {
		eListCurrencies = 1, eFindCurrency = 2,
		eUpdateRate = 3, eCurrencyCalculator = 4,
		eMainMenu = 5
	};

	static short _ReadCurrencyExchangeMenuOption()
	{
		cout << setw(37) << "" << "Choose what do you want to do [1 to 5]? ";
		return clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
	}

	static void _GoBackToCurrencyExchangeMenu()
	{
		cout << "\nPress any key to go back to Currency Exchange Menu..." << endl;
		system("pause>0");
		ShowCurrencyExchangeMenu();
	}

	static void _ShowCurrenciesListScreen()
	{
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		cout << "ShowFindCurrencyScreen" << endl;
	}

	static void _ShowUpdateRateScreen()
	{
		cout << "ShowUpdateRateScreen" << endl;
	}
	
	static void _ShowCurrencyCalculatorScreen()
	{
		cout << "Show Currency Calculator Screen" << endl;
	}

	static void _PerformCurrencyExchangeMenuOption(enCurrencyExchangeMenuOptions CurrencyExchangeMenuOption)
	{
		switch (CurrencyExchangeMenuOption)
		{
		case enCurrencyExchangeMenuOptions::eListCurrencies:
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrencyExchangeMenu();
			break;

		case enCurrencyExchangeMenuOptions::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenu();
			break;

		case enCurrencyExchangeMenuOptions::eUpdateRate:
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeMenu();
			break;

		case enCurrencyExchangeMenuOptions::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenu();
			break;

		case enCurrencyExchangeMenuOptions::eMainMenu:
			break;

		}
	}

public:

	static void ShowCurrencyExchangeMenu()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
		{
			return;
		}

		system("cls");
		_DrawScreenHeader("\tCurrency Exchange Screen");

		cout << setw(37) << "" << "===========================================\n";
		cout << setw(37) << "" << "          Currency Exchange Menu\n";
		cout << setw(37) << "" << "===========================================\n";
		cout << setw(37) << "" << "   [1] List Currencies.\n";
		cout << setw(37) << "" << "   [2] Find Currency.\n";
		cout << setw(37) << "" << "   [3] Update Rate.\n";
		cout << setw(37) << "" << "   [4] Currency Calculator.\n";
		cout << setw(37) << "" << "   [5] Main Menu.\n";
		cout << setw(37) << "" << "===========================================\n";

		_PerformCurrencyExchangeMenuOption((enCurrencyExchangeMenuOptions)_ReadCurrencyExchangeMenuOption());
	}

};

