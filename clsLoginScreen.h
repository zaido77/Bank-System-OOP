#pragma once

#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
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
				cout << "\nInvalid Username/Password\n";
				cout << "You have " << (3 - FailedLoginCount) << " Trial(s) to login.\n\n";
			}

			if (FailedLoginCount == 3)
			{
				cout << "\nYou are Locked after 3 failed login.\n";
				return false;
			}

			string UserName = clsInputValidate::ReadString("Enter Username: ");
			string Password = clsInputValidate::ReadString("Enter Password: ");

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