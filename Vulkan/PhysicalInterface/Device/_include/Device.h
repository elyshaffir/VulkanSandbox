#ifndef SANDBOX_DEVICE_H
#define SANDBOX_DEVICE_H

#include <vulkan/vulkan.h>
#include "../../DeviceSupport/_include/DeviceSupport.h"
#include "../../../Queue/_include/QueueFamilyIndices.h"

namespace sandbox::vulkan
{
	class Device
	{
	public:
		static Device * PickDevice(const DeviceSupport & support, Surface surface,
								   std::vector<VkPhysicalDevice> & physicalDevices,
								   const std::vector<const char *>& validationLayers);

	private:
		VkPhysicalDevice physicalDevice;
		DeviceSupport deviceSupport;
		VkDevice logicalDevice;

		Device(VkPhysicalDevice physicalDevice, DeviceSupport deviceSupport, VkDevice logicalDevice);

		static Device * CreateDevice(VkPhysicalDevice physicalDevice, QueueFamilyIndices queueFamilyIndices,
									 const DeviceSupport& deviceSupport, std::vector<const char *> validationLayers);

		static bool CreateLogicalDevice(VkPhysicalDevice physicalDevice, QueueFamilyIndices queueFamilyIndices,
										const DeviceSupport& deviceSupport, std::vector<const char *> validationLayers,
										VkDevice * logicalDevice);
	};
}

#endif //SANDBOX_DEVICE_H
