#pragma once
#include "clsUser.h"
#include "clsMainScreen.h"
#include "clsInputValidate.h"
class clsDeleteUserScreen : protected clsMainScreen
{
private:
	static void _PrintUserCard(clsUser User) {
		cout << "Client Card" << endl;
		cout << "____________________________\n";
		cout << "\nFirst Name      : " << User.FirstName;
		cout << "\nLast Name       : " << User.LastName;
		cout << "\nFull            : " << User.FullName();
		cout << "\nEmail           : " << User.Email;
		cout << "\nPhone           : " << User.Phone;
		cout << "\nUserName        : " << User.UserName;
		cout << "\nPassword        : " << User.Password;
		cout << "\nPermissions     : " << User.Permissions;
		cout << "\n____________________________\n";
	}

public:

	static void DeleteUser() {
		string UserName = "";

		string Title = "Delete User";

		_ShowMainScreen(Title);

		UserName = clsInputValidate::ReadString("\nPlease enter an username");

		while (!clsUser::IsUserExist(UserName)) {
			cout << "WRONG USERNAME, UserName Does Not Exist. Please enter correct number" << endl;
			cin >> UserName;
		}

		clsUser User = clsUser::Find(UserName);
		_PrintUserCard(User);

		char Del = clsInputValidate::ReadCharacter("\nAre you sure you want to delete? Y/N\n");

		if (toupper(Del) == 'Y') {
			if (User.Delete()) {
				cout << "\nUser deleted successfully\n" << endl;
				_PrintUserCard(User);

			}
		}
		else {
			cout << "User had not been deleted" << endl;
		}


	}
};

