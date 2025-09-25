#pragma once

#include <iostream>
#include <iomanip>
#include "clsUtil.h"
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

};

