#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
using namespace std;
class clsAddNewClientScreen : protected clsMainScreen
{
private:
	static void _ReadClientData(clsBankClient& Client) {


		Client.FirstName = clsInputValidate::ReadString("Please enter the client first name");
		Client.LastName = clsInputValidate::ReadString("Please enter the client last name");
		Client.Email = clsInputValidate::ReadString("Please enter the client email");
		Client.Phone = clsInputValidate::ReadString("Please enter the client phone");
		Client.PinCode = clsInputValidate::ReadString("Please enter the client pincode");
		cout << "Please enter the client account balance" << endl;
		Client.AccountBalance = clsInputValidate::ReadDblNumber();

	}

	static void _PrintClientCard(clsBankClient Client) {
		cout << "Client Card" << endl;
		cout << "____________________________\n";
		cout << "\nFirst Name      : " << Client.FirstName;
		cout << "\nLast Name       : " << Client.LastName;
		cout << "\nFull            : " << Client.FullName();
		cout << "\nEmail           : " << Client.Email;
		cout << "\nPhone           : " << Client.Phone;
		cout << "\nAccount Number  : " << Client.AccountNumber();
		cout << "\nPinCode         : " << Client.PinCode;
		cout << "\nAccount Balance : " << Client.AccountBalance;
		cout << "\n____________________________\n";
	}


public:

	static void AddNewClient() {
		string AccountNumber = "";
		string Title = "Add New Client";

		_ShowMainScreen(Title);

		AccountNumber = clsInputValidate::ReadString("\nPlease enter an account number");

		while (clsBankClient::IsClientExist(AccountNumber)) {
			cout << "WRONG ACCOUNT NUMBER, Account Number Exist" << endl;
			cin >> AccountNumber;
		}

		clsBankClient Client = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadClientData(Client);


		clsBankClient::enSaveResults Result;

		Result = Client.Save();

		switch (Result)
		{
		case clsBankClient::svFailedEmptyObject:
			cout << "\nFailed saving because of empty object" << endl;
			break;
		case clsBankClient::svFailedObjInUse:
			cout << "\nFailed saving because object already exists" << endl;
			break;
		case clsBankClient::svSucceeded:
			cout << "\nSuccessful adding new client" << endl;
			break;
		}

		//Client.Print();
		_PrintClientCard(Client);

	}
};

