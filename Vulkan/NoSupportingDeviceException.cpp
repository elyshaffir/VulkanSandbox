#include "NoSupportingDeviceException.h"

using namespace sandbox::vulkan;

std::string NoSupportingDeviceException::DescribeSpecific()
{
	return "Could not find a device that supports the requested features."
}
