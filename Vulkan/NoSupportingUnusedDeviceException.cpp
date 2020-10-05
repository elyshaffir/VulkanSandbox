#include "NoSupportingUnusedDeviceException.h"

using namespace sandbox::vulkan;

std::string NoSupportingUnusedDeviceException::DescribeSpecific()
{
	return "Could not find an unused device that supports the requested features.";
}
