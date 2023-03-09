#pragma once
#include "clsMainScreen.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUsersScreen : protected clsMainScreen
{
private:
	enum enManageUsersOptions {
		ListUsers = 1, AddNewUser = 2, DeleteUser = 3, 
		UpdateUser = 4, FindUser = 5, MainMenu = 6	};

	static void _ShowUsersListScreen() {
		system("cls");
		//cout << "List Users Screen will be here" << endl;
		clsListUsersScreen::ListUsers();
	}

	static void _ShowAddNewUserScreen() {
		system("cls");
		//cout << "Add New User Screen will be here" << endl;
		clsAddNewUserScreen::AddNewUser();
	}

	static void _ShowDeleteUserScreen() {
		system("cls");
		//cout << "Delete User Screen will be here" << endl;
		clsDeleteUserScreen::DeleteUser();
	}

	static void _ShowUpdateUserScreen() {
		system("cls");
		//cout << "Update User Screen will be here" << endl;
		clsUpdateUserScreen::UpdateUser();
	}

	static void _ShowFindUserScreen() {
		system("cls");
		//cout << "Find User Screen will be here" << endl;
		clsFindUserScreen::FindUser();
	}

	static short _ReadUserInput() {
		cout << "\t\t\t\tPlease Choose what to do [1] -> [6]   ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6);
		return Choice;
	}

	static void _PerformManageUsersMenuOptions(enManageUsersOptions Choice) {
		switch (Choice)
		{
		case enManageUsersOptions::ListUsers:
			_ShowUsersListScreen();
			system("pause");
			ShowManageUsersScreen();
			break;
		case enManageUsersOptions::AddNewUser:
			_ShowAddNewUserScreen();
			system("pause");
			ShowManageUsersScreen();
			break;
		case enManageUsersOptions::DeleteUser:
			_ShowDeleteUserScreen();
			system("pause");
			ShowManageUsersScreen();
			break;
		case enManageUsersOptions::UpdateUser:
			_ShowUpdateUserScreen();
			system("pause");
			ShowManageUsersScreen();
			break;
		case enManageUsersOptions::FindUser:
			_ShowFindUserScreen();
			system("pause");
			ShowManageUsersScreen();
			break;
		case enManageUsersOptions::MainMenu:{}
			//break;
		}
	}
public:
	static void ShowManageUsersScreen() {
		
		system("cls");
		cout << endl;

		string Title = "Manage Users Screen";
		_ShowMainScreen(Title);

		cout << "\t\t\t   ==========================================\n";
		cout << "\t\t\t\t\t Manage Users Menu\n";
		cout << "\t\t\t   ==========================================\n";
		cout << "\t\t\t\t[1] Show Users List \n";
		cout << "\t\t\t\t[2] Add New User    \n";
		cout << "\t\t\t\t[3] Delete User     \n";
		cout << "\t\t\t\t[4] Update User Info\n";
		cout << "\t\t\t\t[5] Find User       \n";
		cout << "\t\t\t\t[6] Main Menu           \n";
		cout << "\t\t\t   ==========================================\n";

		cout << endl;

		_PerformManageUsersMenuOptions((enManageUsersOptions)_ReadUserInput());

	}

};

