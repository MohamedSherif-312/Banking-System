#pragma once
#include<vector>
#include <iostream>
#include <string>
#include "Person.h"
#include "Validation.h"
using namespace std;
class client :public person
{
private:
	double balance;
public:
	client() : person()
	{
		
	}
	client (int id,string name, string password, double balance) : person(name,id, password) 
	{
		setbalance(balance);
	}
	void setbalance(double balance) {
		if (validations::balance_validation(balance))
		{
		this->balance = balance;
		}
		else
		{
			cout << "minimum value is 1500\n";
		}
	}
	double getbalance() {
		return balance;
	}
	void withdraw() {
		double amount;
		cout << "How much do you want to withdraw: "; cin >> amount;
		if (validations::validateamount(amount, balance)) {
			this->balance -= amount;
			cout << "Successful withdraw.\n";
			checkbalance();
		}
		else
			cout << "Insufficient balance, try again with smaller amount\n";
	}
	void deposit() {
		double amount;
		cout << "How much do you want to deposit: "; cin >> amount;
		this->balance += amount;
		cout << "Successful Deposit.\n";
		checkbalance();
	}
	void transeferto(client& recipient) {
		double amount;
		cout << "How much do you want to transfer: "; cin >> amount;
		if (validations::validateamount(amount, balance)) {
			this->balance -= amount;
			recipient.balance += amount;
			cout << "Successful transfer.\n";
			checkbalance();
		}
		else
			cout << "Insufficient balance, try again with smaller amount\n";
	}
	void checkbalance() {
		cout << "your balance is " << getbalance() << endl;
	}
	void display() {

		cout << getname() << '\n' << "id = " << getid() << '\n' << "balance =" << getbalance();
	}
};

static vector<client> allClients;
static vector<client>::iterator clientIT;
