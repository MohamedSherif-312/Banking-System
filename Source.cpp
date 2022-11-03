#include <iostream>
#include <string>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Validation.h"
#include "Data_Source_Interface.h"
#include "File_Helper.h"
#include "File_Manager.h"
#include "Parser.h"
#include "screen.h"
using namespace std;

//void Client() 
//{
//	int counter = 0;
//	do
//	{
//		client c;
//		string name, password;
//		double balance;
//		cout << "enter name : ";
//		cin >> name;
//		c.setname(name);
//		if (validations::name_validation(name) == true)
//		{
//			do
//			{
//				cout << "enter password : ";
//				cin >> password;
//				c.setpassword(password);
//				if (validations::password_validation(password) == true)
//				{
//					do
//					{
//						cout << "enter balance : ";
//						cin >> balance;
//						c.setbalance(balance);
//						if (validations::balance_validation(balance)== false)
//						{
//							counter++;
//						}
//						else
//						{
//							break;
//						}
//					} while (counter < 3);
//				}
//				else
//				{
//					counter++;
//				}
//				if (validations::password_validation(password) == true)
//				{
//					break;
//				}
//			} while (counter < 3);
//		}
//		else
//		{
//			counter++;
//		}
//		if (validations::name_validation(name) == true)
//		{
//			break;
//		}
//	} while (counter < 3);
//}
//void Employee()
//{
//	int counter = 0;
//	do
//	{
//		employee e;
//		string name, password;
//		double salary;
//		cout << "enter name : ";
//		cin >> name;
//		e.setname(name);
//		if (validations::name_validation(name) == true)
//		{
//			do
//			{
//				cout << "enter password : ";
//				cin >> password;
//				e.setpassword(password);
//				if (validations::password_validation(password) == true)
//				{
//					do
//					{
//						cout << "enter salary : ";
//						cin >> salary;
//						e.setsalary(salary);
//						if (validations::salary_validation(salary) == false)
//						{
//							counter++;
//						}
//						else
//						{
//							break;
//						}
//					} while (counter < 3);
//				}
//				else
//				{
//					counter++;
//				}
//				if (validations::password_validation(password) == true)
//				{
//					break;
//				}
//			} while (counter < 3);
//		}
//		else
//		{
//			counter++;
//		}
//		if (validations::name_validation(name) == true)
//		{
//			break;
//		}
//	} while (counter < 3);
//}
//void Admin()
//{
//	int counter = 0;
//	do
//	{
//		admin a;
//		string name, password;
//		double salary;
//		cout << "enter name : ";
//		cin >> name;
//		a.setname(name);
//		if (validations::name_validation(name) == true)
//		{
//			do
//			{
//				cout << "enter password : ";
//				cin >> password;
//				a.setpassword(password);
//				if (validations::password_validation(password) == true)
//				{
//					do
//					{
//						cout << "enter salary : ";
//						cin >> salary;
//						a.setsalary(salary);
//						if (validations::salary_validation(salary) == false)
//						{
//							counter++;
//						}
//						else
//						{
//							break;
//						}
//					} while (counter < 3);
//				}
//				else
//				{
//					counter++;
//				}
//				if (validations::password_validation(password) == true)
//				{
//					break;
//				}
//			} while (counter < 3);
//		}
//		else
//		{
//			counter++;
//		}
//		if (validations::name_validation(name) == true)
//		{
//			break;
//		}
//	} while (counter < 3);
//}
int main()
{
	admin a("mohamed", "typhoon#312", 10000, 11001);
	FileHelper::saveAdmin(a);
	employee e("nour", "wrongindex", 10000, 22001);
	FileHelper::saveEmployee(e);
	client c(33001,"youssef", "bigmotherfucker", 5000);
	FileHelper::saveClient(c);
	screens::runapp();
}
