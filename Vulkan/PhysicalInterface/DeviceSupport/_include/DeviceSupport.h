#ifndef SANDBOX_DEVICESUPPORT_H
#define SANDBOX_DEVICESUPPORT_H

#include <vector>
#include <vulkan/vulkan.h>
#include "../../../Surface/_include/Surface.h"
#include "ArbitraryDeviceSupport.h"

namespace sandbox::vulkan
{
	class DeviceSupport
	{
	public:
		static inline const std::vector<const char *> DEFAULT_DEVICE_EXTENSIONS = {
				VK_KHR_SWAPCHAIN_EXTENSION_NAME
		};

		DeviceSupport(std::vector<const char *> extensions, QueueFamilySupport queueFamilySupport,
					  ArbitraryDeviceSupport arbitraryDeviceSupport);

		bool CheckSupport(VkPhysicalDevice physicalDevice, Surface surface,
						  QueueFamilyIndices queueFamilyIndices) const;

		std::vector<const char *> GetExtensions() const;

		QueueFamilySupport GetQueueFamilySupport() const;

		ArbitraryDeviceSupport GetArbitraryDeviceSupport() const;
	private:
		const std::vector<const char *> extensions;
		const QueueFamilySupport queueFamilySupport;
		const ArbitraryDeviceSupport arbitraryDeviceSupport;

		bool CheckExtensionSupport(VkPhysicalDevice physicalDevice) const;
	};
}

#endif //SANDBOX_DEVICESUPPORT_H
