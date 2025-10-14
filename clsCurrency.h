#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "clsString.h"
using namespace std;

class clsCurrency
{
private:
	static const string FileName;

	enum enMode { EmptyMode = 1, UpdateMode = 2 };

	enMode _Mode;
	string _Country;
	string _Code;
	string _Name;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Delim = "#//#")
	{
		vector<string> vCurrency = clsString::Split(Line, Delim);

		return clsCurrency(
			enMode::UpdateMode,
			vCurrency[0],
			vCurrency[1],
			vCurrency[2],
			stof(vCurrency[3])
		);
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Delim = "#//#")
	{
		string Line = "";

		Line += Currency.GetCountry() + Delim;
		Line += Currency.GetCode() + Delim;
		Line += Currency.GetName() + Delim;
		Line += to_string(Currency.GetRate()) + Delim;

		return Line;
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

	static vector<clsCurrency> _LoadCurrenciesDataFromFile()
	{
		vector<clsCurrency> vCurrencies;

		fstream MyFile;
		MyFile.open(FileName, ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				vCurrencies.push_back(Currency);
			}

			MyFile.close();
		}

		return vCurrencies;
	}

	static void _SaveCurrenciesDataToFile(vector<clsCurrency> vCurrencies)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::out);

		if (MyFile.is_open())
		{
			for (clsCurrency& Currency : vCurrencies)
			{
				MyFile << _ConvertCurrencyObjectToLine(Currency) << "\n";
			}

			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsCurrency> vCurrencies = _LoadCurrenciesDataFromFile();

		for (clsCurrency& Currency : vCurrencies)
		{
			if (Currency.GetCode() == _Code)
			{
				Currency = *this;
				break;
			}
		}

		_SaveCurrenciesDataToFile(vCurrencies);
	}

public:
	clsCurrency(enMode Mode, string Country, string Code, string Name, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_Code = Code;
		_Name = Name;
		_Rate = Rate;
	}

	string GetCountry()
	{
		return _Country;
	}

	string GetCode()
	{
		return _Code;
	}

	string GetName()
	{
		return _Name;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	float GetRate()
	{
		return _Rate;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open(FileName, ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				if (clsString::UpperAllString(Currency.GetCountry()) == Country)
				{
					MyFile.close();
					return Currency;
				}

			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCode(string Code)
	{
		Code = clsString::UpperAllString(Code);

		fstream MyFile;
		MyFile.open(FileName, ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

				if (Currency.GetCode() == Code)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();
		}

		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string Code)
	{
		clsCurrency Currency = FindByCode(Code);
		return !Currency.IsEmpty();
	}

	static vector<clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrenciesDataFromFile();
	}

};

const string clsCurrency::FileName = "Currencies.txt";