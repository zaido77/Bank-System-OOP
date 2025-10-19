#pragma once

#include <iostream>
#include <iomanip>
#include "clsUtil.h"
#include "clsDate.h"
#include "clsUser.h"
#include "Global.h"
using namespace std;

class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		clsUtil::ColorScreen(CurrentUser.Preferences.ScreenColors.Headers());

		cout << clsUtil::Tabs(5) << "______________________________________\n\n";
		
		cout << clsUtil::Tabs(5) << Title << "\n";

		if (SubTitle != "")
			cout << clsUtil::Tabs(5) << SubTitle << "\n";

		cout << clsUtil::Tabs(5) << "______________________________________\n\n";
		
		clsUtil::ColorScreen();
		
		if (!CurrentUser.IsEmpty())
		{
			clsUtil::ColorScreen(clsUtil::White, clsUtil::Blue);
			cout << clsUtil::Tabs(5) << "User: " << CurrentUser.GetUsername() << "\n";
			cout << clsUtil::Tabs(5) << "Date: " << clsDate::FormatDate(clsDate(), CurrentUser.Preferences.DateFormat()) << "\n\n";
			clsUtil::ColorScreen();
		}
	}

	static bool CheckAccessRights(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			_DrawScreenHeader("  Access Denied! Contact your Admin.");
			return false;
		}
		else
		{
			return true;
		}
	}

};

