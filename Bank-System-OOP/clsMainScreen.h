#pragma once
#include <iostream>
#include <iomanip>
#include "Global.h"
#include "clsUser.h"
#include "clsDate.h"
using namespace std;

class clsMainScreen
{
protected:
	
	static void _ShowMainScreen(string Title) {
		system("cls");
		cout  << "\t\t\t\t_________________________________\n\n";
		cout <<"\t\t\t\t         " << Title << "\n";
		cout  << "\t\t\t\t_________________________________\n\n";
		cout << "\t\t\t\t         Date    : " << clsDate::DateToString(clsDate()) << "\n";
		cout << "\t\t\t\t         UserName: " << CurrentUser.UserName << "\n";


	}

	static bool _CheckAccess(clsUser::enPermissions Permission) {
		if (!CurrentUser.CheckAccessPermissions(Permission)) {
			system("cls");
			cout << "\t\t\t\t_________________________________\n\n";
			cout << "\t\t\t\tAccess Denied, contact your admin" << "\n";
			cout << "\t\t\t\t_________________________________\n\n";
			//system("pause");
			return false;
		}
		return true;
	}
	
};

