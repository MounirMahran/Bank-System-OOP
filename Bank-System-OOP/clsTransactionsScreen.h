#pragma once
#include "clsMainScreen.h"
#include "clsMainMenuScreen.h"
#include "clsWithdrawScreen.h"
#include "clsDepositScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

class clsTransactionsScreen : protected clsMainScreen
{
private:
	enum enTransactionsOptions {
		Withdraw = 1, Deposit = 2, TotalBalances = 3, Transfers = 4, TransfersLog  = 5, MainMenu = 6
	};

	static short _ReadUserInput() {
		cout << "\t\t\t\tPlease Choose what to do [1] -> [6]   ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6);
		return Choice;
	}

	static void _ShowWithdrawScreen() {
		system("cls");
		//cout << "Withdraw Screen will be here" << endl;
		clsWithdrawScreen::Withdraw();
	}

	static void _ShowDepositScreen() {
		system("cls");
		//cout << "Deposit screen will be here" << endl;
		clsDepositScreen::Deposit();
	}

	static void _ShowTotalBalancesScreen() {
		system("cls");
		//cout << "Total balances screen will be here" << endl;
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _ShowTransferScreen() {
		system("cls");
		//cout << "Transfer screen will be here" << endl;
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen() {
		system("cls");
		//cout << "Transfer Log screen will be here" << endl;
		clsTransferLogScreen::PrintLoginRegister();
	}

	static void _PerformTransactionsOption(enTransactionsOptions Choice) {
		switch (Choice)
		{
		case enTransactionsOptions::Withdraw:
			_ShowWithdrawScreen();
			system("pause");
			ShowTransactionsScreen();
			break;
		case enTransactionsOptions::Deposit:
			_ShowDepositScreen();
			system("pause");
			ShowTransactionsScreen();
			break;
		case enTransactionsOptions::TotalBalances:
			_ShowTotalBalancesScreen();
			system("pause");
			ShowTransactionsScreen();
			break;
		case enTransactionsOptions::Transfers:
			_ShowTransferScreen();
			system("pause");
			ShowTransactionsScreen();
			break;
		case enTransactionsOptions::TransfersLog:
			_ShowTransferLogScreen();
			system("pause");
			ShowTransactionsScreen();
			break;
		case enTransactionsOptions::MainMenu:{}
			/*clsMainMenuScreen::MainMenuScreen();
			break;*/
		}
	}

public:
	static void ShowTransactionsScreen() {
		string Title = "Transactions Screen";
		_ShowMainScreen(Title);

		cout << "\t\t\t   ==========================================\n";
		cout << "\t\t\t\t\t    Transactions\n";
		cout << "\t\t\t   ==========================================\n";
		cout << "\t\t\t\t[1] Withdraw \n";
		cout << "\t\t\t\t[2] Deposit    \n";
		cout << "\t\t\t\t[3] Total Balances     \n";
		cout << "\t\t\t\t[4] Transfer\n";
		cout << "\t\t\t\t[5] Transfer Log\n";
		cout << "\t\t\t\t[6] Main Menu\n";
		cout << "\t\t\t   ==========================================\n";
		cout << endl;

		_PerformTransactionsOption((enTransactionsOptions)_ReadUserInput());

	}
};

