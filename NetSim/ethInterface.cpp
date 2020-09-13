#include "ethInterface.h"
#include <iomanip>
#include <sstream>

void ethInterface::generateMac()
{
	//A mac address is in the format of:
	// 00-00-00-00-00-00
	int nums[6];
	for (int x = 0; x < 6; x++)
	{
		nums[x] = randDist(randEng);
	}

	//Make a String stream so construct the string easily
	stringstream sstrm;
	sstrm << hex << nums[0] << '-' << hex << nums[1] << '-' << hex << nums[2] << '-' << hex << nums[3] << '-' << hex << nums[4] << '-' << hex << nums[5];
	macAddress = sstrm.str();
}

ethInterface::ethInterface()
{
	//Every interface created need to have a random mac address generated
	generateMac();
}

void ethInterface::addipv4address(string cidr)
{
	addresses.push_back(addressFactory->setIpv4Address(cidr));
}

void ethInterface::addipv4address(string addr, string mask)
{
	addresses.push_back(addressFactory->setIpv4Address(addr, mask));
}

void ethInterface::addipv6address(string cidr)
{
	addresses.push_back(addressFactory->setIpv6Address(cidr));
}

void ethInterface::addipv6address(string addr, string mask)
{
	addresses.push_back(addressFactory->setIpv6Address(addr, mask));
}

ethInterface& ethInterface::getConnection()
{
	return *connection;
}

void ethInterface::setConnection(ethInterface& conn)
{
	connection = &conn;
}

string ethInterface::getMacAddress() const
{
	return this->macAddress;
}

std::ostream& operator<<(std::ostream& out, const ethInterface& theInt)
{
	stringstream sout;
	sout << "Mac Address: " << theInt.getMacAddress() << "\n";
	for (auto addr : theInt.addresses)
	{
		sout << addr;
	}
	return (out << sout.str());
}
