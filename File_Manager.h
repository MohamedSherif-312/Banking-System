#pragma once
#include "Data_Source_Interface.h"
#include "File_Helper.h"

class FileManager : public DataSourceInterface
{
public:
    static void addClient(client c)
    {
        FileHelper::saveClient(c);
    }

    static void addEmployee(employee e)
    {
        FileHelper::saveEmployee(e);
    }

    static void addAdmin(admin a)
    {
        FileHelper::saveAdmin(a);
    }

    static void getAllClients() {
        FileHelper::getAllClients();
    }

    static void getAllEmployees() {
        FileHelper::getAllEmployees();
    }

    static void getAllAdmins() {
        FileHelper::getAllAdmins();
    }

    static void getData() {
        getAllClients();
        getAllEmployees();
        getAllAdmins();
    }

    static void RemoveAllClients()  
    {
        FileHelper::clearFile("C:\\DataBase\\clients\\clients.txt", "C:\DataBase\clients\lastClient.txt", 'c');
    }

    static void RemoveAllAdmins()
    {
        FileHelper::clearFile("C:\\DataBase\\admins\\admins.txt", "C:\DataBase\admins\lastAdmin.txt", 'a');
    }
    
    static void RemoveAllEmployees()
    {
        FileHelper::clearFile("C:\\DataBase\\employees\\employees.txt", "C:\DataBase\employees\lastEmployee.txt", 'e');
    }

    static void UpdateClient()
    {
        RemoveAllClients();
        for (int i = 0; i < allClients.size(); i++)
        {
            addClient(allClients[i]);
        }

    }
    
    static void UpdateAdmin()
    {
        RemoveAllAdmins();
        for (int i = 0; i < allAdmins.size(); i++)
        {
            addAdmin(allAdmins[i]);
        }

    }
    
    static void UpdateEmployee()
    {
        RemoveAllEmployees();
        for (int i = 0; i < allEmployees.size(); i++)
        {
            addEmployee(allEmployees[i]);
        }

    }

};