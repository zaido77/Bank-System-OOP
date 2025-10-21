#pragma once

#include <iostream>
#include "clsUtil.h"
#include "clsString.h"
#include "clsScreenColors.h"
using namespace std;

class clsUserPreferences
{
private:
	string _DateFormat;

public:
	clsScreenColors ScreenColors;

	enum enDateFormatOptions {
		DDMMYYYslash = 1, DDMMYYYdash = 2, DDMMYYYdot = 3,
		YYYYMMDDslash = 4, YYYYMMDDdash = 5, YYYYMMDDdot = 6,
	};
	
	clsUserPreferences() 
	{
		ResetToDefaults();
	}

	clsUserPreferences(string DateFormat, clsScreenColors ScreenColors)
	{
		_DateFormat = DateFormat;
		this->ScreenColors = ScreenColors;
	}

	void SetDateFormat(string DateFormat)
	{
		_DateFormat = DateFormat;
	}

	void SetDateFormat(enDateFormatOptions DateFormat)
	{
		_DateFormat = DateFormatOptionToString(DateFormat);
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

	void ResetToDefaults()
	{
		_DateFormat = "DD/MM/YYYY";
		ScreenColors.ResetToDefualts();
	}

};

