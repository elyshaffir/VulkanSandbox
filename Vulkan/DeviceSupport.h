#ifndef SANDBOX_DEVICESUPPORT_H
#define SANDBOX_DEVICESUPPORT_H

#include <vector>
#include <vulkan/vulkan.h>
#include "Surface.h"

namespace sandbox::vulkan
{
	class DeviceSupport
	{
	public:
		static inline const std::vector<const char *> DEFAULT_DEVICE_EXTENSIONS = {
				VK_KHR_SWAPCHAIN_EXTENSION_NAME
		};

		DeviceSupport(std::vector<const char *> extensions, bool swapChainSupport);

		bool CheckSupport(Surface surface, VkPhysicalDevice physicalDevice) const;

	private:
		const std::vector<const char *> extensions;
		const bool swapChainSupport;

		bool CheckExtensionSupport(VkPhysicalDevice physicalDevice) const;

		bool CheckSwapChainSupport(Surface surface, VkPhysicalDevice physicalDevice) const;
	};
}

#endif //SANDBOX_DEVICESUPPORT_H
