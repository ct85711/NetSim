#include "router.h"

router::router()
{
	//By default a router will have at least one interface
	interfaces.push_back(new ethInterface());
}

router::router(unsigned int numInterface)
{
	//Create as many interfaces as requested
	for (size_t i = 0; i < numInterface; i++)
	{
		interfaces.push_back(new ethInterface());
	}
}
