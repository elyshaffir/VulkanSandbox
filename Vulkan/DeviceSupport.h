#ifndef SANDBOX_DEVICESUPPORT_H
#define SANDBOX_DEVICESUPPORT_H

#include <vector>
#include <vulkan/vulkan.h>
#include "Surface.h"
#include "ArbitraryDeviceSupport.h"

namespace sandbox::vulkan
{
	class DeviceSupport
	{
	public:
		static inline const std::vector<const char *> DEFAULT_DEVICE_EXTENSIONS = {
				VK_KHR_SWAPCHAIN_EXTENSION_NAME
		};

		DeviceSupport(std::vector<const char *> extensions, QueueFamilyRequirements queueFamilyRequirements, ArbitraryDeviceSupport arbitraryDeviceSupport);

		bool CheckSupport(VkPhysicalDevice physicalDevice, Surface surface, QueueFamilyIndices queueFamilyIndices) const;

	private:
		const std::vector<const char *> extensions;
		const QueueFamilyRequirements queueFamilyRequirements;
		const ArbitraryDeviceSupport arbitraryDeviceSupport;

		bool CheckExtensionSupport(VkPhysicalDevice physicalDevice) const;
	};
}

#endif //SANDBOX_DEVICESUPPORT_H
