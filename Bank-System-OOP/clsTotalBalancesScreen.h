#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsUtil.h"
#include "clsMainScreen.h"
#include <iomanip>
using namespace std;

class clsTotalBalancesScreen : protected clsMainScreen
{
private:
	static void _PrintClientBalanceDataLine(clsBankClient Client) {
		cout << "\t\t\t | " << left << setw(15) << Client.AccountNumber();
		cout << " | " << left << setw(20) << Client.FullName();
		cout << " | " << left << setw(15) << Client.AccountBalance << " | " << endl;
	}

public:
	static void ShowTotalBalances() {
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "Total Balances Screen";
		_ShowMainScreen(Title);

		cout << "\n\t\t\t____________________________________________________________\n" << endl;

		cout << "\n\t\t\t | " << left << setw(15) << "AccountNumber";
		cout << " | " << left << setw(20) << "Client Name";
		cout << " | " << left << setw(15) << "Account Balance" << " | " << endl;

		cout << "\n\t\t\t____________________________________________________________\n" << endl;

		if (vClients.size() == 0) {
			cout << "\n\n\n\t\t\t The list has no clients\n\n\n" << endl;
		}
		else {
			for (clsBankClient Client : vClients) {
				_PrintClientBalanceDataLine(Client);
			}
			cout << "\n\t\t\t____________________________________________________________\n" << endl;

		}

		cout << "\t\t\tTotal Balances: " << clsBankClient::GetTotalBalances() << endl;
		cout << "\t\t\tTotal Balances: " << clsUtil::NumberToText(clsBankClient::GetTotalBalances()) << endl << endl;
	}

};

