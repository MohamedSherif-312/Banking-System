#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Validation.h"
#include "Person.h"
class employee :public person
{
protected:
	double salary;
public:
	employee()
	{
		
	}
	employee(string name, string password, double salary,int id) : person(name,id, password)
	{
		setsalary(salary);
	}
	void setsalary(double salary) { 
		if (validations::salary_validation(salary))
		{
		this->salary = salary;
		}
		else
		{
			cout << "minimum value is 5000\n";
		}
	}
	double getsalary() {
		return salary;
	}
	void display() {
		cout << getname() << '\n' << "id = " << getid() << '\n' << "salary =" << salary << '\n';
	}
	//ADDED METHODS
	//=============
	void addClient(client& c) {
		allClients.push_back(c);
	}
	client* searchClient(int id) {
		for (int i = 0; i < allClients.size(); i++) {
			if (allClients[i].getid() == id) {
				client* c = &allClients[i];
				return c;
			}
		}
		return nullptr;
	}
	void listClient() {
		for (int i = 0; i < allClients.size(); i++)
		{
			cout << allClients[i].getid() << endl;
			cout << allClients[i].getname() << endl;
			cout << allClients[i].getpass() << endl;
			cout << allClients[i].getbalance() << endl;
		}
	}
	void editClient(int id, string name, string password, double balance) {
		client* c = searchClient(id);
		c->setname(name);
		c->setpassword(password);
		c->setbalance(balance);
	}
};
static vector<employee> allEmployees;
static vector<employee>::iterator empIT;