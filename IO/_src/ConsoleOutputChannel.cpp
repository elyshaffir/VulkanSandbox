#include "../_include/ConsoleOutputChannel.h"

#include <iostream>

void sandbox::io::ConsoleOutputChannel::Info(std::string info)
{
	std::cout << info << std::endl;
}

void sandbox::io::ConsoleOutputChannel::Error(std::string error)
{
	std::cerr << error << std::endl;
}
