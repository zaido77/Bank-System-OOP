#pragma once

#include <iostream>
#include "clsDate.h"
using namespace std;

class clsInputValidate
{
public:
	static bool IsNumberBetween(short Number, short From, short To)
	{
		return (Number >= From) && (Number <= To);
	}

	static bool IsNumberBetween(int Number, int From, int To)
	{
		return (Number >= From) && (Number <= To);
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		return (Number >= From) && (Number <= To);
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		return (Number >= From) && (Number <= To);
	}

	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
	{
		if (DateFrom.IsAfter(DateTo))
			clsDate::SwapDates(DateFrom, DateTo);

		return (Date.IsAfter(DateFrom) || Date.IsEqual(DateFrom)) &&
			(Date.IsBefore(DateTo) || Date.IsEqual(DateTo));

		// return clsPeriod::isDateInPeriod(Date, clsPeriod(DateFrom, DateTo));
	}

	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		short Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}

	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		short Number = ReadShortNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}

		return Number;
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		int Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}

		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		double Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}

		return Number;
	}

	static bool IsValidDate(clsDate Date)
	{
		return Date.IsValid();
	}

	static string ReadString(string Message = "Enter a String?\n")
	{
		string Str = "";
		cout << Message;
		getline(cin >> ws, Str);

		return Str;
	}

	static int ReadPositiveIntNumber(string ErrorMessage = "Number is not positive, Enter again:\n")
	{
		int Number = ReadIntNumber();

		while (Number <= 0)
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}

		return Number;
	}

	static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		float Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}

	static float ReadPositiveFloatNumber(string ErrorMessage = "Number is not positive, Enter again:\n")
	{
		float Number = ReadFloatNumber();

		while (Number <= 0)
		{
			cout << ErrorMessage;
			Number = ReadFloatNumber();
		}

		return Number;
	}

	static double ReadPositiveDblNumber(string ErrorMessage = "Number is not positive, Enter again:\n")
	{
		double Number = ReadDblNumber();

		while (Number <= 0)
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}

		return Number;
	}

};

