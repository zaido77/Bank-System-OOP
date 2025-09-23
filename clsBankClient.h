#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "C:/Users/User/source/repos/Testing/Testing/clsPerson.h"
#include "C:/Users/User/source/repos/Testing/Testing/clsString.h"
using namespace std;

class clsBankClient : public clsPerson
{
private:
	static const string _FileName;
	static short _NumberOfClients;

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

	static clsBankClient _ConvertLineToClientObject(string Line, string Delim = "#//#")
	{
		vector<string> vClient = clsString::Split(Line, Delim);

		return clsBankClient(
			enMode::UpdateMode,
			vClient[0],
			vClient[1],
			vClient[2],
			vClient[3],
			vClient[4],
			vClient[5],
			stof(vClient[6])
		);
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Delim = "#//#")
	{
		string Line = "";

		Line += Client.GetFirstName() + Delim;
		Line += Client.GetLastName() + Delim;
		Line += Client.GetEmail() + Delim;
		Line += Client.GetPhone() + Delim;
		Line += Client.GetAccountNumber() + Delim;
		Line += Client.GetPinCode() + Delim;
		Line += to_string(Client.GetAccountBalance());

		return Line;
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsBankClient> _LoadClientsDataFromFile()
	{
		vector<clsBankClient> vClients;

		fstream MyFile;
		MyFile.open(_FileName, ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				vClients.push_back(Client);
			}

			MyFile.close();
		}

		return vClients;
	}

	static void _SaveClientsDataToFile(vector<clsBankClient>& vClients)
	{
		fstream MyFile;
		MyFile.open(_FileName, ios::out);

		if (MyFile.is_open())
		{
			for (clsBankClient& Client : vClients)
			{
				MyFile << _ConvertClientObjectToLine(Client) << "\n";
			}

			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.GetAccountNumber() == _AccountNumber)
			{
				C = *this;
				break;
			}
		}

		_SaveClientsDataToFile(_vClients);
	}

	static string _GenerateAccountNumber()
	{
		return ("A1" + ((_NumberOfClients < 10) ? ("0" + to_string(_NumberOfClients)) : to_string(_NumberOfClients)));
	}

	static short _LoadClientsNumber()
	{
		vector<clsBankClient> vClients = _LoadClientsDataFromFile();
		return vClients.size();
	}

	void _Add()
	{
		fstream MyFile;
		MyFile.open(_FileName, ios::app);

		if (MyFile.is_open())
		{
			_Mode = enMode::UpdateMode;
			MyFile << _ConvertClientObjectToLine(*this) << "\n";
			MyFile.close();
		}
	}

public:
	clsBankClient() : clsPerson("","","","")
	{
		_NumberOfClients++;
		_Mode = enMode::AddNewMode;
		_AccountNumber = _GenerateAccountNumber();
	}

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}
	
	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string GetAccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}

	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n______________________________\n";
		cout << "\nFirstName      : " << GetFirstName();
		cout << "\nLastName       : " << GetLastName();
		cout << "\nFull Name      : " << GetFullName();
		cout << "\nEmail          : " << GetEmail();
		cout << "\nPhone          : " << GetPhone();
		cout << "\nAccount Number : " << _AccountNumber;
		cout << "\nPin Code       : " << _PinCode;
		cout << "\nAccount Balance: " << _AccountBalance;
		cout << "\n______________________________\n";
	}

	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open(_FileName, ios::in);

		if (MyFile.is_open())
		{
			string Line = "";
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client.GetAccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}

			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		fstream MyFile;
		MyFile.open(_FileName, ios::in);

		if (MyFile.is_open())
		{
			string Line = "";
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client.GetAccountNumber() == AccountNumber && Client.GetPinCode() == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}

			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = Find(AccountNumber);

		return !Client.IsEmpty();
	}

	enum enSaveResult { svFailedEmptyObject = 0, svUpdateSucceeded = 1, svAddSucceeded = 2 };

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			return enSaveResult::svFailedEmptyObject;
		case enMode::UpdateMode:
			_Update();
			return enSaveResult::svUpdateSucceeded;
		case enMode::AddNewMode:
			_Add();
			return enSaveResult::svAddSucceeded;
		}
	}

};

const string clsBankClient::_FileName = "Clients.txt";

short clsBankClient::_NumberOfClients = clsBankClient::_LoadClientsNumber();