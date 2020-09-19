#include "../include/ValidationLayersUnavailableException.h"

std::string sandbox::vulkan::ValidationLayersUnavailableException::DescribeSpecific()
{
	return "Validation layers requested, but not available!";
}
