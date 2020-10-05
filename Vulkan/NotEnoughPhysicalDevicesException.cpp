#include "NotEnoughPhysicalDevicesException.h"

using namespace sandbox::vulkan;

NotEnoughPhysicalDevicesException::NotEnoughPhysicalDevicesException(uint32_t requestedDevices,
																	 uint32_t availableDevices) :
		requestedDevices(requestedDevices), availableDevices(availableDevices)
{
}

std::string NotEnoughPhysicalDevicesException::DescribeSpecific()
{
	return "Not enough physical devices, " + std::to_string(requestedDevices) + " requested, but only " +
		   std::to_string(availableDevices) + " available.";
}
