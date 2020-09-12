#pragma once

#include <vector>
#include <string>
#include "netAddr.h"

//This makes it so the program can initialize the netAddress class
netAddress* netAddress::address = 0;
using namespace std;

class ethInterface
{
	netAddress *addressFactory = netAddress::getInstance();
public:

	ethInterface() = default;
	~ethInterface() = default;
	vector<void*> addresses;

	void addipv4address(string cidr);
	void addipv4address(string addr, string mask);
	void addipv6address(string cidr);
	void addipv6address(string addr, string mask);
};