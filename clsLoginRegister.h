#pragma once

#include <iostream>
#include <fstream>
#include "clsDate.h"
#include "clsUtil.h"
#include "Global.h"
using namespace std;

class clsLoginRegister
{
private:
	static const string FileName;

	static string _ConvertUserLoginToRegisterRecord(string Delim = "#//#")
	{
		//string Timestamp = clsDate::DateToString(clsDate()) + " - " + clsUtil::GetSystemTime();
		string Timestamp = clsUtil::GetCurrentTimestamp();

		string Record = "";

		Record += Timestamp + Delim;
		Record += CurrentUser.GetUsername() + Delim;
		Record += CurrentUser.GetPassword() + Delim;
		Record += to_string(CurrentUser.GetPermissions());

		return Record;
	}

public:
	static void Log()
	{
		fstream MyFile;
		MyFile.open(FileName, ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << _ConvertUserLoginToRegisterRecord() << "\n";

			MyFile.close();
		}
	}

};

const string clsLoginRegister::FileName = "LoginRegister.txt";