#pragma once
#include <iostream>
#include "clsString.h"

class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:
	clsPerson(string FirstName, string LastName, string Email, string Phone) {
		
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;

	}
	
	//Setter and Getter for fitst name
	void SetFirstName(string FirstName) {
		_FirstName = FirstName;
	}

	string GetFirstName() {
		return _FirstName;
	}

	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;


	//Setter and Getter for last name
	void SetLastName(string LastName) {
		_LastName = LastName;
	}

	string GetLastName() {
		return _LastName;
	}

	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;


	//Setter and Getter for Email
	void SetEmail(string Email) {
		_Email = Email;
	}

	string GetEmail() {
		return _Email;
	}

	__declspec(property(get = GetEmail, put = SetEmail)) string Email;


	//Setter and Getter for phine
	void SetPhone(string Phone) {
		_Phone = Phone;
	}

	string GetPhone() {
		return _Phone;
	}

	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;

	string FullName() {
		return _FirstName + " " + _LastName;
	}

};

