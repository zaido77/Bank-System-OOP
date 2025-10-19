#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUserPreferences.h"
#include "Global.h"
using namespace std;

class clsChangeDateFormatScreen : protected clsScreen
{
private:
    static short _ReadDateFormatOption()
    {
        cout << setw(36) << "" << "Choose which date format you want [1 to 6]? ";
        return clsInputValidate::ReadNumberBetween<short>(1, 6, "Enter Number between 1 to 6? ");
    }

    static void _PerformDateFormatOption(clsUserPreferences::enDateFormatOptions DateFormatOption)
    {
        CurrentUser.UpdateDateFormat(clsUserPreferences::DateFormatOptionToString(DateFormatOption));
    }

public:
	static void ShowChangeDateFormatScreen()
	{
		_DrawScreenHeader("\tChange Date Format Screen");

        cout << setw(36) << "" << "==============================================\n";
        cout << setw(36) << "" << "              Date Format Options\n";
        cout << setw(36) << "" << "==============================================\n";
        cout << setw(36) << "" << "   [1] DD/MM/YYYY\n";
        cout << setw(36) << "" << "   [2] DD-MM-YYYY\n";
        cout << setw(36) << "" << "   [3] DD.MM.YYYY\n";
        cout << setw(36) << "" << "   [4] YYYY/MM/DD\n";
        cout << setw(36) << "" << "   [5] YYYY-MM-DD\n";
        cout << setw(36) << "" << "   [6] YYYY.MM.DD\n";
        cout << setw(36) << "" << "==============================================\n";
        
        _PerformDateFormatOption((clsUserPreferences::enDateFormatOptions)_ReadDateFormatOption());
	}

};

