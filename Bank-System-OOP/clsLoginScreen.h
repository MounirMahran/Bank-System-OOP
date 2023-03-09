#pragma once
#include "clsUser.h"
#include "clsMainScreen.h"
#include "clsInputValidate.h"
#include "Global.h"
#include "clsMainMenuScreen.h"
#include "clsUtil.h"
class clsLoginScreen : protected clsMainScreen
{
private:


	static bool _Login() {
		string _UserName;
		string _Password;
		bool _LoginFailed;
		short Trials = 3;

		_LoginFailed = false;

		do {
			if (_LoginFailed) {
				cout << "\n\nWrong UserName/Password" << endl;
				cout << "You have "<<Trials-1<<" Trial/s" << endl;
				Trials--;
			}

			if (Trials == 0) {

				cout << "You are locked for 3 failed trials\n\n" << endl;
				return false;
			}

			_UserName = clsInputValidate::ReadString("\nPlease enter a username");
			_Password = clsInputValidate::ReadString("Please enter a password");

			CurrentUser = clsUser::Find(_UserName, _Password);

			_LoginFailed = CurrentUser.IsEmpty();

		} while (_LoginFailed);

		CurrentUser.RegisterLogin();
		clsMainMenuScreen::MainMenuScreen();
		return true;
	
	}

public:
	static bool LoginScreen() {
		string Title = "Login Screen";
		_ShowMainScreen(Title);
		return _Login();
	}

};

