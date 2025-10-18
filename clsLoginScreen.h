#pragma once

#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "Global.h"
#include <iostream>
using namespace std;

class clsLoginScreen : protected clsScreen
{
private:
	static bool _Login()
	{
		bool LoginFailed = false;
		short FailedLoginCount = 0;

		do
		{
			if (LoginFailed)
			{
				FailedLoginCount++;

				if (FailedLoginCount == 3)
				{
					cout << "\n" << clsUtil::Tabs(5) << "You are Locked after 3 failed logins.\n";
					return false;
				}

				cout << "\n" << clsUtil::Tabs(5) << "Invalid Username/Password\n";
				cout << clsUtil::Tabs(5) << "You have " << (3 - FailedLoginCount) << " Trial(s) to login.\n";
			}


			cout << "\n\n" << clsUtil::Tabs(5);
			string UserName = clsInputValidate::ReadString("Username: ");

			cout << clsUtil::Tabs(5);
			string Password = clsInputValidate::ReadString("Password: ");


			CurrentUser = clsUser::Find(UserName, Password);
			LoginFailed = CurrentUser.IsEmpty();
			

		} while (LoginFailed);

		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenu();
		return true;
	}

public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t     Login Screen");
		return _Login();
	}

};