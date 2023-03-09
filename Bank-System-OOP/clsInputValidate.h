#pragma once
#include "clsDate.h"
#include "iostream"

class clsInputValidate
{
public:
	static bool IsNumberBetween(short Num, short From, short To) {
		return Num >= From && Num <= To;
	}

	static bool IsNumberBetween(int Num, int From, int To) {
		return Num >= From && Num <= To;
	}

	static bool IsNumberBetween(float Num, float From, float To) {
		return Num >= From && Num <= To;
	}

	static bool IsNumberBetween(double Num, double From, double To) {
		return Num >= From && Num <= To;
	}

	static bool IsDateBetween(clsDate Date, clsDate Date1, clsDate Date2) {
		
		clsDate From;
		clsDate To;

		if (clsDate::IsDate1AfterDate2(Date2, Date1)) {
			From = Date1;
			To = Date2;
		}
		else {
			From = Date2;
			To = Date1;
		}
		
		
		return (clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualtoDate2(Date, From))
			&& (clsDate::IsDate1AfterDate2(To, Date) || clsDate::IsDate1EqualtoDate2(Date, To));
	}

	static int ReadIntNumber(string ErrorMessage = "Invlaid Number, enter it again") {
		int Num;
		
		while (!(cin >> Num)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
		}
		return Num;
		
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not in range, enter it again") {
		int Num = ReadIntNumber();
		while (!IsNumberBetween(Num, From, To)) {
			cout << ErrorMessage << endl;
			Num = ReadIntNumber();	
		}

		return Num;

	}

	static double ReadDblNumber(string ErrorMessage = "Invlaid Number, enter it again") {
		double Num;

		while (!(cin >> Num)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
		}
		return Num;

	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not in range, enter it again") {
		double Num = ReadDblNumber();
		while (!IsNumberBetween(Num, From, To)) {
			cout << ErrorMessage << endl;
			Num = ReadDblNumber();

		}

		return Num;

	}

	static short ReadShortNumber(string ErrorMessage = "Invlaid Number, enter it again") {
		short Num;

		while (!(cin >> Num)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
		}
		return Num;

	}

	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not in range, enter it again") {
		 short Num = ReadDblNumber();
		while (!IsNumberBetween(Num, From, To)) {
			cout << ErrorMessage << endl;
			Num = ReadDblNumber();

		}

		return Num;

	}

	static bool IsValidDate(clsDate Date) {
		return clsDate::IsValidDate(Date);
	}

	static float ReadFloatNumber(string Message) {
		float Num;

			cout << Message << endl;
			cin >> Num;

		return Num;
	}

	static string ReadString(string Message) {
		string Str;

		cout << Message << endl;
		getline(cin >> ws, Str);

		return Str;
	}

	static char ReadCharacter(string Message) {
		char Ch;
		cout << Message << endl;
		cin >> Ch;
		return Ch;
	}
};

