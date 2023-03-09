#pragma once
#include "clsMainScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDepositScreen : protected clsMainScreen
{
public:
	static void Deposit() {

		string Title = "Deposit Screen";
		_ShowMainScreen(Title);

		string AccountNumber = "";

		AccountNumber = clsInputValidate::ReadString("\nPlease enter an account number");

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "WRONG ACCOUNT NUMBER, Account Number Does Not Exist. Please enter correct number" << endl;
			cin >> AccountNumber;
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		system("cls");
		_ShowMainScreen(Title);

		cout << "Balance is: " << Client.AccountBalance << endl;

		cout << "Please enter the amount you want to deposit." << endl;
		double Amount = clsInputValidate::ReadDblNumber();

		char Withdraw = clsInputValidate::ReadCharacter("Are you sure you want to deposit?");

		if (toupper(Withdraw) == 'Y') {
			if (Client.Deposit(Amount)) cout << "Deposit went successfully, your current balance is: " << Client.AccountBalance << endl;
			else cout << "Deposit went unsuccessfully" << endl;
		}
		else cout << "Deposit went unsuccessfully" << endl;
	}
};

