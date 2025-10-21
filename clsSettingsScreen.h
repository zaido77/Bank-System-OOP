#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsChangeDateFormatScreen.h"
#include "clsChangeColorsScreen.h"
using namespace std;

class clsSettingsScreen : protected clsScreen
{
private:
	enum enSettingsMenuOptions {
		eResetToDefaults = 0,
		eChangeDateFormat = 1, eChangeColors = 2, eMainMenu = 3
	};

	static short _ReadSettingsMenuOption()
	{
		cout << setw(37) << "" << "Choose what do you want to do [0 to 3]? ";
		return clsInputValidate::ReadNumberBetween<short>(0, 3, "Enter Number between 0 to 3? ");
	}

	static void _GoBackToSettingsMenu()
	{
		cout << "\nPress any key to go back to Settings Menu..." << endl;
		system("pause>0");
		ShowSettingsScreen();
	}

	static void _ShowChangeDateFormatScreen()
	{
		clsChangeDateFormatScreen::ShowChangeDateFormatScreen();
	}

	static void _ShowChangeColorsScreen()
	{
		clsChangeColorsScreen::ShowChangeColorsScreen();
	}

	static void _PerformSettingsMenuOption(enSettingsMenuOptions SettingsMenuOption)
	{
		switch (SettingsMenuOption)
		{
		case enSettingsMenuOptions::eResetToDefaults:
			CurrentUser.ResetPreferencesToDefaults();
			break;

		case enSettingsMenuOptions::eChangeDateFormat:
			system("cls");
			_ShowChangeDateFormatScreen();
			_GoBackToSettingsMenu();
			break;

		case enSettingsMenuOptions::eChangeColors:
			system("cls");
			_ShowChangeColorsScreen();
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

		clsUtil::ColorScreen(CurrentUser.Preferences.ScreenColors.MenusBorders());
		cout << setw(37) << "" << "===========================================\n";
		cout << setw(37) << "" << "               Settings Menu\n";
		cout << setw(37) << "" << "===========================================\n";
		clsUtil::ColorScreen(CurrentUser.Preferences.ScreenColors.MenusOptions());
		cout << setw(37) << "" << "   [0] Reset To Defaults.\n";
		cout << setw(37) << "" << "   [1] Change Date Format.\n";
		cout << setw(37) << "" << "   [2] Change Colors.\n";
		cout << setw(37) << "" << "   [3] Main Menu.\n";
		clsUtil::ColorScreen(CurrentUser.Preferences.ScreenColors.MenusBorders());
		cout << setw(37) << "" << "===========================================\n";
		clsUtil::ColorScreen();

		_PerformSettingsMenuOption((enSettingsMenuOptions)_ReadSettingsMenuOption());
	}

};

