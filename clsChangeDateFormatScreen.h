#pragma once

#include <iostream>
#include "clsScreen.h"
#include "Global.h"
using namespace std;

class clsChangeDateFormatScreen : protected clsScreen
{
private:
    enum enDateFormatOptions {
        DDMMYYYslash = 1, DDMMYYYdash = 2, DDMMYYYdot = 3,
        YYYYMMDDslash = 4, YYYYMMDDdash = 5, YYYYMMDDdot = 6,
    };

    static string _GetDateFormatStr(enDateFormatOptions DateFormatOption)
    {
        switch (DateFormatOption)
        {
        case enDateFormatOptions::DDMMYYYslash:
            return "DD/MM/YYYY";

        case enDateFormatOptions::DDMMYYYdash:
            return "DD-MM-YYYY";

        case enDateFormatOptions::DDMMYYYdot:
            return "DD.MM.YYYY";

        case enDateFormatOptions::YYYYMMDDslash:
            return "YYYY/MM/DD";

        case enDateFormatOptions::YYYYMMDDdash:
            return "YYYY-MM-DD";

        case enDateFormatOptions::YYYYMMDDdot:
            return "YYYY.MM.DD";


        }
    }

    static short _ReadDateFormatOption()
    {
        cout << setw(36) << "" << "Choose which date format you want [1 to 6]? ";
        return clsInputValidate::ReadNumberBetween<short>(1, 6, "Enter Number between 1 to 6? ");
    }

    static void _PerformDateFormatOption(enDateFormatOptions DateFormatOption)
    {
        CurrentUser.UpdateDateFormat(_GetDateFormatStr(DateFormatOption));
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
        
        _PerformDateFormatOption((enDateFormatOptions)_ReadDateFormatOption());
	}

};

