#pragma once
#include "AdminManager.h"
using namespace std;
class screens {
public:
	static void BankName()
	{

	}
	static void welcome()
	{

	}
	static void loginOptions() 
	{
		cout << "Login As : \n";
		cout << "1-Admin \n";
		cout << "2-Employee\n";
		cout << "3-Client \n";	
	}
	static int LoginAs()
	{
		loginOptions();
		int choice;
		cin >> choice;
		if (choice == 1 || choice == 2 || choice == 3)
		{
			return choice;
		}
		else
		{

			LoginAs();
		}
	}
	static void Invalid(int c)
	{
		cout << "Invalid Entry, Please try again\n";
		LoginScreen(c);
	}
	static void logout()
	{
		LoginScreen(LoginAs());
	}
	static void LoginScreen(int c)
	{
		int id;
		string password;
		system("cls");
		cout << "Enter ID : ";
		cin >> id;
		cout << "Enter password : ";
		cin >> password;
		switch (c)
		{
		case 1:
		{
			if (AdminManager::login(id, password) != NULL)
			{
				while (AdminManager::AdminOptions(AdminManager::login(id, password)) != false);
				logout();
			}
			else Invalid(1);
			break;
		}
		case 2:
		{
			if (EmployeeManager::login(id, password) != NULL)
			{
				while (EmployeeManager::EmployeeOptions(EmployeeManager::login(id, password)) != false);
				logout();
			}
			else Invalid(2);
			break;
		}
		case 3:
		{
			if (ClientManager::login(id, password) != NULL)
			{
				while (ClientManager::ClientOptions(ClientManager::login(id, password)) != false);
				logout();
			}
			else Invalid(3);
			break;
		}

		default:
			loginOptions();
		}
	}
public:
	static void runapp() 
	{
		FileManager::getData();
		welcome();
		LoginScreen(LoginAs());
	}
};