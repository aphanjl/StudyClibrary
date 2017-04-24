#include "CMakeLoop.h"
#include <iostream>

CMakeLoop::CMakeLoop()
{
	std::cout << "CMakeLoop construct---" << std::endl;
}

CMakeLoop::~CMakeLoop()
{
	std::cout << "CMakeLoop destruct--" << std::endl;
}
