#ifndef SANDBOX_ARBITRARYDEVICESUPPORT_H
#define SANDBOX_ARBITRARYDEVICESUPPORT_H

#include <vulkan/vulkan.h>
#include "Surface.h"

namespace vulkan::sandbox
{
	class ArbitraryDeviceSupport
	{
	public:
		ArbitraryDeviceSupport(bool swapChainSupport, bool samplerAnisotropySupport);

		bool CheckSupport(Surface surface, VkPhysicalDevice physicalDevice) const;
	private:
		const bool swapChainSupport;
		const bool samplerAnisotropySupport;

		bool CheckSwapChainSupport(Surface surface, VkPhysicalDevice physicalDevice) const;

		bool CheckSamplerAnisotropySupport(VkPhysicalDevice physicalDevice) const;
	};
}

#endif //SANDBOX_ARBITRARYDEVICESUPPORT_H