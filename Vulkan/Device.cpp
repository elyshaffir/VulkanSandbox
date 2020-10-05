#include <set>
#include <map>
#include "Device.h"
#include "NoPhysicalDeviceCombinationException.h"
#include "NoSupportingUnusedDeviceException.h"

using namespace sandbox::vulkan;

std::vector<Device> Device::GatherDevices(Surface surface, const std::vector<DeviceSupport> & neededSupports,
										  const std::vector<VkPhysicalDevice> & physicalDevices)
{
	std::map<uint32_t, uint32_t> supported;
	for (uint32_t supportIndex = 0; supportIndex < neededSupports.size(); ++supportIndex)
	{
		try
		{
			supported.insert({
									 FindDevice(surface, neededSupports[supportIndex], true, supported,
												physicalDevices),
									 supportIndex
							 });
		}
		catch (NoSupportingUnusedDeviceException &)
		{
			uint32_t usedDeviceIndex = FindDevice(surface, neededSupports[supportIndex], false, supported,
												  physicalDevices);
			uint32_t supportedIndex = supported.find(usedDeviceIndex)->second;

		}
	}
}

Device::Device(VkPhysicalDevice physicalDevice) : physicalDevice(physicalDevice), logicalDevice(nullptr)
{
}

uint32_t Device::FindDevice(Surface surface, const DeviceSupport & support, bool unused,
							const std::map<uint32_t, uint32_t> & supported,
							const std::vector<VkPhysicalDevice> & physicalDevices)
{
	for (uint32_t deviceIndex = 0; deviceIndex < physicalDevices.size(); ++deviceIndex)
	{
		if ((!unused || supported.find(deviceIndex) == supported.end()) &&
			support.CheckSupport(surface, physicalDevices[deviceIndex]))
		{
			return deviceIndex;
		}
	}
	if (unused)
	{
		throw NoSupportingUnusedDeviceException();
	}
	else
	{
		throw NoSupportingDeviceException();
	}
}
