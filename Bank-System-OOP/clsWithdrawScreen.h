#pragma once
#include "clsMainScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsWithdrawScreen : clsMainScreen
{
private:

public:
	static void Withdraw() {

		string Title = "Withdraw Screen";
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

		cout << "Please enter the amount you want to withdraw." << endl;
		double Amount = clsInputValidate::ReadDblNumberBetween(0, Client.AccountBalance,
			"Amount Exceeds balance, please enter an amount below balance.");

		char Withdraw = clsInputValidate::ReadCharacter("Are you sure you want to withdraw?");

		if (toupper(Withdraw) == 'Y') {
			if (Client.Withdraw(Amount)) cout << "Withdrawal went successfully, your current balance is: "<<Client.AccountBalance << endl;
			else cout << "Withdrawal went unsuccessfully" << endl;
		}
		else cout << "Withdrawal went unsuccessfully" << endl;
	}
};

