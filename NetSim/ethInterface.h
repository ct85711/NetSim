#pragma once

#include <tuple>
#include <vector>
#include <string>

//These structs setup the address groupings
struct ipv4addr
{
	ipv4addr() = default;
	std::tuple<int, int, int, int> address;
	std::tuple<int, int, int, int> netmask;
};

struct ipv6addr
{
	std::tuple<char[4], char[4], char[4], char[4], char[4], char[4], char[4], char[4]> address;
	std::tuple<char[4], char[4], char[4], char[4], char[4], char[4], char[4], char[4]> netmask;
};

class ethInterface
{
	ethInterface() = default;
	ethInterface(ipv4addr*);
	ethInterface(std::tuple<int, int, int, int>, std::tuple<int, int, int, int>);
	~ethInterface() = default;
	std::vector<> addresses;
};