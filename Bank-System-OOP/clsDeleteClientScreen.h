#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsDeleteClientScreen : protected clsMainScreen
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

	static void DeleteClient() {
		string AccountNumber = "";

		string Title = "Delete Client";

		_ShowMainScreen(Title);

		AccountNumber = clsInputValidate::ReadString("\nPlease enter an account number");

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "WRONG ACCOUNT NUMBER, Account Number Does Not Exist. Please enter correct number" << endl;
			cin >> AccountNumber;
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClientCard(Client);

		char Del = clsInputValidate::ReadCharacter("\nAre you sure you want to delete? Y/N\n");

		if (toupper(Del) == 'Y') {
			if (Client.Delete()) {
				cout << "\nAccount deleted successfully\n" << endl;
				_PrintClientCard(Client);

			}
		}
		else {
			cout << "Account had not been deleted" << endl;
		}


	}
};

