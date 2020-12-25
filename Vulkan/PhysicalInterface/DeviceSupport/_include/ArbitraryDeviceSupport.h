#ifndef SANDBOX_ARBITRARYDEVICESUPPORT_H
#define SANDBOX_ARBITRARYDEVICESUPPORT_H

#include <vulkan/vulkan.h>
#include "../../../Surface/_include/Surface.h"

namespace sandbox::vulkan
{
	class ArbitraryDeviceSupport
	{
	public:
		ArbitraryDeviceSupport(bool swapChainSupport, bool samplerAnisotropySupport);

		bool CheckSupport(Surface surface, VkPhysicalDevice physicalDevice) const;

		bool GetSamplerAnisotropySupport() const;
	private:
		const bool swapChainSupport;
		const bool samplerAnisotropySupport;

		bool CheckSwapChainSupport(Surface surface, VkPhysicalDevice physicalDevice) const;

		bool CheckSamplerAnisotropySupport(VkPhysicalDevice physicalDevice) const;
	};
}

#endif //SANDBOX_ARBITRARYDEVICESUPPORT_H
