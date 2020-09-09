#include "ethInterface.h"
#include <stdexcept>

ethInterface::ethInterface(ipv4addr* addr)
{
	ipv4 = addr;
}

ethInterface::ethInterface(std::tuple<int, int, int, int>& addr, std::tuple<int, int, int, int>& mask)
{
	/*
	int part1, part2, part3, part4;
	std::tie(part1, part2, part3, part4) = addr;
	if (part1 > 255 || part2 > 255 || part3 > 255 || part4 >255)
		throw new std::invalid_argument("Invalid ip address");
	std::tie(part1, part2, part3, part4) = mask;
	if (part1 > 255 || part2 > 255 || part3 > 255 || part4 > 255)
		throw new std::invalid_argument("Invalid ip mask");
	*/
	ipv4 = new ipv4addr();
	ipv4->address = addr;
	ipv4->netmask = mask;
}
