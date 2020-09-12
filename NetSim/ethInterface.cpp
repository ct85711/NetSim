#include "ethInterface.h"

void ethInterface::addipv4address(string cidr)
{
	addressFactory->setIpv4Address(cidr);
}

void ethInterface::addipv4address(string addr, string mask)
{
	addressFactory->setIpv4Address(addr, mask);
}

void ethInterface::addipv6address(string cidr)
{
	addressFactory->setIpv6Address(cidr);
}

void ethInterface::addipv6address(string addr, string mask)
{
	addressFactory->setIpv6Address(addr, mask);
}