#pragma once

#include <iostream>
#include "clsScreen.h"
using namespace std;

class clsSettingsScreen : protected clsScreen
{
private:
	enum enSettingsMenuOptions {
		eChangeDateFormat = 1, eMainMenu = 2
	};

	static short _ReadSettingsMenuOption()
	{
		cout << setw(37) << "" << "Choose what do you want to do [1 to 2]? ";
		return clsInputValidate::ReadNumberBetween<short>(1, 2, "Enter Number between 1 to 2? ");
	}

	static void _GoBackToSettingsMenu()
	{
		cout << "\nPress any key to go back to Settings Menu..." << endl;
		system("pause>0");
		ShowSettingsScreen();
	}

	static void _ShowChangeDateFormatScreen()
	{
		cout << "\nShowChangeDateFormatScreen will be here\n";
	}

	static void _PerformSettingsMenuOption(enSettingsMenuOptions SettingsMenuOption)
	{
		switch (SettingsMenuOption)
		{
		case enSettingsMenuOptions::eChangeDateFormat:
			system("cls");
			_ShowChangeDateFormatScreen();
			_GoBackToSettingsMenu();
			break;

		case enSettingsMenuOptions::eMainMenu:
			break;

		}
	}

public:
	static void ShowSettingsScreen()
	{
		system("cls");
		_DrawScreenHeader("\t    Settings Screen");

		cout << setw(37) << "" << "===========================================\n";
		cout << setw(37) << "" << "               Settings Menu\n";
		cout << setw(37) << "" << "===========================================\n";
		cout << setw(37) << "" << "   [1] Change Date Format.\n";
		cout << setw(37) << "" << "   [2] Main Menu.\n";
		cout << setw(37) << "" << "===========================================\n";

		_PerformSettingsMenuOption((enSettingsMenuOptions)_ReadSettingsMenuOption());
	}

};

