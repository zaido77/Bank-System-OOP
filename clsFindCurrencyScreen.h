#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{
private:
	enum enFindCurrencyChoice { eByCode = 1, eByCountry = 2 };

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

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :)\n";
			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\nCurrency Not Found :(\n";
		}
	}

public:
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\tFind Currency Screen");

		enFindCurrencyChoice Answer;
		cout << "\nFind By: [1] Code or [2] Country ? ";
		Answer = (enFindCurrencyChoice)clsInputValidate::ReadNumberBetween<short>(1, 2);

		if (Answer == enFindCurrencyChoice::eByCode)
		{
			string Code = clsInputValidate::ReadString("\nEnter Currency Code: ");
			clsCurrency Currency = clsCurrency::FindByCode(Code);
			_ShowResults(Currency);
		}
		else if (Answer == enFindCurrencyChoice::eByCountry)
		{
			string Country = clsInputValidate::ReadString("\nEnter Country Name: ");
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);
		}

	}

};

