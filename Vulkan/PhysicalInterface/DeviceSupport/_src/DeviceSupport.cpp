#include "../_include/DeviceSupport.h"
#include <utility>
#include <set>
#include <string>

using namespace sandbox::vulkan;

DeviceSupport::DeviceSupport(std::vector<const char *> extensions, QueueFamilySupport queueFamilySupport,
							 ArbitraryDeviceSupport arbitraryDeviceSupport) :
		extensions(std::move(extensions)), queueFamilySupport(queueFamilySupport),
		arbitraryDeviceSupport(arbitraryDeviceSupport)
{
}

bool DeviceSupport::CheckSupport(VkPhysicalDevice physicalDevice, Surface surface,
								 QueueFamilyIndices queueFamilyIndices) const
{
	return CheckExtensionSupport(physicalDevice) && queueFamilyIndices.IsComplete(queueFamilySupport) &&
		   arbitraryDeviceSupport.CheckSupport(surface, physicalDevice);
}

std::vector<const char *> DeviceSupport::GetExtensions() const
{
	return extensions;
}

QueueFamilySupport DeviceSupport::GetQueueFamilySupport() const
{
	return queueFamilySupport;
}

ArbitraryDeviceSupport DeviceSupport::GetArbitraryDeviceSupport() const
{
	return arbitraryDeviceSupport;
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
