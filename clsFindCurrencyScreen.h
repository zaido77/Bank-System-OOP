#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{
private:
	enum enFindChoice { ByCode = 1, ByCountry = 2 };

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n_______________________________\n";
		cout << "\nCountry    : " << Currency.GetCountry();
		cout << "\nCode       : " << Currency.GetCode();
		cout << "\nName       : " << Currency.GetName();
		cout << "\nRate(1$) = : " << Currency.GetRate();
		cout << "\n_______________________________\n";
	}

	static clsCurrency _Find(string UserInput, enFindChoice FindChoice)
	{
		switch (FindChoice)
		{
		case enFindChoice::ByCode:
			return clsCurrency::FindByCode(UserInput);

		case enFindChoice::ByCountry:
			return clsCurrency::FindByCountry(UserInput);
		}
	}

	static string _GetFindChoiceString(enFindChoice FindChoice)
	{
		return (FindChoice == enFindChoice::ByCode) ? "Code" : "Country";
	}

public:
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\tFind Currency Screen");

		cout << "\nFind By: [1] Code or [2] Country ? ";
		enFindChoice UserFindChoice = (enFindChoice)clsInputValidate::ReadShortNumberBetween(1, 2);

		string FindChoiceStr = _GetFindChoiceString(UserFindChoice);
		string UserInput = clsInputValidate::ReadString("\nPlease Enter Currency " + FindChoiceStr + ": ");

		clsCurrency Currency = _Find(UserInput, UserFindChoice);
		
		if (Currency.IsEmpty())
		{
			cout << "\nCurrency Not Found :(\n";
		}
		else
		{
			cout << "\nCurrency Found :)\n";
			_PrintCurrencyCard(Currency);
		}

	}

};

