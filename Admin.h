#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"
class admin :public employee {
public:
	admin():employee()
	{ 
		
	}
	admin(string name, string password, double salary,int id) : employee(name, password, salary,id) {
		
	}
	void display() {

		cout << getname() << '\n' << "id = " << getid() << '\n' << "salary =" << getsalary() << '\n';
	}
    //ADDED METHODS
    //=============
	/*void addClient(client& c) {
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
	void listClient(client c) {
		cout << c.getid() << endl;
		cout << c.getname() << endl;
		cout << c.getpass() << endl;
		cout << c.getbalance() << endl;
	}
	void editClient(int id, string name, string password, double balance) {
		client* c = searchClient(id);
		c->setname(name);
		c->setpassword(password);
		c->setbalance(balance);
	}*/
    void addEmployee(employee& e)
    {
        allEmployees.push_back(e);
    }
    employee* searchEmployee(int id)
    {
        for (int i = 0; i < allEmployees.size(); i++)
        {
            if (allEmployees[i].getid() == id)
            {
                employee* e = &allEmployees[i];
                return e;
            }
        }
        return nullptr;
    }
    void listEmployee()
    {
		for (empIT = allEmployees.begin(); empIT < allEmployees.end(); empIT++) {
			empIT[0].display();
			cout << "==========\n";
		}
    }
    void editEmployee(int id, string name, string password, double salary)
    {
        employee* e = searchEmployee(id);
        e->setname(name);
        e->setpassword(password);
        e->setsalary(salary);
    }
};
static vector<admin> allAdmins;
static vector<admin>::iterator adminIT;