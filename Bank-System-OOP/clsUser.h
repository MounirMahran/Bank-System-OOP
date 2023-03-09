#pragma once
#include "clsPerson.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "clsBankClient.h"
#include "clsDate.h"
#include "clsUtil.h"

class clsUser : public clsPerson
{
private:
	enum enMode
	{
		EmptyMode = 0, UpdateMode = 1, AddNewMode = 2
	};

	enMode _Mode;
	string _UserName;
	string _Password;
	short _Permissions;
	bool _MarkForDelete = false;

	static clsUser _GetEmptyUserObject() {

		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static clsUser _ConvertLineToUserObject(string Line, string Dellim = "#//#") {
		vector <string> vUser;
		vUser = clsString::Split(Line, Dellim);

		clsUser User(enMode::UpdateMode, vUser[0], vUser[1], vUser[2], vUser[3],
			vUser[4], vUser[5], stoi(vUser[6]));
		return User;

	}

	static vector <clsUser> _LoadUsersDataFromFile() {
		vector <clsUser> vUsers;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open()) {
			string Line;

			while (getline(MyFile, Line)) {
				clsUser User = _ConvertLineToUserObject(Line);
				vUsers.push_back(User);
			}

			MyFile.close();

		}

		return vUsers;
	}

	static string _CovertUserObjectToLine(clsUser User, string Dellim = "#//#") {
		string Line = "";

		Line += User.FirstName + Dellim;
		Line += User.LastName + Dellim;
		Line += User.Email + Dellim;
		Line += User.Phone + Dellim;
		Line += User.UserName + Dellim;
		Line += User.Password + Dellim;
		Line += to_string(User.Permissions);

		return Line;

	}

	static void _SaveUsersDataToFile(vector <clsUser> vUsers) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);

		string Line;

		if (MyFile.is_open()) {
			for (clsUser User : vUsers) {
				if (User.MarkedForDelete() == false)
				{
					Line = _CovertUserObjectToLine(User);
					MyFile << Line << endl;

				}
			}
			MyFile.close();
		}
	}

	static void _AddDataLineToFile(string DataLine) {
		fstream MyFile;

		MyFile.open("Users.txt", ios::app); //append mode

		if (MyFile.is_open()) {
			MyFile << DataLine << endl;
		}

		MyFile.close();
	}

	void _Update() {
		vector <clsUser> _vUsers;

		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& User : _vUsers) {
			if (User.UserName == _UserName) {
				User = *this;
			}
		}

		_SaveUsersDataToFile(_vUsers);
	}

	void _AddNew() {
		_AddDataLineToFile(_CovertUserObjectToLine(*this));
	}

public:

	enum enPermissions {

		pAll = -1, pListClients = 1, pAddClient = 2, pDeleteClient = 4,
		pUpdateClient = 8, pFindClient = 16, pPerformTransactions = 32,
		pManageTheUsers = 64, pShowLoginRegister = 128
	};

	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, 
		string UserName, string Password, short Permissions) : clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}



	void SetUserName(string UserName) {
		_UserName = UserName;
	}

	string GetUserName() {
		return _UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	void SetPassword(string Password) {
		_Password = Password;
	}

	string GetPassword() {
		return _Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(short Permissions) {
		_Permissions = Permissions;
	}

	short GetPermissions() {
		return _Permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) short Permissions;

	//---------------------------//

	bool MarkedForDelete() {
		return _MarkForDelete;
	}

	static clsUser GetAddNewUserObject(string UserName) {
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	bool IsEmpty() {
		return _Mode == enMode::EmptyMode;
	}

	static clsUser Find(string UserName) {

		fstream MyFile;

		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open()) {
			string Line;

			while (getline(MyFile, Line)) {
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName) {
					MyFile.close();
					return User;
				}

			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName, string Password) {

		fstream MyFile;

		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open()) {
			string Line;

			while (getline(MyFile, Line)) {
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName && User.Password == Password) {
					MyFile.close();
					return User;
				}

			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	static bool IsUserExist(string UserName) {
		clsUser User = Find(UserName);
		return (!User.IsEmpty());
	}

	bool Delete() {
		vector <clsUser> _vUsers;

		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& User : _vUsers) {
			if (User.UserName == _UserName) {
				User._MarkForDelete = true;
				break;
			}
		}

		_SaveUsersDataToFile(_vUsers);

		*this = _GetEmptyUserObject();

		return true;
	}

	enum enSaveResults { svFailedEmptyObject = 0, svSucceeded = 1, svFailedObjInUse = 2 };

	enSaveResults Save() {
		switch (_Mode)
		{
		case clsUser::EmptyMode:
			return enSaveResults::svFailedEmptyObject;

		case clsUser::UpdateMode:
			_Update();
			return enSaveResults::svSucceeded;

		case clsUser::AddNewMode:
			if (IsUserExist(_UserName)) {
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

	static vector <clsUser> GetUsersList() {
		return _LoadUsersDataFromFile();
	}

	bool CheckAccessPermissions(enPermissions Permission) {
		if (this->Permissions == enPermissions::pAll) return true;

		if ((this->Permissions & Permission ) == Permission) return true;
		else return false;
	}

	string _PrepareLoginRecord(string Separator = "#//#") {
		string Line = "";

		Line += clsDate::DateTimeToString(clsDate());
		Line += Separator;
		Line += UserName;
		Line += Separator;
		Line += Password;
		Line += Separator;
		Line += to_string(Permissions);

		return Line;
	}

	string _PrepareTransferRecord(clsBankClient& Sender, clsBankClient& Receiver, double Amount, string Separator = "#//#") {
		string Line = "";

		Line += clsDate::DateTimeToString(clsDate());
		Line += Separator;
		Line += Sender.AccountNumber();
		Line += Separator;
		Line += Receiver.AccountNumber();
		Line += Separator;
		Line += to_string(Amount);
		Line += Separator;
		Line += to_string(Sender.AccountBalance);
		Line += Separator;
		Line += to_string(Receiver.AccountBalance);
		Line += Separator;
		Line += UserName;

		return Line;

	}

	public:
		void RegisterLogin() {
			fstream MyFile;

			MyFile.open("LoginRegister.txt", ios::out | ios::app);

			if (MyFile.is_open()) {
				
				string Line = _PrepareLoginRecord();

				MyFile << Line << endl;

				MyFile.close();

			}
		}

		bool RegisterTransfer(clsBankClient& Sender, clsBankClient& Receiver, double Amount) {
			fstream MyFile;

			MyFile.open("TransferLog.txt", ios::out | ios::app);

			if (MyFile.is_open()) {

				string Line = _PrepareTransferRecord(Sender, Receiver, Amount);

				MyFile << Line << endl;

				MyFile.close();

			}
			return true;
		}

};

