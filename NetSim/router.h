#pragma once
#include <vector>
#include <string>
#include "ethInterface.h"

class router
{
	router();
	router(unsigned int numInterface);
	~router() = default;
	std::string name;

	//Disable the copy and assignment operations
	router(router& other) = delete;
	void operator=(const router& other) = delete;
	public:
		std::vector<ethInterface*> interfaces;
};

