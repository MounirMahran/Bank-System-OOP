#pragma once	
#include <iostream>
#include "clsPerson.h"
#include <string>
#include <fstream>
#include <vector>

class clsBankClient : public clsPerson
{
private:
	enum enMode
	{
		EmptyMode = 0, UpdateMode = 1, AddNewMode = 2
	};

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool _MarkForDelete = false;

	static clsBankClient _GetEmptyClientObject() {

		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static clsBankClient _ConvertLineToClientObject(string Line, string Dellim = "#//#") {
		vector <string> vClient;
		vClient = clsString::Split(Line, Dellim);

		clsBankClient Client(enMode::UpdateMode, vClient[0], vClient[1], vClient[2], vClient[3],
			vClient[4], vClient[5], stod(vClient[6]));
		return Client;

	}

	static vector <clsBankClient> _LoadClientsDataFromFile() {
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) {
			string Line;

			while (getline(MyFile, Line)) {
				clsBankClient Client = _ConvertLineToClientObject(Line);
				vClients.push_back(Client);
			}

			MyFile.close();

		}

		return vClients;
	}

	static string _CovertClientObjectToLine(clsBankClient Client, string Dellim = "#//#") {
		string Line = "";

		Line += Client.FirstName + Dellim;
		Line += Client.LastName + Dellim;
		Line += Client.Email + Dellim;
		Line += Client.Phone + Dellim;
		Line += Client.AccountNumber() + Dellim;
		Line += Client.PinCode + Dellim;
		Line += to_string(Client.AccountBalance);

		return Line;

	}

	static void _SaveClientsDataToFile(vector <clsBankClient> vClients) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		string Line;

		if (MyFile.is_open()) {
			for (clsBankClient Client : vClients) {
				if (Client.MarkedForDelete() == false)
				{
					Line = _CovertClientObjectToLine(Client);
					MyFile << Line << endl;

				}
			}
			MyFile.close();
		}
	}

	static void _AddDataLineToFile(string DataLine) {
		fstream MyFile;

		MyFile.open("Clients.txt", ios::app); //append mode

		if (MyFile.is_open()) {
			MyFile << DataLine << endl;
		}

		MyFile.close();
	}

	void _Update() {
		vector <clsBankClient> _vClients;

		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& Client : _vClients) {
			if (Client.AccountNumber() == AccountNumber()) {
				Client = *this;
			}
		}

		_SaveClientsDataToFile(_vClients);
	}

	void _AddNew() {
		_AddDataLineToFile(_CovertClientObjectToLine(*this));
	}


public:
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber,
		string PinCode, double AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}


	static clsBankClient GetAddNewClientObject(string AccountNumber) {
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool MarkedForDelete() {
		return _MarkForDelete;
	}

	bool IsEmpty() {
		return _Mode == enMode::EmptyMode;
	}

	//getter for Account Number

	string AccountNumber() {
		return _AccountNumber;
	}

	//Setter and getter for Account pincode
	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}

	string GetPinCode() {
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;


	//Setter and getter for Account balance 
	void SetAccountBalance(double AccountBalance) {
		_AccountBalance = AccountBalance;
	}

	double GetAccountBalance() {
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) double AccountBalance;


	/*
	Substituted method to split UI related code out of Buisness code
	void Print() {
		cout << "Client Card" << endl;
		cout << "____________________________\n" ;
		cout << "\nFirst Name      : " << FirstName;
		cout << "\nLast Name       : " << LastName;
		cout << "\nFull            : " << FullName();
		cout << "\nEmail           : " << Email;
		cout << "\nPhone           : " << Phone;
		cout << "\nAccount Number  : " << _AccountNumber;
		cout << "\nPinCode         : " << _PinCode;
		cout << "\nAccount Balance : " << _AccountBalance;
		cout << "\n____________________________\n";
	}*/

	static clsBankClient Find(string AccountNumber) {

		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) {
			string Line;

			while (getline(MyFile, Line)) {
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber) {
					MyFile.close();
					return Client;
				}

			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode) {

		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) {
			string Line;

			while (getline(MyFile, Line)) {
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode) {
					MyFile.close();
					return Client;
				}

			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber) {
		clsBankClient Client = Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	bool Delete() {
		vector <clsBankClient> _vClients;

		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& Client : _vClients) {
			if (Client.AccountNumber() == _AccountNumber) {
				Client._MarkForDelete = true;
				break;
			}
		}

		_SaveClientsDataToFile(_vClients);

		*this = _GetEmptyClientObject();

		return true;
	}

	enum enSaveResults { svFailedEmptyObject = 0, svSucceeded = 1, svFailedObjInUse = 2 };

	enSaveResults Save() {
		switch (_Mode)
		{
		case clsBankClient::EmptyMode:
			return enSaveResults::svFailedEmptyObject;

		case clsBankClient::UpdateMode:
			_Update();
			return enSaveResults::svSucceeded;

		case clsBankClient::AddNewMode:
			if (IsClientExist(_AccountNumber)) {
				return enSaveResults::svFailedEmptyObject;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

		}
	}

	static vector <clsBankClient> GetClientsList() {
		return _LoadClientsDataFromFile();
	}

	bool Withdraw(double Amount) {
		
		if (_AccountBalance >= Amount) {
					_AccountBalance -= Amount;
				}
		else return false;

		
		Save();

		return true;
	}

	bool Deposit(double Amount) {

		_AccountBalance += Amount;

		Save();

		return true;
	}
	
	bool Transfer(clsBankClient& Destination, double Amount) {
		return Withdraw(Amount) && Destination.Deposit(Amount);
	}

	static double GetTotalBalances() {
		vector <clsBankClient> vClients = _LoadClientsDataFromFile();

		double TotalBalances = 0;

		for (clsBankClient Client : vClients) {
			TotalBalances += Client.AccountBalance;
		}

		return TotalBalances;
	}

};

