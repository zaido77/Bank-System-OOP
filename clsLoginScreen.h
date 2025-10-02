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
	static void _Login()
	{
		bool LoginFailed = false;

		do
		{
			if (LoginFailed)
				cout << "\nInvalid UserName/Password\n\n";

			string UserName = clsInputValidate::ReadString("Enter UserName: ");
			string Password = clsInputValidate::ReadString("Enter Password: ");

			CurrentUser = clsUser::Find(UserName, Password);
			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		clsMainScreen::ShowMainMenu();
	}

public:
	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t    Login Screen");
		_Login();
	}

};