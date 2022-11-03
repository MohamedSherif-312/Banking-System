#pragma once
#include "EmployeeManager.h"
using namespace std;

class AdminManager {
private:
	static void AdminMenu(admin* admin)
	{
		system("cls");
		cout << "1- Add new client \n";
		cout << "2- Search for a client\n";
		cout << "3- Edit a client\n";
		cout << "4- Remove existing client\n";
		cout << "5- List all clients\n";
		cout << "6- Add new employee\n";
		cout << "7- Search for an employee\n";
		cout << "8- Edit an employee\n";
		cout << "9- Remove an existing employee\n";
		cout << "10- List all employees\n";
		cout << "11- Assign new admin\n";
		cout << "12- Display my info \n";
		cout << "13- Clear Clients' file \n";
		cout << "14- Clear Employees' file \n";
		cout << "15- Logout\n";
	}
	static void back(admin* admin)
	{
		cout << endl;
		system("pause");
		AdminOptions(admin);
	}
public:
	static void AddAdmin(admin* a)
	{
		int id;
		string password, name;
		double salary;
		admin a1;
		cout << "Enter Admin's name : \n";
		cin >> name;
		a1.setname(name);
		cout << "Enter Admin's password : \n";
		cin >> password;
		a1.setpassword(password);
		cout << "Enter initial salary:\n";
		cin >> salary;
		a1.setsalary(salary);
		cout << "Admin's ID is: ";
		id = FileHelper::getLast("adminid.txt");
		id++;
		cout << id << endl;
		a1.setid(id);
		allAdmins.push_back(a1);
		cout << "Operation successful \n ";
	}
	static void AddEmployee(admin* admin)
	{
		int id;
		string password, name;
		double salary;
		employee e;
		cout << "Enter employee's name : \n";
		cin >> name;
		e.setname(name);
		cout << "Enter employee's password : \n";
		cin >> password;
		e.setpassword(password);
		cout << "Enter initial salary:\n";
		cin >> salary;
		e.setsalary(salary);
		cout << "Employee's ID is: ";
		id = FileHelper::getLast("employeeid.txt");
		id++;
		cout << id << endl;
		e.setid(id);
		admin->addEmployee(e);
		cout << "Operation successful \n ";
	}
	static void SearchForEmployee(admin* admin)
	{
		int id;
		cout << "Enter Employee's ID : \n";
		cin >> id;
		if (admin->searchEmployee(id) == NULL)
		{
			cout << "No employee found with the provided ID\n";
		}
		else
		{
			admin->searchEmployee(id)->display();
		}
	}
	static void EditEmployee(admin* admin)
	{
		int id;
		cout << "Enter employee's ID : \n";
		cin >> id;
		if (admin->searchEmployee(id) == NULL)
		{
			cout << "No employee found with the provided ID\n";
		}
		else
		{
			string name, password;
			double salary;
			cout << "Enter new name: \n";
			cin >> name;
			cout << "Enter new password: \n";
			cin >> password;
			cout << "Enter new salary: \n";
			cin >> salary;
			admin->editEmployee(id, name, password, salary);
			cout << "Info updated\n";
		}
	}
	static admin* login(int id, string password)
	{
		for (int i = 0; i < allAdmins.size(); i++)
		{
			if (allAdmins[i].getid() == id && allAdmins[i].getpass() == password)
			{
				return &allAdmins[i];
			}
		}
		return NULL;
	}
	static void deleteclient(admin* admin) {
		int id;
		char yes;
		bool found = true;
		cout << "Enter ID of client you waant to delete: "; cin >> id;
		for (clientIT = allClients.begin(); clientIT < allClients.end(); clientIT++) {
			if (id == clientIT[0].getid()) {
				found = false;
				cout << "Client found:\n";
				clientIT[0].display();
				cout << "===========\n";
				cout << "Are you aure you want to delete this client?(y/n)\n";
				cin >> yes;
				if (yes == 'y' || yes == 'Y')
				{
					allClients.erase(clientIT);
					cout << "Client deleted successfully.\n";
					break;
				}
				else
					break;
			}
		}
		if (found) {
			cout << "Client doesn't exist...\n";
		}
	}
	static void deleteEmployee(admin* admin) {
		int id;
		char yes;
		bool found = true;
		cout << "Enter ID of employee you waant to delete: "; cin >> id;
		for (empIT = allEmployees.begin(); empIT < allEmployees.end(); empIT++) {
			if (id == empIT[0].getid()) {
				found = false;
				cout << "Employee found:\n";
				empIT[0].display();
				cout << "===========";
				cout << "Are you aure you want to delete this employee?(y/n)\n";
				cin >> yes;
				if (yes == 'y' || yes == 'Y')
				{
					allEmployees.erase(empIT);
					break;
				}
				else
					break;
			}
		}
		if (found) {
			cout << "Employee doesn't exist...\n";
		}
	}
	static bool AdminOptions(admin* admin)
	{
		AdminMenu(admin);
		cout << "What do you want to do, " << admin->getname() << "? \n";
		int choice;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
		{
			EmployeeManager::AddClient(admin);
			FileManager::UpdateClient();
			break;
		}
		case 2:
		{
			EmployeeManager::SearchForClient(admin);
			FileManager::UpdateClient();
			break;
		}
		case 3:
		{
			EmployeeManager::EditClientInfo(admin);
			FileManager::UpdateClient();
			break;
		}
		case 4:
		{
			deleteclient(admin);
			FileManager::UpdateClient();
			break;
		}
		case 5:
		{
			admin->listClient();
			break;
		}
		case 6:
		{
			AddEmployee(admin);
			FileManager::UpdateEmployee();
			break;
		}
		case 7:
		{
			SearchForEmployee(admin);
			FileManager::UpdateEmployee();
			break;
		}
		case 8:
		{
			EditEmployee(admin);
			FileManager::UpdateEmployee();
			break;
		}
		case 9:
		{
			deleteEmployee(admin);
			FileManager::UpdateEmployee();
			break;
		}
		case 10:
		{
			cout << "Employees: \n";
			admin->listEmployee();
			break;
		}
		case 11:
		{
			AddAdmin(admin);
			FileManager::UpdateAdmin();
			break;
		}
		case 12:
		{
			admin->display();
			break;
		}
		case 13:
		{
			FileManager::RemoveAllClients();
			break;
		}
		case 14:
		{
			FileManager::RemoveAllEmployees();
			break;
		}
		case 15:
		{
			return false;
			break;
		}
		default:
		{
			AdminOptions(admin);
			return true;
			break;
		}
		}
		back(admin);
		return true;
	}
};