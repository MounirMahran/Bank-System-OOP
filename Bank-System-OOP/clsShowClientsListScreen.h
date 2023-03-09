#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsMainScreen.h"

using namespace std;

class clsShowClientsListScreen : protected clsMainScreen
{
private:

	static void _PrintClientDataLine(clsBankClient Client) {

		cout << " | " << left << setw(15) << Client.AccountNumber();
		cout << " | " << left << setw(20) << Client.FullName();
		cout << " | " << left << setw(15) << Client.Phone;
		cout << " | " << left << setw(20) << Client.Email;
		cout << " | " << left << setw(15) << Client.PinCode;
		cout << " | " << left << setw(15) << Client.AccountBalance << " | " << endl;

	}

public:

	static void ListClients() {
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "Clients List";

		_ShowMainScreen(Title);


		cout << "\n\n\t\t\t\t\t\t Clients List(" << vClients.size() << ")" << endl;
		cout << "\n_________________________________________________________________";
		cout << "______________________________________________________\n" << endl;

		cout << "\n | " << left << setw(15) << "Account Number";
		cout << " | " << left << setw(20) << "Client Name";
		cout << " | " << left << setw(15) << "Phone";
		cout << " | " << left << setw(20) << "Email";
		cout << " | " << left << setw(15) << "Pin Code";
		cout << " | " << left << setw(15) << "Account Balance" << " | " << endl;

		cout << "\n_________________________________________________________________";
		cout << "______________________________________________________\n" << endl;
		if (vClients.size() == 0) {
			cout << "\n\n\n The list has no clients\n\n\n" << endl;
		}
		else {
			for (clsBankClient Client : vClients) {
				_PrintClientDataLine(Client);
			}
			cout << "\n_________________________________________________________________";
			cout << "______________________________________________________\n" << endl;

		}
	}

};

