#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsUtil.h"
using namespace std;

class clsCurrenciesListScreen : protected clsScreen
{
private:
	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << setw(8) << left << "";
		cout << "| " << setw(30) << Currency.GetCountry();
		cout << "| " << setw(8) << Currency.GetCode();
		cout << "| " << setw(40) << Currency.GetName();
		cout << "| " << setw(10) << Currency.GetRate();
		cout << "\n";
	}

public:
	static void ShowCurrenciesListScreen()
	{
        vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency.";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n";
        cout << setw(8) << left << "";
        cout << "________________________________________________________________________________________________\n\n";

        cout << setw(8) << left << "";
        cout << "| " << setw(30) << "Country";
        cout << "| " << setw(8) << "Code";
        cout << "| " << setw(40) << "Name";
        cout << "| " << setw(10) << "Rate/(1$)";
        cout << "\n";

        cout << setw(8) << left << "";
        cout << "________________________________________________________________________________________________\n\n";        
        if (vCurrencies.size() == 0)
        {
            cout << clsUtil::Tabs(5) << "(No Currencies Available in the System)\n";
        }
        else
        {
            for (clsCurrency& Currency : vCurrencies)
            {
                _PrintCurrencyRecordLine(Currency);
            }
        }
        
        cout << setw(8) << left << "";
        cout << "________________________________________________________________________________________________\n\n";
	}

};

