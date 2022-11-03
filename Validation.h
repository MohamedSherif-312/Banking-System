#pragma once
#include <iostream>
#include <string>
#include <exception>
using namespace std;
class validations {
protected:
	
public:
	static bool name_validation(string name)
	{
		for (int i = 0; i < name.size(); i++)
		{
			if (!isalpha(name[i]))
			{
				return false;
			}
		}
		if (name.size() < 4)
		{
			return false;
		}
		else if (name.size() > 20)
		{
			return false;
		}
		else
		{
			return true;
		}
		
	}
	static bool password_validation(string password)
	{
		if (password.size()<8)
		{
			return false;
		}
		else if (password.size()>20)
		{
			return false;
		}
		else
		{
			return true;
		}
	} 
	static bool salary_validation(double salary)
	{
		if(salary<5000)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	static bool balance_validation(double balance)
	{
		if (balance < 1500)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	static bool validateamount(double amount, double balance) {
		if (amount > balance) {
			return false;
		}
		else
			return true;
	}
};






