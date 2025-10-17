#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsScreen.h"
using namespace std;

class clsUpdateCurrencyRateScreen : protected clsScreen
{
private:
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

	static float _ReadRate()
	{
		cout << "\nEnter New Rate: ";
		float NewRate = clsInputValidate::ReadPositiveNumber<float>();
		return NewRate;
	}

public:
	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("\tUpdate Currency Rate Screen");

		string Code = clsInputValidate::ReadString("\nEnter Currency Code: ");

		while (!clsCurrency::IsCurrencyExist(Code))
		{
			Code = clsInputValidate::ReadString("\nInvalid Currency Code, Enter again: ");
		}

		clsCurrency Currency = clsCurrency::FindByCode(Code);
		_PrintCurrencyCard(Currency);

		char Answer = 'n';
		cout << "\nAre you sure you want to update the rate of this currency? [y/n]? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << "\nUpdate Currency Rate:";
			cout << "\n_____________________\n";
			Currency.UpdateRate(_ReadRate());

			cout << "\nCurrency Rate Updated Succesfully!\n";
			_PrintCurrencyCard(Currency);
		}

	}

};

