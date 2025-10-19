#pragma once

#include <iostream>
#include "clsUtil.h"
using namespace std;

class clsScreenColors
{
private:
	clsUtil::enColors _Headers;
	clsUtil::enColors _MenusBorders;
	clsUtil::enColors _MenusOptions;
	clsUtil::enColors _Tables;

public:
	clsScreenColors()
	{
		_Headers = clsUtil::Yellow;
		_MenusBorders = clsUtil::Gray;
		_MenusOptions = clsUtil::LightBlue;
		_Tables = clsUtil::Green;
	}

	clsScreenColors(clsUtil::enColors Headers, clsUtil::enColors MenusBorders, clsUtil::enColors MenusOptions, clsUtil::enColors Tables)
	{
		_Headers = Headers;
		_MenusBorders = MenusBorders;
		_MenusOptions = MenusOptions;
		_Tables = Tables;
	}

	void SetHeaders(clsUtil::enColors Color)
	{
	    _Headers = Color;
	}
	
	clsUtil::enColors Headers()
	{
	    return _Headers;
	}
	
	void SetMenusBorders(clsUtil::enColors Color)
	{
	    _MenusBorders = Color;
	}
	
	clsUtil::enColors MenusBorders()
	{
	    return _MenusBorders;
	}
	
	void SetMenusOptions(clsUtil::enColors Color)
	{
	    _MenusOptions = Color;
	}
	
	clsUtil::enColors MenusOptions()
	{
	    return _MenusOptions;
	}
	
	void SetTables(clsUtil::enColors Color)
	{
	    _Tables = Color;
	}
	
	clsUtil::enColors Tables()
	{
	    return _Tables;
	}

	static clsScreenColors ConvertLineToScreenColorsObject(string Line, string Delim = "$==$")
	{
		vector<string> vScreenColors = clsString::Split(Line, Delim);

		return clsScreenColors(
			clsUtil::StringToColor(vScreenColors[0]),
			clsUtil::StringToColor(vScreenColors[1]),
			clsUtil::StringToColor(vScreenColors[2]),
			clsUtil::StringToColor(vScreenColors[3])
		);
	}

	string ConvertToLine(string Delim = "$==$")
	{
		string Line = "";

		Line += clsUtil::ColorToString(_Headers) + Delim;
		Line += clsUtil::ColorToString(_MenusBorders) + Delim;
		Line += clsUtil::ColorToString(_MenusOptions) + Delim;
		Line += clsUtil::ColorToString(_Tables);

		return Line;
	}

};

