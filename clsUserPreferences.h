#pragma once

#include <iostream>
using namespace std;

class clsUserPreferences
{
private:
	string _DateFormat;

public:
	enum enDateFormatOptions {
		DDMMYYYslash = 1, DDMMYYYdash = 2, DDMMYYYdot = 3,
		YYYYMMDDslash = 4, YYYYMMDDdash = 5, YYYYMMDDdot = 6,
	};

	clsUserPreferences()
	{
		_DateFormat = "DD/MM/YYYY";
	}

	void SetDateFormat(string DateFormat)
	{
		_DateFormat = DateFormat;
	}

	string DateFormat()
	{
		return _DateFormat;
	}

	static string DateFormatOptionToString(enDateFormatOptions DateFormatOption)
	{
		switch (DateFormatOption)
		{
		case enDateFormatOptions::DDMMYYYslash:
			return "DD/MM/YYYY";

		case enDateFormatOptions::DDMMYYYdash:
			return "DD-MM-YYYY";

		case enDateFormatOptions::DDMMYYYdot:
			return "DD.MM.YYYY";

		case enDateFormatOptions::YYYYMMDDslash:
			return "YYYY/MM/DD";

		case enDateFormatOptions::YYYYMMDDdash:
			return "YYYY-MM-DD";

		case enDateFormatOptions::YYYYMMDDdot:
			return "YYYY.MM.DD";

		}
	}

};

