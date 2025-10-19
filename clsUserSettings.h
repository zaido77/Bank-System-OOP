#pragma once

#include <iostream>
using namespace std;

class clsUserPreferences
{
private:
	string _DateFormat;

public:
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

};

