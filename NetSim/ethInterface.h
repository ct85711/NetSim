#pragma once

#include <vector>
#include <string>
#include <random>
#include "netAddr.h"

//This makes it so the program can initialize the netAddress class
netAddress* netAddress::address = 0;

//Setup a random engine to generate between 0-255
static std::default_random_engine randEng;
static std::uniform_int_distribution<int> randDist{0,255};

using namespace std;

class ethInterface
{
	netAddress *addressFactory = netAddress::getInstance();
	ethInterface* connection = nullptr;
	string macAddress;

	void generateMac();

public:

	ethInterface();
	~ethInterface() = default;
	vector<void*> addresses;

	void addipv4address(string cidr);
	void addipv4address(string addr, string mask);
	void addipv6address(string cidr);
	void addipv6address(string addr, string mask);
	
	// Sets/Gets the connection to another interface connection
	// By default, interfaces start off as not being connected to another interface
	// TODO: Make sure both side's referr to each other
	ethInterface& getConnection();
	void setConnection(ethInterface& conn);

	//Get the Mac address for this interface
	string getMacAddress() const;
};

std::ostream& operator<<(std::ostream& out, const ethInterface& theInterface);