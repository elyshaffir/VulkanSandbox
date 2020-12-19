#ifndef SANDBOX_DEVICE_H
#define SANDBOX_DEVICE_H

#include <vulkan/vulkan.h>
#include "DeviceSupport.h"

namespace sandbox::vulkan
{
	class Device
	{
	public:
		static Device PickDevice(const DeviceSupport& support, Surface surface,
						   std::vector<VkPhysicalDevice> & physicalDevices);

	private:
		VkPhysicalDevice physicalDevice;
		QueueFamilyIndices queueFamilyIndices;
		VkDevice logicalDevice;

		Device(VkPhysicalDevice physicalDevice, QueueFamilyIndices queueFamilyIndices);

		void CreateLogicalDevice();
	};
}

#endif //SANDBOX_DEVICE_H
