#include "Device.h"
#include "NoSupportingDeviceException.h"

using namespace sandbox::vulkan;

Device Device::PickDevice(const DeviceSupport & support, Surface surface,
						  std::vector<VkPhysicalDevice> & physicalDevices)
{
	auto physicalDeviceIterator = physicalDevices.begin();
	while (physicalDeviceIterator != physicalDevices.end())
	{
		QueueFamilyIndices queueFamilyIndices = surface.GetQueueFamilyIndices(*physicalDeviceIterator);
		if (support.CheckSupport(*physicalDeviceIterator, surface, queueFamilyIndices))
		{
			physicalDevices.erase(physicalDeviceIterator);
			return Device(*physicalDeviceIterator, queueFamilyIndices)
		}
		++physicalDeviceIterator;
	}
	throw NoSupportingDeviceException();
}

Device::Device(VkPhysicalDevice physicalDevice, QueueFamilyIndices queueFamilyIndices) :
		physicalDevice(physicalDevice), queueFamilyIndices(queueFamilyIndices), logicalDevice(nullptr)
{
	CreateLogicalDevice();
}

void Device::CreateLogicalDevice()
{

}
