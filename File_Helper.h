#pragma once
#include <fstream>
#include "Client.h"
#include "Admin.h"
#include "Employee.h"
#include "Parser.h"

using namespace std;

class FileHelper
{

public:
	static void saveClient(client c)
	{				
		fstream file("C:\\DataBase\\clients\\clients.txt", ios::app);
		file << c.getname() << '&' << c.getpass() << '&' << c.getbalance() << '&' << c.getid() << endl;
		file.close();
		saveLast("C:\DataBase\clients\lastClient.txt", c.getid());

	}

	static void saveEmployee(employee e)
	{
		fstream file("C:\\DataBase\\employees\\employees.txt", ios::app);
		file << e.getname() << '&' << e.getpass() << '&' << e.getsalary() << '&' << e.getid() << endl;
		file.close();
		saveLast("C:\DataBase\employees\lastEmployee.txt", e.getid());
	}

	static void saveAdmin(admin a)
	{
		fstream file("C:\\DataBase\\admins\\admins.txt", ios::app);
		file << a.getname() << '&' << a.getpass() << '&' << a.getsalary() << '&' << a.getid() << endl;
		file.close();
		saveLast("C:\DataBase\\admins\lastAdmin.txt", a.getid());

	}

	static void getAllClients()
	{   
		fstream file("C:\\DataBase\\clients\\clients.txt", ios::in);
		string line;
		while (getline(file, line))
		{
			client c = Parser::parseToClient(line);
			allClients.push_back(c);
		}
		file.close();
	}

	static void getAllEmployees()
	{
		fstream file("C:\\DataBase\\employees\\employees.txt", ios::in);
		string line;
		while (getline(file, line))
		{
			employee e = Parser::parseToEmployee(line);
			allEmployees.push_back(e);
		}
		file.close();
	}

	static void getAllAdmins()
	{
		fstream file("C:\\DataBase\\admins\\admins.txt", ios::in);
		string line;
		while (getline(file, line))
		{
			admin a = Parser::parseToAdmin(line);
			allAdmins.push_back(a);
		}
		file.close();
	}

	static void saveLast(string fileName,int id)
	{
		fstream file;
		file.open(fileName, ios::out);
		file << id;
		file.close();

	}

	static int getLast(string fileName)
	{
		string id;
		int ID;
		fstream file;
		file.open(fileName, ios::in);
		file >> id;
		file.close();
		return ID = stoi(id);
	}

	static void clearFile(string fileName, string lastIdFile, char Rank)
	{	// PLEASE DON'T ASK ME FEHAA, COPIED AND PASTED FROM STACK OVERFLOW :)
		fstream file;
		file.open(fileName, ios::out);
		file.close();
		file.open(lastIdFile, ios::out);
		if (Rank == 'a')
		{
			file << 11000;
		}
		else if (Rank == 'c')
		{
			file << 33000;
		}
		else if (Rank == 'e')
		{
			file << 55000;
		}
	}
};