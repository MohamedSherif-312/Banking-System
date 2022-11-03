#pragma once
#include <string>
#include <vector>
#include <sstream>
#include "Client.h"
#include "Admin.h"
#include "Employee.h"

using namespace std;

class Parser {

public:
	static vector<string> split(string line) {
		//name & pass & salary & id
		// Before:: Mohamed&MohamedSherif312&5000&101
		// After :: Mohamed  MohamedSherif312  5000 101
		stringstream s(line);
		vector<string> info;
		string data;
		while (getline(s, data, '&')) {
			info.push_back(data);
		}
		return info;
	}

	static client parseToClient(string line) {
		vector<string> info = split(line);
		client c(stoi(info[3]), info[0], info[1], stod(info[2]));
		return c;
	}

	static admin parseToAdmin(string line) {
		vector<string> info = split(line);
		admin a(info[0], info[1], stod(info[2]), stoi(info[3]));
		return a;
	}

	static employee parseToEmployee(string line) {
		vector<string> info = split(line);
		employee e(info[0], info[1], stod(info[2]), stoi(info[3]));
		return e;
	}

};
