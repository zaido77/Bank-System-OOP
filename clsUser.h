#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
using namespace std;

class clsUser : public clsPerson
{
	struct stLoginRegisterRecord; // Decleration

	static const string UsersFileName;
	static const string LoginRegisterFileName;

private:
	enum enMode { EmptyMode = 1, UpdateMode = 2, AddNewMode = 3 };

	enMode _Mode;
	string _UserName;
	string _Password;
	short _Permissions;
	bool _MarkForDelete = false;

	static stLoginRegisterRecord _ConvertLineToLoginRegisterRecord(string Line, string Delim = "#//#")
	{
		vector<string> vLoginRegisterRecord = clsString::Split(Line, Delim);

		stLoginRegisterRecord LoginRegisterRecord;

		LoginRegisterRecord.DateTime = vLoginRegisterRecord[0];
		LoginRegisterRecord.UserName = vLoginRegisterRecord[1];
		LoginRegisterRecord.Password = vLoginRegisterRecord[2];
		LoginRegisterRecord.Permissions = stoi(vLoginRegisterRecord[3]);

		return LoginRegisterRecord;
	}

	string _PrepareLoginRecord(string Delim = "#//#")
	{
		string LoginRecord = "";

		LoginRecord += clsDate::GetSystemDateTimeString() + Delim;
		LoginRecord += _UserName + Delim;
		LoginRecord += _Password + Delim;
		LoginRecord += to_string(_Permissions);

		return LoginRecord;
	}

	static clsUser _ConvertLineToUserObject(string Line, string Delim = "#//#")
	{
		vector<string> vUser = clsString::Split(Line, Delim);

		return clsUser(
			enMode::UpdateMode,
			vUser[0],
			vUser[1],
			vUser[2],
			vUser[3],
			vUser[4],
			vUser[5],
			stoi(vUser[6])
		);
	}

	static string _ConvertUserObjectToLine(clsUser User, string Delim = "#//#")
	{
		string Line = "";

		Line += User.GetFirstName() + Delim;
		Line += User.GetLastName() + Delim;
		Line += User.GetEmail() + Delim;
		Line += User.GetPhone() + Delim;
		Line += User.GetUsername() + Delim;
		Line += User.GetPassword() + Delim;
		Line += to_string(User.GetPermissions());

		return Line;
	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsUser> _LoadUsersDataFromFile()
	{
		vector<clsUser> vUsers;

		fstream MyFile;
		MyFile.open(UsersFileName, ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				vUsers.push_back(User);
			}

			MyFile.close();
		}

		return vUsers;
	}

	static void _SaveUsersDataToFile(vector<clsUser>& vUsers)
	{
		fstream MyFile;
		MyFile.open(UsersFileName, ios::out);

		if (MyFile.is_open())
		{
			for (clsUser& User : vUsers)
			{
				if (!User.GetMarkForDelete())
				{
					MyFile << _ConvertUserObjectToLine(User) << "\n";
				}
			}

			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsUser> vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : vUsers)
		{
			if (U.GetUsername() == _UserName)
			{
				U = *this;
				break;
			}
		}

		_SaveUsersDataToFile(vUsers);
	}

	void _AddNew()
	{
		_AddUserDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	static void _AddUserDataLineToFile(string DataLine)
	{
		fstream MyFile;
		MyFile.open(UsersFileName, ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << "\n";

			MyFile.close();
		}
	}

public:	
	enum enPermissions {
		pAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClient = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64, 
		pLoginRegister = 128
	};

	struct stLoginRegisterRecord
	{
		string DateTime;
		string UserName;
		string Password;
		short Permissions;
	};

	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, short Permissions)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	bool IsEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}

	string GetUsername()
	{
		return _UserName;
	}

	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}

	void SetPermissions(short Permissions)
	{
		_Permissions = Permissions;
	}

	short GetPermissions()
	{
		return _Permissions;
	}

	bool GetMarkForDelete()
	{
		return _MarkForDelete;
	}

	static clsUser Find(string UserName)
	{
		fstream MyFile;
		MyFile.open(UsersFileName, ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);

				if (User.GetUsername() == UserName)
				{
					MyFile.close();
					return User;
				}
			}

			MyFile.close();
		}

		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName, string Password)
	{
		fstream MyFile;
		MyFile.open(UsersFileName, ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);

				if ((User.GetUsername() == UserName) && (User.GetPassword() == Password))
				{
					MyFile.close();
					return User;
				}
			}

			MyFile.close();
		}

		return _GetEmptyUserObject();
	}

	static bool IsUserExist(string UserName)
	{
		clsUser User = Find(UserName);

		return !User.IsEmpty();
	}

	enum enSaveResults { svFailedEmptyObject = 0, svSucceeded = 1, svFailedUserExists = 2 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:

			return enSaveResults::svFailedEmptyObject;

		case enMode::UpdateMode:

			_Update();
			return enSaveResults::svSucceeded;

		case enMode::AddNewMode:

			if (IsUserExist(_UserName))
			{
				return enSaveResults::svFailedUserExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
		}
	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	bool Delete()
	{
		vector<clsUser> vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : vUsers)
		{
			if (U.GetUsername() == _UserName)
			{
				U._MarkForDelete = true;
				_MarkForDelete = true;
				break;
			}
		}

		if (_MarkForDelete)
		{
			_SaveUsersDataToFile(vUsers);
			*this = _GetEmptyUserObject();
			return true;
		}

		return false;
	}

	static vector<clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	bool CheckAccessPermission(enPermissions Permission)
	{
		if (Permission == enPermissions::pAll)
			return true;

		return (Permission & _Permissions) == Permission;
	}

	void RegisterLogin()
	{
		string DataLine = _PrepareLoginRecord();

		fstream MyFile;
		MyFile.open(LoginRegisterFileName, ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << "\n";

			MyFile.close();
		}
	}

	static vector<stLoginRegisterRecord> GetLoginRegisterList()
	{
		vector<stLoginRegisterRecord> vLoginRegisterRecords;

		fstream MyFile;
		MyFile.open(LoginRegisterFileName, ios::in);

		if (MyFile.is_open())
		{
			string Line = "";
			stLoginRegisterRecord LoginRegisterRecord;

			while (getline(MyFile, Line))
			{
				LoginRegisterRecord = _ConvertLineToLoginRegisterRecord(Line);
				vLoginRegisterRecords.push_back(LoginRegisterRecord);
			}

			MyFile.close();
		}

		return vLoginRegisterRecords;
	}

};

const string clsUser::UsersFileName = "Users.txt";
const string clsUser::LoginRegisterFileName = "LoginRegister.txt";