#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsScreenColors.h"
using namespace std;

class clsPerformChangeColorOptionScreen : protected clsScreen
{
private:
    static short _ReadColorOption(string ScreenColorsOptionString)
    {
        cout << setw(37) << "" << "Change color of " + ScreenColorsOptionString + " to [1-15]? ";
        return clsInputValidate::ReadNumberBetween<short>(1, 15, "Enter Number between 1 to 15? ");
    }

public:
	static void ShowPerformChangeColorOptionScreen(clsScreenColors::enScreenColors ScreenColorsOption)
	{
        string ScreenColorsOptionString = clsScreenColors::ScreenColorsEnumToString(ScreenColorsOption);
        
        string SubTitle = "\t    [ " + ScreenColorsOptionString + " ]";
		_DrawScreenHeader("      Perform Color Change Screen", SubTitle);

        clsUtil::ColorScreen(CurrentUser.Preferences.ScreenColors.MenusBorders());
        cout << setw(37) << "" << "===========================================\n";
        cout << setw(37) << "" << "                  Colors\n";
        cout << setw(37) << "" << "===========================================\n";

        clsUtil::ColorScreen(CurrentUser.Preferences.ScreenColors.MenusOptions());
        cout << setw(37) << "" << "   [1] Blue             [8] Gray\n";
        cout << setw(37) << "" << "   [2] Green            [9] Light Blue\n";
        cout << setw(37) << "" << "   [3] Aqua             [10] Light Green\n";
        cout << setw(37) << "" << "   [4] Red              [11] Light Aqua\n";
        cout << setw(37) << "" << "   [5] Purple           [12] Light Red\n";
        cout << setw(37) << "" << "   [6] Yellow           [13] Light Purple\n";
        cout << setw(37) << "" << "   [7] White            [14] Light Yellow\n";
        cout << setw(37) << "" << "                        [15] Bright White\n";

        clsUtil::ColorScreen(CurrentUser.Preferences.ScreenColors.MenusBorders());
        cout << setw(37) << "" << "===========================================\n";
        clsUtil::ColorScreen();

        clsUtil::enColors Color = (clsUtil::enColors)_ReadColorOption(ScreenColorsOptionString);
        
        CurrentUser.UpdateScreenColors(ScreenColorsOption, Color);
	}

};

