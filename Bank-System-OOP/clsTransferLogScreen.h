#pragma once
#include "clsMainScreen.h"

class clsTransferLogScreen : protected clsMainScreen
{
private:
	static void _PrintOneTransfer(string Line) {
		vector <string> vLine = clsString::Split(Line, "#//#");
		cout << " | " << left << setw(23) << vLine[0];
		cout << " | " << left << setw(10) << vLine[1];
		cout << " | " << left << setw(10) << vLine[2];
		cout << " | " << left << setw(15) << vLine[3];
		cout << " | " << left << setw(15) << vLine[4];
		cout << " | " << left << setw(15) << vLine[5];
		cout << " | " << left << setw(10) << vLine[6];
		cout << "| " << endl;
	}
public:
	static void PrintLoginRegister() {
		string Title = "Show Transfer Log Screen";
		_ShowMainScreen(Title);

		cout << "\n________________________________________________________________________________________________________________________\n" << endl;

		cout << "\n | " << left << setw(23) << "Date/Time";
		cout << " | " << left << setw(10) << "S.Acc";
		cout << " | " << left << setw(10) << "R.Acc";
		cout << " | " << left << setw(15) << "Amount";
		cout << " | " << left << setw(15) << "R.Acc Balance";
		cout << " | " << left << setw(15) << "R.Acc Balance";
		cout << " | " << left << setw(10) << "User" << "| " << endl;

		cout << "\n________________________________________________________________________________________________________________________\n" << endl;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);


		if (MyFile.is_open()) {
			string Line = "";
			while (getline(MyFile, Line)) _PrintOneTransfer(Line);

			MyFile.close();
		}
		cout << "\n________________________________________________________________________________________________________________________\n" << endl;
	}
};

