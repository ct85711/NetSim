#pragma once
#include <tuple>
#include <string>

using namespace std;

class netAddress {
	

	//These structs setup the address groupings
	struct ipv4addr
	{
		ipv4addr() = default;
		tuple<short, short, short, short> address;
		tuple<short, short, short, short> netmask;
	};

	struct ipv6addr
	{
		tuple<char[4], char[4], char[4], char[4], char[4], char[4], char[4], char[4]> address;
		tuple<char[4], char[4], char[4], char[4], char[4], char[4], char[4], char[4]> netmask;
	};
	static netAddress *address;
	netAddress() = default;
	~netAddress() = default;

	//Disable the copy and assignment operations
	netAddress(netAddress& other) = delete;
	void operator=(const netAddress& other) = delete;

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
		friend std::ostream& operator<<(std::ostream& out, const netAddress::ipv4addr& ipv4);
		friend std::ostream& operator<<(std::ostream& out, const netAddress::ipv6addr& ipv6);
};

//Overload the tuple's output, so that it can output the addresses in the correct format
std::ostream& operator<<(std::ostream& out, const tuple<short, short, short, short> &addr);
std::ostream& operator<<(std::ostream& out, const tuple<char[4], char[4], char[4], char[4], char[4], char[4], char[4], char[4]>& addr);