#pragma once
#include "clsMainScreen.h"

class clsShowLoginRegisterScreen : protected clsMainScreen
{
private:

	static void _PrintOneLogin(string Line) {
		vector <string> vLine = clsString::Split(Line, "#//#");
		cout << "\t\t\t | " << left << setw(30) <<vLine[0];
		cout << " | " << left << setw(10) << vLine[1];
		cout << " | " << left << setw(10) << vLine[2];
		cout << " | " << left << setw(10) << vLine[3];
		cout << " | " << endl;
	}


public:
	

	static void PrintLoginRegister() {
		string Title = "Show Login Register Screen";
		_ShowMainScreen(Title);

		cout << "\n\t\t\t_________________________________________________________________________\n" << endl;

		cout << "\n\t\t\t | " << left << setw(30) << "Date/Time";
		cout << " | " << left << setw(10) << "UserName";
		cout << " | " << left << setw(10) << "Password";
		cout << " | " << left << setw(10) << "Permissions" << "| " << endl;

		cout << "\n\t\t\t_________________________________________________________________________\n" << endl;

		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);


		if (MyFile.is_open()) {
			string Line = "";
			while (getline(MyFile, Line)) _PrintOneLogin(Line);

			MyFile.close();
		}
		cout << "\n\t\t\t_________________________________________________________________________\n" << endl;
	}

};

