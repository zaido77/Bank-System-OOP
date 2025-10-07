#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
using namespace std;

class clsBankClient : public clsPerson
{
	struct stTranferLogRecord;

private:
	static const string ClientsFileName;
	static const string TransferLogFileName;

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete = false;

	static stTranferLogRecord _ConvertLineToTransferLogRecord(string Line, string Delim = "#//#")
	{
		vector<string> vTranferLogRecord = clsString::Split(Line, Delim);

		stTranferLogRecord TranferLogRecord;

		TranferLogRecord.DateTime = vTranferLogRecord[0];
		TranferLogRecord.SourceAccNumber = vTranferLogRecord[1];
		TranferLogRecord.DestinationAccNumber = vTranferLogRecord[2];
		TranferLogRecord.Amount = stof(vTranferLogRecord[3]);
		TranferLogRecord.SourceAccBalance = stof(vTranferLogRecord[4]);
		TranferLogRecord.DestinationAccBalance = stof(vTranferLogRecord[5]);
		TranferLogRecord.UserName = vTranferLogRecord[6];

		return TranferLogRecord;
	}

	string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient, string UserName, string Delim = "#//#")
	{
		string TransferRecord = "";

		TransferRecord += clsDate::GetSystemDateTimeString() + Delim;
		TransferRecord += _AccountNumber + Delim;
		TransferRecord += DestinationClient.GetAccountNumber() + Delim;
		TransferRecord += to_string(Amount) + Delim;
		TransferRecord += to_string(_AccountBalance) + Delim;
		TransferRecord += to_string(DestinationClient.GetAccountBalance()) + Delim;
		TransferRecord += UserName;

		return TransferRecord;
	}

	void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
	{
		string DataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

		fstream MyFile;
		MyFile.open(TransferLogFileName, ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << "\n";


			MyFile.close();
		}
	}

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
		MyFile.open(ClientsFileName, ios::in);

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
		MyFile.open(ClientsFileName, ios::out);

		if (MyFile.is_open())
		{
			for (clsBankClient& Client : vClients)
			{
				if (!Client.GetMarkForDelete())
				{
					MyFile << _ConvertClientObjectToLine(Client) << "\n";
				}
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

	void _AddNew()
	{
		_AddDataLinetoFile(_ConvertClientObjectToLine(*this));
	}

	static void _AddDataLinetoFile(string DataLine)
	{
		fstream MyFile;
		MyFile.open(ClientsFileName, ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << "\n";

			MyFile.close();
		}
	}

public:
	struct stTranferLogRecord
	{
		string DateTime;
		string SourceAccNumber;
		string DestinationAccNumber;
		float Amount;
		float SourceAccBalance;
		float DestinationAccBalance;
		string UserName;
	};

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

	bool GetMarkForDelete()
	{
		return _MarkForDelete;
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

	void Deposit(float Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(float Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}

	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open(ClientsFileName, ios::in);

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
		MyFile.open(ClientsFileName, ios::in);

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

	enum enSaveResults { svFailedEmptyObject = 0, svSucceeded = 1, svFailedAccountNumberExists = 2 };

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

			if (IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFailedAccountNumberExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
		}
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector<clsBankClient> vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if (C.GetAccountNumber() == _AccountNumber)
			{
				C._MarkForDelete = true;
				_MarkForDelete = true;
				break;
			}
		}

		if (_MarkForDelete)
		{
			_SaveClientsDataToFile(vClients);
			*this = _GetEmptyClientObject();
			return true;
		}

		return false;
	}

	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static float GetTotalBalances()
	{
		vector<clsBankClient> vClients = GetClientsList();

		float TotalBalances = 0;

		for (clsBankClient& Client : vClients)
		{
			TotalBalances += Client.GetAccountBalance();
		}

		return TotalBalances;

	}

	bool Transfer(float Amount, clsBankClient& DestinationClient, string UserName)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}

		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient, UserName);

		return true;
	}

	static vector<stTranferLogRecord> GetTranferLogList()
	{
		vector<stTranferLogRecord> vTranferLogRecords;

		fstream MyFile;
		MyFile.open(TransferLogFileName, ios::in);

		if (MyFile.is_open())
		{
			string Line = "";
			stTranferLogRecord TranferLogRecord;

			while (getline(MyFile, Line))
			{
				TranferLogRecord = _ConvertLineToTransferLogRecord(Line);
				vTranferLogRecords.push_back(TranferLogRecord);
			}

			MyFile.close();
		}

		return vTranferLogRecords;
	}

};

const string clsBankClient::ClientsFileName = "Clients.txt";
const string clsBankClient::TransferLogFileName = "TransferLog.txt";