#include "netAddr.h"

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
	int mask = std::stoi(cidrNotation.substr(++pos));
	string addressPortion = cidrNotation.substr(0U, --pos);
	int ipParts[4];
	for (int part = 0; part < 4; part++)
	{
		pos = addressPortion.find('.');
		ipParts[part] = std::stoi(addressPortion.substr(0U,pos));
		addressPortion = addressPortion.substr(pos + 1);
	}
	theAddress->address = tuple < int, int, int, int>(ipParts[0], ipParts[1], ipParts[2], ipParts[3]);

	//Sadly, you can't do ranges in a switch case with visual Studio c++, so I am stuck using if statements
	
	if (mask >=24) {
		mask = 32 - mask;
		unsigned char thebits = 255 << mask;
		theAddress->netmask = tuple < int, int, int, int>(255, 255, 255, thebits);
	}
	else if (mask >=16) {
		mask = 24 - mask;
		unsigned char thebits = 255 << mask;
		theAddress->netmask = tuple < int, int, int, int>(255, 255, thebits, 0);
	}
	else {
		mask = 16 - mask;
		unsigned char thebits = 255 << mask;
		theAddress->netmask = tuple < int, int, int, int>(255, thebits, 0, 0);
	}
	
	return theAddress;
}

void* netAddress::setIpv4Address(string ipAddr, string mask)
{
	int pos = 0;
	ipv4addr* theAddress = new ipv4addr;
	int addrParts[4];

	//Convert the ip address string into it's parts
	for (int part = 0; part < 4; part++)
	{
		pos = ipAddr.find('.');
		addrParts[part] = std::stoi(ipAddr.substr(0U, pos));
		ipAddr = ipAddr.substr(pos + 1);
	}
	theAddress->address = tuple < int, int, int, int>(addrParts[0], addrParts[1], addrParts[2], addrParts[3]);

	//convert the netmask into it's parts
	for (int part = 0; part < 4; part++)
	{
		pos = mask.find('.');
		addrParts[part] = std::stoi(mask.substr(0U, pos));
		mask = mask.substr(pos + 1);
	}
	theAddress->netmask = tuple < int, int, int, int>(addrParts[0], addrParts[1], addrParts[2], addrParts[3]);
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
