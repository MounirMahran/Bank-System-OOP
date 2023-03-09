#pragma once
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
class clsAddNewUserScreen : protected clsMainScreen
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

	static void AddNewUser() {
		string UserName = "";
		string Title = "Add New User";

		_ShowMainScreen(Title);

		UserName = clsInputValidate::ReadString("\nPlease enter an username");

		while (clsUser::IsUserExist(UserName)) {
			cout << "WRONG USERNAME, UserName Exists" << endl;
			cin >> UserName;
		}

		clsUser User = clsUser::GetAddNewUserObject(UserName);

		_ReadUserData(User);


		clsUser::enSaveResults Result;

		Result = User.Save();

		switch (Result)
		{
		case clsUser::svFailedEmptyObject:
			cout << "\nFailed saving because of empty object" << endl;
			break;
		case clsUser::svFailedObjInUse:
			cout << "\nFailed saving because object already exists" << endl;
			break;
		case clsUser::svSucceeded:
			cout << "\nSuccessful adding new user" << endl;
			break;
		}

		_PrintUserCard(User);

	}

};

