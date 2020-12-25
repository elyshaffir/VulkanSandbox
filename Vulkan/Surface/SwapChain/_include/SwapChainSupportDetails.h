#ifndef SANDBOX_SWAPCHAINSUPPORTDETAILS_H
#define SANDBOX_SWAPCHAINSUPPORTDETAILS_H

#include <vulkan/vulkan.h>
#include <vector>

namespace sandbox::vulkan
{
	struct SwapChainSupportDetails
	{
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};
}

#endif //SANDBOX_SWAPCHAINSUPPORTDETAILS_H
