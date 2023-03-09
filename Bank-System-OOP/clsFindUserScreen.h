#pragma once
#include "clsUser.h"
#include "clsMainScreen.h"
#include "clsInputValidate.h"
class clsFindUserScreen : protected clsMainScreen
{
private:
	static void _PrintUserCard(clsUser User) {
		cout << "User Card" << endl;
		cout << "____________________________\n";
		cout << "\nFirst Name      : " << User.FirstName;
		cout << "\nLast Name       : " << User.LastName;
		cout << "\nFull Name       : " << User.FullName();
		cout << "\nEmail           : " << User.Email;
		cout << "\nPhone           : " << User.Phone;
		cout << "\nUserName        : " << User.UserName;
		cout << "\nPassword        : " << User.Password;
		cout << "\nPermissions     : " << User.Permissions;
		cout << "\n____________________________\n";
	}

public:
	static void FindUser() {
		string Title = "Find User Screen";
		_ShowMainScreen(Title);

		string UserName = "";
		UserName = clsInputValidate::ReadString("Please enter a username");

		if (clsUser::IsUserExist(UserName)) {
			clsUser User = clsUser::Find(UserName);
			_PrintUserCard(User);
		}
		else {
			cout << "User does not exist" << endl;
		}
	}

};

