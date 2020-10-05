#include "PhysicalInterface.h"
#include "NotEnoughPhysicalDevicesException.h"

#include <utility>
#include <stdexcept>

using namespace sandbox::vulkan;

PhysicalInterface::PhysicalInterface() : devices()
{

}

void PhysicalInterface::Initialize(Instance instance, Surface surface,
								   const std::vector<DeviceSupport> & neededExtensions)
{
	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices(instance.GetInstance(), &deviceCount, nullptr);
	if (deviceCount < neededExtensions.size())
	{
		throw NotEnoughPhysicalDevicesException(neededExtensions.size(), deviceCount);
	}

	std::vector<VkPhysicalDevice> physicalDevices(deviceCount);
	vkEnumeratePhysicalDevices(instance.GetInstance(), &deviceCount, physicalDevices.data());
	// Later, differentiate between devices via index, support can overlap
	devices = Device::GatherDevices(surface, neededExtensions, physicalDevices);
	//	for (const auto physicalDevice : physicalDevices)
	//	{
	//		if (IsPhysicalDeviceSuitable(surface, physicalDevice))
	//		{
	//
	//		}
	//	}
}

bool PhysicalInterface::IsPhysicalDeviceSuitable(Surface surface,
												 VkPhysicalDevice physicalDevice) // Deprecated, should be moved to devicesupport
{
	QueueFamilyIndices indices = surface.GetQueueFamilyIndices(physicalDevice);

	bool extensionsSupported = CheckDeviceExtensionSupport(physicalDevice);

	bool swapChainAdequate = false;
	if (extensionsSupported)
	{
		SwapChainSupportDetails swapChainSupport = querySwapChainSupport(physicalDevice);
		swapChainAdequate = !swapChainSupport.formats.empty() && !swapChainSupport.presentModes.empty();
	}

	VkPhysicalDeviceFeatures supportedFeatures;
	vkGetPhysicalDeviceFeatures(physicalDevice, &supportedFeatures);

	return indices.IsComplete() && extensionsSupported && swapChainAdequate && supportedFeatures.samplerAnisotropy;
}
