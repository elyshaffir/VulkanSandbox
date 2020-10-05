#include "DeviceSupport.h"
#include <utility>
#include <set>
#include <string>

using namespace sandbox::vulkan;

DeviceSupport::DeviceSupport(std::vector<const char *> extensions, bool swapChainSupport) :
		extensions(std::move(extensions)), swapChainSupport(swapChainSupport)
{
}

bool DeviceSupport::CheckSupport(Surface surface, VkPhysicalDevice physicalDevice) const
{
	return CheckExtensionSupport(physicalDevice) && CheckSwapChainSupport(surface, physicalDevice);
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

bool DeviceSupport::CheckSwapChainSupport(Surface surface, VkPhysicalDevice physicalDevice) const
{
	if (!swapChainSupport)
	{
		return true;
	}
	SwapChainSupportDetails swapChainSupportDetails = surface.QuerySwapChainSupport(physicalDevice);
	return !swapChainSupportDetails.formats.empty() && !swapChainSupportDetails.presentModes.empty();
}
