#pragma once
#include "clsMainScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferScreen : protected clsMainScreen
{
private:
	static void _PrintClientCard(clsBankClient Client) {
		cout << "Client Card" << endl;
		cout << "____________________________\n";
		cout << "\nFull Name       : " << Client.FullName();
		cout << "\nAccount Number  : " << Client.AccountNumber();
		cout << "\nAccount Balance : " << Client.AccountBalance;
		cout << "\n____________________________\n";
	}

public:
	static void ShowTransferScreen() {
		string Title = "Transfer Screen";
		_ShowMainScreen(Title);

		string AccountNumber1 = "";

		AccountNumber1 = clsInputValidate::ReadString("\nPlease enter the account number you want to transfer from");

		while (!clsBankClient::IsClientExist(AccountNumber1)) {
			cout << "WRONG ACCOUNT NUMBER, Account Number Does Not Exist. Please enter correct number" << endl;
			cin >> AccountNumber1;
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber1);

		_PrintClientCard(Client1);
		cout << endl << endl;

		string AccountNumber2 = "";

		AccountNumber2 = clsInputValidate::ReadString("\nPlease enter the account number you want to transfer to");

		while (!clsBankClient::IsClientExist(AccountNumber2)) {
			cout << "WRONG ACCOUNT NUMBER, Account Number Does Not Exist. Please enter correct number" << endl;
			cin >> AccountNumber2;
		}

		clsBankClient Client2 = clsBankClient::Find(AccountNumber2);

		_PrintClientCard(Client2);
		cout << endl << endl;

		cout << "Please enter the amount to transfer" << endl;
		short Amount = clsInputValidate::ReadDblNumberBetween(1, Client1.AccountBalance, "Amount exceeds account balance");

		char Transfer = clsInputValidate::ReadCharacter("Are you sure you want to transfer? Y/N");

		if (toupper(Transfer) == 'Y' && Client1.Transfer(Client2, Amount) && CurrentUser.RegisterTransfer(Client1, Client2, Amount)) {
			cout << "Transfer went successfully." << endl;
			_PrintClientCard(Client1);
			cout << endl << endl;
			_PrintClientCard(Client2);
		}


	}
};

