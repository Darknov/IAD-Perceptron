#include "Debug.h"

#include <iostream>

void Debug::log(std::string message)
{
	std::cout << message << std::endl;
}

void Debug::log(double message)
{
	std::cout << std::to_string(message) << std::endl;
}
