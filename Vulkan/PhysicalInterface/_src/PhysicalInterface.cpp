#include "../_include/PhysicalInterface.h"
#include "../_include/NotEnoughPhysicalDevicesException.h"

#include <stdexcept>

using namespace sandbox::vulkan;

PhysicalInterface::PhysicalInterface() : devices()
{

}

void PhysicalInterface::Initialize(Instance instance, Surface surface,
								   const std::vector<DeviceSupport> & neededSupports)
{
	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices(instance.GetInstance(), &deviceCount, nullptr);
	if (deviceCount < neededSupports.size())
	{
		throw NotEnoughPhysicalDevicesException(neededSupports.size(), deviceCount);
	}

	std::vector<VkPhysicalDevice> physicalDevices(deviceCount);
	vkEnumeratePhysicalDevices(instance.GetInstance(), &deviceCount, physicalDevices.data());

	for (const DeviceSupport & support : neededSupports)
	{
		devices.push_back(Device::PickDevice(support, surface, physicalDevices, instance.GetValidationLayers()));
	}
}
