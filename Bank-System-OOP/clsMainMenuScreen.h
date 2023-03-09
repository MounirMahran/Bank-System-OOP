#pragma once
#include <iostream>
#include "clsMainScreen.h"
#include "clsInputValidate.h"
#include "clsShowClientsListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginScreen.h"
#include "Global.h"
#include "clsShowLoginRegisterScreen.h"

using namespace std;

class clsMainMenuScreen : protected clsMainScreen
{
private:

	enum _enMainMenuOptions{
		ShowAllClients = 1, AddNewClient = 2, DeleteClient = 3, UpdateClient = 4, FindClient = 5, Transactions = 6, 
		ManageUsers = 7, ShowLoginRegister = 8, Logout = 9 
	};
	
	static void _ShowClientsListScreen() {
		if (!_CheckAccess(clsUser::enPermissions::pListClients)) return;
		system("cls");
		//cout << "List Clients List Code Will Be Here" << endl;
		clsShowClientsListScreen::ListClients();
	}

	static void _AddNewClientScreen() {
		if (!_CheckAccess(clsUser::enPermissions::pAddClient)) return;
		system("cls");
		//cout << "Add New Client Code Will Be Here" << endl;
		clsAddNewClientScreen::AddNewClient();
	}

	static void _DeleteClientScreen() {
		if (!_CheckAccess(clsUser::enPermissions::pDeleteClient)) return;
		system("cls");
		//cout << "Delete Client Code Will Be Here" << endl;
		clsDeleteClientScreen::DeleteClient();
	}

	static void _UpdateClientScreen() {
		if (!_CheckAccess(clsUser::enPermissions::pUpdateClient)) return;
		system("cls");
		//cout << "Update Client Code Will Be Here" << endl;
		clsUpdateClientScreen::UpdateClient();
	}

	static void _FindClientScreen() {
		if (!_CheckAccess(clsUser::enPermissions::pFindClient)) return;
		system("cls");
		//cout << "Find Client Code Will Be Here" << endl;
		clsFindClientScreen::FindClient();
	}

	static void _TransactionsScreen() {
		if (!_CheckAccess(clsUser::enPermissions::pPerformTransactions)) return;
		system("cls");
		//cout << "Transactions Code Will Be Here" << endl;
		clsTransactionsScreen::ShowTransactionsScreen();
	}

	static void _ManageUsersScreen() {
		if (!_CheckAccess(clsUser::enPermissions::pManageTheUsers)) return;
		system("cls");
		//cout << "Manage Users Code Will Be Here" << endl;
		clsManageUsersScreen::ShowManageUsersScreen();
	}

	static short _ReadUserInput() {
		cout << "\t\t\t\tPlease Choose what to do [1] -> [9]   ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 9);
		return Choice;
	}

	static void _ShowLoginRegisterScreen() {
		if (!_CheckAccess(clsUser::enPermissions::pShowLoginRegister)) return;
		system("cls");
		//cout << "Login register code will be here" << endl;
		clsShowLoginRegisterScreen::PrintLoginRegister();
	}

	static void _Logout() {
		system("cls");
		CurrentUser = clsUser::Find("", "");
		//return;
	}

	static void _PerformMainMenuOptions(_enMainMenuOptions Choice) {
		
		switch (Choice)
		{
		case _enMainMenuOptions::ShowAllClients:
			_ShowClientsListScreen();
			system("pause");
			MainMenuScreen();
			break;
		case _enMainMenuOptions::AddNewClient:
			_AddNewClientScreen();
			system("pause");
			MainMenuScreen();
			break;
		case _enMainMenuOptions::DeleteClient:
			_DeleteClientScreen();
			system("pause");
			MainMenuScreen();
			break;
		case _enMainMenuOptions::UpdateClient:
			_UpdateClientScreen();
			system("pause");
			MainMenuScreen();
			break;
		case _enMainMenuOptions::FindClient:
			_FindClientScreen();
			system("pause");
			MainMenuScreen();
			break;
		case _enMainMenuOptions::Transactions:
			_TransactionsScreen();
			system("pause");
			MainMenuScreen();
			break;
		case _enMainMenuOptions::ManageUsers:
			_ManageUsersScreen();
			system("pause");
			MainMenuScreen();
			break;
		case _enMainMenuOptions::ShowLoginRegister:
			_ShowLoginRegisterScreen();
			system("pause");
			MainMenuScreen();
			break;
		case _enMainMenuOptions::Logout:
			_Logout();
			break;
		}
	}

public:

	static void MainMenuScreen() {
		system("cls");
		cout << endl;
		_ShowMainScreen("Main Screen");
		cout << "\t\t\t   ==========================================\n";
		cout << "\t\t\t\t\t    Main Menu\n";
		cout << "\t\t\t   ==========================================\n";
		cout << "\t\t\t\t[1] Show Clients List \n";
		cout << "\t\t\t\t[2] Add New Client    \n";
		cout << "\t\t\t\t[3] Delete Client     \n";
		cout << "\t\t\t\t[4] Update Client Info\n";
		cout << "\t\t\t\t[5] Find Client       \n";
		cout << "\t\t\t\t[6] Transactions      \n";
		cout << "\t\t\t\t[7] Manage Users      \n";
		cout << "\t\t\t\t[8] Show Login Register\n";
		cout << "\t\t\t\t[9] Logout            \n";
		cout << "\t\t\t   ==========================================\n";
		cout << endl;
		_PerformMainMenuOptions((_enMainMenuOptions) _ReadUserInput());

	}

};

