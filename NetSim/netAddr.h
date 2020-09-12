#pragma once
#include <tuple>
#include <string>

using namespace std;

class netAddress {
	static netAddress *address;

	//These structs setup the address groupings
	struct ipv4addr
	{
		ipv4addr() = default;
		tuple<int, int, int, int> address;
		tuple<int, int, int, int> netmask;
	};

	struct ipv6addr
	{
		tuple<char[4], char[4], char[4], char[4], char[4], char[4], char[4], char[4]> address;
		tuple<char[4], char[4], char[4], char[4], char[4], char[4], char[4], char[4]> netmask;
	};
	
	netAddress() {}
	~netAddress() = default;

	public:
		static netAddress *getInstance();
		//This method converts an ip address in cidr notation into it's component parts
		void* setIpv4Address(string cidrNotation);
		//This converts the given ip address and mask strings into it's component parts
		void* setIpv4Address(string ipAddr, string mask);
		//This method converts an ip address in cidr notation into it's component parts
		void* setIpv6Address(string cidrNotation);
		//This converts the given ip address and mask strings into it's component parts
		void* setIpv6Address(string ipAddr, string mask);
};