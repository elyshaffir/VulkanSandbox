#include "DeviceSupport.h"
#include <utility>
#include <set>
#include <string>

using namespace sandbox::vulkan;

DeviceSupport::DeviceSupport(std::vector<const char *> extensions, QueueFamilyRequirements queueFamilyIndices,
							 ArbitraryDeviceSupport swapChainSupport) :
		extensions(std::move(extensions)), queueFamilyIndices(queueFamilyIndices), swapChainSupport(swapChainSupport)
{
}

bool DeviceSupport::CheckSupport(VkPhysicalDevice physicalDevice, Surface surface,
								 QueueFamilyIndices queueFamilyIndices) const
{
	return CheckExtensionSupport(physicalDevice) && queueFamilyIndices.IsComplete(queueFamilyRequirements) &&
		   arbitraryDeviceSupport.CheckSupport(surface, physicalDevice);
}

bool DeviceSupport::CheckExtensionSupport(VkPhysicalDevice physicalDevice) const
{
	uint32_t extensionCount;
	vkEnumerateDeviceExtensionProperties(physicalDevice, nullptr, &extensionCount, nullptr);

	std::vector<VkExtensionProperties> availableExtensions(extensionCount);
	vkEnumerateDeviceExtensionProperties(physicalDevice, nullptr, &extensionCount, availableExtensions.data());

	std::set<std::string> requiredExtensions(extensions.begin(), extensions.end());

	for (const auto & extension : availableExtensions)
	{
		requiredExtensions.erase(extension.extensionName);
	}

	return requiredExtensions.empty();
}
