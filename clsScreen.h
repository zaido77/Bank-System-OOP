#pragma once

#include <iostream>
#include <iomanip>
#include "clsUtil.h"
#include "clsUser.h"
#include "Global.h"
using namespace std;

class clsScreen
{
protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << clsUtil::Tabs(5) << "______________________________________\n\n";
		
		cout << clsUtil::Tabs(5) << Title << "\n";

		if (SubTitle != "")
			cout << clsUtil::Tabs(5) << SubTitle << "\n";

		cout << clsUtil::Tabs(5) << "______________________________________\n\n";
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

