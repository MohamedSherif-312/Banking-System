#pragma once
#include "ClientManager.h"
using namespace std;

class EmployeeManager {
private:
	static void EmployeeMenu()
	{
		system("cls");
		cout << "1- Display My INFO\n";
		cout << "2- Update Password\n";
		cout << "3- Add new client\n";
		cout << "4- Search for client\n";
		cout << "5- List all clients\n";
		cout << "6- Edit client info\n";
		cout << "7- Logout\n";
	}
	static void Back(employee* employee)
	{
		cout << endl;
		system("pause");
		EmployeeOptions(employee);
	}
public:
	static void AddClient(employee* employee)
	{
		int id;
		string password, name;
		double balance;
		client c;
		cout << "Enter client's name : \n";
		cin >> name;
		c.setname(name);
		cout << "Enter client's password : \n";
		cin >> password;
		c.setpassword(password);
		cout << "Enter initial balance:\n";
		cin >> balance;
		c.setbalance(balance);
		cout << "Your ID is: ";
		id = FileHelper::getLast("clientid.txt");
		id++;
		cout << id << endl;
		c.setid(id);
		employee->addClient(c);
		cout << "Operation successful \n ";
	}
	static void SearchForClient(employee* employee)
	{
		int id;
		cout << "Enter client's ID : \n";
		cin >> id;
		if (employee->searchClient(id) == NULL)
		{
			cout << "No client found with the provided ID\n";
		}
		else
		{
			employee->searchClient(id)->display();
		}
	}
	static void EditClientInfo(employee* employee)
	{
		int id;
		cout << "Enter client ID : \n";
		cin >> id;
		if (employee->searchClient(id) == NULL)
		{
			cout << "No client found with the provided ID\n";
		}
		else
		{
			employee->searchClient(id)->display();
			string name, password;
			double balance;
			cout << "Enter new name: \n";
			cin >> name;
			cout << "Enter new password: \n";
			cin >> password;
			cout << "Enter new balance: \n";
			cin >> balance;
			employee->editClient(id, name, password, balance);
			cout << "Info updated\n";
		}
	}
	static employee* login(int id, string password)
	{

		for (empIT = allEmployees.begin(); empIT < allEmployees.end(); empIT++)
		{
			if (empIT[0].getid() == id && empIT[0].getpass() == password)
			{
				return empIT._Ptr;
			}
		}
		return NULL;
	}
	static bool EmployeeOptions(employee* employee)
	{
		EmployeeMenu();
		cout << "What do you want to do," << employee->getname() << "? \n";
		int choice;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			employee->display();
			break;
		case 2:
			ClientManager::ChangePassword(employee);
			break;
		case 3:
			AddClient(employee);
			break;
		case 4:
			SearchForClient(employee);
			break;
		case 5:
		{
			cout << "Clients : \n";
			employee->listClient();
			break;
		}
		case 6:
			EditClientInfo(employee);
			break;
		case 7:
			return false;
			break;
		default:
			EmployeeOptions(employee);
			return true;
			break;
		}
		Back(employee);
		return true;
	}
};