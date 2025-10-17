#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsScreen.h"
using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
	static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:")
	{
		cout << "\n" << Title;
		cout << "\n_______________________________\n";
		cout << "\nCountry    : " << Currency.GetCountry();
		cout << "\nCode       : " << Currency.GetCode();
		cout << "\nName       : " << Currency.GetName();
		cout << "\nRate(1$) = : " << Currency.GetRate();
		cout << "\n_______________________________\n\n";
	}

	static float _ReadAmount()
	{
		cout << "\nEnter Amount To Exchange: ";
		float Amount = clsInputValidate::ReadPositiveNumber<float>();
		return Amount;
	}

	static clsCurrency _GetCurrency(string Message)
	{
		string Code = clsInputValidate::ReadString(Message);

		while (!clsCurrency::IsCurrencyExist(Code))
		{
			Code = clsInputValidate::ReadString("\nInvalid Currency Code, Enter again: ");
		}

		return clsCurrency::FindByCode(Code);
	}

	static void _PrintCalculationsResults(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
	{
		_PrintCurrencyCard(CurrencyFrom, "Convert From:");

		float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);
		
		cout << Amount << " " << CurrencyFrom.GetCode()
			<< " = " << AmountInUSD << " USD\n";

		if (CurrencyTo.GetCode() == "USD")
			return;

		cout << "\nConverting From USD To:\n";
		_PrintCurrencyCard(CurrencyTo, "To:");

		float AmountInCurrencyTo = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);

		cout << Amount << " " << CurrencyFrom.GetCode()
			<< " = " << AmountInCurrencyTo << " " << CurrencyTo.GetCode() << "\n";
	}

public:
	static void ShowCurrencyCalculatorScreen()
	{
		char Continue = 'y';

		while (Continue == 'y' || Continue == 'Y')
		{
			system("cls");
			_DrawScreenHeader("\tCurrency Calculator Screen");

			clsCurrency CurrencyFrom = _GetCurrency("\nEnter Currency1 Code: ");
			clsCurrency CurrencyTo = _GetCurrency("\nEnter Currency2 Code: ");
			float Amount = _ReadAmount();
			
			_PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

			cout << "\nDo you want to perform another calculation? [y/n]? ";
			cin >> Continue;
		}
	}

};