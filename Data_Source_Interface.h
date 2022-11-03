#pragma once
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include <vector>

class DataSourceInterface
{
public:
	virtual void addClient(client c) = 0;
	virtual void addEmployee(employee e) = 0;
	virtual void addAdmin(admin a) = 0;

	virtual vector<client> getAllClients() = 0;
	virtual vector<employee> getAllEmployees() = 0;
	virtual vector<admin> getAllAdmins() = 0;

	virtual void removeAllClients() = 0;
	virtual void removeAllEmployees() = 0;
	virtual void removeAllAdmins() = 0;
};