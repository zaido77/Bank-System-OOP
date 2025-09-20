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
	static const string FileName;

	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	
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
			stod(vClient[6])
		);
	}

	string _ConvertToLine(string Delim = "#//#")
	{
		string Line = "";

		Line += GetFirstName() + Delim;
		Line += GetLastName() + Delim;
		Line += GetEmail() + Delim;
		Line += GetPhone() + Delim;
		Line += _AccountNumber + Delim;
		Line += _PinCode + Delim;
		Line += to_string(_AccountBalance);

		return Line;
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

public:
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
		MyFile.open(FileName, ios::in);

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
		MyFile.open(FileName, ios::in);

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

	static vector<clsBankClient> LoadClientsDataFromFile()
	{
		vector<clsBankClient> vClients;

		fstream MyFile;
		MyFile.open(FileName, ios::in);

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

	static void SaveClientsDataToFile(vector<clsBankClient>& vClients)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::out);

		if (MyFile.is_open())
		{
			for (clsBankClient& Client : vClients)
			{
				if (!Client.IsEmpty())
				{
					MyFile << Client._ConvertToLine() << "\n";
				}
			}

			MyFile.close();
		}
	}

	void Update(vector<clsBankClient>& vClients)
	{
		for (clsBankClient& Client : vClients)
		{
			if (Client.GetAccountNumber() == _AccountNumber)
			{
				Client = *this;
				break;
			}
		}
	}
};

const string clsBankClient::FileName = "Clients.txt";