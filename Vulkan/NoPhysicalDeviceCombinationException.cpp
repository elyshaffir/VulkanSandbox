#include "NoPhysicalDeviceCombinationException.h"

std::string sandbox::vulkan::NoPhysicalDeviceCombinationException::DescribeSpecific()
{
	return "Requested combination of physical devices is unavailable.";
}
