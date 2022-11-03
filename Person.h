#pragma once
#include <iostream>
#include <string>
#include "Validation.h" 
using namespace std;
class person : public validations{
protected:
	int id;
	string name, password;
public:
	person() 
	{ };
	person(string name, int id,string password)
	{
		setid(id);
		setname(name);
		setpassword(password);
	}
	void setid(int id) {
		this->id = id;
	}
	int getid() {
		return id;
	}
	void setname(string name) {
		if (validations::name_validation(name))
		{
		this->name = name;
		}
		else
		{
		cout << "name should be from 5 to 20 alphabetical characters\n";
		}
	}
	string getname() {
		return name;
	}
	void setpassword(string password) {
		if (validations::password_validation(password))
		{
		this->password = password;
		}
		else
		{
			cout << "password should be from 8 to 20 characters\n";
		}
	}
	string getpass() {
		return password;
	}
	virtual void display() = 0 {};
};
