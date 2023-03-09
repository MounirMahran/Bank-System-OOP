#pragma once
#include "clsBankClient.h"
#include "clsMainScreen.h"
#include "clsInputValidate.h"

class clsFindClientScreen : protected clsMainScreen
{
private:
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
	static void FindClient() {
		string AccountNumber = "";

		string Title = "Find Client";

		_ShowMainScreen(Title);

		AccountNumber = clsInputValidate::ReadString("\nPlease enter an account number");

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "WRONG ACCOUNT NUMBER, Account Number Does Not Exist. Please enter correct number" << endl;
			cin >> AccountNumber;
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClientCard(Client);
	}
};

