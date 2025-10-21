#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsScreenColors.h"
#include "clsPerformChangeColorOptionScreen.h"
using namespace std;

class clsChangeColorsScreen : protected clsScreen
{
private:
    static short _ReadChangeColorOption()
    {
        cout << setw(37) << "" << "Choose what to change color of [1 to 4]? ";
        return clsInputValidate::ReadNumberBetween<short>(1, 4, "Enter Number between 1 to 4? ");
    }

    static void _PerformChangeColorsOption(clsScreenColors::enScreenColors ScreenColorsOption)
    {
        system("cls");
        clsPerformChangeColorOptionScreen::ShowPerformChangeColorOptionScreen(ScreenColorsOption);
    }

public:
	static void ShowChangeColorsScreen()
	{
		_DrawScreenHeader("\t  Change Colors Screen");

        clsUtil::ColorScreen(CurrentUser.Preferences.ScreenColors.MenusBorders());
        cout << setw(37) << "" << "===========================================\n";
        cout << setw(37) << "" << "           Screen Colors Options\n";
        cout << setw(37) << "" << "===========================================\n";
        clsUtil::ColorScreen(CurrentUser.Preferences.ScreenColors.MenusOptions());
        cout << setw(37) << "" << "   [1] Headers.\n";
        cout << setw(37) << "" << "   [2] Menus Borders.\n";
        cout << setw(37) << "" << "   [3] Menus Options.\n";
        cout << setw(37) << "" << "   [4] Tables.\n";
        clsUtil::ColorScreen(CurrentUser.Preferences.ScreenColors.MenusBorders());
        cout << setw(37) << "" << "===========================================\n";
        clsUtil::ColorScreen();

        _PerformChangeColorsOption((clsScreenColors::enScreenColors)_ReadChangeColorOption());
	}
};

