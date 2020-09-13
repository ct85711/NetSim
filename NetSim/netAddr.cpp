#include "netAddr.h"
#include <sstream>

netAddress* netAddress::getInstance()
{
	//Check to see if we already have an instance already initialized or not
	if (!address)
		address = new netAddress;

	return address;
}

void* netAddress::setIpv4Address(string cidrNotation)
{
	ipv4addr* theAddress = new ipv4addr;
	unsigned char maskPart = 255;	//the bitmask, assuming all bits

	size_t pos = cidrNotation.rfind('/');
	//Get the mask bit amount
	unsigned int mask = std::stoul(cidrNotation.substr(++pos));
	string addressPortion = cidrNotation.substr(0U, --pos);
	short ipParts[4];
	for (int part = 0; part < 4; part++)
	{
		pos = addressPortion.find('.');
		ipParts[part] = std::stoi(addressPortion.substr(0U,pos));
		addressPortion = addressPortion.substr(pos + 1);
	}
	theAddress->address = tuple <short, short, short, short>(ipParts[0], ipParts[1], ipParts[2], ipParts[3]);

	//Sadly, you can't do ranges in a switch case with visual Studio c++, so I am stuck using if statements
	
	if (mask >=24) {
		mask = 32 - mask;
		unsigned char thebits = 255 << mask;
		theAddress->netmask = tuple <short, short, short, short>((short)255, (short)255, (short)255, (short)thebits);
	}
	else if (mask >=16) {
		mask = 24 - mask;
		unsigned char thebits = 255 << mask;
		theAddress->netmask = tuple <short, short, short, short>((short)255, (short)255, (short)thebits, (short)0);
	}
	else {
		mask = 16 - mask;
		unsigned char thebits = 255 << mask;
		theAddress->netmask = tuple <short, short, short, short>((short)255, (short)thebits, (short)0, (short)0);
	}
	
	return theAddress;
}

void* netAddress::setIpv4Address(string ipAddr, string mask)
{
	int pos = 0;
	ipv4addr* theAddress = new ipv4addr;
	short addrParts[4];

	//Convert the ip address string into it's parts
	for (int part = 0; part < 4; part++)
	{
		pos = ipAddr.find('.');
		addrParts[part] = std::stoi(ipAddr.substr(0U, pos));
		ipAddr = ipAddr.substr(pos + 1);
	}
	theAddress->address = tuple <short, short, short, short>(addrParts[0], addrParts[1], addrParts[2], addrParts[3]);

	//convert the netmask into it's parts
	for (int part = 0; part < 4; part++)
	{
		pos = mask.find('.');
		addrParts[part] = std::stoi(mask.substr(0U, pos));
		mask = mask.substr(pos + 1);
	}
	theAddress->netmask = tuple <short, short, short, short>(addrParts[0], addrParts[1], addrParts[2], addrParts[3]);
	return theAddress;
}

void* netAddress::setIpv6Address(string cidrNotation)
{
	ipv6addr* theAddress = new ipv6addr;
	return theAddress;
}

void* netAddress::setIpv6Address(string ipAddr, string mask)
{
	ipv6addr* theAddress = new ipv6addr;
	return theAddress;
}

std::ostream& operator<<(std::ostream& out, const netAddress::ipv4addr& ipv4)
{
	stringstream sout;
	sout << "Ipv4 Address: " << ipv4.address << "\n" << "Subnet Mask: " << ipv4.netmask;
	return (out << sout.str());
}

std::ostream& operator<<(std::ostream& out, const netAddress::ipv6addr& ipv6)
{
	stringstream sout;
	sout << "Ipv4 Address: " << ipv6.address << "\n" << "Subnet Mask: " << ipv6.netmask;
	return (out << sout.str());
}

std::ostream& operator<<(std::ostream& out, const tuple<short, short, short, short>& addr)
{
	auto[part1, part2, part3, part4] = addr;
	stringstream sout;
	sout << part1 << "." << part2 << "." << part3 << "." << part4;
	return (out << sout.str());
}

std::ostream& operator<<(std::ostream& out, const tuple<char[4], char[4], char[4], char[4], char[4], char[4], char[4], char[4]>& addr)
{
	auto [part1, part2, part3, part4, part5, part6, part7, part8] = addr;
	stringstream sout;
	sout << part1 << ":" << part2 << ":" << part3 << ":" << part4 << ":" << part5 << ":" << part6 << ":" << part7 << ":" << part8;
	return (out << sout.str());
}
