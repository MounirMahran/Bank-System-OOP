#pragma once
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"

class clsUpdateUserScreen : protected clsMainScreen
{
private:
	static void _ReadUserData(clsUser& User) {

		User.FirstName = clsInputValidate::ReadString("Please enter the user first name");
		User.LastName = clsInputValidate::ReadString("Please enter the user last name");
		User.Email = clsInputValidate::ReadString("Please enter the user email");
		User.Phone = clsInputValidate::ReadString("Please enter the user phone");
		User.Password = clsInputValidate::ReadString("Please enter the user password");
		User.Permissions = _ReadPermissions();

	}

	static short _ReadPermissions() {
		char Accept = 'n';
		short Permission = 0;

		Accept = clsInputValidate::ReadCharacter("Do you want to give him all permissions? Y/N");

		cout << endl;
		if (toupper(Accept) == 'Y') return -1;
		else {
			Accept = clsInputValidate::ReadCharacter("Do you want to give him permissions to show clients? Y/N");
			if (toupper(Accept) == 'Y') Permission += clsUser::enPermissions::pListClients;

			Accept = clsInputValidate::ReadCharacter("Do you want to give him permissions to add clients? Y/N");
			if (toupper(Accept) == 'Y') Permission += clsUser::enPermissions::pAddClient;

			Accept = clsInputValidate::ReadCharacter("Do you want to give him permissions to delete clients? Y/N");
			if (toupper(Accept) == 'Y') Permission += clsUser::enPermissions::pDeleteClient;

			Accept = clsInputValidate::ReadCharacter("Do you want to give him permissions to update clients? Y/N");
			if (toupper(Accept) == 'Y') Permission += clsUser::enPermissions::pUpdateClient;

			Accept = clsInputValidate::ReadCharacter("Do you want to give him permissions to find clients? Y/N");
			if (toupper(Accept) == 'Y') Permission += clsUser::enPermissions::pFindClient;

			Accept = clsInputValidate::ReadCharacter("Do you want to give him permissions to perform transactions? Y/N");
			if (toupper(Accept) == 'Y') Permission += clsUser::enPermissions::pPerformTransactions;

			Accept = clsInputValidate::ReadCharacter("Do you want to give him permissions to manage users? Y/N");
			if (toupper(Accept) == 'Y') Permission += clsUser::enPermissions::pManageTheUsers;

			Accept = clsInputValidate::ReadCharacter("Do you want to give him permissions to show login register? Y/N");
			if (toupper(Accept) == 'Y') Permission += clsUser::enPermissions::pShowLoginRegister;

		}
		return Permission;
	}

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
	static void UpdateUser() {

		string UserName = "";
		string Title = "Update User";

		_ShowMainScreen(Title);

		UserName = clsInputValidate::ReadString("\nPlease enter an username");

		while (!clsUser::IsUserExist(UserName)) {
			cout << "WRONG USERNAME, UserName does not exist" << endl;
			cin >> UserName;
		}

		clsUser User = clsUser::Find(UserName);
		_PrintUserCard(User);
		cout << endl;

		char Del = clsInputValidate::ReadCharacter("\nAre you sure you want to update? Y/N\n");

		if (toupper(Del) == 'Y') {

			cout << "\nNew User Data" << endl;
			cout << "________________________" << endl;

			_ReadUserData(User);

			clsUser::enSaveResults Result;

			Result = User.Save();

			switch (Result)
			{
			case clsUser::svFailedEmptyObject:
				cout << "Failed update because of empty object" << endl;
				break;
			case clsUser::svSucceeded:
				cout << "Successful update" << endl;
				break;
			}

			_PrintUserCard(User);
		}

		else {
			cout << "User had not been updated" << endl;
		}
	}

};

