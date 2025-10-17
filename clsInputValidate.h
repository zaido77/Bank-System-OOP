#pragma once

#include <iostream>
#include "clsDate.h"
using namespace std;

class clsInputValidate
{
public:

	template <typename T>
	static bool IsNumberBetween(T Number, T From, T To)
	{
		return (Number >= From) && (Number <= To);
	}

	template <typename T>
	static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		T Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(/*numeric_limits<streamsize>::max(), '\n'*/);

			cout << ErrorMessage;
		}

		return Number;
	}

	template <typename T>
	static short ReadNumberBetween(T From, T To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		T Number = ReadNumber<T>();

		while (!IsNumberBetween<T>(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadNumber<T>();
		}

		return Number;
	}

	template <typename T>
	static T ReadPositiveNumber(string ErrorMessage = "Number is not positive, Enter again:\n")
	{
		T Number = ReadNumber<T>();

		while (Number <= 0)
		{
			cout << ErrorMessage;
			Number = ReadNumber<T>();
		}

		return Number;
	}

	static string ReadString(string Message = "Enter a String?\n")
	{
		string Str = "";
		cout << Message;
		getline(cin >> ws, Str);

		return Str;
	}

	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
	{
		if (DateFrom.IsAfter(DateTo))
			clsDate::SwapDates(DateFrom, DateTo);

		return (Date.IsAfter(DateFrom) || Date.IsEqual(DateFrom)) &&
			(Date.IsBefore(DateTo) || Date.IsEqual(DateTo));

		// return clsPeriod::isDateInPeriod(Date, clsPeriod(DateFrom, DateTo));
	}
	
	static bool IsValidDate(clsDate Date)
	{
		return Date.IsValid();
	}

};

