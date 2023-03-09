#pragma once
#include "clsMainScreen.h"
#include "clsUser.h"

class clsListUsersScreen : protected clsMainScreen
{
private:
	static void _PrintUserDataLine(clsUser User) {

		cout << " | " << left << setw(15) << User.UserName;
		cout << " | " << left << setw(20) << User.FullName();
		cout << " | " << left << setw(15) << User.Phone;
		cout << " | " << left << setw(20) << User.Email;
		cout << " | " << left << setw(15) << User.Password;
		cout << " | " << left << setw(15) << User.Permissions << " | " << endl;

	}
public:
	static void ListUsers() {
		vector <clsUser> vUsers = clsUser::GetUsersList();

		string Title = "Users List";

		_ShowMainScreen(Title);


		cout << "\n\n\t\t\t\t\t\t Users List(" << vUsers.size() << ")" << endl;
		cout << "\n_________________________________________________________________";
		cout << "______________________________________________________\n" << endl;

		cout << "\n | " << left << setw(15) << "UserName";
		cout << " | " << left << setw(20) << "Full Name";
		cout << " | " << left << setw(15) << "Phone";
		cout << " | " << left << setw(20) << "Email";
		cout << " | " << left << setw(15) << "Password";
		cout << " | " << left << setw(15) << "Permessions" << " | " << endl;

		cout << "\n_________________________________________________________________";
		cout << "______________________________________________________\n" << endl;
		if (vUsers.size() == 0) {
			cout << "\n\n\n The list has no Users\n\n\n" << endl;
		}
		else {
			for (clsUser Client : vUsers) {
				_PrintUserDataLine(Client);
			}
			cout << "\n_________________________________________________________________";
			cout << "______________________________________________________\n" << endl;

		}
	}
};

