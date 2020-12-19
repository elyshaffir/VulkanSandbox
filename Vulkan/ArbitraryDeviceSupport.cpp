#include "ArbitraryDeviceSupport.h"

using namespace vulkan::sandbox;

ArbitraryDeviceSupport::ArbitraryDeviceSupport(const bool swapChainSupport, const bool samplerAnisotropySupport) :
		swapChainSupport(swapChainSupport), samplerAnisotropySupport(samplerAnisotropySupport)
{
}

bool ArbitraryDeviceSupport::CheckSupport(Surface surface, VkPhysicalDevice physicalDevice) const
{
	return CheckSwapChainSupport(surface, physicalDevice) && CheckSamplerAnisotropySupport(physicalDevice);
}

bool ArbitraryDeviceSupport::CheckSwapChainSupport(Surface surface, VkPhysicalDevice physicalDevice) const
{
	if (!swapChainSupport)
	{
		return true;
	}
	SwapChainSupportDetails swapChainSupportDetails = surface.QuerySwapChainSupport(physicalDevice);
	return !swapChainSupportDetails.formats.empty() && !swapChainSupportDetails.presentModes.empty();
}

bool ArbitraryDeviceSupport::CheckSamplerAnisotropySupport(VkPhysicalDevice physicalDevice) const
{
	if (!samplerAnisotropySupport)
	{
		return true;
	}
	VkPhysicalDeviceFeatures supportedFeatures;
	vkGetPhysicalDeviceFeatures(physicalDevice, &supportedFeatures);
	return supportedFeatures.samplerAnisotropy;
}
