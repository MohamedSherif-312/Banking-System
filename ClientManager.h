#pragma once
#include <string>
#include "File_Manager.h"
#include "client.h"
using namespace std;

class ClientManager {
private:
	static void PrintClientMenu()
	{
		cout << "1- Display My INFO\n";
		cout << "2- Check Balance\n";
		cout << "3- Update Password\n";
		cout << "4- Withdraw Amount\n";
		cout << "5- Deposit Amount\n";
		cout << "6- Transfer Amount\n";
		cout << "7- Logout\n";
	}
	static void Back(client* client)
	{
		cout << endl;
		system("pause");
		ClientOptions(client);
	}
public:
	static void ChangePassword(person* person)
	{
		string password;
		cout << "Enter new password\n";
		cin >> password;
		person->setpassword(password);
	}
	static client* login(int id, string password)
	{
		for (clientIT = allClients.begin(); clientIT < allClients.end(); clientIT++)
		{
			if (clientIT[0].getid() == id && clientIT[0].getpass() == password)
			{
				return clientIT._Ptr;
			}
		}
		return NULL;
	}
	static bool ClientOptions(client* client)
	{
		PrintClientMenu();
		cout << "What do you want to do, " << client->getname() << "? \n";
		int choice, id;
		double amount;
		employee e;
		cin >> choice;
		switch (choice)
		{
		case 1:
			client->display();
			break;
		case 2:
			client->checkbalance();
			break;
		case 3:
			ChangePassword(client);
			break;
		case 4:
			client->withdraw();
			break;
		case 5:
			client->deposit();
			break;
		case 6:
		{
			cout << "Enter ID of the person you want to transfer to: \n";
			cin >> id;
			while (e.searchClient(id) == NULL)
			{
				cout << "Invalid id.\n";
				cout << "Receiver's ID : \n";
				cin >> id;
			}
			client->transeferto(*e.searchClient(id));
			break;
		}
		case 7:
			return false;
			break;
		default:
		{
			cout << "Invalid entry, Please try again...\n";
			ClientOptions(client);
			return true;
		}
		}
		Back(client);
		return true;
	}
};